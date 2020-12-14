//
//  Q2_1_Array.cpp
//  INHA CLASS
//
//  Created by Kang Minsang on 2020/10/26.
//  Copyright © 2020 Kang Minsang. All rights reserved.
//

#include <iostream>
using namespace std;
//배열의 크기 : 10000, 인덱스 0부터 시작
//at, set, add 메소드 구현

class Array {
public:
    int arr_size = 10000;
    int* array;
    int count = 0;

    Array() {
        this->array = new int[10000];
        for(int i=0; i<10000; i++) {
            array[i] = 0;
        }
        count = 0;
    }

    int at(int idx) {
        if(idx < 0 || idx >= 10000) {
            return 0;
        }
        else
            return array[idx];
    }

    void set(int idx, int value) {
        if(idx < 0 || idx >= 10000) {
            cout<<0<<"\n";
        }
        else {
            array[idx] = value;
        }
        count++;
    }

    void add(int idx, int value) {
        if(count == 0) {
            array[0] = value;
        }
        else {
            int last; //마지막 값이 있는 위치
            for(int i=0; i<10000; i++) {
                if(array[i] == 0) {
                    last = i-1;
                    break;
                }
            }
            //만약 해당위치에 값이 없는경우 -> 마지막위치에 값을 추가한다
            if(array[idx] == 0) {
                array[last+1] = value;
            }
            //만약 해당위치에 값이 있는경우 -> 해당위치부터 뒤로 자료를 미룬다
            else {
                for(int i=last; i>=idx; i--) {
                    if(i == 9999) {
                        continue;
                    }
                    array[i+1] = array[i];
                }
                array[idx] = value;
            }
        }
    }
};

int main()
{
    Array array = Array();
    int M, idx;
    string question;
    cin>>M;
    while(M--) {
        cin>>question;
        if(question == "at") {
            cin>>idx;
            cout<<array.at(idx)<<"\n";
        }
        else if(question == "add") {
            int value;
            cin>>idx>>value;
            array.add(idx,value);
        }
        else if(question == "set") {
            int value;
            cin>>idx>>value;
            array.set(idx,value);
        }
    }

}
