////
////  Q5_1_Sequence_based_DoubleLinkedList.cpp
////  INHA CLASS
////
////  Created by Kang Minsang on 2020/10/28.
////  Copyright © 2020 Kang Minsang. All rights reserved.
////
//
//#include <iostream>
//using namespace std;
//
////Sequence를 Double LinkedList로 구현, insert(p,e), erase(p), begin, end, ++, --, print, size 구현
////class Node, class Iterator, class DoublyLinkedList, class Squence 필요
//
//class Node {
//public:
//    int e;
//    Node* prev;
//    Node* next;
//
//    Node() {
//        this->prev = NULL;
//        this->next = NULL;
//    }
//};
//
//class Iterator {
//public:
//    Node* v;
//
//    Iterator(Node* u) {
//        v = u;
//    }
//
//    int &operator*() {
//        return v->e;
//    }
//
//    bool operator==(const Iterator &p) const {
//        return this->v == p.v;
//    }
//
//    bool operator!=(const Iterator &p) const {
//        return this->v != p.v;
//    }
//
//    Iterator &operator++() {
//        v = v->next;
//        return *this;
//    }
//
//    Iterator &operator--() {
//        v = v->prev;
//        return *this;
//    }
//
//    friend class Sequence;
//};
//
//class Sequence {
//public:
//    int n;
//    Node* header;
//    Node* trailer;
//
//    Sequence() {
//        this->n = 0;
//        this->header = new Node;
//        this->trailer = new Node;
//        header->next = trailer;
//        trailer->prev = header;
//    }
//
//    int size() const {
//        return n;
//    }
//
//    bool empty() const {
//        return (n==0);
//    }
//
//    Iterator begin() const {
//        return Iterator(header->next);
//    }
//
//    Iterator end() const {
//        return Iterator(trailer);
//    }
//
//    void insert(const Iterator &p,const int e) {
//        Node* w = p.v;
//        Node* u = w->prev;
//        Node* v = new Node;
//
//        v->e = e;
//
//        v->next = w;
//        w->prev = v;
//        v->prev = u;
//        u->next = v;
//
//        this->n++;
//    }
//
//    void insertFront(const int e) {
//        insert(begin(),e);
//    }
//
//    void insertBack(const int e) {
//        insert(end(),e);
//    }
//
//    void erase(const Iterator &p) {
//        if(size() == 0) {
//            cout<<"Empty\n";
//        }
//        else {
//            Node* v = p.v;
//            Node* w = v->next;
//            Node* u = v->prev;
//
//            u->next = w;
//            w->prev = u;
//
//            delete v;
//            this->n--;
//        }
//    }
//
//    void eraseFront() {
//        erase(begin());
//    }
//
//    void eraseBack() {
//        erase(--end());
//    }
//
//    Iterator atIndex(int i) const {
//        Iterator p = begin();
//        for(int j=0; j<i; j++) {
//            ++p;
//        }
//        return p;
//    }
//
//    int indexOf(const Iterator& p) const {
//        Iterator q = begin();
//        int j = 0;
//        while(q != p) {
//            ++q;
//            ++j;
//        }
//        return j;
//    }
//
//    void print()
//    {
//        if(empty())
//        {
//            cout<<"Empty\n";
//        }
//        else
//        {
//            Iterator p = begin();
//            Iterator q = end();
//            while(p != q)
//            {
//                cout<<p.v->e<<" ";
//                ++p;
//            }
//            cout<<"\n";
//        }
//    }
//};
//
//int main()
//{
//    int T;
//    cin>>T;
//    Sequence sl;
//    Iterator iter = sl.begin();
//
//    for(int i=0; i<T; i++)
//    {
//        string oper;
//        cin>>oper;
//        if(oper == "insert")
//        {
//            int e;
//            cin>>e;
//            sl.insert(iter, e);
//        }
//        else if(oper == "erase")
//        {
//            sl.erase(iter);
//        }
//        else if(oper == "begin")
//        {
//            iter = sl.begin();
//        }
//        else if(oper == "end")
//        {
//            iter = sl.end();
//        }
//        else if(oper == "++")
//        {
//            ++iter;
//        }
//        else if(oper == "--")
//        {
//            --iter;
//        }
//        else if(oper == "print")
//        {
//            sl.print();
//        }
//        else if(oper == "size")
//        {
//            cout<<sl.size()<<"\n";
//        }
//        else
//        {
//            cout<<"Your command is wrong, try again."<<endl;
//        }
//    }
//    return 0;
//}
