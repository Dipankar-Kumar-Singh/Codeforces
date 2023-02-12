#include <bits/stdc++.h>
using namespace std;

#define int long long
const long long MOD = 1e9 + 7;
const long long INF = numeric_limits<long long>::max();
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()


int n {} , x{} ;
vector<int> v ;
vector<int> taken  ;

int k = 0 ;

void solve(int id)
{
    int sum = 0 ;

    int len = 1 ;

    for(int i = id ; i <= n ; i++ )
    {
        int a = v[i] ;

        if(i == id)
        {
            if(taken[i-1]==1 and v[i-1] + v[i] < 2*x) 
            {
                k = i ;
                taken[i] = 0 ;
                return ;
            }

            sum += a ;
            taken[i] = 1 ;
            k = i ;
        }

        else if(sum + a >= len*x)
        {
            taken[i] = 1  ;
            sum += a ;
            k = i ;

            if(a<x)
            {
                k-- ;
                return ;
            }
        }

        else if(sum + a < len*x)
        {
            k = i  ;
            return ;
        }

        len++ ;
    }

}


signed main()
{
    FAST 
    t_case
    {
        n = 0 , x = 0 ; k = 1 ;
        v.clear() , taken.clear() ;
        
        cin >> n ;

        v.resize(n+1,0) , taken.resize(n+1,0) ;

        for(int i = 1 ; i <= n ; i++)
        {
            cin >> v[i] ;
        }

        cin >> x ;

        for( ; k <= n ; k++)
        {
            solve(k) ;
        }

        cout << count(all(taken),1) << "\n" ;           
    }
}

