#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n"


bool do_swap_and_check(vector<vector<int>> &v , int n , int m , int id1 , int id2 )
{

    for(int i = 0 ; i < n ; i++)
        swap(v[i][id1], v[i][id2]);

    bool possible = 1 ;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j + 1< m; j++)
        {
            if(v[i][j]>v[i][j+1])
            {
                possible = 0 ;
                break;
            }
        }
    }

    for(int i = 0 ; i < n ; i++)
        swap(v[i][id1], v[i][id2]);

    return possible ;

}

void solve()
{
    int n , m ; cin >> n >> m ;
    vector<vector<int>> v(n,vector<int>(m,0)) ;

    for(auto &row : v) for(auto &x : row) cin >> x;

    int found = 0 ;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j + 1 < m; j++)
        {
            if(v[i][j]>v[i][j+1])
            {
                found = 1 ;
                int a = -1 , b = -1 ;

                int MIN = LONG_LONG_MAX ;

                for(int k = j ; k < m ; k++) MIN = min(MIN,v[i][k]) ;
                vector<int> ids ;
                for (int k = j; k < m; k++)
                    if (v[i][k] == MIN)
                    {
                        ids.push_back(k);
                        if (do_swap_and_check(v, n, m, k, j))
                        {
                            a = k, b = j;
                            break;
                        }
                    }
                    

                int maxElement = -10 ;
                for(int k = 0 ; k <= j ; k++) 
                    maxElement = max(maxElement,v[i][k]) ;

                for (int k = 0; k <= j; k++)
                    if (v[i][k] == maxElement)
                    {
                        if (do_swap_and_check(v, n, m, k, j + 1))
                        {
                            a = k, b = j + 1;
                            break;
                        }
                    }

    
                if(a==-1 and b==-1)
                {
                    cout << -1 << nl ;
                    return ;
                }

                if(a>b) swap(a,b) ;
                a++ , b++ ;

                cout << a << " " << b << nl ;
                return ;
            }
        }
    }

    if(!found)
    {
        cout << "1 1" << nl ;
    }
}

signed main()
{   FAST  

    TestCases  
    solve() ;  

}
