//
//  W13_P3_Graph_Matrix.cpp
//  INHA CLASS
//
//  Created by Kang Minsang on 2020/12/14.
//  Copyright © 2020 Kang Minsang. All rights reserved.
//

#include <iostream>
#include <string>
#define MappingSize 501
using namespace std;

class vertex {
public:
    vertex *prev;
    vertex *next;
    int degree;
    int data;
    
    vertex(int data) {
        this->degree = 0;
        this->data = data;
    }
    
    void incress_degree() {
        this->degree++;
    }
    
    void decress_degree() {
        this->degree--;
    }
};

class edge {
public:
    edge* prev;
    edge* next;
    vertex* source;
    vertex* destination;
    string data;
    
    edge(vertex* a, vertex* b, string data) {
        this->source = a;
        this->destination = b;
        this->data = data;
    }
};

class DoublyVertexLinkedList {
public:
    vertex* head;
    vertex* tail;
    
    DoublyVertexLinkedList() {
        this->head = NULL;
        this->tail = NULL;
    }
    
    void insert(vertex* insertVertex) {
        if(this->head == NULL) {
            head = insertVertex;
            tail = insertVertex;
        }
        else {
            tail->next = insertVertex;
            insertVertex->prev = tail;
            tail = insertVertex;
        }
    }
    
    void remove(vertex* delVertex) {
        if(delVertex == head || delVertex == tail) {
            //head 삭제
            if(delVertex == head && delVertex != tail) {
                vertex* temp = head;
                head = head->next;
                head->prev = NULL;
                delete temp;
            }
            //tail 삭제
            else if(delVertex == tail && delVertex != head) {
                vertex* temp = tail;
                tail = tail->prev;
                tail->next = NULL;
                delete temp;
            }
            else {
                head = tail = NULL;
            }
        }
        else {
            delVertex->prev->next = delVertex->next;
            delVertex->next->prev = delVertex->prev;
            delete delVertex;
        }
    }
};

class DoublyEdgeLinkedList {
public:
    edge* head;
    edge* tail;
    
    DoublyEdgeLinkedList() {
        this->head = NULL;
        this->tail = NULL;
    }
    
    void insert(edge* insertEdge) {
        if(this->head == NULL) {
            head = insertEdge;
            tail = insertEdge;
        }
        else {
            tail->next = insertEdge;
            insertEdge->prev = tail;
            tail = insertEdge;
        }
    }
    
    void remove(edge* delEdge) {
        if(delEdge == head || delEdge == tail) {
            if(delEdge == head && delEdge != tail) {
                edge* temp = head;
                head = head->next;
                head->prev = NULL;
                delete temp;
            }
            else if(delEdge == tail && delEdge != head) {
                edge* temp = tail;
                tail = tail->prev;
                tail->next = NULL;
                delete temp;
            }
            else {
                head = tail = NULL;
            }
        }
        else {
            delEdge->prev->next = delEdge->next;
            delEdge->next->prev = delEdge->prev;
            delete delEdge;
        }
    }
    
    int EdgeCount() {
        int count = 0;
        edge* temp = this->head;
        while(temp != NULL) {
            temp = temp->next;
            count++;
        }
        return count;
    }
};

class Graph {
public:
    edge*** edgeMatrix; //N*N 크기의 Edge를 저장하는 Matrix
    DoublyVertexLinkedList *VertexList;
    DoublyEdgeLinkedList *EdgeList;
    int vertexSize; //현재 개수
    int mappingTable[MappingSize]; //Matrix의 index <-> Vertex의 data를 연결해주는 연결고리
    
    Graph() {
        this->edgeMatrix = new edge**[1];
        this->edgeMatrix[0] = new edge*[1];
        this->edgeMatrix[0][0] = NULL;
        this->VertexList = new DoublyVertexLinkedList();
        this->EdgeList = new DoublyEdgeLinkedList();
        this->vertexSize = 0;
        for(int i=0; i<MappingSize; i++) { //연결고리 table의 초기화 : -1로 저장
            mappingTable[i] = -1;
        }
    }
    
    bool isfindVertex(int n) {
        bool flag = false;
        vertex* temp = VertexList->head;
        while(temp != NULL) {
            if(temp->data == n) {
                flag = true;
                break;
            }
            temp = temp->next;
        }
//        cout<<"catch\n";
        return flag;
    }
    
