#include <iostream>
#include <string>
using namespace std;
string a = "abcd";
int n=4,counter=1;

void alt_back(string x){
  
}

int  backtracking(string x,int k,int l){
  
 
  for (int i=0;i<n;i++){
    x[k]=a[i];
    //cout<<x<<endl;
    if(k>0){
      if (x[k]!='a' ||  x[k-1]!='a'){
        
        if (k==l){
          cout<<x<<" ";
          counter++;
          cout<<counter<<endl;
          return 0;
         
        }else{
          backtracking(x,k+1,l);
        }
      }
      
    }else if(k==0){
      backtracking(x,k+1,l);
    }
  }
  
}

int main(){
  int i = backtracking("    ",0,4);
}


