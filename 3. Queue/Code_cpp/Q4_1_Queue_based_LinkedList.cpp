//
//  Q4_1_Queue_based_LinkedList.cpp
//  INHA CLASS
//
//  Created by Kang Minsang on 2020/10/27.
//  Copyright © 2020 Kang Minsang. All rights reserved.
//

#include <iostream>
using namespace std;

//Queue를 LinkedList로 구현, enqueue, dequeue, size, empty, front, rear 추가
//class Node, class LinkedList, class Queue를 생성한다

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() {
        this->head = NULL;
        this->tail = NULL;
    }

    int empty() {
        if(head == NULL && tail == NULL) {
            return 1;
        }
        else {
            return 0;
        }
    }

    void append(int data) {
        Node* V = new Node(data);
        if(head == NULL) {
            head = V;
            tail = V;
        }
        else {
            tail->next = V;
            tail = V;
        }
    }

    int remove_front() {
        if(head == NULL) {
            return -1;
        }
        else {
            Node* temp = head;
            int tmp = head->data;
            head = head->next;
            delete temp;
            return tmp;
        }
    }

    int peek_front() {
        return head->data;
    }

    int peek_rear() {
        return tail->data;
    }
};

class Queue {
public:
    int n;
    int capacity;
    LinkedList* queue;

    Queue(int capacity) {
        this->capacity = capacity;
        this->n = 0;
        this->queue = new LinkedList();
    }

    int size() {
        return n;
    }

    int empty() {
        if(n == 0) {
            return 1;
        }
        else
            return 0;
    }

    void front() {
        if(empty()) {
            cout<<"Empty\n";
        }
        else {
            cout<<queue->peek_front()<<"\n";
        }
    }

    void rear() {
        if(empty()) {
            cout<<"Empty\n";
        }
        else {
            cout<<queue->peek_rear()<<"\n";
        }
    }

    void enqueue(int data) {
        if(n+1 == capacity) {
            cout<<"Full\n";
        }
        else {
            n++;
            queue->append(data);
        }
    }

    void dequeue() {
        if(empty()) {
            cout<<"Empty\n";
        }
        else {
            cout<<queue->remove_front()<<"\n";
            n--;
        }
    }
};

int main()
{
    int S,N;
    string question;
    cin>>S>>N;
    Queue queue = Queue(S+1);
    while(N--) {
        cin>>question;
        if(question == "isEmpty") {
            cout<<queue.empty()<<"\n";
        }
        else if(question == "size") {
            cout<<queue.size()<<"\n";
        }
        else if(question == "front") {
            queue.front();
        }
        else if(question == "rear") {
            queue.rear();
        }
        else if(question == "enqueue") {
            int data;
            cin>>data;
            queue.enqueue(data);
        }
        else if(question == "dequeue") {
            queue.dequeue();
        }
    }
}
