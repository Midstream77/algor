#include <iostream>
#include <cstdlib>
#include <time.h>
#include <algorithm>
#include<queue>
using namespace std;

int get_max_bit(int a){
    return a<10?1:1+get_max_bit(a/10);
}

void _radix_sort(int* arr, int max_bit, int n){

    queue<int> tmp[10];
    int i,j,k=0,digit,mod=10,div=1;
    for(i=0;i<max_bit;i++){

        //push all the numbers into the queue
        for(j=0;j<n;j++){
            digit=(arr[j]%mod)/div;
            tmp[digit].push(arr[j]);
        }

        //pop all the numbers so it will be sorted by variable "digit"
        for(j=0;j<10;j++){
            while(!tmp[j].empty()){
                arr[k++] = tmp[j].front();
                tmp[j].pop();
            }
        }
    }
}

void radix_sort(int* arr, int n){
    int i,max_bit,a;
    for(i=0;i<n;i++) a = max(a,arr[i]);
    max_bit = get_max_bit(a);
    _radix_sort(arr, max_bit, n);
}

int main(){
    int n;
    scanf("%d",&n);
    int *arr = new int[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0;i<n;i++) cout<<arr[i]<<"\t";
    cout<<"\n";
    radix_sort(arr,n);
    for(int i=0;i<n;i++) cout<<arr[i]<<"\t";
}