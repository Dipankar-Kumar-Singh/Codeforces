#include <bits/stdc++.h>
using namespace std;
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(_case = 1 ; _case <=  TOTALTC ; _case++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int _case = 1 ;
vector<vector<int>> matrix , fall ;
int n , m ;

int dfs(int i , int j)
{
    int ans = 0;

    if (i == n + 1) return j;
    if (fall[i][j]) return j;

    if (matrix[i][j] == 1 )
    {
        matrix[i][j] = 2 ;
        ans = dfs(i, j + 1);
        if(i + 1 <= n and fall[i + 1][j] == 1) fall[i][j] = 1 ;
    }
    else if (matrix[i][j] == 2 )
    {
        matrix[i][j] = 2 ;
        ans = dfs(i + 1, j );
        if(i + 1 <= n and fall[i + 1][j] == 1) fall[i][j] = 1 ;
    }
    else if (matrix[i][j] == 3 )
    {
        matrix[i][j] = 2 ;
        ans = dfs(i, j -1 );
        if(i + 1 <= n and fall[i + 1][j] == 1) fall[i][j] = 1 ;
    }

    return ans ;
}

void solve()
{
    int k ; 
    cin >> n >> m >> k ;

    fall =matrix = vector<vector<int>>(n + 1 , vector<int> (m + 1 , 0)) ; 

    for(int  i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= m ; j++) 
            cin >> matrix[i][j] ;

    for(int j = 1 ; j <= m ; j++) 
    {   
        for(int i = n ; i >= 1 ; i--)
        {
            if(matrix[i][j] != 2) break;
            fall[i][j] = 1 ;
        }
    }


    while (k--)
    {
        int col ; cin >> col ;
        cout << dfs(1,col)  << ' ' ;
    }
        
}

signed main() { FAST  solve(); }
