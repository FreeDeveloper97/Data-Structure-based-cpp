////
////  Q4_2_Queue_based_Array.cpp
////  INHA CLASS
////
////  Created by Kang Minsang on 2020/10/27.
////  Copyright © 2020 Kang Minsang. All rights reserved.
////
//
//#include <iostream>
//using namespace std;
//
////Queue를 Array를 통해 구현, enqueue, dequeue, size, empty, front rear 구현
//
//class Queue {
//public:
//    int capacity;
//    int* queue;
//    int f;
//    int r;
//
//    Queue(int capacity) {
//        this->capacity = capacity;
//        this->queue = new int[capacity];
//        this->f = 0;
//        this->r = -1;
//    }
//
//    int empty() {
//        if((r+1)%capacity == f) {
//            return 1;
//        }
//        else
//            return 0;
//    }
//
//    int size() {
//        int temp = (r-f+1 + capacity)%capacity;
//        return temp;
//    }
//
//    void front() {
//        if(empty()) {
//            cout<<"Empty\n";
//        }
//        else {
//            cout<<queue[f]<<"\n";
//        }
//    }
//
//    void rear() {
//        if(empty()) {
//            cout<<"Empty\n";
//        }
//        else {
//            cout<<queue[r]<<"\n";
//        }
//    }
//
//    void enqueue(int data) {
//        if(size()+1 == capacity) {
//            cout<<"Full\n";
//        }
//        else {
//            r = (r+1)%capacity;
//            queue[r] = data;
//        }
//    }
//
//    void dequeue() {
//        if(empty()) {
//            cout<<"Empty\n";
//        }
//        else {
//            cout<<queue[f]<<"\n";
//            queue[f] = 0;
//            f = (f+1)%capacity;
//        }
//    }
//};
//
//int main()
//{
//    int S,N;
//    string question;
//    cin>>S>>N;
//    Queue queue = Queue(S+1);
//    while(N--) {
//        cin>>question;
//        if(question == "isEmpty") {
//            cout<<queue.empty()<<"\n";
//        }
//        else if(question == "size") {
//            cout<<queue.size()<<"\n";
//        }
//        else if(question == "enqueue") {
//            int data;
//            cin>>data;
//            queue.enqueue(data);
//        }
//        else if(question == "dequeue") {
//            queue.dequeue();
//        }
//        else if(question == "front") {
//            queue.front();
//        }
//        else if(question == "rear") {
//            queue.rear();
//        }
//    }
//}
