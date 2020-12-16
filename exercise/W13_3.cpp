//
//  W13_3.cpp
//  INHA CLASS
//
//  Created by Kang Minsang on 2020/12/16.
//  Copyright © 2020 Kang Minsang. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class vertex {
public:
    int data;
    int degree;
    bool visited;
    vector<vertex*> adj_list;

    vertex(int data) {
        this->data = data;
        this->degree = 0;
        this->visited = false;
    }
};

class edge{
public:
    vertex* src;
    vertex* dst;
    string data;

    edge(vertex* in_src, vertex* in_dst, string data) {
        this->src = in_src;
        this->dst = in_dst;
        this->data = data;
    }
};

class Graph {
private:
    int size;
    edge*** edgeMatrix;
    vector<vertex*> vertexList;
    vector<edge*> edgeList;
public:
    Graph(int size) {
        this->size = size;
        edgeMatrix = new edge**[size];
        for(int i=0; i<size; i++) {
            edgeMatrix[i] = new edge*[size];
            for(int j=0; j<size; j++) {
                edgeMatrix[i][j] = NULL;
            }
        }
    }

    vertex* findVertex(int data) {
        vertex* result = NULL;
        for(vertex* w : vertexList) {
            if(w->data == data) {
                result = w;
                break;
            }
        }
        return result;
    }

    edge* findEdge(int in_src, int in_dst) {
        int src = -1;
        int dst = -1;
        for(int i=0; i<vertexList.size(); i++) {
            if(vertexList[i]->data == in_src) {
                src = i;
            }
            if(vertexList[i]->data == in_dst) {
                dst = i;
            }
            if(src != -1 && dst != -1) {
                break;
            }
        }
        edge* result = edgeMatrix[src][dst];
        return result;
    }

    void insertVertex(int data) {
        if(findVertex(data) != NULL) {
            return;
        }
        vertex* newVertex = new vertex(data);
        vertexList.push_back(newVertex);
    }

    void insertEdge(int in_src, int in_dst, string data) {
        vertex* srcV = findVertex(in_src);
        vertex* dstV = findVertex(in_dst);
        if(srcV == NULL || dstV == NULL) {
            cout<<-1<<"\n";
            return;
        }
        if(findEdge(in_src, in_dst) != NULL) {
            cout<<-1<<"\n";
            return;
        }

        int src = -1;
        int dst = -1;
        for(int i=0; i<vertexList.size(); i++) {
            if(vertexList[i]->data == in_src) {
                src = i;
            }
            if(vertexList[i]->data == in_dst) {
                dst = i;
            }
            if(src != -1 && dst != -1) {
                break;
            }
        }
        edge* newEdge = new edge(srcV, dstV, data);
        edgeMatrix[src][dst] = newEdge;
        edgeMatrix[dst][src] = newEdge;
        edgeList.push_back(newEdge);
        srcV->adj_list.push_back(dstV);
        dstV->adj_list.push_back(srcV);
        srcV->degree++;
        dstV->degree++;
    }

    void print() {
        cout<<vertexList.size()<<" "<<edgeList.size()<<"\n";
    }
    
    void eraseVertex(int data) {
        vertex* v = findVertex(data);
        if(v == NULL) {
            cout<<-1<<"\n";
            return;
        }
        //v의 인덱스 src를 구한다
        int src=0;
        for(int i=0; i<vertexList.size(); i++) {
            if(vertexList[i]->data == data) {
                src = i;
                //vertexList에서 제거한다
                vertexList.erase(vertexList.begin()+i);
                break;
            }
        }
        //인접 vertex에서 adj_list 내의 v를 삭제한다
        for(vertex* w : v->adj_list) {
            for(int i=0; i<w->adj_list.size(); i++) {
                if(w->adj_list[i]->data == v->data) {
                    w->adj_list.erase(w->adj_list.begin()+i);
                    break;
                }
            }
        }
        //v에 연결된 edge를 삭제한다
        eraseEdge(v, src);
        //출력한다
        cout<<edgeList.size()<<" ";
        for(int i=0; i<edgeList.size(); i++) {
            cout<<edgeList[i]->data<<" ";
        }
        cout<<"\n";
    }
    
    void eraseEdge(vertex* v, int src) {
        for(int i=0; i<size; i++) {
            if(edgeMatrix[src][i] != NULL) {
                //edgeList에서 제거한다
                for(int j=0; j<edgeList.size(); j++) {
                    if(edgeList[j] == edgeMatrix[src][i]) {
                        edgeList.erase(edgeList.begin()+j);
                        break;
                    }
                }
                //matrix에서 제거한다
                edgeMatrix[src][i] = NULL;
                edgeMatrix[i][src] = NULL;
            }
        }
    }
};

int main()
{
    int N, M, K;
    cin>>N>>M>>K;
    Graph graph = Graph(N);
    int I;
    while(N--) {
        cin>>I;
        graph.insertVertex(I);
    }
    int src, dst;
    string data;
    while(M--) {
        cin>>src>>dst>>data;
        graph.insertEdge(src, dst, data);
    }
    graph.print();
    while(K--) {
        cin>>src;
        graph.eraseVertex(src);
    }
}
