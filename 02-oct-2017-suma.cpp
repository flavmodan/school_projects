#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int S = 9;

/** ahem
 * cand dai ca parametru un obiect (in C++) dânsul/masale este copiat (masale de la matale)
 * din motive de eficienta iei obiectul readonly cand se poate
 * const ca sa nu-l schimbi (dăă)
 * ref ca sa nu fie copiat
 * foloseste vector in plm, deque ul nu e eficient. e o combiatie de array si linked list (oribil)
 */

/** Alte trick uri
 * cout << '\n' in loc de endl, endl da buffer flush care fute cache ul si performanta
 * de asemenea cout << ' ' nu " "
 * ai putea sa foloseti for(int* elem = v; elem != v + n; elem++) si foloseti *elem in loc de v[i]
 * am vazut ca varianta cu pointer e de 2 ori mai rapida daca initializezi un vector cu 0 (benckmark de vara trecuta)
 * despre pointeri la vector si deque:
 * for(vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter) s += *iter;
 * da, e naspa de scris, dar in c++11 ai: auto iter = v.begin() in loc de vector<int>::iterator
 * si mai ai for(int& elem : v) elem = 0 sau for(auto& elem: v) cout << elem
 * dar astea sunt in c++11 iar olimpiada foloseste c++98, si nu ii poti convinge sa schimbe
 * also in c++11: auto s = accumulate(v.begin, v.end(), 0, plus<int>()) in loc de makeSum, in haskell: foldr (+) 0 v sau sum v
 * cam atat
*/

int makeSum(const vector<int>& v){
  int s=0;
  for(int i=0;i<v.size();i++)
    s+=v[i];
  return s;
}

void print(const vector<int>& v){
  for(int i=0;i<v.size();i++)
    cout<<v[i]<<" ";
  cout<<endl;
}

void bkt(vecotr<int>& v){
  for(int i=S-1;i>=1;i--){
    v.push_back(i);
    //print(v);
    if((v.size()==1 || v[v.size()-1]<v[v.size()-2])&&v.size()<=S-1){
      print(v);
      if(makeSum(v)==S){
        cout<<"sol found : ";
        print(v);
      }
      else{
        bkt(v);
        //v.pop_back();
      }
    }
  }
}

int main(){
  vector<int> sol;
  bkt(sol);
}
