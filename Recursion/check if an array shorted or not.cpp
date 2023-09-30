#include<bits/stdc++.h>
using namespace std;


int ar[1000],n;


bool sort(int ar[], int n){


    if(n==1)  return true;

    bool sectolast = sort(ar+1, n-1);

    return (ar[0]<ar[1] && sectolast);
}



int main(){

int i;

int n,c=0;
   cin>>n;
  for(int i=0;i<n;i++){
    cin>>ar[i];
  }

   cout<<sort(ar,n) <<endl;   

}
