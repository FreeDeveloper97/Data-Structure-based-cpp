////
////  W12_2_HashTable_Double.cpp
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
//
//class Cell {
//public:
//    int key;
//    int value;
//    int flag;
//    Cell() {
//        this->key = -1;
//        this->value = -1;
//        this->flag = NOITEM;
//    }
//};
//
//class HashTable {
//private:
//    Cell* CellArray;
//    int hash_size;
//    int cur_size;
//public:
//    HashTable(int size) {
//        this->hash_size = size;
//        CellArray = new Cell[size];
//        this->cur_size = 0;
//    }
//
//    int hashfunciton1(int key) {
//        return key%hash_size;
//    }
//
//    int hashfunction2(int key) {
//        return 17-(key%17);
//    }
//
//    void insert(int key, int value) {
//        int initial_idx = hashfunciton1(key);
//        int cur_idx = hashfunciton1(key);
//        int proving = 1;
//        bool initial = true;
//        while(CellArray[cur_idx].flag == ISITEM) {
//            if(cur_idx == initial_idx && !initial) {
//                return;
//            }
//            else {
//                proving++;
//                initial = false;
//                cur_idx = (hashfunciton1(key) + (proving-1)*hashfunction2(key))%hash_size;
//            }
//        }
//        CellArray[cur_idx].key = key;
//        CellArray[cur_idx].value = value;
//        CellArray[cur_idx].flag = ISITEM;
//    }
//
//    void print() {
//        for(int i=0; i<hash_size; i++) {
//            cout<<CellArray[i].value<<" ";
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
//        int P,Q;
//        cin>>P>>Q;
//        HashTable table = HashTable(P);
//        int key;
//        while(Q--) {
//            cin>>key;
//            table.insert(key,key);
//        }
//        table.print();
//    }
//}
