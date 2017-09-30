#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
 
int nums[]={5,2,7,3},n=4;

int add(string operands){
  int sum=nums[0];
  for(int i=0;i<operands.length();i++){
    if(operands[i]=='+'){
      sum+=nums[i+1];
    }else{
      sum-=nums[i+1];
    }
  }
  return sum;

}

void print(string operands){
  cout<<nums[0];
  for(int i=0;i<n-1;i++){
    cout<<operands[i]<<nums[i+1];
  }
  cout<<endl;
}

void generate(){
  string temp[4]={"+++","++-","+--","---"};
  for(int i=0;i<4;i++)
    do{
      if(add(temp[i])>0){
        print(temp[i]);
      }
    }while(next_permutation(temp[i].begin(),temp[i].end()));
  
}

int main(){
  generate();
}
