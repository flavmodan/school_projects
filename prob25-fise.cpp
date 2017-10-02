#include <iostream>
#include <deque>
#include <cmath>
using namespace std;

int n=7,counter=0;

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

}

void bkt(deque<int> v){
  for(int i=0;i<=9;i++){
    if (abs(i-v[v.size()-1])==1){
      //print(v);
      //cout<<endl;
      v.push_back(i);
      if(i==1 and v.size()==n-1){
        cout<<"sol found : ";
        counter++;
        print(v);
        cout<<"0"<<endl;
      }
      else if(v.size()<=n-1)
        bkt(v);
        v.pop_back();

    }
  }
}


int main(){
  deque<int> v;
  v.push_back(0);
  v.push_back(1);
  bkt(v);
  cout<<counter;
}
