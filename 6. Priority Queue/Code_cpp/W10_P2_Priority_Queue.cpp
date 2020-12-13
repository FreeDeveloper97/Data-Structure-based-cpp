////
////  W10_P2_Priority_Queue.cpp
////  INHA CLASS
////
////  Created by Kang Minsang on 2020/12/13.
////  Copyright © 2020 Kang Minsang. All rights reserved.
////
//
//#include <iostream>
//#include <string>
//#include <vector>
//
//using namespace std;
//enum direction { MIN = 1, MAX = -1}; //root의 특성을 결정, 크기비교시 곱해진다
//
//class Heap {
//private:
//    vector<int> v;
//    int heap_size; //현재 들어가 있는 개수
//    int root_index;
//    int direction; //root의 특성을 저장
//public:
//    Heap(int direction) {
//        v.push_back(-1); //0번째에 더미값을 넣는다
//        this->heap_size = 0;
//        this->root_index = 1; //upHeap에서 탈출하기 위한 index
//        this->direction = direction;
//    }
//    //두 위치를 변경한다
//    void swap(int idx1, int idx2) {
//        v[0] = v[idx1];
//        v[idx1] = v[idx2];
//        v[idx2] = v[0];
//    }
//    void upHeap(int idx) {
//        //탈출조건 : root노드인 경우 upHeap 종료한다
//        if(idx == root_index) {
//            return;
//        }
//        else {
//            int parent = idx/2;
//            if(v[parent]*direction > v[idx]*direction) {
//                swap(parent, idx); //자리바꾼다
//                upHeap(parent); //바뀐 자리에서 다시 비교를 시작한다
//            }
//        }
//    }
//
//    void downHeap(int idx) {
//        int left = idx*2;
//        int right = idx*2+1;
//        if(right <= heap_size) { // right도 존재하는 경우
//            if(v[left]*direction <= v[right]*direction) { // 자식 중에서 기준이 left인지 확인한다 (left가 작은값인지 확인)
//                if(v[left]*direction < v[idx]*direction) { // left값과 비교하여 idx 값이 큰경우 swap을 한다
//                    swap(left, idx); // swap을 진행한다
//                    downHeap(left); // 이동된 위치 left에서 다시 재귀함수를 진행한다
//                }
//                else {
//                    return; //left가 작지만, idx값은 큰경우 swap을 진행하지 않고 반환하여 종료한다
//                }
//            }
//            else { //기준이 right인 경우
//                if(v[right]*direction < v[idx]*direction) {
//                    swap(right, idx);
//                    downHeap(right);
//                }
//                else {
//                    return;
//                }
//            }
//        }//정상 범위 종료
//        else if(left <= heap_size) { //left만 있는 경우
//            if(v[left]*direction < v[idx]*direction) {
//                swap(left, idx);
//                downHeap(left);
//            }
//            else {
//                return;
//            }
//        }
//        else {
//            return;
//        }
//    }
//
//    void insert(int e) {
//        v.push_back(e);
//        heap_size++;
//        upHeap(heap_size); //e의 idx인 heap_size를 가지고 upHeap을 한다
//    }
//
//    int pop() { //root 내용 제거
//        if(!isEmpty()) {
//            int top = v[root_index]; //맨 위의 자료를 저장
//            v[root_index] = v[heap_size]; //root에 말단인 heap_size 위치값을 넣는다
//            heap_size--; //크기를 줄인다
//            v.pop_back(); //말단 내용을 제거한다
//            downHeap(root_index); //상단에 위치한 내용을 downHeap하며 자리를 찾는다
//            return top;
//        }
//        else {
//            return -1;
//        }
//
//    }
//
//    int top() {
//        if(!isEmpty()) {
//            return v[root_index];
//        }
//        else {
//            return -1;
//        }
//    }
//
//    int size() {
//        return heap_size;
//    }
//
//    int isEmpty() {
//        if(heap_size == 0) {
//            return 1;
//        }
//        else {
//            return 0;
//        }
//    }
//
//    void print() {
//        if(!isEmpty()) {
//            for(int i=root_index; i<heap_size; i++) { //최상단부터 프린트한다
//                cout<<v[i]<<" ";
//            }
//            cout<<v[heap_size]<<"\n";
//        }
//        else { // 자료가 없는 경우
//            cout<<-1<<endl;
//        }
//    }
//
//    int find(int x) {
//        if(!isEmpty()) {
//            return v.at(x);
//        }
//        else {
//            return -1;
//        }
//    }
//};
//
//int main() {
//    Heap priorityQueue = Heap(MIN);
//    int N;
//    cin>>N;
//    string question;
//    while(N--) {
//        cin>>question;
//        if(question == "isEmpty") {
//            cout<<priorityQueue.isEmpty()<<"\n";
//        }
//        else if(question == "top") {
//            cout<<priorityQueue.top()<<"\n";
//        }
//        else if(question == "insert") {
//            int e;
//            cin>>e;
//            priorityQueue.insert(e);
//        }
//        else if(question == "size") {
//            cout<<priorityQueue.size()<<"\n";
//        }
//        else if(question == "pop") {
//            cout<<priorityQueue.pop()<<"\n";
//        }
//        else if(question == "print") {
//            priorityQueue.print();
//        }
//    }
//
//}
