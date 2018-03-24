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
	     << "|	1.����" << endl
	     << "|	2.ջ"   << endl
	     << "|	3.���Ա�" << endl
	     << "|	4.��" << endl
		 << "|	5.�˳�"<< endl
		 << "--------------------------" << endl
		 << "\n��������Ӧ������ţ�";
}

//stack classification
void printstack(){
	cout << "------------------------------" << endl
	     << "|	1.˳��ʵ�ֵ�ջ" << endl
	     << "|	2.��ʽջ"       << endl
		 << "|	3.����"         << endl
		 << "------------------------------" << endl
		 << "\n��������Ӧ������ţ�";
}

//function catalogs of sequence statck
void printsstack(){
	cout << "------------------------------" << endl
	     << "|	1.����ջ������" << endl
	     << "|	2.��ջ" << endl
		 << "|	3.��ջ"         << endl
		 << "|	4.��ʾջ��ĿǰԪ��" << endl
		 << "|	5.���ջ"     << endl
		 << "|	6.ջ��"       << endl
		 << "|	7.ջ�ĵ�ǰ��С" << endl 
		 << "|	8.ջ������"   << endl 
		 << "|	9.����"         << endl
		 << "------------------------------" << endl
		 << "\n��������Ӧ������ţ�";
}

//function catalogs of link stack
void printlstack(){
	cout << "----------------------------" << endl
	     << "|	1.��ջ" << endl
		 << "|	2.��ջ"         << endl
		 << "|	3.��ʾջ��ĿǰԪ��" << endl
		 << "|	4.���ջ"     << endl
		 << "|	5.ջ��"       << endl
		 << "|	6.ջ�ĵ�ǰ��С" << endl 
		 << "|	7.����"         << endl
		 << "----------------------------" << endl
		 << "\n��������Ӧ������ţ�";
}

//queue claasification
void printqueue(){
	cout << "-------------------------" << endl
	     << "|	1.ѭ������" << endl
		 << "|	2.��ʽ����" << endl
		 << "|	3.ͷ������˳�����" << endl
		 << "|	4.����" << endl
		 << "-------------------------" << endl
		 << "\n��������Ӧ������ţ�" << endl;
}

//function catalogs of circle queue 
void printcq(){
	cout << "--------------------------" << endl
	     << "|	1.���ö�������" << endl
	     << "|	2.���Ԫ�ؽ���" << endl
		 << "|	3.����"         << endl
		 << "|	4.��ʾ������ĿǰԪ��" << endl
		 << "|	5.��ն���"     << endl
		 << "|	6.����"         << endl
		 << "|	7.��β"         << endl
		 << "|	8.���е�ǰ��С" << endl 
		 << "|	9.���е�����"   << endl 
		 << "|	10.����"         << endl
		 << "--------------------------" << endl
		 << "\n��������Ӧ������ţ�" << endl;
}

//function catalogs of link queue
void printlq(){
	cout << "-------------------------------" << endl
	     << "|	1.���Ԫ�ؽ���" << endl
		 << "|	2.����"         << endl
		 << "|	3.��ʾ������ĿǰԪ��" << endl
		 << "|	4.��ն���"     << endl
		 << "|	5.����"         << endl
		 << "|	6.��β"         << endl
		 << "|	7.���е�ǰ��С" << endl 
		 << "|	8.����"         << endl
		 << "-------------------------------" << endl
		 << "\n��������Ӧ������ţ�" << endl;
}

//function catalogs of sequence queue
void printsq(){
	cout << "----------------------------------" << endl
	     << "|	1.���ö�������" << endl
	     << "|	2.���Ԫ�ؽ���" << endl
		 << "|	3.����"         << endl
		 << "|	4.��ʾ������ĿǰԪ��" << endl
		 << "|	5.��ն���"     << endl
		 << "|	6.����"         << endl
		 << "|	7.��β"         << endl
		 << "|	8.���е�ǰ��С" << endl 
		 << "|	9.���е�����"   << endl 
		 << "|	10.����"         << endl
		 << "-----------------------------------" << endl
		 << "\n��������Ӧ������ţ�" << endl;
}

