////
////  W10_1_MaxHeap.cpp
////  INHA CLASS
////
////  Created by Kang Minsang on 2020/12/15.
////  Copyright © 2020 Kang Minsang. All rights reserved.
////
//
//#include <iostream>
//#include <vector>
//using namespace std;
//enum direction {MIN = 1, MAX = -1};
//
//class Heap {
//private:
//    vector<int> v;
//    int root_idx;
//    int heap_size;
//    int direction;
//public:
//
//    Heap(int direction) {
//        this->v.push_back(-1);
//        this->root_idx = 1;
//        this->heap_size = 0;
//        this->direction = direction;
//    }
//
//    int size() {
//        return heap_size;
//    }
//
//    int isEmpty() {
//        if(size() == 0) {
//            return 1;
//        } else {
//            return 0;
//        }
//    }
//
//    int top() {
//        if(!isEmpty()) {
//            return v[root_idx];
//        }
//        else {
//            return -1;
//        }
//    }
//
//    void swap(int idx1, int idx2) {
//        v[0] = v[idx1];
//        v[idx1] = v[idx2];
//        v[idx2] = v[0];
//    }
//
//    void upHeap(int idx) {
//        if(idx == root_idx) {
//            return;
//        }
//        int parent = idx/2;
//        if(v[parent]*direction > v[idx]*direction) {
//            swap(parent, idx);
//            upHeap(parent);
//        }
//    }
//
//    void downHeap(int idx) {
//        int left = idx*2;
//        int right = idx*2+1;
//        if(right <= heap_size) {
//            //기준점
//            if(v[left]*direction <= v[right]*direction) {
//                //비교
//                if(v[left]*direction < v[idx]*direction) {
//                    swap(left, idx);
//                    downHeap(left);
//                }
//            }
//            else {
//                if(v[right]*direction < v[idx]*direction) {
//                    swap(right, idx);
//                    downHeap(right);
//                }
//            }
//        }
//        else if(left <= heap_size){
//            if(v[left]*direction < v[idx]*direction) {
//                swap(left, idx);
//                downHeap(left);
//            }
//        }
//    }
//
//    void insert(int e) {
//        for(int i=root_idx; i<=heap_size; i++) {
//            if(v[i] == e) {
//                cout<<-1<<"\n";
//                return;
//            }
//        }
//        heap_size++;
//        v.push_back(e);
//        upHeap(heap_size);
//    }
//
//    int pop() {
//        if(!isEmpty()) {
//            int top = v[root_idx];
//            v[root_idx] = v[heap_size];
//            heap_size--;
//            v.pop_back();
//            downHeap(root_idx);
//            return top;
//        }
//        else {
//            return -1;
//        }
//    }
//
//    void print() {
//        if(isEmpty()) {
//            cout<<-1<<"\n";
//        }
//        else {
//            for(int i=root_idx; i<=heap_size; i++) {
//                cout<<v[i]<<" ";
//            }
//            cout<<"\n";
//        }
//    }
//};
//
//int main()
//{
//    Heap heap = Heap(MAX);
//    int N;
//    cin>>N;
//    string q;
//    while(N--) {
//        cin>>q;
//        if(q == "isEmpty") {
//            cout<<heap.isEmpty()<<"\n";
//        }
//        else if(q == "insert") {
//            int e;
//            cin>>e;
//            heap.insert(e);
//        }
//        else if(q == "pop") {
//            cout<<heap.pop()<<"\n";
//        }
//        else if(q == "size") {
//            cout<<heap.size()<<"\n";
//        }
//        else if(q == "top") {
//            cout<<heap.top()<<"\n";
//        }
//        else if(q == "print") {
//            heap.print();
//        }
//    }
//}
