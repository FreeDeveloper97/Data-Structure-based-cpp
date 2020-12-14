//
//  W14_P1_Graph_DFS.cpp
//  INHA CLASS
//
//  Created by Kang Minsang on 2020/12/14.
//  Copyright © 2020 Kang Minsang. All rights reserved.
//

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
using namespace std;


#define NOT_EXPLORED 0
#define DISCOVERY 1
#define BACK 2
class vertex {
public:
    int data;
    int degree;
    bool visited;
    char C;
    vector <vertex*> adj_list;
    vertex(int data, char C) {
        this->data = data;
        this->degree = 0;
        this->visited = false;
        this->C = C;
    }
};

class edge {
public:
    vertex* src;
    vertex* dst;
    int data;
    bool edge_stat;
    edge(vertex* src, vertex* dst) {
        this->src = src;
        this->dst = dst;
        this->edge_stat = NOT_EXPLORED;
    }
};

#define vertexRange 1000
class graph {
public:
    edge*** edgeMatrix;
    vector<vertex*> vertex_list;
    vector<edge*> edge_list;
    queue<vertex*> q;
    graph() {
        edgeMatrix = new edge **[vertexRange];
        for (int i = 0; i < vertexRange; i++) {
            edgeMatrix[i] = new edge * [vertexRange];
            for (int j = 0; j < vertexRange; j++) {
                edgeMatrix[i][j] = NULL;
            }
        }
    }

    vertex* findvertex(int data) {
        vertex* v = NULL;
        for (int i = 0; i < vertex_list.size(); i++) {
            if (vertex_list[i]->data == data) {
                v = vertex_list[i];
                break;
            }
        }
        return v;
    }
    
    edge* findedge(int src, int dst) {
        int _src = NULL, _dst = NULL;
        for (int i = 0; i < vertex_list.size(); i++) {
            if (vertex_list[i]->data == src) {
                _src = i;
            }
            if (vertex_list[i]->data == dst) {
                _dst = i;
            }
        }
        if (edgeMatrix[_src][_dst] == NULL) {
            return NULL;
        }
        else {
            return edgeMatrix[_src][_dst];
        }
    }

    void insert_vertex(int n, char C) {
        if (findvertex(n) != NULL) {
            return;
        }

        else {
            int size = vertex_list.size();
            vertex* newVertex = new vertex(n,C);
            vertex_list.push_back(newVertex);
        }
    }

    void insert_edge(int source, int destination) {
        vertex* src = findvertex(source);
        vertex* dst = findvertex(destination);
        int _src = NULL, _dst = NULL;
        for (int i = 0; i < vertex_list.size(); i++) {
            if (vertex_list[i]->data == source) {
                _src = i;
            }
            if (vertex_list[i]->data == destination) {
                _dst = i;
            }
        }
        if (findedge(source, destination) == NULL) {
            edge* new_e = new edge(src, dst);
            edge_list.push_back(new_e);
            edgeMatrix[_src][_dst] = new_e;
            edgeMatrix[_dst][_src] = new_e;
            src->adj_list.push_back(dst);
            dst->adj_list.push_back(src);
        }
        else {
            return;
        }
        src->degree++;
        dst->degree++;
    }

    void DFS(vertex* curV) {
        //학생들이 직접 작성하세요
        curV->visited = true;
        cout<<curV->C;

        //정점 번호가 낮은순으로 탐색
        vector <vertex*> list_sort;
        int N = curV->adj_list.size();
        while(N--) {
            int min = 501;
            //최소값 찾기
            for(int i=0; i<curV->adj_list.size(); i++) {
                if(curV->adj_list[i]->data < min) {
                    min = curV->adj_list[i]->data;
                }
            }
            //최소값 해당 vertex 넣기
            for(int i=0; i<curV->adj_list.size(); i++) {
                if(curV->adj_list[i]->data == min) {
                    list_sort.push_back(curV->adj_list[i]);
                    curV->adj_list.erase(curV->adj_list.begin()+i);
                    break;
                }
            }
        }
        curV->adj_list = list_sort;
        //최소값 순으로 정렬된 list_sort
        for(int i=0; i<curV->adj_list.size(); i++) {
            if(list_sort[i]->visited == false) {
                DFS(list_sort[i]);
            }
        }
    }

    void startDFS(int start) {
        DFS(findvertex(start));
    }
};

int main() {
    graph g = graph();
    int N,M,K;
    cin>>N>>M>>K;
    int I;
    char C;
    while(N--) {
        cin>>I>>C;
        g.insert_vertex(I, C);
    }
    int S,D;
    while(M--) {
        cin>>S>>D;
        g.insert_edge(S, D);
    }
    g.startDFS(K);
}
