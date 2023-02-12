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
   
   vector<int> f(n+10) ; 
   f[0] = 1 ; f[1] = 0 ;

   for(int i = 2 ; i <= n ; i++) f[i] = 2*f[i-2] ;

   cout << f[n] << endl ;

}
signed main(){   FAST     solve() ;  }



