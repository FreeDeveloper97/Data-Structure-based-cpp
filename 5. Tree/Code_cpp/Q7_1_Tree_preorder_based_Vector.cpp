//
//  Q7_1_Tree_preorder_based_Vector.cpp
//  INHA CLASS
//
//  Created by Kang Minsang on 2020/10/28.
//  Copyright © 2020 Kang Minsang. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

//class Node, class Tree를 만든다, insert, postorder 구현
class Node {
public:
    int data;
    Node* parent;
    vector<Node*> child_vector;

    Node(int data) {
        this->data = data;
        this->parent = NULL;
    }

    void setParent(Node* p) {
        this->parent = p;
    }

    void addChild(Node* c) {
        child_vector.push_back(c);
    }
};

class Tree {
public:
    Node* root;
    vector<Node*> tree;

    int size() {
        int size = (int)tree.size();
        return size;
    }
    Tree(int data) {
        this->root = new Node(data);
        this->tree.push_back(root);
    }

    void insert(int parent, int data) {
        for(int i=0; i<size(); i++) {
            if(tree[i]->data == parent) {
                Node* v = new Node(data);
                v->setParent(tree[i]);
                tree[i]->addChild(v);
                tree.push_back(v);
            }
        }
    }

    void postorder(Node* p) {
        if(!p) {
            return;
        }
        cout<<p->data<<" ";
        for(Node*& child : p->child_vector) {
            postorder(child);
        }
    }

    void startPostorder(int data) {
        for(int i=0; i<size(); i++) {
            if(tree[i]->data == data) {
                postorder(tree[i]);
                cout<<"\n";
            }
        }
    }
};

int main()
{
    int N,M;
    cin>>N;
    while(N--) {
        Tree tree = Tree(1);
        cin>>M;
        int p,d;
        while(M--) {
            cin>>p>>d;
            tree.insert(p,d);
        }
        tree.startPostorder(1);
    }
}
