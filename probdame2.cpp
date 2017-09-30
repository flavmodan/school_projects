#include <iostream>
using namespace std;

int n;
bool mat[][];

void print(bool mat[][],int n){
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cout<<mat[i][j]<<" ";
    }
    cout<<endl;
  }
}

bool check(bool mat[][] , int i, int j){
  if (i < 0 || i > n-1 || j<0 || j> n-1){
    return true;
  }else{
    if(mat[i][j]){
      return false;
    }else{
      check(mat,i-1,j);
      check(mat,i+1,j);
      check(mat,i,j+1);
      check(mat,i,j-1);
      check(mat,i+1,j+1);
      check(mat,i+1,j-1);
      check(mat,i-1,j+1);
      check(mat,i-1,j-1);
    }
  }
}

void bkt(bool mat[][],int k,int i,int j){
  for ( int i =0 ;i <n ;i++){
    for (int j=0;j<n;j++){
      if(check(mat,i,j)){
        mat[i][j]=true;
        if(k==n){
          print(mat,n);
        }
      }

    }
  }
}
