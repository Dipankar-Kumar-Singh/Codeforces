#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int total ; cin >> total ;  for(test = 1 ; test <=  total ; test++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n"  
#define print(ans) cout << "Case #" << test << ": " << ans << "\n" ;
int test = 0 ;
void solve()
{
    int n = 8 ;
    vector<string> v(n) ; 
    for(auto &r : v) cin >> r ; 

    
    for(int i = 0 ; i < n ; i++)
    {
        set<char> s  ;
        for(int j = 0 ; j < n ; j++)
        {
            s.insert(v[i][j]) ;
        }

        if(s.size()==1)
        {
            if(*s.begin() == 'R')
            {
                cout << *s.begin() << nl ;
                return ;
            }
        }
    }

    for(int j = 0 ; j < n ; j++)
    {
        set<char> s  ;
        for(int i = 0 ; i < n ; i++)
        {
            s.insert(v[i][j]) ;
        }

        if(s.size()==1)
        {
            if(*s.begin() == 'B')
            {
                cout << *s.begin() << nl ;
                return ;
            }
        }
    }
    
}

signed main(){  FAST    TestCases    solve() ; }