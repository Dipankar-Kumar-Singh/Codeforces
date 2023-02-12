#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define nl "\n"  

int n ;
int v[2001][2001] ;
int d1[4021] , d2[4021] ; 

void build()
{
    for(int i = 0 ; i < n ; i++) for(int j = 0 ; j < n ; j++) 
    {
        d1[i + j] += v[i][j] ,
        d2[i - j + n - 1] += v[i][j];
    }
}

signed main()
{
    FAST 
    cin >> n ; 
    for(int i = 0 ; i < n ; i++) for(int j = 0 ; j < n ; j++) cin >> v[i][j] ;

    tuple<int, int, int> t1{0, 0, 0}, t2{0, 0, 0};

    build() ;
    for(int i = 0 ; i < n ; i++) for(int j = 0 ; j < n ; j++) 
    {
        int cur = (d1[i + j] + d2[i - j + n - 1] - v[i][j]);
        
        tuple t = {cur, i + 1, j + 1};

        if ((i + j) & 1)
            t1 = max(t, t1);
        else
            t2 = max(t, t2);
    }
    auto &[a,x1,y1] = t1 ; 
    auto &[b,x2,y2] = t2 ;
    cout << ( a + b ) << nl << x1 << " " << y1 << " " << x2 << " " << y2 ;
}
