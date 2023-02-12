#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 


void solve()
{
    string s;
    cin >> s;

    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if(s[i]=='0')
        {
            cout << i + 1 << nl ;
            return ;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if(s[i]=='?')
        {
            cout << i + 1 << nl ;
            return ;
        }
    }

    cout << 1 << nl ;


}

signed main()
{   FAST  

    TestCases  
    solve() ;  

}

