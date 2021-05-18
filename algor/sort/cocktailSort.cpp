#include <iostream>
using namespace std;

void swap(int &a, int&b){
    int t=a;
    a=b;
    b=t;
}

void cocktail_sort(int* arr,int n){
    int start=1,end=n-1,step=1;
    int left=1,right=n-1;
    int i=0;
    while(left!=right){
        i+=step;
        if(arr[i]<arr[i-1]) swap(arr[i],arr[i-1]);
        if(i==end){
            if(step==1){
                right--;
                end=left+1;
            }
            if(step==-1){
                left++;
                end=right;
            }
            step*=-1;
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
    cocktail_sort(arr,n);
    for(int i=0;i<n;i++) cout<<arr[i]<<"\t";
}