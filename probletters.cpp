#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

vector<char> letters;
int n;

ifstream fin("d.in");

bool check(vector<char> attempt){
  int countLetters=0;
  for(int i=0;i<attempt.size()-1;i++){
    if(attempt[i]==attempt[i+1])
      return false;
    if(attempt[i]==letters[0])
      countLetters++;
  }
  if(attempt[attempt.size()-1]==letters[0])
    countLetters++;
  if(countLetters>=n/2)
    return false;
  return true;
}

void bkt(vector<char> v){
  for(int i=0;i<letters.size();i++){
    v.push_back(letters[i]);
    if(check(v)){
      if(v.size()==n){
        for(int k=0;k<v.size();k++)
          cout<<v[k]<<" ";
        cout<<endl;
      }else{
        bkt(v);
        v.pop_back();
      }
    }
  }
}
int main(){
  int p;
  fin>>n>>p;
  for(int i=0;i<p;i++){
    char temp;
    fin>>temp;
    letters.push_back(temp);
    cout<<temp;
  }
  vector<char>sol;
  bkt(sol);
}
