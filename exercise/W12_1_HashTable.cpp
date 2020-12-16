////
////  W12_1_HashTable.cpp
////  INHA CLASS
////
////  Created by Kang Minsang on 2020/12/16.
////  Copyright © 2020 Kang Minsang. All rights reserved.
////
//
//#include <iostream>
//using namespace std;
//#define NOITEM 0
//#define ISITEM 1
//#define AVAILABLE 2
//class Cell {
//private:
//    int key;
//    int value;
//    int flag;
//public:
//    Cell() {
//        this->key = -1;
//        this->value = -1;
//        this->flag = NOITEM;
//    }
//    int getFlag() {
//        return flag;
//    }
//    int getKey() {
//        return key;
//    }
//    int getValue() {
//        return value;
//    }
//    void setFlag(int f) {
//        flag = f;
//    }
//    void setValue(int v) {
//        value = v;
//    }
//    void setKey(int k) {
//        key = k;
//    }
//};
//
//class HashTable {
//private:
//    Cell* CellArray;
//    int hashSize;
//    int curSize;
//public:
//    HashTable(int size) {
//        this->hashSize = size;
//        this->curSize = 0;
//        this->CellArray = new Cell[hashSize];
//    }
//
//    int size() {
//        return curSize;
//    }
//
//    int hashfunction(int key) {
//        return key%hashSize;
//    }
//    
//    void insert(int key, int value) {
//        int probing = 1;
//        int initial_idx = hashfunction(key);
//        int cur_idx = hashfunction(key);
//        bool isinitial = true;
//        while(CellArray[cur_idx].getFlag() != NOITEM) {
//            if(cur_idx == initial_idx && !isinitial) {
//                return;
//            }
//            else {
//                probing++;
//                isinitial = false;
//                cur_idx = (cur_idx+1)%hashSize;
//            }
//        }
//        CellArray[cur_idx].setKey(key);
//        CellArray[cur_idx].setValue(value);
//        CellArray[cur_idx].setFlag(ISITEM);
//    }
//
//    void print() {
//        for(int i=0; i<hashSize; i++) {
//            cout<<CellArray[i].getValue()<<" ";
//        }
//        cout<<"\n";
//    }
//};
//
//int main()
//{
//    int T;
//    cin>>T;
//    while(T--) {
//        int P;
//        cin>>P;
//        HashTable table = HashTable(P);
//        int Q;
//        cin>>Q;
//        int key;
//        while(Q--) {
//            cin>>key;
//            table.insert(key, key);
//        }
//        table.print();
//    }
//}
