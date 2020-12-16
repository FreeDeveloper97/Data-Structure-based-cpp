////
////  W14_2_DFS.cpp
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
//    int data;
//
//    edge(vertex* src, vertex* dst) {
//        this->src = src;
//        this->dst = dst;
//    }
//};
//
//class Graph {
//private:
//    edge*** edgeMatrix;
//    vector<vertex*> vertex_list;
//    vector<edge*> edge_list;
//    int size;
//public:
//    Graph(int size) {
//        this->size = size;
//        this->edgeMatrix = new edge**[size];
//        for(int i=0; i<size; i++) {
//            edgeMatrix[i] = new edge*[size];
//            for(int j=0; j<size; j++) {
//                edgeMatrix[i][j] = NULL;
//            }
//        }
//    }
//
//    vertex* findvertex(int data) {
//        vertex* result = NULL;
//        for(int i=0; i<vertex_list.size(); i++) {
//            if(vertex_list[i]->data == data) {
//                result = vertex_list[i];
//                break;
//            }
//        }
//        return result;
//    }
//
//    edge* findedge(int input_src, int input_dst) {
//        int src = -1;
//        int dst = -1;
//        for(int i=0; i<vertex_list.size(); i++) {
//            if(vertex_list[i]->data == input_src) {
//                src = i;
//            }
//            if(vertex_list[i]->data == input_dst) {
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
//    void insertVertex(int data) {
//        if(findvertex(data) != NULL) {
//            //동일 vertex가 존재하는 경우
//            return;
//        }
//        vertex* newVertex = new vertex(data);
//        vertex_list.push_back(newVertex);
//    }
//
//    void insertEdge(int input_src, int input_dst) {
//        vertex* srcV = findvertex(input_src);
//        vertex* dstV = findvertex(input_dst);
//        int src = -1;
//        int dst = -1;
//        for(int i=0; i<vertex_list.size(); i++) {
//            if(vertex_list[i]->data == input_src) {
//                src = i;
//            }
//            if(vertex_list[i]->data == input_dst) {
//                dst = i;
//            }
//            if(src != -1 && dst != -1) {
//                break;
//            }
//        }
//        if(findedge(input_src, input_dst) != NULL) {
//            //해당 edge가 존재하는 경우
//            cout<<-1<<"\n";
//            return;
//        }
//        else {
//            edge* newEdge = new edge(srcV, dstV);
//            edge_list.push_back(newEdge);
//            edgeMatrix[src][dst] = newEdge;
//            edgeMatrix[dst][src] = newEdge;
//            srcV->adj_list.push_back(dstV);
//            dstV->adj_list.push_back(srcV);
//            srcV->degree++;
//            dstV->degree++;
//        }
//    }
//
//    void DFS(vertex* curV) {
//        curV->visited = true;
//        cout<<curV->data<<" ";
//        for(vertex* w : curV->adj_list) {
//            if(w->visited == false) {
//                DFS(w);
//            }
//        }
//    }
//
//    void startDFS(int start) {
//        DFS(findvertex(start));
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
//    graph.startDFS(A);
//}
