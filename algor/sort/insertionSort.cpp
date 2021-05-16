#include <iostream>
using namespace std;

void insertion_sort(int* arr,int n){
    int i,j,temp;
    for(i=1;i<n;i++){
        temp = arr[i];
        for(j=i-1;j>0&&arr[j]>temp;j--) arr[j+1]=arr[j];
        arr[j+1]=temp;
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int *arr = new int[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0;i<n;i++) cout<<arr[i]<<"\t";
    cout<<"\n";
    insertion_sort(arr,n);
    for(int i=0;i<n;i++) cout<<arr[i]<<"\t";
}