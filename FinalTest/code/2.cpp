//
//  2.cpp
//  FinalTest
//
//  Created by Kang Minsang on 2020/12/18.
//

#include <iostream>
using namespace std;
#define NOITEM 0
#define ISITEM 1
#define AVAILABLE 2

class cell {
public:
    int key;
    int value;
    int flag;

    cell() {
        this->key = -1;
        this->value = -1;
        this->flag = NOITEM;
    }
};

class HashTable {
private:
    cell* cellArray;
    int hash_size;
public:
    HashTable(int size) {
        this->hash_size = size;
        this->cellArray = new cell[size];
    }

    int hashfunction(int key) {
        return key%hash_size;
    }

    void insert(int key, int value) {
        int cur_idx = hashfunction(key);
        while(cellArray[cur_idx].flag == ISITEM) {
            cur_idx = (cur_idx+1)%hash_size;
        }
        cellArray[cur_idx].key = key;
        cellArray[cur_idx].value = value;
        cellArray[cur_idx].flag = ISITEM;
    }

    void erase(int key) {
        int initial_idx = hashfunction(key);
        int cur_idx = hashfunction(key);
        bool initial = true;
        while(cellArray[cur_idx].flag != NOITEM) {
            if(cellArray[cur_idx].key == key) {
                cellArray[cur_idx].key = 0;
                cellArray[cur_idx].value = 0;
                cellArray[cur_idx].flag = AVAILABLE;
            }
            else if(initial_idx == cur_idx && !initial) {
                return;
            }
            else {
                cur_idx = (cur_idx+1)%hash_size;
            }
        }
    }

    void print() {
        for(int i=0; i<hash_size; i++) {
            cout<<cellArray[i].value<<" ";
        }
        cout<<"\n";
    }
};

int main()
{
    int T;
    cin>>T;
    while(T--) {
        int P, Q;
        cin>>P>>Q;
        HashTable table = HashTable(P);
        int key;
        while(Q--) {
            cin>>key;
            table.insert(key, key);
        }
        int R;
        cin>>R;
        while(R--) {
            cin>>key;
            table.erase(key);
        }
        table.print();
    }
}
