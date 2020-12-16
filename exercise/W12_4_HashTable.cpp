////
////  W12_4_HashTable.cpp
////  INHA CLASS
////
////  Created by Kang Minsang on 2020/12/16.
////  Copyright © 2020 Kang Minsang. All rights reserved.
////
//
//#include <iostream>
//using namespace std;
//#define ISITEM 0
//#define NOITEM 1
//#define AVAILABLE 2
//
//class cell {
//public:
//    int key;
//    int value;
//    int flag;
//    cell() {
//        this->key = -1;
//        this->value = -1;
//        this->flag = NOITEM;
//    }
//};
//
//class HashTable {
//private:
//    cell* cellArray;
//    int hash_size;
//    int cur_size;
//public:
//    HashTable(int size) {
//        this->hash_size = size;
//        this->cellArray = new cell[hash_size];
//        this->cur_size = 0;
//    }
//
//    int hashfunction(int key) {
//        return key%hash_size;
//    }
//
//    void insert(int key, int value) {
//        int initial_idx = hashfunction(key);
//        int cur_idx = hashfunction(key);
//        int proving = 1;
//        bool initial = true;
//        while(cellArray[cur_idx].flag == ISITEM) {
//            if(cur_idx == initial_idx && !initial) {
//                return;
//            }
//            else {
//                proving++;
//                initial = false;
//                cur_idx = (cur_idx+1)%hash_size;
//            }
//        }
//        cellArray[cur_idx].key = key;
//        cellArray[cur_idx].value = value;
//        cellArray[cur_idx].flag = ISITEM;
//    }
//
//    void find(int key) {
//        int initial_idx = hashfunction(key);
//        int cur_idx = hashfunction(key);
//        int proving = 1;
//        bool initial = true;
//        while(cellArray[cur_idx].flag != NOITEM) {
//            if(cellArray[cur_idx].key == key) {
//                cout<<"True "<<proving<<"\n";
//                return;
//            }
//            else if(cur_idx == initial_idx && !initial) {
//                cout<<"False "<<proving<<"\n";
//                return;
//            }
//            else {
//                proving++;
//                initial = false;
//                cur_idx = (cur_idx+1)%hash_size;
//            }
//        }
//        cout<<"False "<<proving<<"\n";
//        return;
//    }
//
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
//            table.insert(key, key);
//        }
//        int R;
//        cin>>R;
//        while(R--) {
//            cin>>key;
//            table.find(key);
//        }
//    }
//}
