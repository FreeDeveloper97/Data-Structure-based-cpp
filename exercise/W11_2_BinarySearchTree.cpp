////
////  W11_2_BinarySearchTree.cpp
////  INHA CLASS
////
////  Created by Kang Minsang on 2020/12/15.
////  Copyright © 2020 Kang Minsang. All rights reserved.
////
//
//#include <iostream>
//using namespace std;
//
////class Node
////class BinarySearchTree
////1. Node* find(int e)
////2. void insert(int e)
////3. Node* find_min(Node* node)
////4, Node* find_max(Node* node)
//
//class Node {
//private:
//    int data;
//    Node* parent;
//    Node* leftChild;
//    Node* rightChild;
//public:
//    Node() {
//        this->data = 0;
//        this->parent = NULL;
//        this->leftChild = NULL;
//        this->rightChild = NULL;
//    }
//
//    Node(int data) {
//        this->data = data;
//        this->parent = NULL;
//        this->leftChild = NULL;
//        this->rightChild = NULL;
//    }
//
//    Node* getLeftChild() {
//        return leftChild;
//    }
//    Node* getRightChild() {
//        return rightChild;
//    }
//    void setLeftChild(Node* node) {
//        leftChild = node;
//    }
//    void setRightChild(Node* node) {
//        rightChild = node;
//    }
//    void setParent(Node* node) {
//        parent = node;
//    }
//    int getData() {
//        return data;
//    }
//};
//
//class BinarySearchTree {
//private:
//    Node* root;
//public:
//    BinarySearchTree() {
//        this->root = NULL;
//    }
//
//    Node* find(int e) {
//        Node* result = root;
//        while(result != NULL) {
//            if(result->getData() == e) {
//                return result;
//            }
//            else if(e < result->getData()) {
//                result = result->getLeftChild();
//            }
//            else {
//                result = result->getRightChild();
//            }
//        }
//        return NULL;
//    }
//
//    void insert(int e) {
//        Node* newNode = new Node(e);
//        Node* parent = NULL;
//        Node* temp = root;
//        if(root == NULL) {
//            root = newNode;
//            return;
//        }
//        while(temp != NULL) {
//            parent = temp;
//            if(e < temp->getData()) {
//                temp = temp->getLeftChild();
//            }
//            else {
//                temp = temp->getRightChild();
//            }
//        }
//        if(e < parent->getData()) {
//            parent->setLeftChild(newNode);
//            newNode->setParent(parent);
//        }
//        else {
//            parent->setRightChild(newNode);
//            newNode->setParent(parent);
//        }
//    }
//
//    Node* find_min(Node* node) {
//        Node* result = NULL;
//        Node* temp = node;
//        while(temp != NULL) {
//            result = temp;
//            temp = temp->getLeftChild();
//        }
//        return result;
//    }
//
//    Node* find_max(Node* node) {
//        Node* result = NULL;
//        Node* temp = node;
//        while(temp != NULL) {
//            result = temp;
//            temp = temp->getRightChild();
//        }
//        return result;
//    }
//
//    void print(int x) {
//        Node* node = find(x);
//        int max;
//        int min;
//        max = node->getRightChild() == NULL ? node->getData() : find_max(node->getRightChild())->getData();
//        min = node->getLeftChild() == NULL ? node->getData() : find_min(node->getLeftChild())->getData();
//        cout<<min<<" "<<max<<"\n";
//    }
//};
//
//int main()
//{
//    int T;
//    cin>>T;
//    while(T--) {
//        BinarySearchTree tree = BinarySearchTree();
//        int P;
//        cin>>P;
//        int e;
//        while(P--) {
//            cin>>e;
//            tree.insert(e);
//        }
//        int x;
//        cin>>x;
//        tree.print(x);
//    }
//}
