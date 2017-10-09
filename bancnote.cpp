#include <iostream>
using namespace std;

int n,sol[101],counter=1;

int monezi[]={5,10,20,25};

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

int Min[100],mk=10000000;

void update(int v[],int k){
  for(int i=0;i<=k;i++){
    Min[i]=v[i];
  }
}

void bkt(int sol[],int k){
  for(int i=4;i>=0;i--){
    sol[k]=monezi[i];
    if(k==0){
      bkt(sol,k+1);
    }else{
      if(sol[k]<=sol[k-1] && k<=n){
        if(sum(sol,k)==n){
          if(k<mk){
            update(sol,k);
            mk=k;
          }
          cout<<"sol found ";
          counter++;
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
  cin>>n;
  bkt(sol,0);
  cout<<"optimum sol ";print(Min,mk);
  cout<<counter;
}
