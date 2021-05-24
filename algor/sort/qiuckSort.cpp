#include <iostream>
using namespace std;

void swap(int &a, int &b){
    int t = a;
    a = b;
    b = t;
}

void _qiuck_sort(int* arr, int left, int right){
    if(left>right) return;
    int i=left, j=right, pivot=arr[i];
    while(i<j){
        while(arr[j]>=pivot&&i<j) j--;
        while(arr[i]<=pivot&&i<j) i++;
        if(i<j) swap(arr[i],arr[j]);
    }
    swap(arr[left],arr[i]);
    _qiuck_sort(arr,left,i-1);
    _qiuck_sort(arr,i+1,right);
}

void qiuck_sort(int* arr, int n){
    _qiuck_sort(arr,0,n-1);
}

int main(){
    int n;
    scanf("%d",&n);
    int *arr = new int[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0;i<n;i++) cout<<arr[i]<<"\t";
    cout<<"\n";
    qiuck_sort(arr,n);
    for(int i=0;i<n;i++) cout<<arr[i]<<"\t";
}