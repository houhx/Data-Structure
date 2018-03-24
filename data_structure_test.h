#pragma once
#include "queue/sequence_queue.h"
#include "queue/link_queue.h"
#include "queue/circle_queue.h"
#include "stack/sequence_stack.h"
#include "stack/link_stack.h"
#include "list/link_list.h"
#include "list/static_link_list.h"
#include "list/sequence_list.h"
#include "tree/binary_tree.h"

//data structure catalogs
void print(){
    cout << "--------------------------" << endl
	     << "|	1.队列" << endl
	     << "|	2.栈"   << endl
	     << "|	3.线性表" << endl
	     << "|	4.树" << endl
		 << "|	5.退出"<< endl
		 << "--------------------------" << endl
		 << "\n请输入相应功能序号：";
}

//stack classification
void printstack(){
	cout << "------------------------------" << endl
	     << "|	1.顺序实现的栈" << endl
	     << "|	2.链式栈"       << endl
		 << "|	3.返回"         << endl
		 << "------------------------------" << endl
		 << "\n请输入相应功能序号：";
}

//function catalogs of sequence statck
void printsstack(){
	cout << "------------------------------" << endl
	     << "|	1.设置栈的容量" << endl
	     << "|	2.进栈" << endl
		 << "|	3.出栈"         << endl
		 << "|	4.显示栈中目前元素" << endl
		 << "|	5.清空栈"     << endl
		 << "|	6.栈顶"       << endl
		 << "|	7.栈的当前大小" << endl 
		 << "|	8.栈的容量"   << endl 
		 << "|	9.返回"         << endl
		 << "------------------------------" << endl
		 << "\n请输入相应功能序号：";
}

//function catalogs of link stack
void printlstack(){
	cout << "----------------------------" << endl
	     << "|	1.进栈" << endl
		 << "|	2.出栈"         << endl
		 << "|	3.显示栈中目前元素" << endl
		 << "|	4.清空栈"     << endl
		 << "|	5.栈顶"       << endl
		 << "|	6.栈的当前大小" << endl 
		 << "|	7.返回"         << endl
		 << "----------------------------" << endl
		 << "\n请输入相应功能序号：";
}

//queue claasification
void printqueue(){
	cout << "-------------------------" << endl
	     << "|	1.循环队列" << endl
		 << "|	2.链式队列" << endl
		 << "|	3.头不动的顺序队列" << endl
		 << "|	4.返回" << endl
		 << "-------------------------" << endl
		 << "\n请输入相应功能序号：" << endl;
}

//function catalogs of circle queue 
void printcq(){
	cout << "--------------------------" << endl
	     << "|	1.设置队列容量" << endl
	     << "|	2.添加元素进队" << endl
		 << "|	3.出队"         << endl
		 << "|	4.显示队列中目前元素" << endl
		 << "|	5.清空队列"     << endl
		 << "|	6.队首"         << endl
		 << "|	7.队尾"         << endl
		 << "|	8.队列当前大小" << endl 
		 << "|	9.队列的容量"   << endl 
		 << "|	10.返回"         << endl
		 << "--------------------------" << endl
		 << "\n请输入相应功能序号：" << endl;
}

//function catalogs of link queue
void printlq(){
	cout << "-------------------------------" << endl
	     << "|	1.添加元素进队" << endl
		 << "|	2.出队"         << endl
		 << "|	3.显示队列中目前元素" << endl
		 << "|	4.清空队列"     << endl
		 << "|	5.队首"         << endl
		 << "|	6.队尾"         << endl
		 << "|	7.队列当前大小" << endl 
		 << "|	8.返回"         << endl
		 << "-------------------------------" << endl
		 << "\n请输入相应功能序号：" << endl;
}

