//
//  Q5_4_DoublyLinkedList2.cpp
//  INHA CLASS
//
//  Created by Kang Minsang on 2020/10/30.
//  Copyright © 2020 Kang Minsang. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node() {
        this->next = NULL;
        this->prev = NULL;
    }
};

class Iterator {
public:
    Node* v;

    Iterator(Node* u) {
        this->v = u;
    }

    int &operator*() {
        return v->data;
    }

    Iterator &operator++() {
        v = v->next;
        return *this;
    }

    Iterator &operator--() {
        v = v->prev;
        return *this;
    }

    bool operator==(const Iterator &p) const {
        return v == p.v;
    }

    bool operator!=(const Iterator &p) const{
        return v != p.v;
    }
    friend class DoublyLinkedList;
};

class DoublyLinkedList {
public:
    int n;
    Node* header;
    Node* trailer;

    DoublyLinkedList() {
        this->n = 0;
        this->header = new Node();
        this->trailer = new Node();
        header->next = trailer;
        trailer->prev = header;
    }

    Iterator begin() {
        return Iterator(header->next);
    }

    Iterator end() {
        return Iterator(trailer);
    }

    void insert(const Iterator& p, const int d) {
        Node* w = p.v;
        Node* u = w->prev;
        Node* v = new Node();
        v->data = d;

        v->next = w;
        w->prev = v;
        v->prev = u;
        u->next = v;
        this->n++;
    }

    void insertBack(const int d) {
        insert(end(),d);
    }

    void calculate() {
        Iterator p = begin();
        double sum = 0;
        int min = p.v->data;
        while(p!=end()) {
            int temp = p.v->data;
            sum += temp;
            if(temp < min) {
                min = temp;
            }
            ++p;
        }
        sum /= n;
        int temp = floor(sum);
        cout<<temp<<" "<<min<<"\n";
    }

    Iterator atIndex(int i) {
        Iterator p = begin();
        for(int j=0; j<i; j++) {
            ++p;
        }
        return p;
    }
    
    int indexOf(Iterator &p) {
        int j=0;
        while(p != end()) {
            ++p;
            ++j;
        }
        return j;
    }
};

int main()
{
    int T;
    cin>>T;
    while(T--) {
        DoublyLinkedList list = DoublyLinkedList();
        int N;
        cin>>N;
        while(N--) {
            int temp;
            cin>>temp;
            list.insertBack(temp);
        }
        list.calculate();
    }
}
