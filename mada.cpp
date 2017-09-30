#include<iostream>
using namespace std;
int x[50],n,l,a;
int valid(int k)
{
  for(int i=1;i<k;i++)
    {
      if(x[i]==x[k])
        return 0;
    }
  if(k==1 and x[k]==0)
    return 0;
}
void af()
{
  for(int i=0;i<=n;i++)
    cout<<x[i];
  cout<<endl;
  a++;
}
void bkt(int k)
{
  for(int i=0;i<=9;i++)
    {
      x[k]=i;
      if(valid(k))
        if(k==n)
          {
            int s;
            for(int i=1;i<=n;i++)
              s+=x[i];
            if(s==l)
              af();
          }
        else
          bkt(k+1);
    }
}
int main()
{
  cin>>n>>l;
  if(a==0)
    cout<<"NU EXISTA";
}
