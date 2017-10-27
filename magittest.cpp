#include<iostream>
#include<fstream>
#include<deque>
#include<cmath>

using namespace std;

int n;

struct dama{
  int lin,col;
};

bool checkSafe(int i,int j,deque<dama> sol){
  for(int k=0;k<sol.size();k++){
    if(sol[k].col==k||sol[k].lin==i|| abs(sol[k].col-j)==abs(sol[k].lin-i)||j-i==sol[k].col-sol[k].lin){
      return false;
    }
  }
  return true;
}

void bkt(deque<dama> sol){
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(checkSafe(i,j,sol)){
        dama temp;
        temp.lin=i;
        temp.col=j;
        sol.push_back(temp);
        if(sol.size()==n){
          for(int k=0;k<sol.size();k++)
            cout<<sol[k].lin<<sol[k].col<<endl;
          cout<<endl;
        }else{
          bkt(sol);
          sol.pop_back();
        }
      }
    }
  }
}
int main(){
  cin>>n;
  deque<dama>sol;
  bkt(sol);
}
