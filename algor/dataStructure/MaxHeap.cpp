#include "MaxHeap.hpp"

template <class T>
MaxHeap<T>::MaxHeap(){
    new (this)MaxHeap(100);
    //这个写法网上看来的，不太懂
    //this = new MaxHeap(100) 会报错
}

template <class T>
MaxHeap<T>::MaxHeap(int max_size){
    this->arr = new T[max_size];
    this->max_size = max_size;
    this->size = 0;
}

//析构函数，以前从来没有写过
template <class T>
MaxHeap<T>::~MaxHeap(){
    size = 0;
    max_size = 0;
    delete[] arr;
}


//-1 means doesn't exist
template <class T>
int MaxHeap<T>::search(T data){
    for(int i=0;i<this->size;i++)
        if(arr[i]==data) return i;
    return -1;
}

//-1 means failed to insert
template <class T>
int MaxHeap<T>::insert(T data){
    if(size==max_size){
        cout<<"MaxHeap full"<<endl;
        return -1;
    }
    if(this->search(data)!=-1){
        cout<<"data existed"<<endl;
        return -1;
    }
    arr[size] = data;
    this->adjust_up(size);
    this->size++;
    return 0;
}

//-1 means failed to delete
template <class T>
int MaxHeap<T>::del(T data){
    int pos = this->search(data);
    if(pos==-1){
        cout<<"data doesn't exist"<<endl;
        return -1;
    }
    this->swap(arr[pos],arr[size]);
    arr[size]=0;
    size--;
    this->adjust_down(pos);
    return 0;
}

template <class T>
void MaxHeap<T>::print(){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<"\t";
    }
}

//test
int main(){
     int a[] = {10, 40, 30, 60, 90, 70, 20, 50, 80};
    MaxHeap<int>* p = new MaxHeap<int>();
    for(int i=0;i<9;i++){
        p->insert(a[i]);
    }
    p->print();
    cout<<endl;
    p->del(90);
    p->print();
}
