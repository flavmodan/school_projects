#include <iostream>
#include <deque>

using namespace std;

int S = 9;

int makeSum(deque <int> v){
  int s=0;
  for(int i=0;i<v.size();i++)
    s+=v[i];
  return s;
}

void print(deque <int> v){
  for(int i=0;i<v.size();i++)
    cout<<v[i]<<" ";
  cout<<endl;
}

void bkt(deque <int> v){
  for(int i=S-1;i>=1;i--){
    v.push_back(i);
    //print(v);
    if((v.size()==1 || v[v.size()-1]<v[v.size()-2])&&v.size()<=S-1){
      print(v);
      if(makeSum(v)==S){
        cout<<"sol found : ";
        print(v);
      }
      else{
        bkt(v);
        //v.pop_back();
      }
    }
  }
}

int main(){
  deque<int> sol;
  bkt(sol);
}
