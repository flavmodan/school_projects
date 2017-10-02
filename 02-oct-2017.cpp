#include <iostream>
#include <deque>
// sitnr intregi sibmultimi in care cel putin 3 num sunt 3unghi



using namespace std;

deque <int> nums = {7 ,1 ,2 ,5 ,10,3,12};

bool isTriangle(int a, int b, int c){
  if(a+b>c && a+c>b && b+c>a)
    return true;
  return false;
}

bool vectorIsTriangle(deque <int> v){
  for(int i=0;i<v.size()-2;i++){
    for(int j=i+1;j<v.size()-1;j++){
      for(int k=j+1;k<v.size();k++){
        if(isTriangle(v[i],v[j],v[k])){
          return true;
        }
      }
    }
  }
  return false;
}

void print(deque <int> v){
  for(int i=0;i<v.size();i++){
    cout<<v[i]<<" ";
  }
  cout<<endl;
}

void bkt(deque <int> v,int last){
  for(int i=last;i<nums.size();i++){
    v.push_back(nums[i]);
    if(v.size()<=nums.size()){
      if(v.size()>=3){
        if(vectorIsTriangle(v)){
          print(v);
        }
      }
      bkt(v,i+1);
      v.pop_back();
    }
  }
}

int main(){
  deque <int> sol;
  bkt(sol,0);
}
