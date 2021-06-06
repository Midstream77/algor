#pragma once
#include <iostream>
#include <algorithm>
using namespace std;

template <class T>
class MaxHeap{
private:
    T* arr;
    int max_size;
    int size;

public:
    MaxHeap();
    MaxHeap(int max_size);
    ~MaxHeap();

    int search(T data);
    int insert(T data);
    int del(T data);
    void print();

private:
    void swap(T &a, T &b){
        T c = a;
        a = b;
        b = c;
    }

    void adjust_up(int start){
        int parent = (start-1)/2;
        if(arr[parent]>=arr[start]) return;
        swap(arr[parent],arr[start]);
        adjust_up(parent);
    }

    void adjust_down(int start){
        int left_child = start*2+1;
        int right_child = left_child+1;
        int max_child = left_child;

        if(left_child>size) return;
        if(right_child>size){
            if(arr[left_child]>arr[start])
                swap(arr[right_child],arr[left_child]);
            return;
        }
        if(arr[left_child]<arr[right_child]) max_child++;
        swap(arr[start],arr[max_child]);
        adjust_down(max_child);
    }
};
