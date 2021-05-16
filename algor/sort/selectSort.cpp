#include <iostream>
using namespace std;

void swap(int &a, int&b){
    int t=a;
    a=b;
    b=t;
}

void select_sort(int* arr,int n){
    int minn,minn_i;
    for(int i=0;i<n;i++){
        minn=0x3f3f3f;
        for(int j=i;j<n;j++){
            if(arr[j]<minn){
                minn=arr[j];
                minn_i=j;
            }
        }
        swap(arr[i],arr[minn_i]);
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int *arr = new int[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0;i<n;i++) cout<<arr[i]<<"\t";
    cout<<"\n";
    select_sort(arr,n);
    for(int i=0;i<n;i++) cout<<arr[i]<<"\t";
}