#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 


void solve()
{
   int n ; cin >> n ;
   vector<int> v (n) ; for(auto &x : v) cin >> x ;

   map<int,int> m ;

   for(auto &x : v)
   {
        int d = x%10 ;
        m[d]++ ;
   }

   for(auto &x : v)
   {
      
        int d = x%10 ;
        m[d]-- ;

        int req = 3 - d ;
        if(req<0) req = (10 - abs(req)) ;

        for(int i = 0 ; i <= 10 ; i++)
        {

            for(int j = 0 ; j <= 10 ; j++ )
            {
                if((i+j)%10!=req) continue;
                int a = i;
                int b = j;
                if (m[a])
                {
                    m[a]--;
                    if (m[b])
                    {
                        cout << "YES\n";
                        return;
                    }
                    m[a]++;
                }
            }
        } 

        m[d]++ ;
   }

   cout << "NO\n" ;


}
signed main(){   FAST      TestCases      solve() ;  }
