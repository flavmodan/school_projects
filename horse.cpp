#include<fstream>
#include<iostream>
using namespace std;
int n, t[50][50],m; // m= numarul de mutari
int vx[8]={-2,-1,1,2,2,1,-1,-2}, vy[8]={1,2,2,1,-1,-2,-2,-1};
void tipar()
{ for(int i=1;i<=n;i++)
 {for(int j=1;j<=n;j++)
 cout<<t[i][j]<<' ';
 cout<<endl;
 } }
int verifica(int x,int y, int i)
{
 return (x+vx[i]>=1 && x+vx[i]<=n && y+vy[i]>=1 && y+vy[i]<=n && t[x+vx[i]][y+vy[i]]==0);
}
int numar(int x, int y) // numarul de pozitii pe care poate sari calul
{int nr=0;
for(int i=0;i<8;i++)
 if (verifica(x,y,i)) nr++;
return nr;
}
void greedy(int x , int y)
{int xf,yf, nrmin,gasit,nr;
t[x][y]=m; gasit=0; nrmin=9;
for(int i=0;i<8;i++)
 if ( verifica(x,y,i))
 { nr=numar(x+vx[i],y+vy[i]);
 if(nr<nrmin) // se alege calea cu numarul cel mai mic de posibilitati, cea mai putin accesibila
 {nrmin=nr;
 xf=x+vx[i];
 yf=y+vy[i];
 gasit=1;}
 }
 if(gasit)
 { m++; greedy(xf,yf); }
}
int main()
{ cout<<"n=";cin>>n;
 t[1][1]=1;m=1;
 greedy(1,1);
 if(m==n*n) tipar();
 else
 cout<<"Nu exista solutie";}
