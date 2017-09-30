#include <iostream>
#include <deque>
#define S 100
#define N 5
using namespace std;

int a[]={1,5,10,50,100};

bool sum(deque <int> v){
  int s=0;
  for (int i=0;i<v.size();i++){
    s+=v[i];
  }
  return s==S;
}

bool appears(deque <int> v,int k){
  for(int i=0;i<v.size();i++){
    if(v[i]==k)
      return true;

  }
  return false;
}


void bkt(deque <int> v){
  for(int i=0;i<N;i++){
    /*if(!appears(v,a[i])){
      v.push_back(a[i]);
      }*/
    v.push_back(a[i]);
    /*
    for(int k=0;k<v.size();k++){
      cout<<v[k]<<" ";
      }
    cout<<endl;
    */
    if(sum(v) && v.size()<=S){
      cout<<"sol found : ";
      for(int k=0;k<v.size();k++){
        cout<<v[k]<<" ";
      }
      cout<<endl;
    }else if(v.size()<=S){
      bkt(v);
      v.pop_back();
    }
  }
}

int main(){
  deque <int> v;
  bkt(v);
}
