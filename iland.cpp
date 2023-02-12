#include <bits/stdc++.h>
using namespace std;
#define int long long

vector < string > v;
int n , m ;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool isValid(int i , int j)
{
    if( i < 0 or j < 0 or i >= n or j >= m) return 0 ;
    return ( v[i][j] == 'X' ) ;
}

int lands(int i , int j )
{
    int land = 0 ;

    for(int d = 0 ; d < 4 ; d++)
    {
        int x = i + dx[d] ;
        int y = j + dy[d] ;

        land += isValid(x,y) ;
    }

    return land ;
}

signed main()
{

    cin >> n >> m ;
    v = vector<string>(n) ;
    for(auto &s : v) cin >> s ;
    vector<vector<int>> mark(n, vector<int>(m));

    for(int i = 0  ; i < n; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            int land = lands(i , j ) ;
            mark[i][j] = (land < 2) ;
        }
    }

    for(int i = 0  ; i < n; i++)
        for(int j = 0 ; j < m ; j++)
            if(mark[i][j] == 1) v[i][j] = '.' ; 

    vector<int> rt(n) , ct(m) ;
    for(int i = 0 ; i < n ; i++)
    {
        int found = 0 ; 
        for(int j = 0 ; j < m ; j++)
            if (v[i][j] == 'X') found = 1 ;

        if(found)  break; 
        else rt[i] = 1 ;
    }

    for(int i = n - 1 ; i >= 0 ; i--)
    {
        int found = 0 ; 
        for(int j = 0 ; j < m ; j++)
            if (v[i][j] == 'X') found = 1 ;
        
        if(found)  break; 
        else rt[i] = 1 ;
    }

    for(int j = 0 ; j < m ; j++)
    {
        int found = 0 ;
        for (int i = 0; i < n; i++)
            if (v[i][j] == 'X')  found = 1;
        
         if(found)  break; 
        else ct[j] = 1 ;
    }

    for(int j = m - 1 ; j >= 0 ; j--)
    {
        int found = 0 ;
        for (int i = 0; i < n; i++)
            if (v[i][j] == 'X')  found = 1;
        
         if(found)  break; 
        else ct[j] = 1 ;
    }

    for(int i = 0  ; i < n; i++)
    {
        if( rt[i] == 1 ) continue;
        for(int j = 0 ; j < m ; j++)
        {
            if(ct[j] == 1) continue;
            cout << v[i][j] ;
        }
        cout << "\n" ;
    }
}