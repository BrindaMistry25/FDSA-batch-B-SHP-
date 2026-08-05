#include<iostream>
using namespace std;
int main(){
string numplate[20];
int i;
int n;
string target;
cout<<"Enter num plate";
for(i=0;i<10;i++){
    cin>>numplate[i];
}
cout<<"Enter guard left";
cin>>n;
cout<<"Enter targetpalte";
cin>>target;
if(n==0){

for(i=0;i<10;i++){
        if(numplate[i]==target){
            cout<<target<<"Found at"<<i;
        }
}
}
else{
    for(i=n;i<10;i++){
        if(numplate[i]==target){
            cout<<target<<"Found at"<<i;
        }
    }
}

}