    vertex* findVertex(int n) {
        vertex* temp = VertexList->head;
        while(temp != NULL) {
            if(temp->data == n) {
                break;
            }
            temp = temp->next;
        }
        return temp; //있는경우 해당 vertex 반환, 없는경우 NULL 반환
    }
    
    void insert_vertex(int n) {
        //n이 이미 존재하는 경우 종료
        if(isfindVertex(n)) {
            return;
        }
        else {
            //N+1 * N+1 크기의 tempMatrix 생성
            edge*** tempMatrix = new edge**[vertexSize+1];
            for(int i=0; i<vertexSize+1; i++) {
                tempMatrix[i] = new edge*[vertexSize+1];
                for(int j=0; j<vertexSize+1; j++) {
                    tempMatrix[i][j] = NULL;
                }
            }
            //edgeMatrix -> tempMatrix로 붙여넣기
            for(int i=0; i<vertexSize; i++) {
                for(int j=0; j<vertexSize; j++) {
                    tempMatrix[i][j] = edgeMatrix[i][j];
                }
            }
            //edgeMatrix : tempMatrix로 수정
            edgeMatrix = tempMatrix;
            
            //여기서부터 insert 시작
            vertex* newVertex = new vertex(n);
            //list에 추가
            VertexList->insert(newVertex);
            //개수 증가
            this->vertexSize++;
            //index : vertexSize-1 <-> data : n 대응을 table에 넣기
            mappingTable[vertexSize-1] = n;
        }
    }
    
    void erase_vertex(int n) {
        //존재하지 않거나 개수가 0개인 경우 종료
        if(!isfindVertex(n) || vertexSize == 0) {
            cout<<-1<<"\n";
            return;
        }
        else {
            //N-1 * N-1 크기의 tempMatrix 생성
            edge*** tempMatrix = new edge**[vertexSize-1];
            for(int i=0; i<vertexSize-1; i++) {
                tempMatrix[i] = new edge*[vertexSize-1];
                for(int j=0; j<vertexSize-1; j++) {
                    tempMatrix[i][j] = NULL;
                }
            }
            //삭제될 vertex의 index 찾기
            int middleIdx = 0;
            for(int i=0; i<vertexSize; i++) {
                if(mappingTable[i] == n) {
                    middleIdx = i;
                }
            }
            //mappingTable 한칸씩 앞당기기
            for(int i=middleIdx; i<vertexSize; i++) {
                mappingTable[i] = mappingTable[i+1];
            }
            //EdgeList 에서 삭제 vertex와 연결된 Edge를 삭제한다
            //edgeMatrix 에서 삭제 행 중에서 열값중에 연결된 Edge가 있는경우 해당 Edge를 list에서 제거한다
            for(int i=0; i<vertexSize; i++) {
                if(this->edgeMatrix[middleIdx][i] != NULL) {
                    EdgeList->remove(this->edgeMatrix[middleIdx][i]);
                }
            }
            //tempMatrix로 옮기기
            for(int i=0; i<vertexSize; i++) {
                for(int j=0; j<vertexSize; j++) {
                    //안전지대 : 그대로 붙여넣기
                    if(i<middleIdx && j<middleIdx) {
                        tempMatrix[i][j] = edgeMatrix[i][j];
                    }
                    //대각선으로 이동, 붙여넣기
                    else if(i>middleIdx && j>middleIdx) {
                        tempMatrix[i-1][j-1] = edgeMatrix[i][j];
                    }
                    //열 땡겨서 붙여넣기
                    else if(j>middleIdx) {
                        tempMatrix[i][j-1] = edgeMatrix[i][j];
                    }
                    //행 땡겨서 붙여넣기
                    else if(i>middleIdx) {
                        tempMatrix[i-1][j] = edgeMatrix[i][j];
                    }
                }
            }
            //수정된 Matrix로 저장
            this->edgeMatrix = tempMatrix;
            //마지막으로 삭제 vertex를 VertexList에서 삭제
            VertexList->remove(findVertex(n));
            //크기줄이기
            vertexSize--;
            
            printEdge();
        }
    }
    
