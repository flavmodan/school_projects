#include<iostream>
#include<string>
using namespace std;

bool let[100];

string word="alinus";

void bkt(int w[],int k){
  for(int i=w[k-1];i<=word.length();i++){
    w[k]=i;
    if((let[w[k]] && w[k]==k)||!let[w[k]]){
      if(k==word.length()){
        for(int i=0;i<=k;i++){
          cout<<word[w[i]];
        }
        cout<<endl;
      }else{
        bkt(w,k+1);
      }
    }
  }
}

void make(){
  for(int i=1;i<=word.length();i++){
    if(word[i]!='a' && word[i]!='e' && word[i]!='i'&& word[i]!='u'&& word[i]!='o'){
      let[i]=true;
    }
  }
}

int main(){
  make();
  int w[100];
  bkt(w,1);
}
