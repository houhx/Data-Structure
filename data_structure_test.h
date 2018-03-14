﻿#pragma once
#include "queue/sequence_queue.h"
#include "queue/link_queue.h"
#include "queue/circle_queue.h"
#include "stack/sequence_stack.h"
#include "stack/link_stack.h"
#include "list/link_list.h"
#include "list/static_link_list.h"

void print(){
	cout << "1.队列" << endl
	     << "2.栈"   << endl
	     << "3.线性表" << endl
	     << "4.退出" << endl;
}

void printstack(){
	cout << "1.顺序实现的栈" << endl
	     << "2.链式栈"       << endl
		 << "3.返回"         << endl; 
}

void printsstack(){
	cout << "1.设置栈的容量" << endl
	     << "2.进栈" << endl
		 << "3.出栈"         << endl
		 << "4.显示栈中目前元素" << endl
		 << "5.清空栈"     << endl
		 << "6.栈顶"       << endl
		 << "7.栈的当前大小" << endl 
		 << "8.栈的容量"   << endl 
		 << "9.返回"         << endl;
}

void printlstack(){
	cout << "1.进栈" << endl
		 << "2.出栈"         << endl
		 << "3.显示栈中目前元素" << endl
		 << "4.清空栈"     << endl
		 << "5.栈顶"       << endl
		 << "6.栈的当前大小" << endl 
		 << "7.返回"         << endl;
}

void printqueue(){
	cout << "1.循环队列" << endl
		 << "2.链式队列" << endl
		 << "3.头不动的顺序队列" << endl
		 << "4.返回" << endl;
}

void printcq(){
	cout << "1.设置队列容量" << endl
	     << "2.添加元素进队" << endl
		 << "3.出队"         << endl
		 << "4.显示队列中目前元素" << endl
		 << "5.清空队列"     << endl
		 << "6.队首"         << endl
		 << "7.队尾"         << endl
		 << "8.队列当前大小" << endl 
		 << "9.队列的容量"   << endl 
		 << "10.返回"         << endl;
}

void printlq(){
	cout << "1.添加元素进队" << endl
		 << "2.出队"         << endl
		 << "3.显示队列中目前元素" << endl
		 << "4.清空队列"     << endl
		 << "5.队首"         << endl
		 << "6.队尾"         << endl
		 << "7.队列当前大小" << endl 
		 << "8.返回"         << endl;
}

void printsq(){
	cout << "1.设置队列容量" << endl
	     << "2.添加元素进队" << endl
		 << "3.出队"         << endl
		 << "4.显示队列中目前元素" << endl
		 << "5.清空队列"     << endl
		 << "6.队首"         << endl
		 << "7.队尾"         << endl
		 << "8.队列当前大小" << endl 
		 << "9.队列的容量"   << endl 
		 << "10.返回"         << endl;
}

void printlist(){
	cout << "1.单链表" << endl
	     << "2.静态链表" << endl 
	     << "3.返回"   << endl;
}

void printllist(){
	cout << "1.添加元素进表" << endl
	     << "2.按升序添加元素进表" << endl
		 << "3.按降序添加元素进表" << endl 
		 << "4.删除指定位置元素"         << endl
		 << "5.显示表中目前元素" << endl
		 << "6.清空表"     << endl
		 << "7.查看表中指定位置元素" << endl
		 << "8.表当前大小" << endl 
		 << "9.返回"         << endl;
}

void printsllist(){
	cout << "1.添加元素进表" << endl
	     << "2.按升序添加元素进表" << endl
		 << "3.按降序添加元素进表" << endl 
		 << "4.删除指定位置元素"         << endl
		 << "5.显示表中目前元素" << endl
		 << "6.清空表"     << endl
		 << "7.查看表中指定位置元素" << endl
		 << "8.表当前大小" << endl 
		 << "9.返回"         << endl;
}