//function catalogs of sequence queue
void printsq(){
	cout << "----------------------------------" << endl
	     << "|	1.设置队列容量" << endl
	     << "|	2.添加元素进队" << endl
		 << "|	3.出队"         << endl
		 << "|	4.显示队列中目前元素" << endl
		 << "|	5.清空队列"     << endl
		 << "|	6.队首"         << endl
		 << "|	7.队尾"         << endl
		 << "|	8.队列当前大小" << endl 
		 << "|	9.队列的容量"   << endl 
		 << "|	10.返回"         << endl
		 << "-----------------------------------" << endl
		 << "\n请输入相应功能序号：" << endl;
}

//list classification
void printlist(){
	cout << "---------------------------" << endl 
	     << "|	1.单链表" << endl 
	     << "|	2.静态链表" << endl
		 << "|	3.顺序线性表" << endl 
	     << "|	4.返回"   << endl
		 << "---------------------------" << endl
		 << "\n请输入相应功能序号：";
}

//function catalogs of link list
void printllist(){
	cout << "-------------------------------------------" << endl
	     << "|	1.添加元素进表,自动插入尾端"<< endl
	     << "|	2.添加元素进表，并自动按升序排列"<< endl
		 << "|	3.添加元素进表，并自动按降序排列"<< endl 
		 << "|	4.向指定位置添加元素"<< endl
		 << "|	5.删除指定位置元素"<< endl
		 << "|	6.显示表中目前元素"<< endl
		 << "|	7.清空表"<< endl
		 << "|	8.查看表中指定位置元素"<< endl
		 << "|	9.表当前大小"<< endl 
		 << "|	10.返回"<< endl
		 << "-------------------------------------------" << endl
		 << "\n请输入相应功能序号：";
}

//function catalogs of static link list, implemetion by array
void printsllist(){
	cout << "1.添加元素进表" << endl
	     << "2.按升序添加元素进表" << endl
		 << "3.按降序添加元素进表" << endl 
		 << "4.删除指定位置元素"         << endl
		 << "5.显示表中目前元素" << endl
		 << "6.清空表"     << endl
		 << "7.查看表中指定位置元素" << endl
		 << "8.表当前大小" << endl 
		 << "9.返回"         << endl
		 << "\n请输入相应功能序号：";
}

//function catalogs of sequence list
void printslist(){
	cout << "-------------------------------------------" << endl
	     << "|	1.添加元素进表,自动插入尾端"<< endl
	     << "|	2.添加元素进表，并自动按升序排列"<< endl
		 << "|	3.添加元素进表，并自动按降序排列"<< endl 
		 << "|	4.向指定位置添加元素"<< endl
		 << "|	5.删除指定位置元素"<< endl
		 << "|	6.显示表中目前元素"<< endl
		 << "|	7.清空表"<< endl
		 << "|	8.查看表中指定位置元素"<< endl
		 << "|	9.表当前大小"<< endl 
		 << "|	10.返回"<< endl
		 << "-------------------------------------------" << endl
		 << "\n请输入相应功能序号：";
}

//tree classification
void printtree(){
	cout << "--------------------" << endl
	     << "|	1.二叉树" << endl
		 << "|	2.退出"   << endl
		 << "--------------------" << endl
		 << "\n请输入相应功能序号：";
}

//function catalogs of binary tree
void printbitree(){
	cout << "-------------------" << endl
	     << "|	1.创建树" << endl
		 << "|	2.树的总节点数" << endl
		 << "|	3.先序" << endl
		 << "|	4.中序" << endl
		 << "|	5.后序" << endl
		 << "|	6.返回"   << endl
		 << "-------------------" << endl
		 << "\n请输入相应功能序号：";
}

//clear the screen
void clearscreen(){
 	#ifdef _WIN32
		system("cls");
 	#else
		system("clear");
 	#endif
}


