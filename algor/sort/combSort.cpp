#include <iostream>
using namespace std;

void swap(int &a, int&b){
    int t=a;
    a=b;
    b=t;
}

void comb_sort(int* arr,int n){
    int gap = n;
    int shrink = 1.3;
    while(gap>0){
        if(gap=gap/shrink) gap--;
        else gap/=shrink;
        for(int i=gap;i<n;i++){
            if(arr[i]<arr[i-gap]) 
                swap(arr[i],arr[i-gap]);
        }
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int *arr = new int[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0;i<n;i++) cout<<arr[i]<<"\t";
    cout<<"\n";
    comb_sort(arr,n);
    for(int i=0;i<n;i++) cout<<arr[i]<<"\t";
}