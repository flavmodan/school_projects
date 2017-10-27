#include<iostream>
#include<fstream>

using namespace std;

ifstream fin("date.in");

int main(int argc, char *argv[argc])
{
  int maxDistance,coordonates[100],nrInFront[100],indexInFront[100];
  int n;
  fin>>n;
  for (int i = 0; i < n; i++) {
    fin>>coordonates[i];
  }
  fin>>maxDistance;
  nrInFront[n-1]=1;
  indexInFront[n-1]=-1;
  for (int i = n-2; i >=0; i--) {
    int j=i+1;
    while(coordonates[j]-coordonates[i]<maxDistance && j<n){
      j++;
    }
    nrInFront[i]=nrInFront[j]+1;
    indexInFront[i]=j;
  }
  cout<<nrInFront[0]<<endl;;
  int index=indexInFront[0];
  cout<<coordonates[0]<<" ";
  while(index!=-1){
    cout<<coordonates[index]<<" ";
    index=indexInFront[index];
  }



  return 0;
}