void test(){
	print();
	int type;
	while((cin >> type) && type != 5){
		switch(type){
		    case 1:{                                      //队列 
				clearscreen();
		        printqueue();
				while((cin >> type) && type != 4){
					switch(type){
					    case 1: {                       //循环队列
					        clearscreen();
					        printcq();
		                    cqueue cq;
		                    while((cin >> type) && type != 10){
							    switch(type){
								    case 1: {
								        cout << "\n\n目前大小为：" << cq.size() << endl
										     << "容量为：" << cq.capacity() << endl 
											 << "请输入你要设置的容量：";
								        cin >> type;
								        cq.setcapacity(type+1);
								        cout << "\n设置成功！现在容量为：" << cq.capacity() << "\n\n";
								        printcq();
								        break;
									}
											
								    case 2: {
								    	int remainder = cq.capacity()-cq.size();
								    	
								    	if(remainder == 0) cout << "\n\n队列已满，不能添加！\n\n";
								    	else{
								    		cout << "\n\n目前还能最多添加" << remainder
											     << "个元素，请依次输入你要添加的元素，并用空格隔开: \n"; 
								            while(cin >> type){
								                cq.push(type);
								                if(cin.get() == '\n') break;
										    }
										    cout << "\n添加完成！\n" << endl;
										}
										
										printcq();
										break;
									}
													
									case 3: {
									    return_code rc = cq.pop(type);
									    if(rc == underflow) cout << "\n\n队列已空！\n\n";
									    else cout << "\n\n出队元素为：" << type << "\n\n";
										printcq();
										break;
									}
											        
									case 4: {
										cout << "\n\n";
										cq.traver([](elemtype& e)->void{cout << e << "  ";});
										cout << "\n\n";
									    printcq();
										break;   
									}
											
									case 5: {
										cq.clear();
									    cout << "\n\n队列已清空！\n" << endl;
										printcq();
										break;
								    }
											     
									case 6: {
										if(cq.empty()) cout << "\n\n队列是空的！\n";
										else{
											cq.front(type);
									        cout << "\n\n" << type << "\n\n";
										}
										printcq();
										break;
									}
											        
									case 7: {
										if(cq.empty()) cout << "\n\n队列是空的！\n";
										else{
											cq.back(type);
									        cout << "\n\n" << type << "\n\n";
										}
										printcq();
										break;
									}
											        
									case 8: {
										cout << "\n\n" << cq.size() << "\n\n";
									    printcq();
										break;
									}
									
									case 9: {
										cout << "\n\n" << cq.capacity() << "\n\n";
										printcq();
										break;
									}        		
								}
							}
							clearscreen();
							printqueue();
							break;
					    }
					    
					    case 2: {                        //链式队列
					        clearscreen();
					        printlq();
		                    linkqueue<int> lq;
		                    while((cin >> type) && type != 8){
							    switch(type){			
								    case 1: {
								    	cout << "\n\n请依次输入你要添加的元素，并用空格隔开,回车结束: \n"; 
								        while(cin >> type){
								            lq.push(type);
								            if(cin.get() == '\n') break;
										}
										cout << "\n添加完成！\n" << endl;
								
										printlq();
										break;
									}
													
									case 2: {
									    return_code rc = lq.pop(type);
									    if(rc == underflow) cout << "\n\n队列已空！\n\n";
									    else cout << "\n\n出队元素为：" << type << "\n\n";
										printlq();
										break;
									}
											        
									case 3: {
										if(lq.empty()){
											cout << "\n\n队列是空的！\n\n";
											printlq();
											break;
										}
										cout << "\n\n";
										lq.traver([](const int &e)->void{cout << e << "  ";});
										cout << "\n\n";
									    printlq();
										break;   
									}
											
									case 4: {
										lq.clear();
									    cout << "\n\n队列已清空！\n" << endl;
										printlq();
										break;
								    }
											     
									case 5: {
										if(lq.empty()) cout << "\n\n队列是空的！\n\n";
										else{
											lq.front(type);
									        cout << "\n\n" << "队首元素为：" << type << "\n\n";
										}
										printlq();
										break;
									}
											        
									case 6: {
										if(lq.empty()) cout << "\n\n队列是空的！\n\n";
										else{
											lq.back(type);
									        cout << "\n\n" << "队尾元素为：" << type << "\n\n";
										}
										printlq();
										break;
									}
											        
									case 7: {
										cout << "\n\n" << "队列大小为：" << lq.size() << "\n\n";
									    printlq();
										break;
									}

									default: {
										cout << "\n\n请输入正确的序号！\n\n";
										printlq();
										break;
									}      		
								}
							}
							clearscreen();
							printqueue();
							break;
					    }
						
						case 3: {                        //顺序队列
					        clearscreen();
					        printsq();
		                    squeue sq;
		                    while((cin >> type) && type != 10){
							    switch(type){
								    case 1: {
								        cout << "\n\n目前大小为：" << sq.size() << endl
								             << "容量为：" << sq.capacity() << endl
										     << "请输入你要设置的容量：";
								        cin >> type;
								        sq.setcapacity(type);
								        cout << "\n设置成功！现在容量为：" << sq.capacity() << "\n\n";
								        printsq();
								        break;
									}
											
								    case 2: {
								    	cout << "请依次输入你要添加的元素，并用空格隔开: \n"; 
								        while(cin >> type){
								            sq.push(type);
								            if(cin.get() == '\n') break;
										}
										cout << "\n添加完成！\n" << endl;
										
										printsq();
										break;
									}
													
									case 3: {
									    return_code rc = sq.pop(type);
									    if(rc == underflow) cout << "\n\n队列已空！\n\n";
									    else cout << "\n\n出队元素为：" << type << "\n\n";
										printsq();
										break;
									}
											        
									case 4: {
										cout << "\n\n";
										sq.traver([](elemtype& e)->void{cout << e << "  ";});
										cout << "\n\n";
									    printsq();
										break;   
									}
											
									case 5: {
										sq.clear();
									    cout << "\n\n队列已清空！\n" << endl;
										printsq();
										break;
								    }
											     
									case 6: {
										if(sq.empty()) cout << "\n\n队列是空的！\n";
										else{
											sq.front(type);
									        cout << "\n\n" << type << "\n\n";
										}
										printsq();
										break;
									}
											        
									case 7: {
										if(sq.empty()) cout << "\n\n队列是空的！\n";
										else{
											sq.back(type);
									        cout << "\n\n" << type << "\n\n";
										}
										printsq();
										break;
									}
											        
									case 8: {
										cout << "\n\n" << sq.size() << "\n\n";
									    printsq();
										break;
									}
									
									case 9: {
										cout << "\n\n" << sq.capacity() << "\n\n";
										printsq();
										break;
									}        		
								}
							}
							clearscreen();
							printqueue();
							break;
					    }		  
				    }
				}
				clearscreen();
				print();
				break;
			}
			        
	        case 2:{                                     //栈 
		    	clearscreen();
		        printstack();
				while((cin >> type) && type != 3){
					switch(type){
					    case 1: {                        //顺序栈
					        clearscreen();
					        printsstack();
		                    sstack<int> ss;
		                    while((cin >> type) && type != 9){
							    switch(type){
								    case 1: {
								        cout << "\n目前大小为：" << ss.size() << endl
								             << "容量为：" << ss.getcapacity() << endl
										     << "请输入你要设置的容量：";
								        cin >> type;
										if(type < ss.size()){
											cout << "\nerror! 设置的容量小于当前栈中元素数量。\n" << endl;
											printsstack();
											break;
										}
								        ss.setcapacity(type);
								        cout << "\n设置成功！现在容量为：" << ss.getcapacity() << "\n\n";
								        printsstack();
								        break;
									}
											
								    case 2: {
								    	cout << "\n\n请依次输入你要压入的元素，用空格分开,回车结束：\n"; 
								        while(cin >> type){
								            ss.push(type);
								            if(cin.get() == '\n') break;
										}
										cout << "\n添加完成！\n" << endl;
										
										printsstack();
										break;
									}
													
									case 3: {
									    return_code rc = ss.pop(type);
									    if(rc == underflow) cout << "\n\n栈已空！\n\n";
									    else cout << "\n\n出栈元素为：" << type << "\n\n";
										printsstack();
										break;
									}
											        
									case 4: {
										if(ss.empty()){
											cout << "\n\n栈是空的！\n\n";
											printsstack();
											break;
										}
										cout << "\n\n";
										ss.traver([](const int &e)->void{cout << e << "  ";});
										cout << "\n\n";
									    printsstack();
										break;   
									}
											
									case 5: {
										ss.clear();
									    cout << "\n\n栈已清空！\n" << endl;
										printsstack();
										break;
								    }
											     
									case 6: {
										if(ss.empty()) cout << "\n\n栈是空的！\n" << endl;
										else{
											ss.top(type);
									        cout << "\n\n" << "栈顶元素为：" << type << "\n\n";
										}
										printsstack();
										break;
									}
											        
									case 7: {
										cout << "\n\n" << "栈的大小为： " << ss.size() << "\n\n";
									    printsstack();
										break;
									}
									
									case 8: {
										cout << "\n\n" << "栈的容量为：" << ss.getcapacity() << "\n\n";
										printsstack();
										break;
									}

									default: {
										cout << "\n\n请输入正确的序号！\n\n";
										printsstack();
										break;
									}        		
								}
							}
							clearscreen();
							printstack();
							break;
					    }
					    
					    case 2: {                        //链式栈
					    	clearscreen();
					        printlstack();
		                    linkstack<int> ls;
		                    while((cin >> type) && type != 7){
							    switch(type){
								    case 1: {
								    	cout << "\n\n请依次输入你要压入的元素，用空格分开,回车结束：\n"; 
								        while(cin >> type){
								            ls.push(type);
								            if(cin.get() == '\n') break;
										}
										cout << "\n添加完成！\n" << endl;
										
										printlstack();
										break;
									}
													
									case 2: {
									    return_code rc = ls.pop(type);
									    if(rc == underflow) cout << "\n\n栈已空！\n\n";
									    else cout << "\n\n出栈元素为：" << type << "\n\n";
										printlstack();
										break;
									}
											        
									case 3: {
										if(ls.empty()){
											cout << "\n\n栈是空的！\n\n";
											printlstack();
											break;
										}
										cout << "\n\n";
										ls.traver([](const int &e)->void{cout << e << "  ";});
										cout << "\n\n";
									    printlstack();
										break;   
									}
											
									case 4: {
										ls.clear();
									    cout << "\n\n栈已清空！\n" << endl;
										printlstack();
										break;
								    }
											     
									case 5: {
										if(ls.empty()) cout << "\n\n栈是空的！\n\n";
										else{
											ls.top(type);
									        cout << "\n\n" << "栈顶元素为：" << type << "\n\n";
										}
										printlstack();
										break;
									}
											        
									case 6: {
										cout << "\n\n" << "栈的大小：" << ls.size() << "\n\n";
									    printlstack();
										break;
									}

									default: {
										cout << "\n\n请输入正确的序号！\n\n";
										printllist();
										break;
									}       		
								}
							}
							clearscreen();
							printstack();
							break;
						}		  
				    }
				}
				clearscreen();
				print();
				break;
			}
			
			case 3:{                                     //线性表 
		    	clearscreen();
		        printlist();
				while((cin >> type) && type != 4){
					switch(type){
					    case 1: {                    //单链表 
					        clearscreen();
					        printllist();
		                    linklist<int> ll;
		                    while((cin >> type) && type != 10){
							    switch(type){
								    case 1: {
								    	cout << "\n请依次输入你要添加的元素，用空格分开,回车结束：\n";

								        while(cin >> type){
								            if(ll.insert(ll.size(), type) == Range_error){
												cout << "range_error!" << endl;
											}
								            if(cin.get() == '\n') break;
										}

										cout << "\n添加完成!\n"    << endl;
										
										printllist();
										break;
									}
													
									case 2: {
										ll.ascendingsort();
									    cout << "\n请依次输入你要添加的元素，用空格分开,回车结束：\n";

								        while(cin >> type){
								            if(ll.insert(type, [](const int &a, const int &b)->bool{
								            	return a<b;
											}) == Range_error){
												cout << "range_error!" << endl;
											}
								            if(cin.get() == '\n') break;
										}

										cout << "\n添加完成!\n"    << endl;
										
										printllist();
										break;
									}
									
									case 3: {
										ll.descendingsort();
									    cout << "\n请依次输入你要添加的元素，用空格分开, 回车结束：\n";

								        while(cin >> type){
								            if(ll.insert(type, [](const int &a, const int &b)->bool{
								            	return a>b;
											}) == Range_error){
												cout << "range_error!" << endl;
											}
								            if(cin.get() == '\n') break;
										}
										
										cout << "\n添加完成!\n"    << endl;
										
										printllist();
										break;
									}
									
									case 4: {
										int pos = -1;
										cout << "\n请输入您想插入元素的位置(0-" << ll.size() << "): ";
										cin >> pos;
										cout << "\n请输入您要插入的元素值： ";
										cin >> type;

										if(ll.insert(pos, type) == Range_error){
											cout << "\n插入位置不合法!\n" << endl;
										}
										else{
											cout << "\n插入成功！\n" << endl;
										}

										printllist();
										break;
									}

									case 5: {
										if(ll.empty()){
											cout << "\n表是空表，无法进行删除操作！\n\n";
											printllist();
											break;
										}
										cout << "\n指出你要删除第几个元素（0-" << ll.size()-1 << " ）：";
										cin >> type;
										int save = 0;
										ll.remove(type,save);
										cout << "\n成功删除第"<< type << "个元素：" << save << endl;
										cout << endl;
										printllist();
										break;
									}
											        
									case 6: {
										if(ll.empty()){
											cout << "\n表为空！\n" << endl;
											printllist();
										    break;
										}
										cout << "\n";
										ll.traver([](const int &e)->void{cout << e << "  ";});
										cout << "\n\n";
									    printllist();
										break;   
									}
											
									case 7: {
										ll.clear();
									    cout << "\n表已清空！\n" << endl;
										printllist();
										break;
								    }
											     
									case 8: {
										if(ll.empty()){
											cout << "\n表是空表，无法进行查看操作！\n\n";
											printllist();
											break;
										}
										cout << "\n指出你要查看第几个元素（0-" << ll.size()-1 << " ）：";
										cin >> type;
										int save = 0;
										ll.retrieve(type,save);
										cout << "\n第"<< type << "个元素：" << save << endl;
										cout << endl;
										printllist();
										break;
									}
											        
									case 9: {
										cout << "\n表的长度： " << ll.size() << "\n\n";
									    printllist();
										break;
									}

									default: {
										cout << "\n请输入正确的序号! \n\n";
										printllist();
										break;
									}       		
								}
							}
							clearscreen();
							printlist();
							break;
					    }
						
						case 2: {                    //静态链表 
					        clearscreen();
					        printsllist();
		                    sllist<int> sll;
		                    while((cin >> type) && type != 9){
							    switch(type){
								    case 1: {
								    	cout << "\n\n请依次输入你要添加的元素，用空格分开：\n"; 
								        while(cin >> type){
								            sll.insert(type, sll.size()+1);
								            if(cin.get() == '\n') break;
										}
										cout << "\n添加完成！\n" << endl;
										
										printsllist();
										break;
									}
													
									case 2: {
									    cout << "\n\n请依次输入你要添加的元素，用空格分开：\n"; 
								        while(cin >> type){
								            sll.insert(type, [](const int &a, const int &b)->bool{
								            	return a>b;
											});
								            if(cin.get() == '\n') break;
										}
										cout << "\n添加完成！\n" << endl;
										
										printsllist();
										break;
									}
									
									case 3: {
									    cout << "\n\n请依次输入你要添加的元素，用空格分开：\n"; 
								        while(cin >> type){
								            sll.insert(type, [](const int &a, const int &b)->bool{
								            	return a<b;
											});
								            if(cin.get() == '\n') break;
										}
										cout << "\n添加完成！\n" << endl;
										
										printsllist();
										break;
									}
									
									case 4: {
										if(sll.empty()){
											cout << "\n\n表是空表，无法进行删除操作！\n";
											printllist();
											break;
										}
										cout << "\n\n指出你要删除第几个元素（1-" << sll.size() << " ）：";
										cin >> type;
										int save = 0;
										sll.remove(type,save);
										cout << "\n成功删除第"<< type << "个元素：" << save << endl;
										printsllist();
										break;
									}
											        
									case 5: {
										cout << "\n\n";
										sll.traver([](const int &e)->void{cout << e << "  ";});
										cout << "\n\n";
									    printsllist();
										break;   
									}
											
									case 6: {
										sll.clear();
									    cout << "\n\n表已清空！\n" << endl;
										printsllist();
										break;
								    }
											     
									case 7: {
										if(sll.empty()){
											cout << "\n\n表是空表，无法进行查看操作！\n";
											printllist();
											break;
										}
										cout << "\n\n指出你要查看第几个元素（1-" << sll.size() << " ）：";
										cin >> type;
										int save = 0;
										sll.retrieve(type,save);
										cout << "\n第"<< type << "个元素：" << save << endl;
										printsllist();
										break;
									}
											        
									case 8: {
										cout << "\n\n" << sll.size() << "\n\n";
									    printsllist();
										break;
									}       		
								}
							}
							clearscreen();
							printlist();
							break;
					    }

						case 3: {                    //顺序线性表
							clearscreen();
					        printslist();
		                    slist<int> sl;
		                    while((cin >> type) && type != 10){
							    switch(type){
								    case 1: {
								    	cout << "\n请依次输入你要添加的元素，用空格分开,回车结束：\n";

								        while(cin >> type){
								            if(sl.insert(sl.getlen(), type) == Range_error){
												cout << "range_error!" << endl;
											}
								            if(cin.get() == '\n') break;
										}

										cout << "\n添加完成!\n"    << endl;
										
										printslist();
										break;
									}
													
									case 2: {
										sl.ascendingsort();
									    cout << "\n请依次输入你要添加的元素，用空格分开,回车结束：\n";

								        while(cin >> type){
								            if(sl.insert(type, [](const int &a, const int &b)->bool{
								            	return a<b;
											}) == Range_error){
												cout << "range_error!" << endl;
											}
								            if(cin.get() == '\n') break;
										}

										cout << "\n添加完成!\n"    << endl;
										
										printslist();
										break;
									}
									
									case 3: {
										sl.descendingsort();
									    cout << "\n请依次输入你要添加的元素，用空格分开, 回车结束：\n";

								        while(cin >> type){
								            if(sl.insert(type, [](const int &a, const int &b)->bool{
								            	return a>b;
											}) == Range_error){
												cout << "range_error!" << endl;
											}
								            if(cin.get() == '\n') break;
										}
										
										cout << "\n添加完成!\n"    << endl;
										
										printslist();
										break;
									}
									
									case 4: {
										int pos = -1;
										cout << "\n请输入您想插入元素的位置(0-" << sl.getlen() << "): ";
										cin >> pos;
										cout << "\n请输入您要插入的元素值： ";
										cin >> type;

										if(sl.insert(pos, type) == Range_error){
											cout << "\n插入位置不合法!\n" << endl;
										}
										else{
											cout << "\n插入成功！\n" << endl;
										}

										printslist();
										break;
									}

									case 5: {
										if(sl.empty()){
											cout << "\n表是空表，无法进行删除操作！\n\n";
											printslist();
											break;
										}
										cout << "\n指出你要删除第几个元素（0-" << sl.getlen()-1 << " ）：";
										cin >> type;
										int save = 0;
										sl.deletelemt(type,save);
										cout << "\n成功删除第"<< type << "个元素：" << save << endl;
										cout << endl;
										printslist();
										break;
									}
											        
									case 6: {
										if(sl.empty()){
											cout << "\n表为空！\n" << endl;
											printslist();
										    break;
										}
										cout << "\n";
										sl.traver([](const int &e)->void{cout << e << "  ";});
										cout << "\n\n";
									    printslist();
										break;   
									}
											
									case 7: {
										sl.clear();
									    cout << "\n表已清空！\n" << endl;
										printslist();
										break;
								    }
											     
									case 8: {
										if(sl.empty()){
											cout << "\n表是空表，无法进行查看操作！\n\n";
											printslist();
											break;
										}
										cout << "\n指出你要查看第几个元素（0-" << sl.getlen()-1 << " ）：";
										cin >> type;
										int save = 0;
										sl.retrieve(type,save);
										cout << "\n第"<< type << "个元素：" << save << endl;
										cout << endl;
										printslist();
										break;
									}
											        
									case 9: {
										cout << "\n表的长度： " << sl.getlen() << "\n\n";
									    printslist();
										break;
									}

									default: {
										cout << "\n请输入正确的序号! \n\n";
										printslist();
										break;
									}       		
								}
							}
							clearscreen();
							printlist();
							break;
						}		  
				    }
				}
				clearscreen();
				print();
				break;
			}

			case 4:{                                     //树
				clearscreen();
				printtree();
				while((cin >> type) && type != 2){
					switch(type){
						case 1: {                //二叉树
							clearscreen();
							printbitree();
							bitree<int> bt;
							while((cin >> type) && type != 6){
								switch(type){
									case 1: {
										cout << endl << endl;
										bt.createbitree_preorder();
										cout << endl;
										printbitree();
										break;
									}

									case 2: {
										cout << "\n\n树的总节点数为：" << bt.size() << "\n\n";
										printbitree();
										break;
									}

									case 3: {
										if(bt.empty()){
											cout << "\n\n树是空树\n\n";
											printbitree();
											break;
										}
										cout << "\n\n树的先序输出为：\n";
										bt.preorder_traverse([](const int &t)->void{
											cout << t << "  ";
										});
										cout << "\n\n";
										printbitree();
										break;
									}

									case 4: {
										if(bt.empty()){
											cout << "\n\n树是空树\n\n";
											printbitree();
											break;
										}
										cout << "\n\n树的中序输出为：\n";
										bt.inorder_traverse([](const int &t)->void{
											cout << t << "  ";
										});
										cout << "\n\n";
										printbitree();
										break;
									}

									case 5: {
										if(bt.empty()){
											cout << "\n\n树是空树\n\n";
											printbitree();
											break;
										}
										cout << "\n\n树的后序输出为：\n";
										bt.postorder_traverse([](const int &t)->void{
											cout << t << "  ";
										});
										cout << "\n\n";
										printbitree();
										break;
									}

									default: {
										cout << "\n\n请输入正确序号！\n\n";
										printbitree();
										break;
									}
								}
							}
							clearscreen();
							printtree();
							break;
						}

						default: {
							cout << "\n\n请输入正确序号！\n\n";
							printtree();
							break;
						}
					}
				}
				clearscreen();
				print();
				break;
			}

			default: {
				cout << "\n\n请输入正确的序号！\n\n";
				break;
			} 						  
	    }
	}
}


