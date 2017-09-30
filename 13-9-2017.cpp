#include <iostream>
using namespace std;

int a[]={1,2,3,4,5,6},f=3,n=3,nr=5,x[10];



void bkt(int x[],int k){
  for (int i=f+1; i<nr;i++){
    x[k]=a[i];
    if(k==2){
      for (int j=0;j<f;j++){
        cout<<"f: "<<a[j]<<" m: "<<x[1]<<" "<<x[2]<<endl;
      }
    }else{
      bkt(x,k+1);
    }
  }
}

int main(){
  bkt(x,1);
}

// n persoane dintr-e care f wamen (respekt dem, respektin wamen is important )
// n=?
//
