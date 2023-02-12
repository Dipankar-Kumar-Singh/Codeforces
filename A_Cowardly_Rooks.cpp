#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(_case = 1 ; _case <=  TOTALTC ; _case++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int _case = 1 ;

void solve()
{
   int n;   cin >> n;
   int m ; cin >> m ;
   
    vector<int> row(n) , col(n) ;

    vector<vector<int>> v (n,vector<int>(n)) ;

    while(m--)
    {
        int x , y ; cin >> x >> y ;
        x-- , y-- ;
        v[x][y]++ ;
        row[x]++ ;
        col[y]++ ;
    }

    for(int i =0 ; i < n ;i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            int& curr = v[i][j] ;
            if(curr > 0)
            {
                // col[j]-- ;
                // row[i]-- ;

                bool found = 0 ;

                for(int k = 0 ; k < n ; k++)
                {

                    if(row[k]==0 and i!=i)
                    {
                        found = 1 ;
                        cout << "YES" << nl ;
                        return ;
                    }

                    if(col[k]==0 and k!=j)
                    {
                        found = 1 ;
                        cout << "YES" << nl ;
                        return ;
                    }
                }
            }
        }
    }

    cout << "NO" << nl ;


}
signed main(){   FAST      TestCases      solve() ;  }



