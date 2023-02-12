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
   int n ; cin >>  n; 
   int m ; cin >> m ;
   string s ;
   for(int i = 0 ; i < m ; i++) s += 'B' ;

   for(int i = 0 ; i < n; i++)
   {
        int x; cin >> x ;
        x-- ;

        x = min(x,m-x-1) ;
        int a = x;
        int b = m - x - 1;
        if(s[a] != 'A') s[x] = 'A' ;
        else s[b] = 'A' ;
   }

   cout << s << nl ;

}
signed main(){   FAST      TestCases      solve() ;  }