//list classification
void printlist(){
	cout << "---------------------------" << endl 
	     << "|	1.������" << endl 
	     << "|	2.��̬����" << endl
		 << "|	3.˳�����Ա�" << endl 
	     << "|	4.����"   << endl
		 << "---------------------------" << endl
		 << "\n��������Ӧ������ţ�";
}

//function catalogs of link list
void printllist(){
	cout << "-------------------------------------------" << endl
	     << "|	1.���Ԫ�ؽ���,�Զ�����β��"<< endl
	     << "|	2.���Ԫ�ؽ������Զ�����������"<< endl
		 << "|	3.���Ԫ�ؽ������Զ�����������"<< endl 
		 << "|	4.��ָ��λ�����Ԫ��"<< endl
		 << "|	5.ɾ��ָ��λ��Ԫ��"<< endl
		 << "|	6.��ʾ����ĿǰԪ��"<< endl
		 << "|	7.��ձ�"<< endl
		 << "|	8.�鿴����ָ��λ��Ԫ��"<< endl
		 << "|	9.��ǰ��С"<< endl 
		 << "|	10.����"<< endl
		 << "-------------------------------------------" << endl
		 << "\n��������Ӧ������ţ�";
}

//function catalogs of static link list, implemetion by array
void printsllist(){
	cout << "1.���Ԫ�ؽ���" << endl
	     << "2.���������Ԫ�ؽ���" << endl
		 << "3.���������Ԫ�ؽ���" << endl 
		 << "4.ɾ��ָ��λ��Ԫ��"         << endl
		 << "5.��ʾ����ĿǰԪ��" << endl
		 << "6.��ձ�"     << endl
		 << "7.�鿴����ָ��λ��Ԫ��" << endl
		 << "8.��ǰ��С" << endl 
		 << "9.����"         << endl
		 << "\n��������Ӧ������ţ�";
}

//function catalogs of sequence list
void printslist(){
	cout << "-------------------------------------------" << endl
	     << "|	1.���Ԫ�ؽ���,�Զ�����β��"<< endl
	     << "|	2.���Ԫ�ؽ������Զ�����������"<< endl
		 << "|	3.���Ԫ�ؽ������Զ�����������"<< endl 
		 << "|	4.��ָ��λ�����Ԫ��"<< endl
		 << "|	5.ɾ��ָ��λ��Ԫ��"<< endl
		 << "|	6.��ʾ����ĿǰԪ��"<< endl
		 << "|	7.��ձ�"<< endl
		 << "|	8.�鿴����ָ��λ��Ԫ��"<< endl
		 << "|	9.��ǰ��С"<< endl 
		 << "|	10.����"<< endl
		 << "-------------------------------------------" << endl
		 << "\n��������Ӧ������ţ�";
}

//tree classification
void printtree(){
	cout << "--------------------" << endl
	     << "|	1.������" << endl
		 << "|	2.�˳�"   << endl
		 << "--------------------" << endl
		 << "\n��������Ӧ������ţ�";
}

