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
   int H , M ; cin >> H >> M ;

   int ans = 1e10 ;
   pair<int,int> anspair ;

    for(int i = 0 ; i < n ; i++)
    {
        int h , m ;
        cin >> h >> m ;

        if(h < H)
        {
            H = 24 - H ;
        }
        
        int hr = H + h ;

        if(M < m) M = 60 - M ;

        int mn = M + mn ;

        int len = hr * 60 + mn ;

        if(len < ans)
        {
            ans = len ;
            anspair = {hr,mn} ;
        }

    }

   cout << anspair.first << "  " << anspair.second << nl  ;


}
signed main(){   FAST      TestCases      solve() ;  }