    void insert_Edge(int inputSource, int inputDestination, string data) {
        //해당 vertex가 없는경우 종료
        if(!isfindVertex(inputSource) || !isfindVertex(inputDestination)) {
            cout<<-1<<"\n";
            return;
        }
        else {
            //source, destination 값에 맞는 vertex의 index를 각각 저장
            int source = -1;
            int destination = -1;
            for(int i=0; i<=vertexSize; i++) {
                if(mappingTable[i] == inputSource) {
                    source = i;
                }
                if(mappingTable[i] == inputDestination) {
                    destination = i;
                }
                if(source != -1 && destination != -1) {
                    break;
                }
            }
            //Matrix에서 해당 Edge가 이미 존재하는 경우 : 종료 후 반환
            if(edgeMatrix[source][destination] != NULL || edgeMatrix[destination][source] != NULL) {
                cout<<-1<<"\n";
                return;
            }
            
            //여기서부터 insert 시작
            //Edge 생성
            edge* newEdge = new edge(findVertex(inputSource), findVertex(inputDestination), data);
            //해당 행, 열에 Edge 추가
            edgeMatrix[source][destination] = newEdge;
            edgeMatrix[destination][source] = newEdge;
            //두 vertex의 degree 증가
            findVertex(inputSource)->incress_degree();
            findVertex(inputDestination)->incress_degree();
            //최종적으로 새로운 Edge를 EdgeList에 추가
            EdgeList->insert(newEdge);
        }
    }
    
    void erase_edge(int inputSource, int inputDestination) {
        int source = -1;
        int destination = -1;
        //source, destination 값에 맞는 vertex의 각 index 구하여 저장
        for(int i=0; i<=vertexSize; i++) {
            if(mappingTable[i] == inputSource) {
                source = i;
            }
            if(mappingTable[i] == inputDestination) {
                destination = i;
            }
            if(source != -1 && destination != -1) {
                break;
            }
        }
        //이미 삭제되어 없는경우 : 종료
        if(edgeMatrix[source][destination] == NULL || edgeMatrix[destination][source] == NULL) {
            return;
        }
        //여기서부터 삭제 시작
        //해당 vertex들의 degree 감소
        findVertex(inputSource)->decress_degree();
        findVertex(inputDestination)->decress_degree();
        //해당 Edge를 EdgeList에서 제거
        edge* delEdge = edgeMatrix[source][destination];
        EdgeList->remove(delEdge);
        edgeMatrix[source][destination] = NULL;
        edgeMatrix[destination][source] = NULL;
    }
    
    void printSize() {
        int verCount;
        int edgCount;
        verCount = vertexSize;
        edgCount = EdgeList->EdgeCount();
        cout<<verCount<<" "<<edgCount<<"\n";
    }
    
    void isAdjacent(int inputSource, int inputDestination) {
        vertex* A = findVertex(inputSource);
        vertex* B = findVertex(inputDestination);
        if(A == NULL || B == NULL) {
            cout<<-1<<"\n";
            return;
        }
        int source = -1;
        int destination = -1;
        //source, destination 값에 맞는 vertex의 각 index 구하여 저장
        for(int i=0; i<=vertexSize; i++) {
            if(mappingTable[i] == inputSource) {
                source = i;
            }
            if(mappingTable[i] == inputDestination) {
                destination = i;
            }
            if(source != -1 && destination != -1) {
                break;
            }
        }
        edge* temp = edgeMatrix[source][destination];
        edge* temp2 = edgeMatrix[destination][source];
        if(temp != NULL && temp!= NULL && temp == temp2) {
            cout<<1<<"\n";
            return;
        }
        else {
            cout<<0<<"\n";
            return;
        }
    }
    
    void printEdge() {
        int edgCount = EdgeList->EdgeCount();
        cout<<edgCount<<" ";
        edge* temp = EdgeList->head;
        while(temp != NULL) {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<"\n";
    }
};

int main()
{
    Graph graph = Graph();
    int N, M, K;
    cin>>N>>M>>K;
    int I;
    while(N--) {
        cin>>I;
        graph.insert_vertex(I);
    }
    int S, D;
    string U;
    while(M--) {
        cin>>S>>D>>U;
        graph.insert_Edge(S, D, U);
    }
    graph.printSize();
    while(K--) {
        cin>>I;
        graph.erase_vertex(I);
    }
}
