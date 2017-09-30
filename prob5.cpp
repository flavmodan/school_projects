#include <iostream>
using namespace std;

int n=9,sol[10];

void print(int v[],int k){
  for(int i=k;i>=0;i--){
    cout<<v[i]<<" ";
  }
  cout<<endl;
}

int sum(int v[],int k){
  int total=0;
  for(int i=0;i<=k;i++){
    total=total+v[i];
  }
  return total;
}

void bkt(int sol[],int k){
  for(int i=n-1;i>=1;i--){
    sol[k]=i;
    if(k==0){
      bkt(sol,k+1);
    }else{
      if(sol[k]<=sol[k-1] && k<=n){
        if(sum(sol,k)==n){
          cout<<"sol found ";
          print(sol,k);
          cout<<endl;
        }else{
          bkt(sol,k+1);
        }
      }
    }
  }
}

int main(){
  bkt(sol,0);
}
