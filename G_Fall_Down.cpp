#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 

int const stone = 1 ;
int const obs = 9 ;
int const clear = 0 ;

void print(vector< vector<int>> &v , int &n , int &m)
{
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ;j++) 
        {
            if(v[i][j] == clear ) cout << '.';
            if(v[i][j] == obs )   cout <<'o' ;
            if(v[i][j] == stone)  cout << '*';
            
        }
        cout << nl ;
    }

}

void solve()
{
   int n , m ; cin >> n >> m ;
   vector< vector<int>> v(n, vector<int> (m,0)) ;

    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ;j++)
        {
            char c ; cin >> c ;
            if(c=='.') v[i][j] = clear ;
            if(c=='o') v[i][j] = obs ;
            if(c=='*') v[i][j] = stone ;
        }
    }

    for(int i = n-1 ; i >= 0 ; i--)
    {
        for(int j = 0 ; j < m ; j++)
        {
            if(v[i][j] == stone)
            {
                int k = i+1 ;
                for(;k<n and v[k][j] == clear ;k++)
                {
                    if(k==n) break;
                    // if(v[k][j]!=clear) break;
                }

                if(k==n)k-- ;
                if(v[k][j]!=clear) k-- ;
                k  = max(i,k) ;
                swap(v[k][j],v[i][j]) ;
            }
        }
    }

    // print(v,n,m) ;

    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ;j++) 
        {
            if(v[i][j] == clear ) cout << '.';
            if(v[i][j] == obs )   cout <<'o' ;
            if(v[i][j] == stone)  cout << '*';
            
        }
        cout << nl ;
    }

    cout << nl ;






}

signed main()
{   FAST  

    TestCases  
    solve() ;  

}

