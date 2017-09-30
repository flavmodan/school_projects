#include <iostream>
#include <deque>

using namespace std;


deque<int> makeNew(deque <int> n,int target){
  deque <int> result;
  for(int i=0;i<target;i++)
    result.push_back(n[i]);
  result.push_back(n[target]+n[target+1]);

  for(int i=target+2;i<n.size();i++)
    result.push_back(n[i]);

  return result;
}


void print(deque <int> n){
  for(int i=0;i<n.size();i++){
    cout<<n[i]<<" ";
  }
  cout<<endl;
}


void bkt(deque<int> n,int layer){
  if(n.size()==2){
    //print(n);
    return ;
  }else{
    for(int i=0;i<n.size()-1;i++){
      deque<int> temp(makeNew(n,i));
      print(temp);
      if(i<=layer)
        bkt(temp,layer+1);
    }
  }
}

int main(){
  deque <int> test;
  for(int i=0;i<10;i++)
    test.push_back(1);
  bkt(test,1);
}
