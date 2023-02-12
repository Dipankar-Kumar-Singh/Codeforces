#include <bits/stdc++.h>
using namespace std;

#define int long long
const long long MOD = 1e9 + 7;
const long long INF = numeric_limits<long long>::max();
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()


signed main()
{
    FAST 
    t_case
    {
        string s ; cin >> s ;

        if(s.size()&1)
        {
            cout << "NO\n" ;
            continue ;
        }

        else 
        {
            int n = s.size() ;

            string s1 (s.begin() , s.begin()+s.size()/2) ;
            string s2 (s.begin()+s.size()/2, s.end()) ;

            if(s1==s2)
            {
                cout << "YES\n" ;
                continue ;
            }

            else cout << "NO\n" ;


        }
        
                                  
                                        
                                       
    }
}

