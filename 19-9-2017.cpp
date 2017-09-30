#include <iostream>
using namespace std;

//fie s o permutare de ordin n
//k=punct fix daca s(k)=k
//sa se genereze toate permutarilede ordin n care au exact p puncte fixe


int n,p;

int nrPFixe(int v[],int k){
  int counter=0;
  for(int i=0;i<=k;i++){
    if(v[i]==i+1){
      counter++;
    }
  }
  return counter;
}

bool appears(int v[],int k,int cif){
  if(k==0)
    return false;
  for(int i=0;i<=k;i++){
    if(v[i]==cif)
      return true;
  }
  return false;
}


void bkt(int v[],int k){
  for(int i=n;i>=1;i--){
    if(!appears(v,k,i)){
      v[k]=i;
      if(k==n-1 && nrPFixe(v,k)==p){
        for(int j=0;j<=k;j++){
          cout<<v[j]<<" ";
        }
        cout<<endl;
      }else{
        bkt(v,k+1);
      }
    }
  }
}

int main(){
  n=5;p=2;
  int sol[20];
  bkt(sol,0);
}
