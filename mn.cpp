#include <iostream>
#define N 3
using namespace std;

int sizes[]={4,5,3},counter=0;

void bkt(int v[],int k){

  for(int i=1;i<=sizes[k];i++){
    v[k]=i;
    if(k==N-1){
      counter++;
      for(int j=0;j<N;j++){
        cout<<v[j]<<" ";
      }
      cout<<endl;
    }else{
      bkt(v,k+1);
    }
  }
}

int main(){
  int v[N];
  bkt(v,0);
  cout<<endl<<counter;
}
