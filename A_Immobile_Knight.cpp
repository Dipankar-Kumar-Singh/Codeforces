#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int total ; cin >> total ;  for(test = 1 ; test <=  total ; test++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n"  
#define print(ans) cout << "Case #" << test << ": " << ans << "\n" ;


int const INF  = 1e18 ;
int test = 0 ;


void solve()
{
    int n ; cin >> n ;
    int m ; cin >> m ;

    auto valid = [&](int i , int j) -> bool {
        if( i < 0 or j < 0  or i >= n or j>=m ) return 0 ;
        return 1 ;
    } ;

    auto gen = [&](int i, int j) -> vector<pair<int, int>>
    {
        vector<pair<int, int>> v = {{i - 2, j - 1},
                                    {i - 2, j + 1},
                                    {i - 1, j + 2},
                                    {i + 1, j + 2},
                                    {i + 2, j + 1},
                                    {i + 2, j - 1},
                                    {i + 1, j - 2},
                                    {i - 1, j - 2}};

        return v ;
    };

    for(int i = 0; i < n ; i++)
    {
        for(int j = 0 ; j < m  ; j++)
        {
            
            bool canmove = 0 ;
            for(auto [x , y ] : gen(i,j))
            {
                if(valid(x,y))
                {
                     canmove = true ;
                }
            }

            if(canmove == 0)
            {
                cout << i + 1 << " " << j + 1 << nl ;
                return ;
            }
        }
    } 

    cout << 1 << " " << 1 << nl ;   

}

signed main(){  FAST    TestCases    solve() ; }