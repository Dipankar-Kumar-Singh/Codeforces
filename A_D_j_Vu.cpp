#include <bits/stdc++.h>
using namespace std;

#define int long long
const long long MOD = 1e9 + 7;
const long long INF = numeric_limits<long long>::max();
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()


bool isPla(string s)
{
    int l = 0 , r = s.size( )  -1 ;
    while (l<=r)
    {
       if(s[l]!=s[r]) return 0 ;
       l++ ;
       r--;
    }
    return 1 ;
}

bool all_a(string s)
{
    for(auto &c : s)
    {
        if(c != 'a') return 0 ;
    }

    return 1 ;
}

signed main()
{
    FAST 
    t_case
    {

     string s ; cin >> s ;
    
        if(all_a(s))
        {

            cout << "NO\n" ; continue;

        }

        // if(isPla(s))
        // {
        //     s.push_back('a') ;
        //     cout << "YES\n" ; cout << s << "\n" ;

        //     continue ;
        // }

        // else 
        // {
        //     string s2 = s ;
        //     s2.push_back('a') ;

        // }



        string s1 = s , s2 = s ;

        reverse(all(s2)) ; s2+='a' ; reverse(all(s2)) ;

        s1+='a' ;

        if(!isPla(s1))
        {
            cout << "YES\n" ; cout << s1 << "\n" ;
        }

        else if(!isPla(s2))
        {
            cout << "YES\n" ; cout << s2 << "\n" ;
        }
                                  
                                        
                                       
    }
}

