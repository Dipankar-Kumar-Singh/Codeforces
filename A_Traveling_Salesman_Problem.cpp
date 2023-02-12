#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(_case = 1 ; _case <=  TOTALTC ; _case++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int _case = 1 ;

void solve()
{
   int n;   cin >> n;
   set<int> sx , sy ;

   for(int i = 0 ; i < n ; i++)
   {
        int x , y ; cin >> x >> y ;
        sx.insert(x) ; sy.insert(y) ;
   }


   int ans = 0 ; 
   if(*sx.begin()<0) ans += abs(*sx.begin())*2 ;
   if(*sy.begin()<0) ans += abs(*sy.begin())*2 ;
   if(*--sy.end()>0) ans += *--sy.end()*2 ;
   if(*--sx.end()>0) ans += *--sx.end()*2 ;


   cout << ans << nl ;

}
signed main(){   FAST      TestCases      solve() ;  }



