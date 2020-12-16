////
////  W11_1_BinarySearchTree.cpp
////  INHA CLASS
////
////  Created by Kang Minsang on 2020/12/15.
////  Copyright © 2020 Kang Minsang. All rights reserved.
////
//
//#include <iostream>
//using namespace std;
//
////class Node가 필요
////class BinarySearchTree가 필요
////functions
////1. Node* find(int e)
////2. insert(int e)
////3. erase(int e) : 삭제하기 전 포인터를 NULL 변환 후 delete 한다
////4. Node* min_findNode(Node* start)
//
////5. print
////6. Node* max_findNode(Node* start)
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
//    Node(int data) {
//        this->data = data;
//        this->parent = NULL;
//        this->leftChild = NULL;
//        this->rightChild = NULL;
//    }
//    int getData() {
//        return data;
//    }
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
//    Node* findNode(int e) {
//        Node* start = root;
//        while(start != NULL) {
//            if(e == start->getData()) {
//                return start;
//            }
//            else if(e < start->getData()) {
//                start = start->getLeftChild();
//            }
//            else {
//                start = start->getRightChild();
//            }
//        }
//        return NULL;
//    }
//
//    void insert(int e) {
//        Node* newNode = new Node(e);
//        if(root == NULL) {
//            root = newNode;
//            return;
//        }
//        Node* parent = NULL;
//        Node* temp = root;
//        while(temp != NULL) {
//            parent = temp;
//            if(e < parent->getData()) {
//                temp = temp->getLeftChild();
//            }
//            else {
//                temp = temp->getRightChild();
//            }
//        }
//        //parent : 넣을 노드
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
//        Node* min = NULL;
//        Node* temp = node;
//        while(temp != NULL) {
//            min = temp;
//            temp = temp->getLeftChild();
//        }
//        return min;
//    }
//
//    Node* find_max(Node* node) {
//        Node* max = NULL;
//        Node* temp = node;
//        while(temp != NULL) {
//            max = temp;
//            temp = temp->getRightChild();
//        }
//        return max;
//    }
//
//    //문제를 위한 함수
//    void print(int x) {
//        Node* node = findNode(x);
//        int max;
//        int min;
//        max = node->getLeftChild() == NULL ? node->getData() : find_max(node->getLeftChild())->getData();
//        min = node->getRightChild() == NULL ? node->getData() : find_min(node->getRightChild())->getData();
//        cout<<max<<" "<<min<<"\n";
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
//        int N;
//        while(P--) {
//            cin>>N;
//            tree.insert(N);
//        }
//        int x;
//        cin>>x;
//        tree.print(x);
//    }
//}
