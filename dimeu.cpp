#include <iostream>
#include <algorithm>
#include <string>
#include <deque>
using namespace std;

struct Meh{
  int meh;
  string blah;
};;

  bool order(Meh a , Meh b){
    if(a.meh>b.meh){
      if(a.blah=="a" && b.blah=="b")
        return false;
      else
        return true;
    }else{
      return true;
    }
  }

int main(){
  deque <Meh> v;
  Meh temp;
  for(int i=0;i<4;i++){
    temp.meh=i;
    if(i%2){
      temp.blah="a";
    }else{
      temp.blah="b";
    }
    v.push_back(temp);
  }
  do{
    for(int i=0;i<v.size();i++){
      cout<<v[i].meh<<" "; 
    }
    cout<<endl;
      }while(next_permutation(v.begin(),v.end(),order));
}

