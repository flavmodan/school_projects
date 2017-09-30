#include <iostream>
#include <deque>
#include <cmath>

using namespace std;
int S;

deque <int> primes;

int makeSum(deque <int> num){
  int s=0;
  for(int i=0;i<num.size();i++){
    s+=num[i];
  }
  return s;
}

bool prime(int n){
  if(n<=1)
    return false;
  if(n==2)
    return true;
  if(n==3)
    return true;
  if(n%2==0)
    return false;
  if(n%3==0)
    return false;

  for(int d=5;d<int(sqrt(n));d+=2)
    if(n%d==0)
      return false;

  return true;
}

void makePrimes(int target){
  for(int i=2;i<=target;i++){
    if(prime(i)){
      primes.push_back(i);
    }
  }
}

void print(deque <int> num){
  for(int i=0;i<num.size();i++){
    cout<<num[i]<<" ";
  }
  cout<<endl;
}

void bkt(deque <int> v){
  for(int i=0;i<primes.size();i++){
    v.push_back(primes[i]);
    print(v);
    if(v.size()==1){
      if(makeSum(v)==S){
        cout<<"sol found ";
        print(v);
        return ;
      }else{
        bkt(v);
        v.pop_back();
      }
    }else{
      if(v[v.size()-1]>=v[v.size()-2] && v.size()<=S/2+1){
        if(makeSum(v)==S){
          cout<<"sol found ";
          print(v);
          return ;
        }else{
          bkt(v);
          v.pop_back();
        }
      }
    }
  }
}

int main(){
  cin>>S;
  makePrimes(S);
  deque <int> sol;
  bkt(sol);
}
