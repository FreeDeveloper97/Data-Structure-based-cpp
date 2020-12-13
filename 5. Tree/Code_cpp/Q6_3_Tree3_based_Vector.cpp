////
////  Q6_3_Tree3_based_Vector.cpp
////  INHA CLASS
////
////  Created by Kang Minsang on 2020/10/29.
////  Copyright © 2020 Kang Minsang. All rights reserved.
////
//
//#include <iostream>
//#include <vector>
//using namespace std;
//
////vector 사용하여 tree 구현, depth(p) 구현
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
//        this->child_vector.push_back(p);
//    }
//};
//
//class Tree {
//public:
//    Node* root;
//    vector<Node*> tree;
//
//    Tree(int data) {
//        this->root = new Node(data);
//        this->tree.push_back(root);
//    }
//
//    int size() {
//        int size = tree.size();
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
//                return;
//            }
//        }
//    }
//
//    int printDepth(Node* p) {
//        if(p == root) {
//            return 0;
//        }
//        return 1+printDepth(p->parent);
//    }
//
//    void startDepth(int data) {
//        for(int i=0; i<size(); i++) {
//            if(tree[i]->data == data) {
//                cout<<printDepth(tree[i])<<"\n";
//                return;
//            }
//        }
//    }
//};
//
//int main()
//{
//    Tree tree = Tree(1);
//    int N,M;
//    int p,d;
//    cin>>N>>M;
//    while(N--) {
//        cin>>p>>d;
//        tree.insert(p, d);
//    }
//    while(M--) {
//        int target;
//        cin>>target;
//        tree.startDepth(target);
//    }
//}
