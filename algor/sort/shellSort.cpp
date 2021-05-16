#include <iostream>
using namespace std;

void swap(int &a, int&b){
    int t=a;
    a=b;
    b=t;
}

void shell_sort(int* arr,int n){
    for(int gap=n/2;gap>0;gap/=2){
        for(int i=gap;i<n;i++){
            int j=i;
            while(j-gap>=0&&arr[j]<arr[j-gap]){
                //using swap in insertion sort
                swap(arr[j],arr[j-gap]);
                j-=gap;
            }
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
    shell_sort(arr,n);
    for(int i=0;i<n;i++) cout<<arr[i]<<"\t";
}