//function catalogs of binary tree
void printbitree(){
	cout << "-------------------" << endl
	     << "|	1.������" << endl
		 << "|	2.�����ܽڵ���" << endl
		 << "|	3.����" << endl
		 << "|	4.����" << endl
		 << "|	5.����" << endl
		 << "|	6.����"   << endl
		 << "-------------------" << endl
		 << "\n��������Ӧ������ţ�";
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
		    case 1:{                                      //���� 
				clearscreen();
		        printqueue();
				while((cin >> type) && type != 4){
					switch(type){
					    case 1: {                       //ѭ������
					        clearscreen();
					        printcq();
		                    cqueue cq;
		                    while((cin >> type) && type != 10){
							    switch(type){
								    case 1: {
								        cout << "\n\nĿǰ��СΪ��" << cq.size() << endl
										     << "����Ϊ��" << cq.capacity() << endl 
											 << "��������Ҫ���õ�������";
								        cin >> type;
								        cq.setcapacity(type+1);
								        cout << "\n���óɹ�����������Ϊ��" << cq.capacity() << "\n\n";
								        printcq();
								        break;
									}
											
								    case 2: {
								    	int remainder = cq.capacity()-cq.size();
								    	
								    	if(remainder == 0) cout << "\n\n����������������ӣ�\n\n";
								    	else{
								    		cout << "\n\nĿǰ����������" << remainder
											     << "��Ԫ�أ�������������Ҫ��ӵ�Ԫ�أ����ÿո����: \n"; 
								            while(cin >> type){
								                cq.push(type);
								                if(cin.get() == '\n') break;
										    }
										    cout << "\n�����ɣ�\n" << endl;
										}
										
										printcq();
										break;
									}
													
									case 3: {
									    return_code rc = cq.pop(type);
									    if(rc == underflow) cout << "\n\n�����ѿգ�\n\n";
									    else cout << "\n\n����Ԫ��Ϊ��" << type << "\n\n";
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
									    cout << "\n\n��������գ�\n" << endl;
										printcq();
										break;
								    }
											     
									case 6: {
										if(cq.empty()) cout << "\n\n�����ǿյģ�\n";
										else{
											cq.front(type);
									        cout << "\n\n" << type << "\n\n";
										}
										printcq();
										break;
									}
											        
									case 7: {
										if(cq.empty()) cout << "\n\n�����ǿյģ�\n";
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
					    
					    case 2: {                        //��ʽ����
					        clearscreen();
					        printlq();
		                    linkqueue<int> lq;
		                    while((cin >> type) && type != 8){
							    switch(type){			
								    case 1: {
								    	cout << "\n\n������������Ҫ��ӵ�Ԫ�أ����ÿո����,�س�����: \n"; 
								        while(cin >> type){
								            lq.push(type);
								            if(cin.get() == '\n') break;
										}
										cout << "\n�����ɣ�\n" << endl;
								
										printlq();
										break;
									}
													
									case 2: {
									    return_code rc = lq.pop(type);
									    if(rc == underflow) cout << "\n\n�����ѿգ�\n\n";
									    else cout << "\n\n����Ԫ��Ϊ��" << type << "\n\n";
										printlq();
										break;
									}
											        
									case 3: {
										if(lq.empty()){
											cout << "\n\n�����ǿյģ�\n\n";
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
									    cout << "\n\n��������գ�\n" << endl;
										printlq();
										break;
								    }
											     
									case 5: {
										if(lq.empty()) cout << "\n\n�����ǿյģ�\n\n";
										else{
											lq.front(type);
									        cout << "\n\n" << "����Ԫ��Ϊ��" << type << "\n\n";
										}
										printlq();
										break;
									}
											        
									case 6: {
										if(lq.empty()) cout << "\n\n�����ǿյģ�\n\n";
										else{
											lq.back(type);
									        cout << "\n\n" << "��βԪ��Ϊ��" << type << "\n\n";
										}
										printlq();
										break;
									}
											        
									case 7: {
										cout << "\n\n" << "���д�СΪ��" << lq.size() << "\n\n";
									    printlq();
										break;
									}

									default: {
										cout << "\n\n��������ȷ����ţ�\n\n";
										printlq();
										break;
									}      		
								}
							}
							clearscreen();
							printqueue();
							break;
					    }
						
						case 3: {                        //˳�����
					        clearscreen();
					        printsq();
		                    squeue sq;
		                    while((cin >> type) && type != 10){
							    switch(type){
								    case 1: {
								        cout << "\n\nĿǰ��СΪ��" << sq.size() << endl
								             << "����Ϊ��" << sq.capacity() << endl
										     << "��������Ҫ���õ�������";
								        cin >> type;
								        sq.setcapacity(type);
								        cout << "\n���óɹ�����������Ϊ��" << sq.capacity() << "\n\n";
								        printsq();
								        break;
									}
											
								    case 2: {
								    	cout << "������������Ҫ��ӵ�Ԫ�أ����ÿո����: \n"; 
								        while(cin >> type){
								            sq.push(type);
								            if(cin.get() == '\n') break;
										}
										cout << "\n�����ɣ�\n" << endl;
										
										printsq();
										break;
									}
													
									case 3: {
									    return_code rc = sq.pop(type);
									    if(rc == underflow) cout << "\n\n�����ѿգ�\n\n";
									    else cout << "\n\n����Ԫ��Ϊ��" << type << "\n\n";
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
									    cout << "\n\n��������գ�\n" << endl;
										printsq();
										break;
								    }
											     
									case 6: {
										if(sq.empty()) cout << "\n\n�����ǿյģ�\n";
										else{
											sq.front(type);
									        cout << "\n\n" << type << "\n\n";
										}
										printsq();
										break;
									}
											        
									case 7: {
										if(sq.empty()) cout << "\n\n�����ǿյģ�\n";
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
			        
	        case 2:{                                     //ջ 
		    	clearscreen();
		        printstack();
				while((cin >> type) && type != 3){
					switch(type){
					    case 1: {                        //˳��ջ
					        clearscreen();
					        printsstack();
		                    sstack<int> ss;
		                    while((cin >> type) && type != 9){
							    switch(type){
								    case 1: {
								        cout << "\nĿǰ��СΪ��" << ss.size() << endl
								             << "����Ϊ��" << ss.getcapacity() << endl
										     << "��������Ҫ���õ�������";
								        cin >> type;
										if(type < ss.size()){
											cout << "\nerror! ���õ�����С�ڵ�ǰջ��Ԫ��������\n" << endl;
											printsstack();
											break;
										}
								        ss.setcapacity(type);
								        cout << "\n���óɹ�����������Ϊ��" << ss.getcapacity() << "\n\n";
								        printsstack();
								        break;
									}
											
								    case 2: {
								    	cout << "\n\n������������Ҫѹ���Ԫ�أ��ÿո�ֿ�,�س�������\n"; 
								        while(cin >> type){
								            ss.push(type);
								            if(cin.get() == '\n') break;
										}
										cout << "\n�����ɣ�\n" << endl;
										
										printsstack();
										break;
									}
													
									case 3: {
									    return_code rc = ss.pop(type);
									    if(rc == underflow) cout << "\n\nջ�ѿգ�\n\n";
									    else cout << "\n\n��ջԪ��Ϊ��" << type << "\n\n";
										printsstack();
										break;
									}
											        
									case 4: {
										if(ss.empty()){
											cout << "\n\nջ�ǿյģ�\n\n";
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
									    cout << "\n\nջ����գ�\n" << endl;
										printsstack();
										break;
								    }
											     
									case 6: {
										if(ss.empty()) cout << "\n\nջ�ǿյģ�\n" << endl;
										else{
											ss.top(type);
									        cout << "\n\n" << "ջ��Ԫ��Ϊ��" << type << "\n\n";
										}
										printsstack();
										break;
									}
											        
									case 7: {
										cout << "\n\n" << "ջ�Ĵ�СΪ�� " << ss.size() << "\n\n";
									    printsstack();
										break;
									}
									
									case 8: {
										cout << "\n\n" << "ջ������Ϊ��" << ss.getcapacity() << "\n\n";
										printsstack();
										break;
									}

									default: {
										cout << "\n\n��������ȷ����ţ�\n\n";
										printsstack();
										break;
									}        		
								}
							}
							clearscreen();
							printstack();
							break;
					    }
					    
					    case 2: {                        //��ʽջ
					    	clearscreen();
					        printlstack();
		                    linkstack<int> ls;
		                    while((cin >> type) && type != 7){
							    switch(type){
								    case 1: {
								    	cout << "\n\n������������Ҫѹ���Ԫ�أ��ÿո�ֿ�,�س�������\n"; 
								        while(cin >> type){
								            ls.push(type);
								            if(cin.get() == '\n') break;
										}
										cout << "\n�����ɣ�\n" << endl;
										
										printlstack();
										break;
									}
													
									case 2: {
									    return_code rc = ls.pop(type);
									    if(rc == underflow) cout << "\n\nջ�ѿգ�\n\n";
									    else cout << "\n\n��ջԪ��Ϊ��" << type << "\n\n";
										printlstack();
										break;
									}
											        
									case 3: {
										if(ls.empty()){
											cout << "\n\nջ�ǿյģ�\n\n";
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
									    cout << "\n\nջ����գ�\n" << endl;
										printlstack();
										break;
								    }
											     
									case 5: {
										if(ls.empty()) cout << "\n\nջ�ǿյģ�\n\n";
										else{
											ls.top(type);
									        cout << "\n\n" << "ջ��Ԫ��Ϊ��" << type << "\n\n";
										}
										printlstack();
										break;
									}
											        
									case 6: {
										cout << "\n\n" << "ջ�Ĵ�С��" << ls.size() << "\n\n";
									    printlstack();
										break;
									}

									default: {
										cout << "\n\n��������ȷ����ţ�\n\n";
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
			
			case 3:{                                     //���Ա� 
		    	clearscreen();
		        printlist();
				while((cin >> type) && type != 4){
					switch(type){
					    case 1: {                    //������ 
					        clearscreen();
					        printllist();
		                    linklist<int> ll;
		                    while((cin >> type) && type != 10){
							    switch(type){
								    case 1: {
								    	cout << "\n������������Ҫ��ӵ�Ԫ�أ��ÿո�ֿ�,�س�������\n";

								        while(cin >> type){
								            if(ll.insert(ll.size(), type) == Range_error){
												cout << "range_error!" << endl;
											}
								            if(cin.get() == '\n') break;
										}

										cout << "\n������!\n"    << endl;
										
										printllist();
										break;
									}
													
									case 2: {
										ll.ascendingsort();
									    cout << "\n������������Ҫ��ӵ�Ԫ�أ��ÿո�ֿ�,�س�������\n";

								        while(cin >> type){
								            if(ll.insert(type, [](const int &a, const int &b)->bool{
								            	return a<b;
											}) == Range_error){
												cout << "range_error!" << endl;
											}
								            if(cin.get() == '\n') break;
										}

										cout << "\n������!\n"    << endl;
										
										printllist();
										break;
									}
									
									case 3: {
										ll.descendingsort();
									    cout << "\n������������Ҫ��ӵ�Ԫ�أ��ÿո�ֿ�, �س�������\n";

								        while(cin >> type){
								            if(ll.insert(type, [](const int &a, const int &b)->bool{
								            	return a>b;
											}) == Range_error){
												cout << "range_error!" << endl;
											}
								            if(cin.get() == '\n') break;
										}
										
										cout << "\n������!\n"    << endl;
										
										printllist();
										break;
									}
									
									case 4: {
										int pos = -1;
										cout << "\n�������������Ԫ�ص�λ��(0-" << ll.size() << "): ";
										cin >> pos;
										cout << "\n��������Ҫ�����Ԫ��ֵ�� ";
										cin >> type;

										if(ll.insert(pos, type) == Range_error){
											cout << "\n����λ�ò��Ϸ�!\n" << endl;
										}
										else{
											cout << "\n����ɹ���\n" << endl;
										}

										printllist();
										break;
									}

									case 5: {
										if(ll.empty()){
											cout << "\n���ǿձ��޷�����ɾ��������\n\n";
											printllist();
											break;
										}
										cout << "\nָ����Ҫɾ���ڼ���Ԫ�أ�0-" << ll.size()-1 << " ����";
										cin >> type;
										int save = 0;
										ll.remove(type,save);
										cout << "\n�ɹ�ɾ����"<< type << "��Ԫ�أ�" << save << endl;
										cout << endl;
										printllist();
										break;
									}
											        
									case 6: {
										if(ll.empty()){
											cout << "\n��Ϊ�գ�\n" << endl;
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
									    cout << "\n������գ�\n" << endl;
										printllist();
										break;
								    }
											     
									case 8: {
										if(ll.empty()){
											cout << "\n���ǿձ��޷����в鿴������\n\n";
											printllist();
											break;
										}
										cout << "\nָ����Ҫ�鿴�ڼ���Ԫ�أ�0-" << ll.size()-1 << " ����";
										cin >> type;
										int save = 0;
										ll.retrieve(type,save);
										cout << "\n��"<< type << "��Ԫ�أ�" << save << endl;
										cout << endl;
										printllist();
										break;
									}
											        
									case 9: {
										cout << "\n��ĳ��ȣ� " << ll.size() << "\n\n";
									    printllist();
										break;
									}

									default: {
										cout << "\n��������ȷ�����! \n\n";
										printllist();
										break;
									}       		
								}
							}
							clearscreen();
							printlist();
							break;
					    }
						
						case 2: {                    //��̬���� 
					        clearscreen();
					        printsllist();
		                    sllist<int> sll;
		                    while((cin >> type) && type != 9){
							    switch(type){
								    case 1: {
								    	cout << "\n\n������������Ҫ��ӵ�Ԫ�أ��ÿո�ֿ���\n"; 
								        while(cin >> type){
								            sll.insert(type, sll.size()+1);
								            if(cin.get() == '\n') break;
										}
										cout << "\n�����ɣ�\n" << endl;
										
										printsllist();
										break;
									}
													
									case 2: {
									    cout << "\n\n������������Ҫ��ӵ�Ԫ�أ��ÿո�ֿ���\n"; 
								        while(cin >> type){
								            sll.insert(type, [](const int &a, const int &b)->bool{
								            	return a>b;
											});
								            if(cin.get() == '\n') break;
										}
										cout << "\n�����ɣ�\n" << endl;
										
										printsllist();
										break;
									}
									
									case 3: {
									    cout << "\n\n������������Ҫ��ӵ�Ԫ�أ��ÿո�ֿ���\n"; 
								        while(cin >> type){
								            sll.insert(type, [](const int &a, const int &b)->bool{
								            	return a<b;
											});
								            if(cin.get() == '\n') break;
										}
										cout << "\n�����ɣ�\n" << endl;
										
										printsllist();
										break;
									}
									
									case 4: {
										if(sll.empty()){
											cout << "\n\n���ǿձ��޷�����ɾ��������\n";
											printllist();
											break;
										}
										cout << "\n\nָ����Ҫɾ���ڼ���Ԫ�أ�1-" << sll.size() << " ����";
										cin >> type;
										int save = 0;
										sll.remove(type,save);
										cout << "\n�ɹ�ɾ����"<< type << "��Ԫ�أ�" << save << endl;
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
									    cout << "\n\n������գ�\n" << endl;
										printsllist();
										break;
								    }
											     
									case 7: {
										if(sll.empty()){
											cout << "\n\n���ǿձ��޷����в鿴������\n";
											printllist();
											break;
										}
										cout << "\n\nָ����Ҫ�鿴�ڼ���Ԫ�أ�1-" << sll.size() << " ����";
										cin >> type;
										int save = 0;
										sll.retrieve(type,save);
										cout << "\n��"<< type << "��Ԫ�أ�" << save << endl;
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

						case 3: {                    //˳�����Ա�
							clearscreen();
					        printslist();
		                    slist<int> sl;
		                    while((cin >> type) && type != 10){
							    switch(type){
								    case 1: {
								    	cout << "\n������������Ҫ��ӵ�Ԫ�أ��ÿո�ֿ�,�س�������\n";

								        while(cin >> type){
								            if(sl.insert(sl.getlen(), type) == Range_error){
												cout << "range_error!" << endl;
											}
								            if(cin.get() == '\n') break;
										}

										cout << "\n������!\n"    << endl;
										
										printslist();
										break;
									}
													
									case 2: {
										sl.ascendingsort();
									    cout << "\n������������Ҫ��ӵ�Ԫ�أ��ÿո�ֿ�,�س�������\n";

								        while(cin >> type){
								            if(sl.insert(type, [](const int &a, const int &b)->bool{
								            	return a<b;
											}) == Range_error){
												cout << "range_error!" << endl;
											}
								            if(cin.get() == '\n') break;
										}

										cout << "\n������!\n"    << endl;
										
										printslist();
										break;
									}
									
									case 3: {
										sl.descendingsort();
									    cout << "\n������������Ҫ��ӵ�Ԫ�أ��ÿո�ֿ�, �س�������\n";

								        while(cin >> type){
								            if(sl.insert(type, [](const int &a, const int &b)->bool{
								            	return a>b;
											}) == Range_error){
												cout << "range_error!" << endl;
											}
								            if(cin.get() == '\n') break;
										}
										
										cout << "\n������!\n"    << endl;
										
										printslist();
										break;
									}
									
									case 4: {
										int pos = -1;
										cout << "\n�������������Ԫ�ص�λ��(0-" << sl.getlen() << "): ";
										cin >> pos;
										cout << "\n��������Ҫ�����Ԫ��ֵ�� ";
										cin >> type;

										if(sl.insert(pos, type) == Range_error){
											cout << "\n����λ�ò��Ϸ�!\n" << endl;
										}
										else{
											cout << "\n����ɹ���\n" << endl;
										}

										printslist();
										break;
									}

									case 5: {
										if(sl.empty()){
											cout << "\n���ǿձ��޷�����ɾ��������\n\n";
											printslist();
											break;
										}
										cout << "\nָ����Ҫɾ���ڼ���Ԫ�أ�0-" << sl.getlen()-1 << " ����";
										cin >> type;
										int save = 0;
										sl.deletelemt(type,save);
										cout << "\n�ɹ�ɾ����"<< type << "��Ԫ�أ�" << save << endl;
										cout << endl;
										printslist();
										break;
									}
											        
									case 6: {
										if(sl.empty()){
											cout << "\n��Ϊ�գ�\n" << endl;
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
									    cout << "\n������գ�\n" << endl;
										printslist();
										break;
								    }
											     
									case 8: {
										if(sl.empty()){
											cout << "\n���ǿձ��޷����в鿴������\n\n";
											printslist();
											break;
										}
										cout << "\nָ����Ҫ�鿴�ڼ���Ԫ�أ�0-" << sl.getlen()-1 << " ����";
										cin >> type;
										int save = 0;
										sl.retrieve(type,save);
										cout << "\n��"<< type << "��Ԫ�أ�" << save << endl;
										cout << endl;
										printslist();
										break;
									}
											        
									case 9: {
										cout << "\n��ĳ��ȣ� " << sl.getlen() << "\n\n";
									    printslist();
										break;
									}

									default: {
										cout << "\n��������ȷ�����! \n\n";
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

			case 4:{                                     //��
				clearscreen();
				printtree();
				while((cin >> type) && type != 2){
					switch(type){
						case 1: {                //������
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
										cout << "\n\n�����ܽڵ���Ϊ��" << bt.size() << "\n\n";
										printbitree();
										break;
									}

									case 3: {
										if(bt.empty()){
											cout << "\n\n���ǿ���\n\n";
											printbitree();
											break;
										}
										cout << "\n\n�����������Ϊ��\n";
										bt.preorder_traverse([](const int &t)->void{
											cout << t << "  ";
										});
										cout << "\n\n";
										printbitree();
										break;
									}

									case 4: {
										if(bt.empty()){
											cout << "\n\n���ǿ���\n\n";
											printbitree();
											break;
										}
										cout << "\n\n�����������Ϊ��\n";
										bt.inorder_traverse([](const int &t)->void{
											cout << t << "  ";
										});
										cout << "\n\n";
										printbitree();
										break;
									}

									case 5: {
										if(bt.empty()){
											cout << "\n\n���ǿ���\n\n";
											printbitree();
											break;
										}
										cout << "\n\n���ĺ������Ϊ��\n";
										bt.postorder_traverse([](const int &t)->void{
											cout << t << "  ";
										});
										cout << "\n\n";
										printbitree();
										break;
									}

									default: {
										cout << "\n\n��������ȷ��ţ�\n\n";
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
							cout << "\n\n��������ȷ��ţ�\n\n";
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
				cout << "\n\n��������ȷ����ţ�\n\n";
				break;
			} 						  
	    }
	}
}


