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
        int a , b , c; 
        cin >> a >> b >> c ; 


        if((b-a) == (c- b)) 
        {
            cout << "YES\n" ; continue ;
        }

        // ab -> c

        int d = b-a ;
        
        int cc = b + (d) ;

        if(cc%c==0 and cc>0)
        {
           int t = cc/c ;
           if(t*c == cc)
           {
               cout << "YES\n" ; 
               continue ;
           }
        }
       
        // bc --> a

        d = 0 ; cc = 0 ;
        d = c-b ;
        cc = b - d ;

     

        if(cc%a==0 and cc>0)
        {     
           
             int t = cc/a ;
             if (t * a == cc)
             {
                 cout << "YES\n";
                 continue;
             }
        }
     

        // ca --> b

        d = 0 , cc = 0 ;

        d = c-a ;
        if(d%2!=0 )
        {   
            cout << "NO\n";
            continue;
        }

        d = d/2 ;

        cc = a  + d ;

        if(cc%b==0 and cc>0)
        {   
            int t = cc/b ;
            if (t * b == cc)
            {
                cout << "YES\n";
                continue;
            }
        }
        else 
        {
            cout << "NO\n" ; continue ;
        }   
                                        
                                       
    }
}

