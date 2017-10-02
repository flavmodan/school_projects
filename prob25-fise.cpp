#include <iostream>
#include <deque>
#include <cmath>
using namespace std;

int n=5;

bool appears(deque<int> v,int k){
  for(int i=0;i<v.size();i++){
    if(v[i]==k)
      return true;
  }
  return false;
}

void print(deque<int> v){
  for(int i=0;i<v.size();i++)
    cout<<v[i]<<" ";
  cout<<"0"<<endl;
}

void bkt(deque<int> v){
  for(int i=0;i<=9;i++){
      v.push_back(i);
      if(abs(v[v.size()-1]-v[v.size()-2])==1){
        if(v.size()==n-1 && v[v.size()-1]==1){
          cout<<"sol found ";
          print(v);
        }else{
          bkt(v);
        }
      }
    }
  }


int main(){
  deque<int> v;
  v.push_back(0);
  v.push_back(1);
  bkt(v);
}
