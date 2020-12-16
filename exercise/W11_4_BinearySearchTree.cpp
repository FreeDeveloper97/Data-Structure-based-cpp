////
////  W11_4_BinearySearchTree.cpp
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
//    Node* getParent() {
//        return parent;
//    }
//    Node* getLeftChild() {
//        return leftChild;
//    }
//    Node* getRightChild() {
//        return rightChild;
//    }
//    int getData() {
//        return data;
//    }
//    void setParent(Node* node) {
//        parent = node;
//    }
//    void setLeftChild(Node* node) {
//        leftChild = node;
//    }
//    void setRightChild(Node* node) {
//        rightChild = node;
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
//                if(delNode->getLeftChild() != NULL) {
//                    root = delNode->getLeftChild();
//                }
//                else {
//                    root = delNode->getRightChild();
//                }
//                delete delNode;
//            }
//            else {
//                Node* parent = delNode->getParent();
//                Node* child = delNode->getLeftChild() != NULL ? delNode->getLeftChild() : delNode->getRightChild();
//                if(child->getData() < parent->getData()) {
//                    parent->setLeftChild(child);
//                    child->setParent(parent);
//                }
//                else {
//                    parent->setRightChild(child);
//                    child->setParent(parent);
//                }
//                delete delNode;
//            }
//        }
//        else if(num == 2) {
//            Node* min = find_min(delNode->getRightChild());
//            int data = min->getData();
//            erase(data);
//            delNode->setData(data);
//        }
//    }
//
//    void startPost() {
//        if(root == NULL) {
//            cout<<"Empty\n";
//        }
//        else {
//            postOrderPrint(root);
//            cout<<"\n";
//        }
//    }
//
//    void postOrderPrint(Node* node) {
//        if(node == NULL) {
//            return;
//        }
//        postOrderPrint(node->getLeftChild());
//        postOrderPrint(node->getRightChild());
//        cout<<node->getData()<<" ";
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
//        while(Q--) {
//            cin>>N;
//            tree.erase(N);
//        }
//        tree.startPost();
//    }
//}
