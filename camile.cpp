#include <iostream>
#include <deque>
using namespace std;

int n=4;

void bkt(deque <int> v){
  for(int i=1;i<=n;i++){
    v.push_back(i);
    for(int j=0;j<v.size();j++){
      cout<<v[j]<<" ";
      }
    cout<<endl;
    
    if(v.size()>1){
      if(v[v.size()-1]-v[v.size()-2]>1){
        if(v.size()==n){
          cout<<"sol found "<<endl;
          for(int j=0;j<v.size();j++){
            cout<<v[j]<<" ";
          }
          cout<<endl;
        }else{
          bkt(v);
          v.pop_back();
        }
      }
    }else if(v.size()==1){
      bkt(v);
    }
  }
}

int main(){
  deque <int> v;
  bkt(v);
}
