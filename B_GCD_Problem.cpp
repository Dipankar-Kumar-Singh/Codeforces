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
        
        int n ; cin >> n ;

        int c {1}, b {} ; 
        int a = {} ;

        int on = n ;


            for( ; c < (on) ; c++ )
            {
                
                int rem = n - c ;   // 13 --> 12 
                a = rem/2  ;        // 12/2 --> 6 
                b = rem - a ;       // 12 - 6 --> 7
                
                while(gcd(a,b)!=c)
                {   
                    a++ , b-- ;
                    if(a==1 or b==1) break ;
                }

                if(gcd(a,b)==c) break ;

            }


        cout << a << " " << b << " " << c << "\n" ;

                        
                                       
    }
}

