#include<bits/stdc++.h>
using namespace std;



int fact(int n){

    if(n==0)  return 1;


    return n*fact(n-1);
}

int main(){

int i;

int n,c=0;
   cin>>n;
  cout<<fact(n)<<endl;

       

}
