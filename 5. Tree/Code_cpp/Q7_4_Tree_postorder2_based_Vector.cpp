//
//  Q7_4_Tree_postorder2_based_Vector.cpp
//  INHA CLASS
//
//  Created by Kang Minsang on 2020/10/28.
//  Copyright © 2020 Kang Minsang. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
// postorder 구현, 특정노드의 postorder 하며 leaf 노드의 경우 data 출력

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

    void addChild(Node* p) {
        child_vector.push_back(p);
    }
};

class Tree {
public:
    Node* root;
    vector<Node*> tree;

    Tree(int data) {
        this->root = new Node(data);
        tree.push_back(root);
    }

    int size() {
        int size = (int)tree.size();
        return size;
    }

    void insert(int p, int d) {
        for(int i=0; i<size(); i++) {
            if(tree[i]->data == p) {
                Node* v = new Node(d);
                v->setParent(tree[i]);
                tree[i]->addChild(v);
                tree.push_back(v);
                return;
            }
        }
    }

    void postorder(Node* p) {
        if(p->child_vector.size() == 0) {
            cout<<p->data<<" ";
            return;
        }
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
    int N;
    cin>>N;
    while(N--) {
        Tree tree = Tree(1);
        int M,target,p,d;
        cin>>M>>target;
        while(M--) {
            cin>>p>>d;
            tree.insert(p, d);
        }
        tree.startPostorder(target);
    }
}
