#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(_case = 1 ; _case <=  TOTALTC ; _case++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int _case = 1 ;
int const INF = 1e10 ;

bool nonInc(vector<int> &v , int n)
{
    int st = INF ;
    for(auto x : v)
    {
        if(x <= st) st = x ;
        else return 0 ;
    }

    return 1 ;
}

bool nonDec(vector<int> &v, int n)
{
    int st = -1 ;
    for(auto x : v)
    {
        if(x >= st) st = x ;
        else return 0 ;
    }

    return 1 ;  
}

bool incThenDec(vector<int> &v, int n)
{
    auto it = max_element(all(v)) ;
    auto it1 = it ;
    auto it2 = it ;

    if(it==v.begin()) return 0 ;
    if(it==v.end()) return 0 ;

    vector<int> v1 , v2;

    for( ; ; it1--)
    {
        v1.push_back(*it1) ;
        if(it1==v.begin()) break;
    }

     for( ; it2 != v.end() ; it2++)
    {
        v2.push_back(*it2) ;
    }

    return (nonInc(v1,v1.size()) and nonInc(v2,v2.size())) ;
}


void solve()
{
   int n;   cin >> n;
   vector<int> v(n);  for (auto &x : v) cin >> x;


   if(nonDec(v,n) or nonInc(v,n) or incThenDec(v,n))
   {
        cout << "YES" << nl ;
   }

   else cout << "NO\n" ;

}
signed main(){   FAST      TestCases      solve() ;  }



