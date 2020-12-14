
  Q5_2_Sequence2_based_DoublyLinkedList.cpp
  INHA CLASS

  Created by Kang Minsang on 2020/10/28.
  Copyright © 2020 Kang Minsang. All rights reserved.


#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node() {
        this->prev = NULL;
        this->next = NULL;
    }
};

class Iterator {
public:
    Node* v;

    Iterator(Node* u) {
        v = u;
    }

    bool operator==(const Iterator &p) const {
        return this->v == p.v;
    }

    bool operator!=(const Iterator &p) const {
        return this->v != p.v;
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
    friend class Sequence;
};

class Sequence {
public:
    int n;
    Node* header;
    Node* trailer;

    Sequence() {
        this->n = 0;
        header = new Node();
        trailer = new Node();
        header->next = trailer;
        trailer->prev = header;
    }

    bool empty() {
        return (n == 0);
    }

    int size() {
        return n;
    }

    Iterator begin() const {
        return Iterator(header->next);
    }

    Iterator end() const {
        return Iterator(trailer);
    }

    void insert(const Iterator &p, int e) {
        Node* w = p.v;
        Node* u = w->prev;
        Node* v = new Node;
        v->data = e;

        v->next = w;
        w->prev = v;
        v->prev = u;
        u->next = v;
        this->n++;
    }

    void erase(const Iterator &p) {
        if(empty()) {
            cout<<"Empty\n";
        }
        else {
            Node* v = p.v;
            Node* w = v->next;
            Node* u = v->prev;

            u->next = w;
            w->prev = u;
            delete v;
            this->n--;
        }
    }

    void reversePrint() {
        if(empty()) {
            cout<<"Empty\n";
        }
        else {
            Iterator p = end();
            --p;
            while(p != begin()) {
                cout<<p.v->data<<" ";
                --p;
            }
            cout<<p.v->data<<"\n";
        }
    }
};

int main()
{
    Sequence s = Sequence();
    Iterator p = s.begin();
    int N;
    string question;

    cin>>N;
    while(N--) {
        cin>>question;
        if(question == "insert") {
            int data;
            cin>>data;
            s.insert(p,data);
        }
        else if(question == "reversePrint") {
            s.reversePrint();
        }
        else if(question == "size") {
            cout<<s.size()<<"\n";
        }
        else if(question == "erase") {
            s.erase(p);
        }
        else if(question == "begin") {
            p = s.begin();
        }
        else if(question == "end") {
            p = s.end();
        }
        else if(question == "++") {
            ++p;
        }
        else if(question == "--") {
            --p;
        }
    }
}
