////
////  W11_P4_Binary_Search_Tree.cpp
////  INHA CLASS
////
////  Created by Kang Minsang on 2020/12/13.
////  Copyright © 2020 Kang Minsang. All rights reserved.
////
//
//#include <iostream>
//using namespace std;
//
//class Node {
//public:
//    int data;
//    Node* leftChild;
//    Node* rightChild;
//    Node* parent;
//
//    Node() {
//        this->leftChild = NULL;
//        this->rightChild = NULL;
//        this->parent = NULL;
//    }
//
//    Node(int data) {
//        this->data = data;
//        this->leftChild = NULL;
//        this->rightChild = NULL;
//        this->parent = NULL;
//    }
//};
//
//class BST {
//private:
//    Node* root;
//public:
//    BST() {
//        this->root = NULL;
//    }
//
//    void insert(int inputData) {
//        Node* newNode = new Node(inputData); //삽입될 노드
//        Node* saveNode = NULL; //저장할 노드 위치
//        //첫번째 노드가 삽입될 경우
//        if(root == NULL) {
//            root = newNode;
//        }
//        //정상적인 경우
//        else {
//            Node* curNode = root;
//            while(curNode != NULL) {
//                saveNode = curNode;
//                //중복된 값이 있는경우
//                if(curNode->data == inputData) {
//                    cout<<"Duplication\n";
//                    return;
//                }
//                //left로 이동
//                else if(curNode->data > inputData) {
//                    curNode = curNode->leftChild;
//                }
//                //right로 이동
//                else {
//                    curNode = curNode->rightChild;
//                }
//            }
//            //입력될 위치인 saveNode 찾기 종료
//            //curNode는 NULL이지만, saveNode는 parent에 위치
//            if(saveNode->data > inputData) {
//                newNode->parent = saveNode;
//                saveNode->leftChild = newNode;
//            }
//            else {
//                newNode->parent = saveNode;
//                saveNode->rightChild = newNode;
//            }
//        }
//    }
//
//    Node* find(int inputData) {
//        Node* curNode = root;
//        while(curNode != NULL) {
//            if(curNode->data == inputData) {
//                return curNode;
//            }
//            else if(curNode->data > inputData) {
//                curNode = curNode->leftChild;
//            }
//            else {
//                curNode = curNode->rightChild;
//            }
//        }
//        return NULL;
//    }
//
//    Node* min_findNode(Node* _Node) {
//        Node* curNode = _Node;
//        Node* saveNode = NULL;
//        while(curNode != NULL) {
//            saveNode = curNode;
//            curNode = curNode->leftChild;
//        }
//        //saveNode가 가장 왼쪽 Node이다
//        return saveNode;
//    }
//
//    Node* max_findNode(Node* _Node) {
//        Node* curNode = _Node;
//        Node* saveNode = NULL;
//        while(curNode != NULL) {
//            saveNode = curNode;
//            curNode = curNode->rightChild;
//        }
//        return saveNode;
//    }
//
//    void erase(int data) {
//        Node* curNode = find(data);
//        //자식수에 따라 삭제가 달리 이뤄진다
//        int numofchild = bool(curNode->leftChild) + bool(curNode->rightChild);
//        //자식이 없는경우
//        if(numofchild == 0) {
//            //root노드 삭제의 경우
//            if(curNode == root) {
//                root = NULL;
//            }
//            //정상의 자식이 없는 삭제의 경우
//            else {
//                //왼쪽 삭제
//                if(curNode->parent->data > curNode->data) {
//                    curNode->parent->leftChild = NULL;
//                }
//                //오른쪽 삭제
//                else {
//                    curNode->parent->rightChild = NULL;
//                }
//            }
//            delete curNode;
//        }
//        //자식이 2개인 경우
//        else if(numofchild == 2) {
//            //오른쪽 tree중 위치이동대상인 가장적은값을 찾는다
//            Node* minNode = min_findNode(curNode->rightChild);
//            //값만 변경을 위해 data로 임시저장한다
//            int data = minNode->data;
//            //가장적었던 Node를 삭제한다
//            erase(minNode->data);
//            //값을 수정한다
//            curNode->data = data;
//        }
//        //자식이 1개인 경우
//        else if(numofchild == 1){
//            //root의 경우 root 포인터를 변경 후 curNode를 삭제한다
//            if(curNode == root) {
//                if(curNode->leftChild != NULL) {
//                    root = curNode->leftChild;
//                }
//                else {
//                    root = curNode->rightChild;
//                }
//            }
//            //정상의 자식이 1개인 경우
//            else {
//                //부모와 자식을 찾아놓는다
//                Node* curParent = curNode->parent;
//                Node* child = (curNode->leftChild) ? curNode->leftChild : curNode->rightChild;
//                //child를 left로 이동
//                if(curParent->data > child->data) {
//                    curParent->leftChild = child;
//                    child->parent = curParent;
//                }
//                //child를 right로 이동
//                else {
//                    curParent->rightChild = child;
//                    child->parent = curParent;
//                }
//            }
//            //이동이 종료된 후 curNode를 삭제한다
//            delete curNode;
//        }
//    }
//
//    void preorderPrint(Node* curNode) {
//        if(curNode != NULL) {
//            cout<<curNode->data<<" ";
//            preorderPrint(curNode->leftChild);
//            preorderPrint(curNode->rightChild);
//        }
//    }
//
//    void inorderPrint(Node* curNode) {
//        if(curNode != NULL) {
//            inorderPrint(curNode->leftChild);
//            cout<<curNode->data<<" ";
//            inorderPrint(curNode->rightChild);
//        }
//    }
//
//    void postorderPrint(Node* curNode) {
//        if(curNode != NULL) {
//            postorderPrint(curNode->leftChild);
//            postorderPrint(curNode->rightChild);
//            cout<<curNode->data<<" ";
//        }
//    }
//
//    void preorder() {
//        preorderPrint(root);
//        cout<<"\n";
//    }
//
//    void inorder() {
//        if(root == NULL) {
//            cout<<"Empty\n";
//        }
//        else {
//            inorderPrint(root);
//            cout<<"\n";
//        }
//    }
//
//    void postorder() {
//        if(root == NULL) {
//            cout<<"Empty\n";
//        }
//        else {
//            postorderPrint(root);
//            cout<<"\n";
//        }
//    }
//
//    void find_min_max(int findX) {
//        Node* start = find(findX);
//        int left_min;
//        int right_max;
//        if(start->leftChild != NULL) {
//            left_min = min_findNode(start->leftChild)->data;
//        }
//        else {
//            left_min = start->data;
//        }
//        if(start->rightChild != NULL) {
//            right_max = max_findNode(start->rightChild)->data;
//        }
//        else {
//            right_max = start->data;
//        }
//        cout<<left_min<<" "<<right_max<<"\n";
//    }
//};
//
//int main()
//{
//    int T;
//    cin>>T;
//    while(T--) {
//        BST tree = BST();
//        int P;
//        cin>>P;
//        int N;
//        while(P--) {
//            cin>>N;
//            tree.insert(N);
//        }
//        int Q;
//        cin>>Q;
//        int delX;
//        while(Q--) {
//            cin>>delX;
//            tree.erase(delX);
//        }
//        tree.postorder();
//    }
//}
