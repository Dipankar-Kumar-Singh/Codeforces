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
   string u , d ;
   cin >> u >> d ;

   for(int i =  0 ; i < n ; i++)
   {
        if(u[i]=='B') u[i] = 'G' ;
        if(d[i]=='B') d[i] = 'G' ;
   }

   cout << ((d == u) ? "YES" : "NO") << nl;
}
signed main(){   FAST      TestCases      solve() ;  }



