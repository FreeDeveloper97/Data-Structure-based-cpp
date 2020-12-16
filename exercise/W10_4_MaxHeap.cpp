////
////  W10_4_MaxHeap.cpp
////  INHA CLASS
////
////  Created by Kang Minsang on 2020/12/15.
////  Copyright © 2020 Kang Minsang. All rights reserved.
////
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//enum directrion {MIN=1, MAX=-1};
//
//class Heap {
//private:
//    vector<int> v;
//    int root_idx;
//    int heap_size;
//    int direction;
//    int count;
//public:
//    Heap(int direction) {
//        this->v.push_back(-1);
//        this->root_idx = 1;
//        this->heap_size = 0;
//        this->direction = direction;
//        this->count = 0;
//    }
//
//    bool isEmpty() {
//        return heap_size == 0;
//    }
//
//    void swap(int idx1, int idx2) {
//        v[0] = v[idx1];
//        v[idx1] = v[idx2];
//        v[idx2] = v[0];
//    }
//
//    void upHeap(int idx) {
//        count++;
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
//            if(v[left]*direction <= v[right]*direction) {
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
//        else if(left <= heap_size) {
//            if(v[left]*direction < v[idx]*direction) {
//                swap(left, idx);
//                downHeap(left);
//            }
//        }
//    }
//
//    void insert(int e) {
//        heap_size++;
//        v.push_back(e);
//        upHeap(heap_size);
//    }
//
//    void print() {
//        for(int i=root_idx; i<=heap_size; i++) {
//            cout<<v[i]<<" ";
//        }
//        cout<<"\n";
//    }
//
//    int getCount() {
//        return count;
//    }
//
//    void getValue(int p) {
//        cout<<v[p]<<"\n";
//    }
//
//    void sortting() {
//        sort(v.begin()+1, v.end(), greater<int>());
//    }
//};
//
//int main()
//{
//    int count = 0;
//    int T;
//    cin>>T;
//    while(T--) {
//        Heap heap = Heap(MAX);
//        int N, p;
//        cin>>N>>p;
//        int e;
//        while(N--) {
//            cin>>e;
//            heap.insert(e);
//        }
//        heap.print();
//        heap.getValue(p);
//        heap.sortting();
//        heap.getValue(p);
//        count += heap.getCount();
//        cout<<count<<"\n";
//    }
//}
//
