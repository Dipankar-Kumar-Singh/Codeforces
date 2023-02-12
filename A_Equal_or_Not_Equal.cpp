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

        int n = s.size() ;

    

        int total_changes = count(s.begin() , s.begin() + n-1 , 'N') ;

        if(total_changes == 0)
        {
            if(s.back() == 'N')
            {
                cout << "NO\n" ;
            }

            else cout << "YES\n" ;

            continue ;
        }

        else if(total_changes == 1){
            if(s.back( ) == 'E')
            {
                cout << "NO\n" ;
            }

            else cout << "YES\n" ;

            continue ;
        }

        else cout << "YES\n" ;

       


        
                                  
                                        
                                       
    }
}

