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
   string s; cin >> s ;
   string t ; for(auto x : s) t += towlower(x) ;
   cout <<( t =="yes" ? "YES" : "NO") << nl ;

}
signed main(){   FAST      TestCases      solve() ;  }



