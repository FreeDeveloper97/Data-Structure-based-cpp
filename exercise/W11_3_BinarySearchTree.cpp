////
////  W11_3_BinarySearchTree.cpp
////  INHA CLASS
////
////  Created by Kang Minsang on 2020/12/15.
////  Copyright © 2020 Kang Minsang. All rights reserved.
////
//
//#include <iostream>
//using namespace std;
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
//    Node* getLeftChild() {
//        return leftChild;
//    }
//    Node* getRightChild() {
//        return rightChild;
//    }
//    Node* getParent() {
//        return parent;
//    }
//    int getData() {
//        return data;
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
//    void setData(int data) {
//        this->data = data;
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
//            if(e < temp->getData()) {
//                temp = temp->getLeftChild();
//            }
//            else {
//                temp = temp->getRightChild();
//            }
//        }
//        newNode->setParent(parent);
//        if(e < parent->getData()) {
//            parent->setLeftChild(newNode);
//        }
//        else {
//            parent->setRightChild(newNode);
//        }
//    }
//
//    Node* find(int e) {
//        Node* result = root;
//        while(result != NULL) {
//            if(e == result->getData()) {
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
//    void erase(int e) {
//        Node* delNode = find(e);
//        int num = bool(delNode->getLeftChild()) + bool(delNode->getRightChild());
//        if(num == 0) {
//            if(delNode == root) {
//                root = NULL;
//            }
//            else {
//                Node* parent = delNode->getParent();
//                if(e < parent->getData()) {
//                    parent->setLeftChild(NULL);
//                }
//                else {
//                    parent->setRightChild(NULL);
//                }
//            }
//            delete delNode;
//        }
//        else if(num == 1) {
//            if(delNode == root) {
//                Node* child = delNode->getLeftChild() != NULL ? delNode->getLeftChild() : delNode->getRightChild();
//                root = child;
//            }
//            else {
//                Node* parent = delNode->getParent();
//                Node* child = delNode->getLeftChild() != NULL ? delNode->getLeftChild() : delNode->getRightChild();
//                child->setParent(parent);
//                if(e < parent->getData()) {
//                    parent->setLeftChild(child);
//                }
//                else {
//                    parent->setRightChild(child);
//                }
//            }
//            delete delNode;
//        }
//        else if(num == 2) {
//            int data = find_min(delNode->getRightChild())->getData();
//            erase(data);
//            delNode->setData(data);
//        }
//    }
//
//    void inorderStart() {
//        if(root == NULL) {
//            cout<<"Empty\n";
//            return;
//        }
//        inorderPrint(root);
//        cout<<"\n";
//    }
//    void inorderPrint(Node* node) {
//        if(node == NULL) {
//            return;
//        }
//        inorderPrint(node->getLeftChild());
//        cout<<node->getData()<<" ";
//        inorderPrint(node->getRightChild());
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
//        int Q;
//        cin>>Q;
//        int x;
//        while(Q--) {
//            cin>>x;
//            tree.erase(x);
//        }
//        tree.inorderStart();
//    }
//}
