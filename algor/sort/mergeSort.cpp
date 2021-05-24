#include <iostream>
using namespace std;
void _merge(int* arr, int left, int mid, int right){
    if(left>mid||mid>right) return;

    int i=left, j=mid+1, m=0;
    int* tmp = new int[right-left+1];

    while(i<=mid&&j<=right){
        if(arr[i]<arr[j]) tmp[m++]=arr[i++];
        else tmp[m++]=arr[j++];
    }
    while(i<=mid) tmp[m++]=arr[i++];
    while(j<=right) tmp[m++]=arr[j++];
    for(i=0;i<=right-left;i++) arr[left+i] = tmp[i];

    delete []tmp;
}

void _merge_sort(int* arr, int left, int right){
    if(left>=right) return;
    int mid = (left+right)/2;
    _merge_sort(arr,left,mid);
    _merge_sort(arr,mid+1,right);
    _merge(arr,left, mid, right);
}

void merge_sort(int* arr, int n){
    _merge_sort(arr,0,n-1);
}

int main(){
    int n;
    scanf("%d",&n);
    int *arr = new int[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0;i<n;i++) cout<<arr[i]<<"\t";
    cout<<"\n";
    merge_sort(arr,n);
    for(int i=0;i<n;i++) cout<<arr[i]<<"\t";
}