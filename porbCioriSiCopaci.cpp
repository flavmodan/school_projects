#include <iostream>
#include <vector>
#include <fstream>
#include<algorithm>
using namespace std;

ifstream fin("ciori.in");

bool checkTarget(vector<int> target,vector<int> v,int progress){
  for(int i=progress;i<target.size();i++){
    if(v[i]!=target[i])
      return false;
  }
  return true;
}

int main(){
  int n;
  vector<int> trees;
  vector<int> target;
  fin>>n;
  for(int i=0;i<n;i++){
    int x;
    fin>>x;
    trees.push_back(x);
  }
  for(int i=0;i<n;i++){
    int x;
    fin>>x;
    target.push_back(x);
  }
  int i=0,tar=0,j=0;
  for(j=0;j<trees.size();j++){
    if(trees[j]==0)
      break;
  }
  for(i=0;!checkTarget(trees,target,i);i++){
    if(trees[i]!=target[i]){

      for(tar=0;tar<trees.size();tar++){
        if(trees[tar]==target[i])
          break;
      }

      //cout<<i<<" : ";
      cout<<"cioara "<<trees[i]<<" trece de pe copacul "<<i+1<<" pe copacul "<<j+1<<endl;;
      swap(trees[i],trees[j]);

      cout<<"cioara "<<trees[tar]<< " trece de pe copacul "<<tar+1<<" pe copacul "<<i+1<<endl;
      swap(trees[i],trees[tar]);
      // for(int k=0;k<trees.size();k++){
      //   cout<<trees[k]<<" ";
      // }
      j=tar;
      cout<<endl;
    }
  }

}
