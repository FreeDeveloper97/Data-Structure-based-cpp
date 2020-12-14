//
//  Q4_4_Queue_game2_based_LinkedList.cpp
//  INHA CLASS
//
//  Created by Kang Minsang on 2020/10/27.
//  Copyright © 2020 Kang Minsang. All rights reserved.
//

#include <iostream>
using namespace std;

//Queue를 LinkedList를 통해 구현, 게임을 만들기
//이긴경우 카드값차-1을 다음판 상대카드에 합산

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
        if(empty()) {
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
};

class Queue {
public:
    int n;
    LinkedList* queue;
    int capacity;

    Queue(int capacity) {
        this->capacity = capacity;
        this->n = 0;
        this->queue = new LinkedList();
    }

    int dequeue() {
        if(n == 0) {
            return -1;
        }
        else {
            int temp = queue->remove_front();
            n--;
            return temp;
        }
    }

    void enqueue(int data){
        n++;
        queue->append(data);
    }
};

int main()
{
    int T,N;
    cin>>T;
    while(T--){
        Queue Q1 = Queue(21);
        Queue Q2 = Queue(21);
        cin>>N;
        int card;
        int temp = N;
        while(temp--) {
            cin>>card;
            Q1.enqueue(card);
        }
        temp = N;
        while(temp--) {
            cin>>card;
            Q2.enqueue(card);
        }
        int score_q1 = 0;
        int score_q2 = 0;
        int plus_q1 = 0;
        int plus_q2 = 0;
        //입력 종료
        while(N--) {
            int c1 = Q1.dequeue();
            int c2 = Q2.dequeue();
            c1 += plus_q1;
            c2 += plus_q2;
            int result = c1-c2;

            if(result > 0) {
                score_q1++;
                plus_q2 = result-1;
                plus_q1 = 0;
            }
            else if(result < 0) {
                score_q2++;
                plus_q1 = -(result)-1;
                plus_q2 = 0;

            }
            else if(result == 0) {
                plus_q1 = 0;
                plus_q2 = 0;
            }
        }
        if(score_q1 > score_q2) {
            cout<<1<<"\n";
        }
        else if(score_q2 > score_q1) {
            cout<<2<<"\n";
        }
        else if(score_q1 == score_q2) {
            cout<<0<<"\n";
        }
        score_q1 = 0;
        score_q2 = 0;
        plus_q1 = 0;
        plus_q2 = 0;
    }
}
