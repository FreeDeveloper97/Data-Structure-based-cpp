////
////  Q7_3_Tree_preorder2_based_Vector.cpp
////  INHA CLASS
////
////  Created by Kang Minsang on 2020/10/28.
////  Copyright © 2020 Kang Minsang. All rights reserved.
////
//
//#include <iostream>
//#include <vector>
//using namespace std;
//
//class Node {
//public:
//    int data;
//    Node* parent;
//    vector<Node*> child_vector;
//
//    Node(int data) {
//        this->data = data;
//        this->parent = NULL;
//    }
//
//    void setParent(Node* p) {
//        this->parent = p;
//    }
//
//    void addChild(Node* p) {
//        child_vector.push_back(p);
//    }
//};
//
//class Tree {
//public:
//    Node* root;
//    vector<Node*> tree;
//    int count;
//
//    Tree(int data) {
//        this->root = new Node(data);
//        tree.push_back(root);
//        this->count = 0;
//    }
//
//    int size() {
//        int size = (int)tree.size();
//        return size;
//    }
//
//    void insert(int p, int d) {
//        for(int i=0; i<size(); i++) {
//            if(tree[i]->data == p) {
//                Node* v = new Node(d);
//                v->setParent(tree[i]);
//                tree[i]->addChild(v);
//                tree.push_back(v);
//            }
//        }
//    }
//
//    void preorder(Node* p) {
//        this->count++;
//        if(p->child_vector.size() == 0) {
//            cout<<this->count<<" ";
//            this->count = 0;
//            return;
//        }
//        for(Node*& child : p->child_vector) {
//            preorder(child);
//        }
//    }
//
//    void startPreorder(int data) {
//        for(int i=0; i<size(); i++) {
//            if(tree[i]->data == data) {
//                preorder(tree[i]);
//                cout<<"\n";
//            }
//        }
//    }
//};
//
//int main()
//{
//    int N;
//    cin>>N;
//    while(N--) {
//        Tree tree = Tree(1);
//        int M,p,d;
//        cin>>M;
//        while(M--) {
//            cin>>p>>d;
//            tree.insert(p,d);
//        }
//        tree.startPreorder(1);
//    }
//}
