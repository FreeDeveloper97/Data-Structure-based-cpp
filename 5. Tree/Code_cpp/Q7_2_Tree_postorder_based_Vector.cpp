////
////  Q7_2_Tree_postorder_based_Vector.cpp
////  INHA CLASS
////
////  Created by Kang Minsang on 2020/10/28.
////  Copyright © 2020 Kang Minsang. All rights reserved.
////
//
//#include <iostream>
//#include <vector>
//using namespace std;
////class Node, class Tree, insert(p,d), postorder 구현
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
//    int size() {
//        int size = (int)tree.size();
//        return size;
//    }
//
//    Tree(int data) {
//        this->root = new Node(data);
//        this->tree.push_back(root);
//    }
//
//    void insert(int p, int d) {
//        for(int i=0; i<size(); i++) {
//            if(tree[i]->data ==p) {
//                Node* v = new Node(d);
//                v->setParent(tree[i]);
//                tree[i]->addChild(v);
//                tree.push_back(v);
//                return;
//            }
//        }
//    }
//
//    void postorder(Node* p) {
//        if(!p) {
//            return;
//        }
//        for(Node*& child : p->child_vector) {
//            postorder(child);
//        }
//        cout<<p->data<<" ";
//    }
//
//    void startPostorder(int data) {
//        for(int i=0; i<size(); i++) {
//            if(tree[i]->data == data) {
//                postorder(tree[i]);
//                cout<<"\n";
//                return;
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
//        tree.startPostorder(1);
//    }
//}
