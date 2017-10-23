#include<iostream>
#include<vector>

using namespace std;

struct Box{
  vector<int>elements;
};

int m,n;

Box boxes[100];

bool appears(int x){
  for(int i=1;i<=m;i++){
    for(int j=0;j<boxes[i].elements.size();j++){
      if(x==boxes[i].elements[j])
        return true;
    }
  }
  return false;
}

int totalElements(){
  int sum=0;
  for(int i=1;i<=m;i++){
    sum+=boxes[i].elements.size();
  }
  return sum;
}

void bkt(int box){
  for(int i=1;i<=n;i++){
    if(!appears(i)){
      for(int k=1;k<=m;k++){
        cout<<endl<<i <<" :: box "<<k<<" : ";
        for(int l=0;l<boxes[k].elements.size();l++){
          cout<<boxes[k].elements[l]<<" ";
        }
        if(k==m)
          cout<<endl;
      }
      boxes[box].elements.push_back(i);
      if(box==m){
        if(totalElements()==n){
          cout<<" solution :: ";
          for(int k=1;k<=m;k++){
            cout<<"box "<<k<<" : ";
            for(int l=0;l<boxes[k].elements.size();l++){
              cout<<boxes[k].elements[l]<<" ";
            }
            if(k==m)
              cout<<endl;
          }
        }
      }else{
        bkt(box+1);
        for(int k=0;k<=boxes[box+1].elements.size();k++){
          boxes[box+1].elements.pop_back();
        }
        if(i<n)
          boxes[box].elements.pop_back();
        if(i==n){
          i=0;
          if(boxes[box].elements.size()==n-1){
            for(int k=0;k<=boxes[box].elements.size();k++){
              boxes[box].elements.pop_back();
            }
          }
        }
        for(int l=0;l<boxes[box].elements.size();l++){
          cout<<boxes[box].elements[l]<<" ";
        }
        cout<<endl<<i<<endl;;
        cout<<endl;

      }
    }
  }
}
int main(){
  n=3,m=2;
  bkt(1);
}
