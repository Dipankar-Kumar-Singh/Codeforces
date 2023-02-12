#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 


void solve()
{
    string s; cin >> s ;
    int n = s.size() ;

    if((s.back()=='A') or (s.front()=='B')) {cout << "NO\n" ; return ;}

    int ca{} , cb{} ;
    for(auto &x : s )  
    {
        if(x=='A') ca++ ; else cb++ ;
    }

    if((ca<cb) ) {cout << "NO\n" ; return ;}

    vector<bool> marked(s.size(),0) ;

    for(int i = 0 ; i < n ; i++)
    {
        if(s[i]=='B')
        for(int j = i ; j >= 0 ; j--)
        {
            if(!marked[j] and s[j]=='A') 
            {
                marked[j] = 1; 
                break;
            }

            else if(j==0)
            {
                cout << "NO\n" ;
                return ;
            }
        }
    }

    cout << "YES\n" ;
    return ;
    
}

signed main()
{   FAST  

    TestCases  
    solve() ;  

}

