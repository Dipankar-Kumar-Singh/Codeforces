#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n"  

void solve()
{
    string s ; cin >> s ;

    map<char,int> fr ;

    for(auto x : s)
    {
        if(x>='A' and x <= 'Z')
        {
            auto y = tolower(x) ;
            if(fr[y]==0)
            {
                cout << "NO\n" ;
                return ;
            }
        }
        fr[x]++ ;
    }

    cout << "YES\n" ;


    

}

signed main()
{   FAST  

    TestCases  
    solve() ;  

}

