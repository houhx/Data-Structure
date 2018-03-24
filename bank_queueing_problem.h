#pragma once
#include "list/link_list.h"
#include "queue/link_queue.h"
#include <ctime>

struct Event{
	int Occurtime; //�¼�������ʱ��
	int etype;     //�¼����ͣ�0-�ﵽ�¼��� x��1-4��-x�����뿪�¼�, -1Ϊ��ʼֵ
	Event(int o=0, int e=-1): Occurtime(o), etype(e){}; 
}; 

struct qelement{
	int arrivetime; //�������е�ʱ��
	int dealtime;   //����ʱ�� 
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
	ll.insert(event, cmp); //����һ�������¼������¼������� 
}

void customerarrive(){
	Event e;
	ll.remove(1,e);
	
	cout << "���ʱ�䣺" << e.Occurtime ;
	
	int dealtime = 1+rand()%5;
	int arrivetime = 1+rand()%30;
	
	qelement qe(e.Occurtime, dealtime);
	int minq = minqueue();
	cout << "���봰��" << minq+1 << endl; 
	lq[minq].push(qe);
	if(lq[minq].size() == 1){ //����뿪�¼� 
		Event newdeparture(e.Occurtime+dealtime, minq+1);
		ll.insert(newdeparture, cmp); 
	}
	
	Event newarrive(e.Occurtime+arrivetime, 0);//����µĴﵽ�¼� 
	if( newarrive.Occurtime >= closetime ) return;
	ll.insert(newarrive, cmp);
}

void customerdeparture(){
	Event e;
	ll.remove(1,e);  //ȡ���뿪�¼� 
	
	qelement qe;
	lq[e.etype-1].pop(qe); //ȡ���뿪����
	
	totaltime += e.Occurtime - qe.arrivetime; //��¼ʱ������� 
	totalnums++;
	
	cout << "�뿪" << e.etype << "�Ŵ��ڣ�ʱ��:" << e.Occurtime 
	     << "������ͣ��ʱ�䣺" <<  e.Occurtime - qe.arrivetime << endl; 
	
	if(lq[e.etype-1].size() > 0){
		lq[e.etype-1].front(qe);
		Event newdeparture(e.Occurtime + qe.dealtime, e.etype); //����µ��뿪�¼� 
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
	
	cout << "���������е�ƽ��ͣ��ʱ�䣺" << totaltime/totalnums << endl;
}
