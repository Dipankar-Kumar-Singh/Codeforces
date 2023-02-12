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
    string s ; cin >> s ;

    int k ; cin >> k ; 
    
    for(int i = 0 ; i < k ;i++) s.push_back('?') ;

    int n = s.size() ;
    int ans = 0 ;

 
    for(int len = 0 ; 2*len <= n ; len++)
        {   
            for(int i = 0 ; i + len < n ; i++ )
            {
               
                int p1 = i - len ;  // first pointer  [ backword ]
                int p2 = i  ;       // second pointere [ forword ] 

                bool possible = 1 ;

                while (1)
                {
                    p1++ ; p2++ ;
                    if( p2 >= i+len ) break ; 


                    if(p1<0)  
                    {
                        possible = 0 ; break ;
                        // even without break , it was working fine , it was comparing garbage value ,
                        // but breaking without making possible false was cauing wrong answer .... [ longer len ]
                    }
                   

                    //if(s[p1]=='?' or s[p2]=='?') break ;
                    // "🔥" this statement was causing the problem

                    if(s[p1] != s[p2] and s[p2]!='?' and s[p1] !='?')
                    {
                        possible = 0 ; break ;
                    }
                }

                if(possible)
                {
                    ans = max(ans , len) ;
                }   
            }
        }


        cout << ans*2 ;

}

