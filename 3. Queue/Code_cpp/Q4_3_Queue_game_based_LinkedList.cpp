//
//  Q4_3_Queue2_based_LinkedList.cpp
//  INHA CLASS
//
//  Created by Kang Minsang on 2020/10/27.
//  Copyright © 2020 Kang Minsang. All rights reserved.
//

#include <iostream>
using namespace std;

//Queue를 LinkedList를 통해 구현, 게임을 구현
//win -> hp-1만큼 다음회에 추가
//class Node, class LinkedList, class Stack

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
        else
            return 0;
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
    int capacity;
    LinkedList* queue;

    Queue(int capacity) {
        this->capacity = capacity;
        this->n = 0;
        this->queue = new LinkedList();
    }

    void enqueue(int data) {
        this->n++;
        queue->append(data);
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
};

int main() {
    int T,N;
    int card;
    cin>>T;
    while(T--) {
        Queue Q1 = Queue(21);
        Queue Q2 = Queue(21);
        cin>>N;
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
        //카드입력 완료, 게임시작
        int plus_q1 = 0;
        int plus_q2 = 0;
        int score_q1 = 0;
        int score_q2 = 0;
        while(N--) {
            int c1 = Q1.dequeue();
            int c2 = Q2.dequeue();
            c1 += plus_q1;
            c2 += plus_q2;
            int result = c1 - c2;
            //1이 이긴경우
            if(result > 0) {
                score_q1++;
                plus_q1 = result-1;
                plus_q2 = 0;
            }
            //2가 이긴경우
            else if(result < 0) {
                score_q2++;
                plus_q2 = -(result)-1;
                plus_q1 = 0;
            }
            //비긴경우
            else if(result == 0) {
                plus_q1 = 0;
                plus_q2 = 0;
            }
        }
        //게임 종료
        if(score_q1 > score_q2) {
            cout<<1<<"\n";
        }
        else if(score_q2 > score_q1) {
            cout<<2<<"\n";
        }
        else if(score_q1 == score_q2) {
            cout<<0<<"\n";
        }
        plus_q1 = 0;
        plus_q2 = 0;
        score_q1 = 0;
        score_q2 = 0;
    }
}
