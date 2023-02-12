#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(_case = 1 ; _case <=  TOTALTC ; _case++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int _case = 1 ;

int N = 0 ;
vector<int> v ;
string s ;

long long power(long long a, long long b)
{
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)                    res = (res * a);
        
        a = (a * a);
        b = b >> 1;
    }
    return (res);
}


void update(int node)
{
    int x = N - node ;
    if(x>=1) 
    {
        int lc = v[N - (2 * x + 1)];
        int rc = v[N - (2 * x )];

        // v[node] =  0 ;

        if(lc==-1)
        {
            // DO Nothing
        }
        else 
        {
            if( s[node] == '0' or s[node] == '?' ) v[node] += lc ;
        }

        if(rc == -1)
        {
            // DO Nothing
        }
        else 
        {
            if( s[node] == '1'  or s[node] == '?' ) v[node] += rc ;
        }

        update(N-(x/2)) ;
    }
}

// int dfs()
// {

// }

void solve()
{
    int K ; cin >> K ;
    N = power(2,K) - 1 ;
    cin >> s ;

    v = vector<int>(4*N + 10,-1) ;

    for(int i = 0 ; i < N ; i++) v[i] = 0 ;


    for(int i = 0 ; i < N ; i++) update(i) ;

    int q ; cin >> q ;
    while(q--)
    {
        int node ; cin >> node ;
        char val ; cin >> val ;
        s[--node] = val ;
        update(node) ;
        // cout << v[N-1] << nl ;


        for(int i : v) cout << i << " " ; cout << nl ;
    }

}
signed main(){   FAST   solve() ;  }



