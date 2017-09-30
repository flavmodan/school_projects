#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int S=6;
bool cif[10];

bool checkSum(deque <int> num){
  int s=0;
  for(int i=0;i<num.size();i++){
    s+=num[i];
  }
  return s;
}

bool checkCif(deque <int> num,int k){
  for(int i=0;i<num.size();i++){
    if(k==num[i])
      return false;
  }
  return true;
}

void print(deque <int> num){
  for(int i=0;i<num.size();i++)
    cout<<num[i]<<" ";
  cout<<endl;
}

void bkt(deque <int> num){
  print(num);
  if(num.size()==0){
    for(int i=1;i<=9;i++){
      num.push_back(i);
      if(checkSum(num)==S){
        do{
          if(num[0]!=0){
            print(num);
          }
        }while(next_permutation(num.begin(),num.end()));
          }else{
        if(checkSum(num)<S && num.size()<=S){
          bkt(num);
          num.pop_back();
        }
      }
    }
  }else{
    for(int i=0;i<=9;i++){
      if(checkCif(num,i)){
      num.push_back(i);
      if(checkSum(num)==S){
        
        do{
          if(num[0]!=0){
            print(num);
          }
        }while(next_permutation(num.begin(),num.end()));
      }else{
        if(checkSum(num)<S){
          bkt(num);
          num.pop_back();
        }
      }
      }
    }
  }
}


int main(){
  deque <int> num;
  bkt(num);
}
