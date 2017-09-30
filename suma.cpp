#include <iostream>
#include<ctime>
using namespace std ;

int n=9,sol[100000];



void print(int v[],int k){
  for(int i=k;i>0;i--){
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
  for(int i=n;i>=0;i--){
    sol[k]=i;
    if(k==0){
      bkt(sol,k+1);
    }else{
      if(sol[k]<=sol[k-1] && k<=n){
        if(sum(sol,k)==n){
          /*cout<<n<<" = ";
          print(sol,k);
          cout<<endl;
          */
        }else{
          bkt(sol,k+1);
        }
      }
    }
  }
}

int main(){
  for(n=9;n<15;n++){
    float stime=clock();
    bkt(sol,0);
    float etime=clock();
    cout<<n<<" : "<<(etime-stime)/CLOCKS_PER_SEC<<endl;
  }


}
