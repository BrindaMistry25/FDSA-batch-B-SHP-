#include<iostream>
using namespace std;
int main(){
    string word;
string arr[100];

int n,i;
cout<<"Enter the no of elements";
cin>>n;

for(i=0;i<n;i++){
    cin>>arr[i];
}
cout<<"Enter the word to find";
cin>>word;
for(i=n/2;i<n;i++){
    if(arr[i]==word){
        cout<<"word found at"<<i+1 <<":position to right"<<endl;
    }
}
for(i=n/2;i>0;i--){
    if(arr[i]==word){
        cout<<"word found at"<<i+1 <<":position to left"<<endl;
    }

}
}


