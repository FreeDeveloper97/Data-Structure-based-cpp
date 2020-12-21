//
//  3.cpp
//  FinalTest
//
//  Created by Kang Minsang on 2020/12/18.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class vertex {
public:
    int data;
    bool visited;
    vector<vertex*> adj_list;

    vertex(int data) {
        this->data = data;
        this->visited = false;
    }
};

class edge {
public:
    vertex* src;
    vertex* dst;

    edge(vertex* in_src, vertex* in_dst) {
        this->src = in_src;
        this->dst = in_dst;
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
        vertex* newVertex = new vertex(data);
        vertexList.push_back(newVertex);
    }

    void insertEdge(int in_src, int in_dst) {
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
        vertex* srcV = findVertex(in_src);
        vertex* dstV = findVertex(in_dst);
        edge* newEdge = new edge(srcV, dstV);
        edgeMatrix[src][dst] = newEdge;
        edgeMatrix[dst][src] = newEdge;
        edgeList.push_back(newEdge);
        srcV->adj_list.push_back(dstV);
        dstV->adj_list.push_back(srcV);
    }

    void printBFS(vertex* v) {
        queue<vertex*> q;
        v->visited = true;
        q.push(v);
        while(!q.empty()) {
            vertex* temp = q.front();
            q.pop();
            cout<<temp->data<<" ";
            for(vertex* w : temp->adj_list) {
                if(w->visited == false) {
                    w->visited = true;
                    q.push(w);
                }
            }
        }
    }

    void startBFS(int A) {
        printBFS(findVertex(A));
        cout<<"\n";
    }
};

int main()
{
    int N, M, A;
    cin>>N>>M>>A;
    Graph graph = Graph(N);
    int I;
    while(N--) {
        cin>>I;
        graph.insertVertex(I);
    }
    int src, dst;
    while(M--) {
        cin>>src>>dst;
        graph.insertEdge(src, dst);
    }
    graph.startBFS(A);
}
