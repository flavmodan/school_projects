#include <iostream>
#include <fstream>
#include <deque>
using namespace std;

ifstream in ("mat.in");

struct Path{
  int lin,col;
};

int mat[100][100],n,m;

void pathfind (int i,int j,deque<Path> p){
  if(mat[i][j]==0){
    
    Path temp;
    temp.lin=i;
    temp.col=j;
    mat[i][j]=2;
    p.push_back(temp);
    if(i==0 || j==0 || i==n-1 || j==m-1){
      cout<<"sol found : "<<endl;
      for(int k=0;k<p.size();k++){
        cout<<p[k].lin<<" "<<p[k].col<<endl;
      }
    }else{
    if(i-1>=0){
      pathfind(i-1,j,p);
    }
    if(i+1<=n-1){
      pathfind(i+1,j,p);
    }
    if(j-1>=0){
      pathfind(i,j-1,p);
    }
    if(j+1<=m-1){
      pathfind(i,j+1,p);
    }
    }
  }
}



int main(){
  in>>n>>m;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      in>>mat[i][j];
    }
  }

  deque <Path> p;
  pathfind(3,2,p);
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cout<<mat[i][j]<<" ";
    }
    cout<<endl;
  }
}
