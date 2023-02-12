#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int total ; cin >> total ;  for(test = 1 ; test <=  total ; test++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n"  
#define print(ans) cout << "Case #" << test << ": " << ans << "\n" ;


int const INF  = 1e18 ;
int test = 0 ;


void solve()
{
    int ans = 0 ; 
    string s ; cin >> s;
    int n = s.size() ;


    for(int i = 0 ; i < n ; i++)
    {
        set<char> st ;
        for(int j = i ; j < n ; j++)
        {
            // cerr << s[j] << " " ;
            st.insert(s[j]) ;
            if(st.size()>3)
            {
                i = j - 1;
                ans++ ;
                // cerr << " i = " << i << nl;
                break;
            }
            else if (j == s.size() - 1)
            {
                i = n;
                ans++;
                break;
            }
        }
        // cerr << endl ;
    }

    // cerr << nl << nl << nl ;
    

    cout << ans << nl;
    

    

    // print(ans) ;
}

signed main(){  FAST    TestCases    solve() ; }