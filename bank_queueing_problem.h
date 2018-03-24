#pragma once
#include "list/link_list.h"
#include "queue/link_queue.h"
#include <ctime>

struct Event{
	int Occurtime; //事件发生的时间
	int etype;     //事件类型，0-达到事件； x（1-4）-x窗口离开事件, -1为初始值
	Event(int o=0, int e=-1): Occurtime(o), etype(e){}; 
}; 

struct qelement{
	int arrivetime; //到达银行的时间
	int dealtime;   //处理时间 
	qelement(int a=0, int d=0): arrivetime(a), dealtime(d){};
};

const  int closetime = 120; 
static double totaltime;
static double totalnums;
static linklist<Event> ll;
static linkqueue<qelement> lq[4];



bool cmp(const Event &a, const Event &b){
	return a.Occurtime > b.Occurtime;
}

int minqueue(){
	int m = lq[0].size() > lq[1].size() ? 1 : 0;
	m = lq[m].size() > lq[2].size() ? 2 : m;
	m = lq[m].size() > lq[3].size() ? 3 : m;
	return m;
} 

void init(){
	totaltime = 0;
	totalnums = 0;
	Event event(0,0);
	ll.insert(event, cmp); //将第一个到达事件放入事件发生器 
}

void customerarrive(){
	Event e;
	ll.remove(1,e);
	
	cout << "到达，时间：" << e.Occurtime ;
	
	int dealtime = 1+rand()%5;
	int arrivetime = 1+rand()%30;
	
	qelement qe(e.Occurtime, dealtime);
	int minq = minqueue();
	cout << "进入窗口" << minq+1 << endl; 
	lq[minq].push(qe);
	if(lq[minq].size() == 1){ //添加离开事件 
		Event newdeparture(e.Occurtime+dealtime, minq+1);
		ll.insert(newdeparture, cmp); 
	}
	
	Event newarrive(e.Occurtime+arrivetime, 0);//添加新的达到事件 
	if( newarrive.Occurtime >= closetime ) return;
	ll.insert(newarrive, cmp);
}

void customerdeparture(){
	Event e;
	ll.remove(1,e);  //取出离开事件 
	
	qelement qe;
	lq[e.etype-1].pop(qe); //取出离开的人
	
	totaltime += e.Occurtime - qe.arrivetime; //记录时间和人数 
	totalnums++;
	
	cout << "离开" << e.etype << "号窗口，时间:" << e.Occurtime 
	     << "在银行停留时间：" <<  e.Occurtime - qe.arrivetime << endl; 
	
	if(lq[e.etype-1].size() > 0){
		lq[e.etype-1].front(qe);
		Event newdeparture(e.Occurtime + qe.dealtime, e.etype); //添加新的离开事件 
		ll.insert(newdeparture, cmp);
	} 
}

void bank_simulation(){
	srand(time(nullptr));
	init();
	while(!ll.empty()){
		Event top;
		ll.retrieve(1,top);
		switch(top.etype){
			case 0:{
				customerarrive();
				break;
			}
			
			default:{
				customerdeparture();
				break;
			}
		}
	}
	
	cout << "人们在银行的平均停留时间：" << totaltime/totalnums << endl;
}
