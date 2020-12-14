
  Q2_2_SinglyList.cpp
  INHA CLASS

  Created by Kang Minsang on 2020/10/26.
  Copyright © 2020 Kang Minsang. All rights reserved.


#include <iostream>
using namespace std;
//singly list로 구현, addfront, removefront, front, empty

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class SinglyLinkedList {
public:
    Node* head;
    Node* tail;

    SinglyLinkedList() {
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

    void addFront(int data) {
        Node* V = new Node(data);
        if(empty()) {
            head = V;
            V->next = tail;
        }
        else {
            V->next = head;
            head = V;
        }
    }

    int removeFront() {
        if(empty()) {
            return -1;
        }
        else {
            Node* temp = head;
            int tempValue = temp->data;
            head = head->next;
            delete temp;
            return tempValue;
        }
    }

    int front() {
        if(empty()) {
            return -1;
        }
        else {
            return head->data;
        }
    }
};

int main()
{
    SinglyLinkedList list = SinglyLinkedList();
    int N;
    string question;
    cin>>N;
    while(N--) {
        cin>>question;
        if(question == "empty") {
            cout<<list.empty()<<"\n";
        }
        else if(question == "front") {
            cout<<list.front()<<"\n";
        }
        else if(question == "addFront") {
            int data;
            cin>>data;
            list.addFront(data);
        }
        else if(question == "removeFront") {
            cout<<list.removeFront()<<"\n";
        }
    }
}
