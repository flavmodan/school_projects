#include <iostream>
#include <fstream>
using namespace std;
ifstream f ("nr.in");

bool mat[100][100];
int nrCol=4,colors[100],n;

void color (int colors[],int k){
  for(int i=0;i<nrCol;i++){
    if(k==0){
      colors[k]=i;
      color(colors,k++);

    }else{
      colors[k]=i;
      if(colors[k]==colors[k-1] && mat[k][k-1]){
        continue;
      }else{
        if(k==n-1){
          cout<<"sol found : "<<endl;;
          for(int j=0 ; j<n ; j++){
            cout<<j<<" : "<<colors[j]<<endl;
          }
        }else{
          color(colors,k+1);
        }
      }
    }
  }
}

int main (){
  f>>n;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      f>>mat[i][j];
    }
  }

}