void test(){
	print();
	int type;
	while((cin >> type) && type != 4){
		switch(type){
		    case 1:{                                      //队列 
		    	system("clear");
		        printqueue();
				while((cin >> type) && type != 4){
					switch(type){
					    case 1: {
					        system("clear");
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
							system("clear");
							printqueue();
							break;
					    }
					    
					    case 2: {
					        system("clear");
					        printlq();
		                    linkqueue<int> lq;
		                    while((cin >> type) && type != 8){
							    switch(type){			
								    case 1: {
								    	cout << "\n\n请依次输入你要添加的元素，并用空格隔开: \n"; 
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
										if(lq.empty()) cout << "\n\n队列是空的！\n";
										else{
											lq.front(type);
									        cout << "\n\n" << type << "\n\n";
										}
										printlq();
										break;
									}
											        
									case 6: {
										if(lq.empty()) cout << "\n\n队列是空的！\n";
										else{
											lq.back(type);
									        cout << "\n\n" << type << "\n\n";
										}
										printlq();
										break;
									}
											        
									case 7: {
										cout << "\n\n" << lq.size() << "\n\n";
									    printlq();
										break;
									}      		
								}
							}
							system("clear");
							printqueue();
							break;
					    }
						
						case 3: {
					        system("clear");
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
							system("clear");
							printqueue();
							break;
					    }		  
				    }
				}
				system("clear");
				print();
				break;
			}
			        
	        case 2:{                                     //栈 
		    	system("clear");
		        printstack();
				while((cin >> type) && type != 3){
					switch(type){
					    case 1: {
					        system("clear");
					        printsstack();
		                    sstack ss;
		                    while((cin >> type) && type != 9){
							    switch(type){
								    case 1: {
								        cout << "\n\n目前大小为：" << ss.size() << endl
								             << "容量为：" << ss.capacity() << endl
										     << "请输入你要设置的容量：";
								        cin >> type;
								        ss.setcapacity(type);
								        cout << "\n设置成功！现在容量为：" << ss.capacity() << "\n\n";
								        printsstack();
								        break;
									}
											
								    case 2: {
								    	cout << "\n\n请依次输入你要压入的元素，用空格分开：\n"; 
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
										cout << "\n\n";
										ss.traver([](elemtype& e)->void{cout << e << "  ";});
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
										if(ss.empty()) cout << "\n\n栈是空的！\n";
										else{
											ss.top(type);
									        cout << "\n\n" << type << "\n\n";
										}
										printsstack();
										break;
									}
											        
									case 7: {
										cout << "\n\n" << ss.size() << "\n\n";
									    printsstack();
										break;
									}
									
									case 8: {
										cout << "\n\n" << ss.capacity() << "\n\n";
										printsstack();
										break;
									}        		
								}
							}
							system("clear");
							printstack();
							break;
					    }
					    
					    case 2: {
					    	system("clear");
					        printlstack();
		                    linkstack ls;
		                    while((cin >> type) && type != 7){
							    switch(type){
								    case 1: {
								    	cout << "\n\n请依次输入你要压入的元素，用空格分开：\n"; 
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
										cout << "\n\n";
										ls.traver([](elemtype& e)->void{cout << e << "  ";});
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
										if(ls.empty()) cout << "\n\n栈是空的！\n";
										else{
											ls.top(type);
									        cout << "\n\n" << type << "\n\n";
										}
										printlstack();
										break;
									}
											        
									case 6: {
										cout << "\n\n" << ls.size() << "\n\n";
									    printlstack();
										break;
									}       		
								}
							}
							system("clear");
							printstack();
							break;
						}		  
				    }
				}
				system("clear");
				print();
				break;
			}
			
			case 3:{                                     //线性表 
		    	system("clear");
		        printlist();
				while((cin >> type) && type != 3){
					switch(type){
					    case 1: {                    //单链表 
					        system("clear");
					        printllist();
		                    linklist<int> ll;
		                    while((cin >> type) && type != 9){
							    switch(type){
								    case 1: {
								    	cout << "\n\n请依次输入你要添加的元素，用空格分开：\n"; 
								        while(cin >> type){
								            ll.insert(type, ll.size()+1);
								            if(cin.get() == '\n') break;
										}
										cout << "\n添加完成！\n" << endl;
										
										printllist();
										break;
									}
													
									case 2: {
									    cout << "\n\n请依次输入你要添加的元素，用空格分开：\n"; 
								        while(cin >> type){
								            ll.insert(type, [](const int &a, const int &b)->bool{
								            	return a>b;
											});
								            if(cin.get() == '\n') break;
										}
										cout << "\n添加完成！\n" << endl;
										
										printllist();
										break;
									}
									
									case 3: {
									    cout << "\n\n请依次输入你要添加的元素，用空格分开：\n"; 
								        while(cin >> type){
								            ll.insert(type, [](const int &a, const int &b)->bool{
								            	return a<b;
											});
								            if(cin.get() == '\n') break;
										}
										cout << "\n添加完成！\n" << endl;
										
										printllist();
										break;
									}
									
									case 4: {
										if(ll.empty()){
											cout << "\n\n表是空表，无法进行删除操作！\n";
											printllist();
											break;
										}
										cout << "\n\n指出你要删除第几个元素（1-" << ll.size() << " ）：";
										cin >> type;
										int save;
										ll.remove(type,save);
										cout << "\n成功删除第"<< type << "个元素：" << save << endl;
										printllist();
										break;
									}
											        
									case 5: {
										cout << "\n\n";
										ll.traver([](const int &e)->void{cout << e << "  ";});
										cout << "\n\n";
									    printllist();
										break;   
									}
											
									case 6: {
										ll.clear();
									    cout << "\n\n表已清空！\n" << endl;
										printllist();
										break;
								    }
											     
									case 7: {
										if(ll.empty()){
											cout << "\n\n表是空表，无法进行查看操作！\n";
											printllist();
											break;
										}
										cout << "\n\n指出你要查看第几个元素（1-" << ll.size() << " ）：";
										cin >> type;
										int save;
										ll.retrieve(type,save);
										cout << "\n第"<< type << "个元素：" << save << endl;
										printllist();
										break;
									}
											        
									case 8: {
										cout << "\n\n" << ll.size() << "\n\n";
									    printllist();
										break;
									}       		
								}
							}
							system("clear");
							printlist();
							break;
					    }
						
						case 2: {                    //静态链表 
					        system("clear");
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
										
										printllist();
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
										
										printllist();
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
										
										printllist();
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
										int save;
										sll.remove(type,save);
										cout << "\n成功删除第"<< type << "个元素：" << save << endl;
										printllist();
										break;
									}
											        
									case 5: {
										cout << "\n\n";
										sll.traver([](const int &e)->void{cout << e << "  ";});
										cout << "\n\n";
									    printllist();
										break;   
									}
											
									case 6: {
										sll.clear();
									    cout << "\n\n表已清空！\n" << endl;
										printllist();
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
										int save;
										sll.retrieve(type,save);
										cout << "\n第"<< type << "个元素：" << save << endl;
										printllist();
										break;
									}
											        
									case 8: {
										cout << "\n\n" << sll.size() << "\n\n";
									    printllist();
										break;
									}       		
								}
							}
							system("clear");
							printlist();
							break;
					    }		  
				    }
				}
				system("clear");
				print();
				break;
			} 						  
	    }
	}
}


