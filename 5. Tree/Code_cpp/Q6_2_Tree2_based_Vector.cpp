////
////  Q6_2_Tree2_based_Vector.cpp
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
////tree를 vector 사용하여 제작, insert(p,x), delete(p), print(p) 구현
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
//    ~Node() {}
//
//    void setParent(Node* parent) {
//        this->parent = parent;
//    }
//
//    void insertChild(Node* child) {
//        child_vector.push_back(child);
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
//        this->root = new Node(1);
//        tree.push_back(root);
//    }
//
//    int size() {
//        int size = (int)tree.size();
//        return size;
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
//                Node* target = tree[i];
//                if(target == root) {
//                    return;
//                }
//                Node* parent = target->parent;
//                for(Node*& child : target->child_vector) {
//                    child->setParent(parent);
//                    parent->insertChild(child);
//                }
//                parent->deleteChild(target);
//                tree.erase(tree.begin()+i);
//                delete target;
//                return;
//            }
//        }
//    }
//
//    void printLevel(int data) {
//        for(int i=0; i<size(); i++) {
//            if(tree[i]->data == data) {
//                if(tree[i] == root) {
//                    cout<<data<<"\n";
//                    return;
//                }
//                Node* parent = tree[i]->parent;
//                for(Node*& child : parent->child_vector) {
//                    cout<<child->data<<" ";
//                }
//                cout<<"\n";
//                return;
//            }
//        }
//        cout<<0<<"\n";
//        return;
//    }
//
//};
//
//int main()
//{
//    Tree tree = Tree(1);
//    int N,data;
//    string question;
//    cin>>N;
//    while(N--) {
//        cin>>question;
//        if(question == "insert") {
//            int parent;
//            cin>>parent>>data;
//            tree.insertNode(parent, data);
//        }
//        else if(question == "print") {
//            cin>>data;
//            tree.printLevel(data);
//        }
//        else if(question == "delete") {
//            cin>>data;
//            tree.deleteNode(data);
//        }
//    }
//}
