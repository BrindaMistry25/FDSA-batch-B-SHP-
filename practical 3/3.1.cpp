#include<iostream>
using namespace std;
void bubblesort(int arr[],int n){
    int i,j;
for(i=0;i<n-1;i++){
    for(j=0;j<n-i-1;j++){
        if(arr[j]>arr[j+1]){
            swap(arr[j],arr[j+1]);
        }
    }
}
}
void selectionsort(int arr[],int n){
int i,j,si;
for(i=0;i<n-1;i++){
    si=i;
    for(j=i+1;j<n;j++){
        if(arr[j]<arr[si]){
            si=j;
        }
    }
    swap(arr[i],arr[si]);
}
}

void display(int arr[],int n){
    int i,j;
    for(i=0;i<n;i++){
        cout<<arr[i]<<",";
    }
}
void insertionsort(int arr[],int n){
    int i;
for(i=1;i<n;i++){
    int curr=arr[i];
    int prev=i-1;
    while(prev>=0 && arr[prev]>curr){
        arr[prev+1]=arr[prev];
        prev--;
    }
    arr[prev+1]=curr;
}
}
int main(){
int arr[50];
int n;
cout<<"Enter the num of elements";
cin>>n;
int i,j;
cout<<"Entrer elements";
for(i=0;i<n;i++){
    cin>>arr[i];
}
cout<<"Using bubble sort"<<endl;
bubblesort(arr,n);
display(arr,n);
cout<<endl;
cout<<"Using selection sort"<<endl;
selectionsort(arr,n);
display(arr,n);
cout<<endl;
cout<<"Using Insertion sort"<<endl;
insertionsort(arr,n);
display(arr,n);
}

