#include <bits/stdc++.h>
using namespace std;

#define int long long
const long long MOD = 1e9 + 7;
const long long INF = numeric_limits<long long>::max();
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" ;


int n , m , k ; 
int dir = 1 ;

pair<int,int> inc(int &r , int &c )
{
    if(dir == 1)
    {
        c++ ;
        if(c == m) 
        { c = m - 1  ; r++ ; dir = -1 ;}
    }

    else if(dir == -1)
    {
        c-- ;
        if( c < 0 )
        {
            c = 0 ;
            r++ ;
            dir = 1  ;
        }
    }


    return {r,c} ;
}

signed main()
{
    FAST 
    cin >> n >> m >> k ;

    int r = 0 , c = 0 ; 
   

    vector<pair<int,int>> v ;

    int points = n*m ;

    while (points--)
    {
        v.push_back({r,c}) ;
        inc(r,c) ;
    }

    int p = 0 ;

    for(int loop = 1; loop <= k; loop++)
    {
        if(loop == k)
        {
            cout << v.size() - p << " " ;
            for(int i = p ; i < v.size() ; i++)
            {
                cout << v[i].first + 1 << " " <<  v[i].second + 1 << " ";
            }
        }

        else
        {
            int ct = 2;
            cout << ct << " ";
            while (ct--)
            {
                cout << v[p].first + 1 << " " << v[p].second + 1 << " ";
                p++;
            }

            cout << nl;
        }
    }

}

