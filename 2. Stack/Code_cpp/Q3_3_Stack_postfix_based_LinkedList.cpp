////
////  Q3_3_Stack_postfix_based_LinkedList.cpp
////  INHA CLASS
////
////  Created by Kang Minsang on 2020/10/27.
////  Copyright © 2020 Kang Minsang. All rights reserved.
////
//
//#include <iostream>
//using namespace std;
//
////stack을 LinkedList로 구현, 후위표기법 계산 구현
////class Node, LinkedList, stack 필요하다
//
//class Node {
//public:
//    int data;
//    Node* next;
//
//    Node(int data) {
//        this->data = data;
//        this->next = NULL;
//    }
//};
//
//class LinkedList {
//public:
//    Node* head;
//    Node* tail;
//
//    LinkedList() {
//        this->head = NULL;
//        this->tail = NULL;
//    }
//
//    int empty() {
//        if(head == NULL && tail == NULL) {
//            return 1;
//        }
//        else
//            return 0;
//    }
//
//    void append(int data) {
//        Node* V = new Node(data);
//        if(empty()) {
//            head = V;
//            tail = V;
//        }
//        else {
//            tail->next = V;
//            tail = V;
//        }
//    }
//
//    int remove() {
//        if(empty()) {
//            return -1;
//        }
//        else {
//            Node* p = head;
//            Node* u = head;
//
//            while(p->next != NULL) {
//                u = p;
//                p = p->next;
//            }
//
//            int temp = p->data;
//            if(p == head) {
//                head = NULL;
//                tail = NULL;
//            }
//            else {
//                u->next = NULL;
//                tail = u;
//            }
//            delete p;
//            return temp;
//        }
//    }
//
//    int peek() {
//        if(empty()) {
//            return -1;
//        }
//        else {
//            return tail->data;
//        }
//    }
//
//    void print() {
//        cout<<"stack : [";
//        Node* p = head;
//        if(!empty()) {
//            while(p->next != NULL) {
//                cout<<p->data<<" ";
//                p = p->next;
//            }
//            cout<<p->data;
//        }
//        cout<<"]\n";
//    }
//};
//
//class Stack {
//public:
//    int n;
//    LinkedList* stack;
//
//    Stack() {
//        this->n = 0;
//        this->stack = new LinkedList();
//    }
//
//    int empty() {
//        if(stack->empty()) {
//            return 1;
//        }
//        else
//            return 0;
//    }
//
//    void push(int data) {
//        n++;
//        stack->append(data);
//    }
//
//    int pop() {
//        if(empty()) {
//            return -1;
//        }
//        else {
//            n--;
//            return stack->remove();
//        }
//    }
//
//    void print() {
//        stack->print();
//    }
//
//};
//
//int postFix(string input) {
//    int result = 0;
//    Stack stack_v = Stack();
//    for(int i=0; i<input.size(); i++) {
//        char temp = input.at(i);
//        if(temp >= '0' && temp <= '9') {
//            int inputValue = int(temp-'0');
//            stack_v.push(inputValue);
//        }
//        else {
//            int y = stack_v.pop();
//            int x = stack_v.pop();
//            if(temp == '+') {
//                stack_v.push(x+y);
//            }
//            else if(temp == '-') {
//                stack_v.push(x-y);
//            }
//            else if(temp == '*') {
//                stack_v.push(x*y);
//            }
//        }
//    }
//    result = stack_v.pop();
//    return result;
//}
//
//int main()
//{
//    int N;
//    string input;
//    cin>>N;
//    while(N--) {
//        cin>>input;
//        cout<<postFix(input)<<"\n";
//    }
//}
