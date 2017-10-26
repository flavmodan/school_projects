#include<iostream>
#include<fstream>
#include<vector>
#include<cmath>

using namespace std;

struct move{
  int x,y,element;
};

int mat[100][100],h,maxDistance=0,n,m;

vector<move> maxRoad;

ifstream fin("date.in");

void walk(int x, int y,vector<move>moves,int prevHeight){
  //cout<<x<<" "<<y<<" -> "<<mat[y][x]<<endl;
  if(x<0 || x==m || y<0 || y==n){
    if(moves.size()>=maxDistance){
      //cout<<"sol :"<<maxDistance<<endl;
      maxDistance=moves.size();
      maxRoad=moves;
    }
    //return;
  }else{
    if(abs(prevHeight-mat[y][x])<=h){
      move temp={x,y,mat[y][x]};
      moves.push_back(temp);
      int cHeight=mat[y][x];
      mat[y][x]=10000;
      //cout<<"going out form "<<x<<" "<<y<<"->"<<cHeight<<" : "<<abs(prevHeight-cHeight)<<endl;
      walk(x-1,y,moves,cHeight);
      walk(x+1,y,moves,cHeight);
      walk(x,y+1,moves,cHeight);
      walk(x,y-1,moves,cHeight);
      mat[y][x]=cHeight;
    }
  }
}

int main(){
  int x0,y0;
  fin>>n>>m>>x0>>y0>>h;
  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      fin>>mat[i][j];

  vector<move> moves;
  walk(x0,y0,moves,mat[y0][x0]);
  for(int i=0;i<maxRoad.size();i++){
    cout<<maxRoad[i].y<<" "<<maxRoad[i].x<<" -> "<<maxRoad[i].element<<endl;
  }
  cout<<maxRoad.size();
}
