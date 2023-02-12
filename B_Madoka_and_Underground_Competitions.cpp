#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(_case = 1 ; _case <=  TOTALTC ; _case++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int _case = 1 ;

int n , k ;

vector<vector<char>> v ;

void dfs(int i , int j)
{
    if(i < 0 or j < 0 or i>=n or j >= n) return ;

    if(v[i][j] =='X') return ;
    v[i][j] = 'X' ;

    dfs(i + k, j);
    dfs(i - k, j);
    dfs(i, j + k);
    dfs(i, j - k);

}

void solve()
{
    int r, c;
    cin >> n >> k >> r >> c;

    v = vector<vector<char>>(n,vector<char>(n,'.')) ;

    dfs(--r,--c) ;

    for(int i = 0 ; i < n; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            bool foundVertical  = 0 ;
            for(int a = i - 1 ; a > i - k ; a--)
            {
                if(a<0 or a>=n) break;
                if(v[a][j]=='X') foundVertical = 1 ;
            }

            for(int a = i + 1 ; a < i + k ; a++)
            {
                if(a<0 or a>=n) break;
                if(v[a][j]=='X') foundVertical = 1 ;
            }

            bool foundHorizontal = 0 ;

            for(int a = j - 1 ; a > j - k ; a--)
            {
                if(a<0 or a>=n) break;
                if(v[i][a]=='X') foundHorizontal = 1 ;
            }

            for(int a = j + 1 ; a < j + k ; a++)
            {
                if(a<0 or a>=n) break;
                if(v[i][a]=='X') foundHorizontal = 1 ;
            }

            if(foundHorizontal or foundVertical) continue;

            dfs(i,j) ;
        }
    }

    for (auto &r : v){
        for (auto &x : r) cout << x;
        cout << nl;
    }

}
signed main(){   FAST      TestCases      solve() ;  }



