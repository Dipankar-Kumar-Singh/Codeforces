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
        
        string a , s ; cin >> a >> s ;

        string sc = s ;


        // int i = 0 , j = 0 ; 

        string b ;

        bool never_pos = 0 ;

        if(s.size() < a.size()) 
        {
            never_pos =  1 ;
            cout << -1 << "\n" ;
            continue ;
        }


        for(int i = a.size() - 1  ; i >= 0 ; i--)
        {   

            if(s.empty())
            {
                    never_pos = 1 ;
                    break ;
            }

            char x = a[i] ;

            char y = s.back() ;

            s.pop_back() ;

            if(y < x )
            {
                string bundle ; 
                bundle.push_back(y) ;

                if(s.empty())
                {
                    never_pos = 1 ;
                    break ;
                }

   
                y = s.back() ;
                s.pop_back() ;


                bundle.push_back(y) ;

                reverse(all(bundle)) ;

                int bd = stoi(bundle) ;
 
                int dif = bd - (x-'0') ;

                if(dif>=10  or dif<0)
                { 
                    never_pos = 1 ; 
                    break ;
                }

               
                string p11 = to_string(dif) ;
                b += p11 ;
        
            }

            else 
            {
                
                int num1 = x - '0';
                int num2 = y - '0' ;


                int dif = abs(num2 - num1 ) ;

                string p11 = to_string(dif) ;

                b += p11 ;
 

            }
 

        }

        if(never_pos)
        {
            cout << -1 << "\n" ;
            continue; 
        }


        while (!s.empty())
        {
            b +=s.back() ; 
            s.pop_back() ;
        }
        

        if(never_pos)
        {
            cout << -1 << "\n" ;
            continue; 
        }

        reverse(all(b)) ;

        int ans = 0 ; 
        if(!never_pos)  ans  = stoll(b) ;
        
        cout << ans << "\n" ;
                        
                                       
    }
}

