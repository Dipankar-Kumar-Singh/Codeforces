#include <bits/stdc++.h>
using namespace std;

#define int long long
const long long MOD = 1e9 + 7;
const long long INF = numeric_limits<long long>::max();
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()


int n{} ;

bool inverted = 0 ;
vector<int> on , zo ;

char give( string  b , int i)
{

    if(inverted)
    {
        if(b[i] == '1') return '0' ;
        else return '1' ;
    }

    else return b[i] ;

}

signed main()
{
    FAST 
    t_case
    {
        n = 0 ;
        cin >> n ;

        string a , b ; 
        cin >> a >> b ;

        on.clear() , zo.clear() ;
        on.resize(n+1,0) , zo.resize(n+1,0) ;

        int possible = 1 ;
    
        for(int i = 1 ; i <= n ; i++)
        {   
            zo[i] =  (b[i-1]=='0') + zo[i-1] ;
            on[i] =  (b[i-1]=='1') + on[i-1] ;
        }

        if(n==1)
        {
            if(a==b) cout << "YES\n" ; 
            else cout << "NO\n";
            continue ;
        }

        for(int j = n-1 ; j >= 0 ; j--)
        {
            if(a[j] != give(b,j))
            {   
                inverted = !inverted ;
                int zz = zo[j+1]  , oo = on[j+1] ;
                if(zz != oo) 
                {   possible = 0 ;
                    break ;
                }
                
            }
        }

        if(possible) cout << "YES\n" ;
        else cout << "NO\n" ;                                                       
                                       
    }
}

