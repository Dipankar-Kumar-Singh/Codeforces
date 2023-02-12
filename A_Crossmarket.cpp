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
   int n , m ; 
   cin >> n >> m ;

   if(n < m ) swap(n,m) ;

   int h = (m > 1 ? 1 : 0) ; 

    int c = min(n,m) ;
    int r = max(n,m) ;

    if(n==1 and m==1)
    {
        cout << 0 << nl ;
        return ;
    }

    cout << 1 + r -1 + c - 1 + c -1 << nl ;


}
signed main(){   FAST      TestCases      solve() ;  }



