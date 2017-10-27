#include<iostream>
#include<deque>
#include<string>
#include<fstream>

using namespace std;

ifstream fin("fazan.in");
ofstream fout("fazan.out");

bool checkFazan(string a , string b){

  if((a[a.length()-1]==b[1])&&(a[a.length()-2]==b[0]))
    return true;
  return false;
}

bool appears(deque<string> sol,string k){
  for(int i=0;i<sol.size();i++){
    if(k==sol[i])
      return true;
  }
  return false;
}


int n,m;
deque<string> words;
void bkt(deque<string> sol){
  for(int i=0;i<words.size();i++){
    if(!appears(sol,words[i])){
      sol.push_back(words[i]);
      // for(int k=0;k<sol.size();k++){
      //   cout<<sol[k]<<" ";
      // }
      // cout<<endl;
      if(sol.size()<=1){
        bkt(sol);
        sol.pop_back();
      }else{
        if(checkFazan(sol[sol.size()-2],sol[sol.size()-1])){
          cout<<"sol : ";
            for(int k=0;k<sol.size();k++){
              cout<<sol[k]<<" ";
            }
            cout<<endl;
          }else{
            bkt(sol);
            sol.pop_back();
          }

      }
    }
  }
}

int main(){
    fin>>n>>m;

    for(int i=0;i<n;i++){
      string temp;
      fin>>temp;
      words.push_back(temp);
    }
    deque<string> sol;
    bkt(sol);
    //cout<<checkFazan("paul","ultim");
  }
