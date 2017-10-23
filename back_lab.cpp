#include <iostream>
#include <fstream>
#include <deque>

using namespace std;

ifstream fin ("lab.in");

int mat[100][100],n,m;

void read(){
  fin>>n>>m;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      fin>>mat[i][j];
    }
  }
}

struct point{
  int lin,col;
};

void makePath(int i,int j,deque<point> points){
  if(mat[i][j]==16)
    return;
  if(i<0 || j<0 || i==n || j==m){
    point temp={i,j};
    points.push_back(temp);
    cout<<points.size()<<endl;
    for(int k=0;k<points.size();k++)
      cout<<points[k].lin<<" "<<points[k].col<<endl;
    cout<<endl;
    mat[i][j]=16;
    return;
  }
  int matCp=mat[i][j];
  mat[i][j]=16;
  if(matCp&8){
    makePath(i-1,j,points);
  }
  if(matCp&4){
    makePath(i,j+1,points);
  }
  if(matCp&1){
    makePath(i,j-1,points);
  }
  if(matCp&2){
    makePath(i+1,j,points);
  }
}

int main(){
  read();
  deque<point> points;
  makePath(1,2,points);
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++)
      cout<<mat[i][j]<<" ";
    cout<<endl;
  }
}
