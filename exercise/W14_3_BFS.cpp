////
////  W14_3_BFS.cpp
////  INHA CLASS
////
////  Created by Kang Minsang on 2020/12/16.
////  Copyright © 2020 Kang Minsang. All rights reserved.
////
//
//#include <iostream>
//#include <vector>
//#include <queue>
//using namespace std;
//
//class vertex {
//public:
//    int data;
//    int degree;
//    bool visited;
//    vector<vertex*> adj_list;
//
//    vertex(int data) {
//        this->data = data;
//        this->degree = 0;
//        this->visited = false;
//    }
//};
//
//class edge {
//public:
//    vertex* src;
//    vertex* dst;
//
//    edge(vertex* insrc, vertex* indst) {
//        this->src = insrc;
//        this->dst = indst;
//    }
//};
//
//class Graph{
//private:
//    int size;
//    edge*** edgeMatrix;
//    vector<vertex*> vertexList;
//    vector<edge*> edgeList;
//public:
//    Graph(int size) {
//        this->size = size;
//        edgeMatrix = new edge**[size];
//        for(int i=0; i<size; i++) {
//            edgeMatrix[i] = new edge*[size];
//            for(int j=0; j<size; j++) {
//                edgeMatrix[i][j] = NULL;
//            }
//        }
//    }
//    vertex* findVertex(int data) {
//        vertex* result = NULL;
//        for(vertex* w : vertexList) {
//            if(w->data == data) {
//                result = w;
//                break;
//            }
//        }
//        return result;
//    }
//
//    void insertVertex(int data) {
//        if(findVertex(data) != NULL) {
//            //동일 vertex
//            return;
//        }
//        vertex* newVertex = new vertex(data);
//        vertexList.push_back(newVertex);
//    }
//
//    edge* findEdge(int in_src, int in_dst) {
//        int src = -1;
//        int dst = -1;
//        for(int i=0; i<vertexList.size(); i++) {
//            if(vertexList[i]->data == in_src) {
//                src = i;
//            }
//            if(vertexList[i]->data == in_dst) {
//                dst = i;
//            }
//            if(src != -1 && dst != -1) {
//                break;
//            }
//        }
//        edge* result = edgeMatrix[src][dst];
//        return result;
//    }
//
//    void insertEdge(int in_src, int in_dst) {
//        if(findEdge(in_src, in_dst) != NULL) {
//            //동일 edge
//            cout<<-1<<"\n";
//            return;
//        }
//        vertex* srcV = findVertex(in_src);
//        vertex* dstV = findVertex(in_dst);
//        int src = -1;
//        int dst = -1;
//        for(int i=0; i<vertexList.size(); i++) {
//            if(vertexList[i]->data == in_src) {
//                src = i;
//            }
//            if(vertexList[i]->data == in_dst) {
//                dst = i;
//            }
//            if(src != -1 && dst != -1) {
//                break;
//            }
//        }
//        edge* newEdge = new edge(srcV, dstV);
//        edgeMatrix[src][dst] = newEdge;
//        edgeMatrix[dst][src] = newEdge;
//        edgeList.push_back(newEdge);
//        srcV->adj_list.push_back(dstV);
//        dstV->adj_list.push_back(srcV);
//        srcV->degree++;
//        dstV->degree++;
//    }
//
//    void BFS(vertex* curV) {
//        queue<vertex*> q;
//        curV->visited = true;
//        q.push(curV);
//        while(!q.empty()) {
//            vertex* temp = q.front();
//            q.pop();
//            cout<<temp->data<<" ";
//            for(vertex* w : temp->adj_list) {
//                if(w->visited == false) {
//                    w->visited = true;
//                    q.push(w);
//                }
//            }
//        }
//    }
//
//    void startBFS(int start) {
//        BFS(findVertex(start));
//        cout<<"\n";
//    }
//};
//
//int main()
//{
//    int N,M,A;
//    cin>>N>>M>>A;
//    Graph graph = Graph(N);
//    int I;
//    while(N--) {
//        cin>>I;
//        graph.insertVertex(I);
//    }
//    int src, dst;
//    while(M--) {
//        cin>>src>>dst;
//        graph.insertEdge(src, dst);
//    }
//    graph.startBFS(A);
//}
