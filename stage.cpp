#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

ifstream fin("nr.in");

struct Event{
  int start,finish;
};

bool order(Event A,Event B){
  return A.start<B.finish;
}

int main(){
  int n;
  Event events[100];
  fin>>n;
  for(int i=0;i<n;i++){
    int a,b;
    fin>>a>>b;
    events[i].start=a*60+b;
  }
  for(int i=0;i<n;i++){
    int a,b;
    fin>>a>>b;
    events[i].finish=a*60+b;
  }
  sort(events,events+n,order);
  cout<<events[0].start/60<<" "<<events[0].start%60<<"->"<<events[0].finish/60<<" "<<events[0].finish%60<<endl;
  for(int i=1;i<n-1;i++){
    ;
    if(events[i].finish<=events[i+1].start){
      cout<<events[i].start/60<<" "<<events[i].start%60<<"->"<<events[i].finish/60<<" "<<events[i].finish%60<<endl;;
    }
  }



}
