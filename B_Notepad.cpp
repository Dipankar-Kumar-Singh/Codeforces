    // Everything in the Universe is Balanced 
    // Every Disappointment you face in life will be balanced with something good for you 
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(__case__ = 1 ; __case__ <=  TOTALTC ; __case__++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int __case__ = 1 ;

void solve()
{
    int n ; 
    cin >> n ;
    string s ; cin >> s ;
    set<string> st ;

    for (int i = 0; i < n; i++)
    {
        if (i + 1 < n)
        {
            string p = s.substr(i, 2);

            if (st.count(p))
            {
                cout << "YES\n";
                return;
            }

            else if(i - 1 >= 0)
            {
                p = s.substr(i - 1, 2);
                st.insert(p);
            }
        }
    }

    cout << "NO" << nl ;
}

signed main() { FAST TestCases solve(); }
