#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 

int const N = 27 ;

void solve()
{
    map<pair<char,char>,int> m ;
    int n ; cin >> n;  int ans = 0 ;

    for(int i = 0 ; i < n; i++)
    {
        string s ; cin >> s ;   
        char c1 = s[0] , c2 = s[1] ;
        m[{c1,c2}]++ ;

        for(char c = 'a' ; c <= 'z' ; c++)
        {
            if (c != c2)   ans += m[{c1, c}];
            if (c != c1)   ans += m[{c, c2}];
        }
    }

    cout << ans << nl ;
}

signed main()
{   FAST  

    TestCases  
    solve() ;  

}

