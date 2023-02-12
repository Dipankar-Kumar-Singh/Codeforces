#include <bits/stdc++.h>
using namespace std;

#define int long long
const long long MOD = 1e9 + 7;
const long long INF = numeric_limits<long long>::max();
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()

void nop()
{
    cout << "-1\n" ;
}

signed main()
{
    FAST 
    t_case
    {
        int n ; cin >> n ;
        int k ; cin >> k ;

        if(k>n)
        {
           cout << "-1\n" ;
           continue ;
        }

        int m = ceil(n*1.0 /(double)2) ;
      
        if(n == 1)
        {
            if(k==1) 
            {
                cout << "R\n" ; 
                continue ;
            }

            else  if(k == 0)
            {
                cout << ".\n" ; 
                continue ;
            }

            else 
            {
                cout << "-1\n" ; 
                continue ;
            }
        }

        if(k>m)
        {
            cout << "-1\n" ; 
            continue ;
        }

         for(int i = 0 ; i < n ; i ++)
            {
                for(int j = 0 ; j < n ; j++)
                {
                    if(i==j and i%2==0 and k>0)
                    {
                        cout << 'R'  ;
                        k-- ;
                    }

                    else cout << '.' ;
                }

                cout << "\n" ;
            }








        
                                  
                                        
                                       
    }
}

