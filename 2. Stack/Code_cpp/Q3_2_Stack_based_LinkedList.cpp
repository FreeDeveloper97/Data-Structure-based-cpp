////
////  Q3_2_Stack_based_LinkedList.cpp
////  INHA CLASS
////
////  Created by Kang Minsang on 2020/10/27.
////  Copyright © 2020 Kang Minsang. All rights reserved.
////
//
//#include <iostream>
//using namespace std;
////Stack을 LinkedList로 구현, empty, top, push, pop, size
////class Node, LinkedList, Stack 필요하다
//
//class Node { // Node : 1. data, 2. next 포인터가 필요하다
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
//    //List : 1. head, 2. tail 포인터가 필요하다
//    //empty, append, delete, peek이 필요하다
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
//            int temp = 0;
//            Node* p;
//            Node* u;
//
//            u = head;
//            p = head;
//            //p가 tail일때 정지 : p->next가 NULL이 아닐동안 반복
//            while(p->next != NULL) {
//                u = p;
//                p = p->next;
//            }
//
//            temp = p->data;
//            u->next = NULL;
//            tail = u;
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
//};
//
////1. 스택의 크기 n, 2. 리스트포인터가 필요하다
////empty, top, push, pop, size 필요하다
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
//    int top() {
//        if(empty()) {
//            return -1;
//        }
//        else {
//            return stack->tail->data;
//        }
//    }
//
//    void push(int data) {
//        stack->append(data);
//        n++;
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
//    int size() {
//        return n;
//    }
//
//};
//
//int main()
//{
//    Stack stack = Stack();
//    int N;
//    string question;
//    cin>>N;
//    while(N--) {
//        cin>>question;
//        if(question == "empty") {
//            cout<<stack.empty()<<"\n";
//        }
//        else if(question == "top") {
//            cout<<stack.top()<<"\n";
//        }
//        else if(question == "pop") {
//            cout<<stack.pop()<<"\n";
//        }
//        else if(question == "push") {
//            int data;
//            cin>>data;
//            stack.push(data);
//        }
//        else if(question == "size") {
//            cout<<stack.size()<<"\n";
//        }
//    }
//}
