//
//  1.cpp
//  FinalTest
//
//  Created by Kang Minsang on 2020/12/18.
//

#include <iostream>
#include <vector>
using namespace std;

class Heap {
private:
    int heap_size;
    int root_idx;
    vector<int> v;
public:
    Heap() {
        this->heap_size = 0;
        v.push_back(-1);
        this->root_idx = 1;
    }

    void swap(int idx1, int idx2) {
        v[0] = v[idx1];
        v[idx1] = v[idx2];
        v[idx2] = v[0];
    }
    
    void upHeap(int idx) {
        if(idx == root_idx) {
            return;
        }
        int parent = idx/2;
        if(v[idx] < v[parent]) {
            swap(idx, parent);
            upHeap(parent);
        }
    }
    
    void downHeap(int idx) {
        int left = idx*2;
        int right = idx*2+1;
        if(right<= heap_size) {
            if(v[left] <= v[right]) {
                if(v[idx] > v[left]) {
                    swap(idx, left);
                    downHeap(left);
                }
            }
            else {
                if(v[idx] > v[right]) {
                    swap(idx, right);
                    downHeap(right);
                }
            }
        }
        else if(left <= heap_size) {
            if(v[idx] > v[left]) {
                swap(idx, left);
                downHeap(left);
            }
        }
    }
    
    int find(int data) {
        int result = -1;
        for(int i=root_idx; i<=heap_size; i++) {
            if(v[i] == data) {
                result = i;
                break;
            }
        }
        return result;
    }
    
    void erase(int data) {
        while(v[root_idx] != data) {
            pop();
            downHeap(root_idx);
        }
        pop();
        downHeap(root_idx);
        print();
    }
    
    void pop() {
        swap(root_idx, heap_size);
        heap_size--;
        v.pop_back();
    }

    void insert(int data) {
        heap_size++;
        v.push_back(data);
        upHeap(heap_size);
    }
    
    void print() {
        if(heap_size == 0) {
            cout<<"Empty\n";
            return;
        }
        for(int i=root_idx; i<=heap_size; i++) {
            cout<<v[i]<<" ";
        }
        cout<<"\n";
    }
};

int main()
{
    int T;
    cin>>T;
    while(T--) {
        int N;
        cin>>N;
        Heap heap = Heap();
        int data;
        while(N--) {
            cin>>data;
            heap.insert(data);
        }
        int P;
        cin>>P;
        heap.erase(P);
    }
}
