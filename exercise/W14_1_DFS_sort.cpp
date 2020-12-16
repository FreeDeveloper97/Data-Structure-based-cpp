////
////  W14_1_DFS_sort.cpp
////  INHA CLASS
////
////  Created by Kang Minsang on 2020/12/16.
////  Copyright © 2020 Kang Minsang. All rights reserved.
////
//
//#include <iostream>
//#include <vector>
//using namespace std;
//
//class vertex {
//public:
//    int data;
//    int degree;
//    bool visited;
//    char c;
//    vector<vertex*> adj_list;
//
//    vertex(int data, char c) {
//        this->data = data;
//        this->degree = 0;
//        this->visited = false;
//        this->c = c;
//    }
//};
//
//class edge {
//public:
//    vertex* src;
//    vertex* dst;
//
//    edge(vertex* in_src, vertex* in_dst) {
//        this->src = in_src;
//        this->dst = in_dst;
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
//
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
//    void insertVertex(int data, char c) {
//        if(findVertex(data) != NULL) {
//            //동일 vertex
//            return;
//        }
//        vertex* newVertex = new vertex(data, c);
//        vertexList.push_back(newVertex);
//    }
//
//    void insertEdge(int in_src, int in_dst) {
//        if(findEdge(in_src, in_dst) != NULL) {
//            //동일 edge
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
//        srcV->adj_list.push_back(dstV);
//        dstV->adj_list.push_back(srcV);
//        srcV->degree++;
//        dstV->degree++;
//    }
//
//    void sort_adj_list(vertex* v) {
//        for(int i=0; i<v->adj_list.size()-1; i++) {
//            for(int j=i+1; j<v->adj_list.size(); j++) {
//                if(v->adj_list[i]->data > v->adj_list[j]->data) {
//                    vertex* temp = v->adj_list[i];
//                    v->adj_list[i] = v->adj_list[j];
//                    v->adj_list[j] = temp;
//                }
//            }
//        }
//    }
//
//    void sort_vertex() {
//        for(int i=0; i<vertexList.size(); i++) {
//            sort_adj_list(vertexList[i]);
//        }
//    }
//
//    void DFS(vertex* v) {
//        v->visited = true;
//        cout<<v->c;
//        for(vertex* w : v->adj_list) {
//            if(w->visited == false) {
//                DFS(w);
//            }
//        }
//    }
//
//    void startDFS(int k) {
//        sort_vertex();
//        DFS(findVertex(k));
//        cout<<"\n";
//    }
//};
//
//int main()
//{
//    int N, M, K;
//    cin>>N>>M>>K;
//    Graph graph = Graph(N);
//    int I;
//    char C;
//    while(N--) {
//        cin>>I>>C;
//        graph.insertVertex(I, C);
//    }
//    int src, dst;
//    while(M--) {
//        cin>>src>>dst;
//        graph.insertEdge(src, dst);
//    }
//    graph.startDFS(K);
//}
