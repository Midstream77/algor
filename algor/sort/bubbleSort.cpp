#include <iostream>
using namespace std;

void swap(int &a, int&b){
    int t=a;
    a=b;
    b=t;
}

void bubble_sort(int* arr,int n){
    for(int i=0;i<n;i++){
        for(int j=1;j<n;j++)
            if(arr[j-1]>arr[j]) swap(arr[j-1],arr[j]);
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int *arr = new int[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0;i<n;i++) cout<<arr[i]<<"\t";
    cout<<"\n";
    bubble_sort(arr,n);
    for(int i=0;i<n;i++) cout<<arr[i]<<"\t";
}