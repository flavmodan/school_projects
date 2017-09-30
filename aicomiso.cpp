#include <iostream>
#include <fstream>
#include <deque>

//meh

using namespace std;

int n;
bool mat[100][100];

void route(deque <int> path,int line){
  for(int j=1;j<=n;j++){
    if(path.size()>1){
      if(mat[line][j] && j!=path[path.size()-1] && j!=path[path.size()-2]){
      path.push_back(j);
      if(j==1){
        for(int i=0;i<path.size();i++)
          cout<<path[i]<<" ";
        cout<<endl;
        return;
      }else{
        route(path,j);
        path.pop_back();
      }
      }
    }else{
      if(mat[line][j] && j!=path[path.size()-1]){
        path.push_back(j);
        if(j==1){
          for(int i=0;i<path.size();i++)
            cout<<path[i]<<" ";
          cout<<endl;
        }else{
          route(path,j);
          path.pop_back();
      }
      }
    }

  }
}

int main(){
  ifstream f("map.in");
  f>>n;
  for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
      f>>mat[i][j];

  deque <int> path;
  path.push_back(1);
  route(path,1);
}
