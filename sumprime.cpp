#include<iostream>
#include<cmath>
#include<deque>

using namespace std;

deque <int> primes;

bool prime(int n){
  if(n==2)
    return true;
  if(n==3)
    return true;
  if(n%2==0)
    return false;
  if(n%3==0)
    return false;

  for(int d=5;d<=int(sqrt(n));d+=2){
    if(n%d==0)
      return false;
  }

  return true;

}

void makePrime(int n){
  for(int i=2;i<=n;i++){
    if(prime(i)){
      cout<<"generating prime "<<i<<endl;
      primes.push_back(i);
    }
  }
}

int n=35,sol[1000];

void print(int v[],int k){
  for(int i=k;i>=1;i--){
    cout<<v[i]<<"+";
  }
  cout<<v[0];
  cout<<endl;
}

int sum(int v[],int k){
  int total=0;
  for(int i=0;i<=k;i++){
    total=total+v[i];
  }
  return total;
}

void bkt(int sol[],int k){
  for(int i=primes.size()-1;i>=0;i--){
    sol[k]=primes[i];
    if(k==0){
      bkt(sol,k+1);
    }else{
      if(sol[k]<=sol[k-1] && k<=n/2+1){
        if(sum(sol,k)==n){
          cout<<"sol found ";
          print(sol,k);
          cout<<endl;
        }else{
          bkt(sol,k+1);
        }
      }
    }
  }
}

int main(){
  cin>>n;
  makePrime(n);
  bkt(sol,0);
}
