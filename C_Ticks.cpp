#include <bits/stdc++.h>
using namespace std;

#define int long long
const long long MOD = 1e9 + 7;
const long long INF = numeric_limits<long long>::max();
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()

int ans = 0 ; bool possible = 1 ;
int n {}, m{} , min_req{} ;
vector<vector<char>> v ;

void dfs(int d1 , int d2 , int i , int j , int dir)
{
    if( d2 > d1 ) return ;
    if((i >= n) or (j >= m) or (i < 0) or (j < 0) or (v[i][j]=='.')) 
    {
        if(d1 == d2 and d1>0) ans++ ;
        else if(d1 != d2 and d1>0){possible = 0 ;}
        return;
    }

    if( v[i][j] == '*'  and dir == 0 )
    {   ++d1  ;
        dfs(d1,d2,i+1,j+1,0) ;
        dfs(d1,d2,i-1,j+1,1) ;
    }

    else if( v[i][j] == '*'  and dir == 1 )
    {   
        ++d2 ;
        dfs(d1,d2,i-1,j+1,1) ;
    }
    
};


signed main()
{
    FAST 
    t_case
    {   
        ans = n = m = min_req = 0 ; v.clear();
        cin >> n >> m >> min_req ;
        v.resize(n, vector<char>(m) ) ;

        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < m ; j++)
                cin >> v[i][j] ;        


        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < m ; j++)
                if(v[i][j]=='*') dfs(0,0,i+1,j+1,0)  ;
                                        
        if(ans>=min_req) cout << "YES" ; else cout << "NO" ;
        cout << "\n" ;                                
    }
}

