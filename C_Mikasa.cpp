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
   int n , m ; cin >> n >> m ;
   int ans = 0 ;
   m++ ;
   if(n > m) {cout << 0 << nl ; return ;}
    // n xor v[i] >= m + 1 ;
    
   for(int i = 30 ; i >= 0 ; i--)
   {
       int mbit = (m >> i) & 1;
       int nbit = (n >> i) & 1;

       if(mbit)
       {
           if (nbit == 0) ans = ans | (1 << i) ;
       }

       else 
       {
            if(nbit == 1)
            {
                break;
            }
       }
   }

   cout << ans << nl ;

}
signed main(){   FAST      TestCases      solve() ;  }



