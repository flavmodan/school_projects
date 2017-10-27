#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
using namespace std;

int sequence[100]={8,3,6,50,10,8,100,30,60,40,80},lengths[100],n=11;

int main(){
  // fill(lengths,lengths+n,1);
  // for(int i=0;i<n;i++){
  //   for(int j=i+1;j<n;j++){
  //     int max=sequence[i];
  //     if(max<sequence[j]){
  //       lengths[i]++;
  //       max=sequence[j];
  //       j++;
  //     }
  //   }
  // }


  lengths[n-1]=1;
  for(int i=n-2;i>=0;i--){
    for(int j=i+1;j<n;j++){
      if(sequence[i]<sequence[j]){
        lengths[i]=lengths[j]+1;
        break;
      }
    }
  }
  int maxim=0;
  for(int i=0;i<n;i++){
    cout<<lengths[i]<<" ";
    if(lengths[i]>=maxim)
      maxim=lengths[i];
  }
  cout<<endl<<maxim;
  // vector<vector<int> >subsequences;
  // subsequences.resize(n);
  // for(int i=0;i<n;i++){
  //   subsequences[i].push_back(sequence[i]);
  //   for(int j=i+1;j<n;j++){
  //     if(sequence[j]>subsequences[i][subsequences[i].size()-1]){
  //       subsequences[i].push_back(sequence[j]);
  //     }
  //   }
  // }
  // for(int i=0;i<subsequences.size();i++){
  //   for(int j=0;j<subsequences[i].size();j++){
  //     cout<<subsequences[i][j]<<" ";
  //   }
  //   cout<<endl;
  // }

}
