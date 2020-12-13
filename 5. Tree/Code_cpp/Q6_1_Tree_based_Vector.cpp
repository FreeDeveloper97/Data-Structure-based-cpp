////
////  Q6_1_Tree_based_Vector.cpp
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
////Node를 vector 이용하여 구현, insert(p,x), delete(p), print(p) 구현
////class Node, class Tree 구현
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
//    void setParent(Node* parent) {
//        this->parent = parent;
//    }
//
//    void insertChild(Node* child) {
//        this->child_vector.push_back(child);
//    }
//
//    void deleteChild(Node* child) {
//        for(int i=0; i<child_vector.size(); i++) {
//            if(child_vector[i] == child) {
//                child_vector.erase(child_vector.begin() + i);
//            }
//        }
//    }
//};
//
//class Tree {
//public:
//    Node* root;
//    vector<Node*> tree;
//
//    Tree(int data) {
//        root = new Node(data);
//        tree.push_back(root);
//    }
//
//    int size() {
//        return (int)tree.size();
//    }
//
//    void insertNode(int parent, int data) {
//        for(int i=0; i<size(); i++) {
//            if(tree[i]->data == parent) {
//                Node* V = new Node(data);
//                V->setParent(tree[i]);
//                tree[i]->insertChild(V);
//                tree.push_back(V);
//                return;
//            }
//        }
//    }
//
//    void deleteNode(int data) {
//        for(int i=0; i<size(); i++) {
//            if(tree[i]->data == data) {
//                if(tree[i] == root) {
//                    return;
//                }
//                Node* target = tree[i];
//                Node* parent = tree[i]->parent;
//                for(Node*& child : target->child_vector) {
//                    parent->insertChild(child);
//                    child->setParent(parent);
//                }
//                parent->deleteChild(target);
//                tree.erase(tree.begin()+i);
//                delete target;
//                return;
//            }
//        }
//    }
//
//    void printChild(int data) {
//        for(int i=0; i<size(); i++) {
//            if(tree[i]->data == data) {
//                Node* parent = tree[i];
//                if(parent->child_vector.size() == 0) {
//                    cout<<"0\n";
//                    return;
//                }
//                for(Node*& child : parent->child_vector) {
//                    cout<<child->data<<" ";
//                }
//                cout<<"\n";
//                return;
//            }
//        }
//    }
//};
//
////int main() {
////    Tree tree = Tree(1);
////    int N,data;
////    string question;
////    cin>>N;
////    while(N--) {
////        cin>>question;
////        if(question == "insert") {
////            int parent;
////            cin>>parent>>data;
////            tree.insertNode(parent, data);
////        }
////        else if(question == "print") {
////            cin>>data;
////            tree.printChild(data);
////        }
////        else if(question == "delete") {
////            cin>>data;
////            tree.deleteNode(data);
////        }
////        else if(question == "size") {
////            cout<<tree.size()<<"\n";
////        }
////    }
////}
