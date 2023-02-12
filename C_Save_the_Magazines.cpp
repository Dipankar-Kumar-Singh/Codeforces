#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int total ; cin >> total ;  for(test = 1 ; test <=  total ; test++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n"  


int const INF  = 1e18 ;
int test = 0 ;


void solve()
{
    int ans = 0 ; 
    int n ; cin >> n ;
    string s ; cin >> s ;
    vector<int> v(n) ; for(auto &x : v) cin >> x ; 

    for(int i = 0 ; i + 1 < n ; i++)
    {
        
        if(s[i]=='0' and s[i+1]=='1')
        {
            int minElement = v[i] ;
            int minElementIndex = i ;

            int lastOne = i + 1 ;
            for(int j = i + 1 ; j < n ; j++)
            {
                if(s[j] == '0') break;

                lastOne = j ;

                if(v[j] <= minElement)
                {
                    minElement = v[j] ;
                    minElementIndex = j ;
                }
            }

            // cout << "\nmin = " << minElement << " minId " << minElementIndex << nl ;

            for(int j = i ; j <= lastOne ; j++)
            {
                if(j == minElementIndex)
                {
                    s[j] = '0' ;
                }

                else 
                {
                    s[j] = '1' ;
                }
            }

            i = lastOne ;
        
        }
    }

    // cout << s << nl ;

    for(int i = 0; i < n ; i++)
    {
        if(s[i]=='1') ans += v[i] ;
    }

    cout << ans << nl ;

}

signed main(){  FAST    TestCases    solve() ; }