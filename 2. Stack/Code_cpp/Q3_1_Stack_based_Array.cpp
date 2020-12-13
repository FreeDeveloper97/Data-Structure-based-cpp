////
////  Q3_1_Stack_based_Array.cpp
////  INHA CLASS
////
////  Created by Kang Minsang on 2020/10/26.
////  Copyright © 2020 Kang Minsang. All rights reserved.
////
//
//#include <iostream>
//using namespace std;
////스택을 array로 구현, empty, top, push, pop, size
////class Stack 구현
//
//class Stack { //1. 배열포인터, 2. 사이즈, 3. top위치가 필요하다
//public:
//    int capacity;
//    int* stack;
//    int t;
//
//    //스택 생성자 : 1. 사이즈 설정, 2. 배열 설정, top 설정한다
//    Stack(int capacity) {
//        this->capacity = capacity;
//        this->stack = new int[capacity];
//        this->t = -1;
//    }
//
//    int empty() {
//        if(t == -1)
//            return 1;
//        else
//            return 0;
//    }
//
//    int top() {
//        if(empty()) {
//            return -1;
//        }
//        else {
//            return stack[t];
//        }
//    }
//
//    void push(int data) {
//        if(t == capacity-1) {
//            cout<<"FULL\n";
//        }
//        else {
//            t++;
//            stack[t] = data;
//        }
//    }
//
//    int pop() {
//        if(empty()) {
//            return -1;
//        }
//        else {
//            int temp = stack[t];
//            stack[t] = 0;
//            t--;
//            return temp;
//        }
//    }
//
//    int size() {
//        return t+1;
//    }
//};
//
//int main() {
//    Stack stack = Stack(10000);
//    int N;
//    string question;
//    cin>>N;
//    while(N--) {
//        cin>>question;
//        if(question == "empty") {
//            cout<<stack.empty()<<"\n";
//        }
//        else if(question == "push") {
//            int data;
//            cin>>data;
//            stack.push(data);
//        }
//        else if(question == "size") {
//            cout<<stack.size()<<"\n";
//        }
//        else if(question == "pop") {
//            cout<<stack.pop()<<"\n";
//        }
//        else if(question == "top") {
//            cout<<stack.top()<<"\n";
//        }
//    }
//}
