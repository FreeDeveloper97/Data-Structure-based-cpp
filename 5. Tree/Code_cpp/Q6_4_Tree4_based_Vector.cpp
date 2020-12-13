////
////  Q6_4_Tree4_based_Vector.cpp
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
//
//    Tree(int data) {
//        this->root = new Node(1);
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
//    int depth(Node* p) {
//        if(p == root) {
//            return 0;
//        }
//        return 1+depth(p->parent);
//    }
//
//    void startDepth(int d) {
//        for(int i=0; i<size(); i++) {
//            if(depth(tree[i]) == d) {
//                if(tree[i] == root) {
//                    cout<<1<<"\n";
//                    return;
//                }
//                Node* temp = tree[i]->parent;
//                int max = temp->child_vector[0]->data;
//                for(Node*& child : temp->child_vector) {
//                    if(child->data > max) {
//                        max = child->data;
//                    }
//                }
//                cout<<max<<"\n";
//                return;
//            }
//        }
//        cout<<0<<"\n";
//        return;
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
//        tree.insert(p,d);
//    }
//    int depth;
//    while(M--) {
//        cin>>depth;
//        tree.startDepth(depth);
//    }
//}
