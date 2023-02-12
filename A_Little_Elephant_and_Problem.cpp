#include <bits/stdc++.h>
using namespace std;

#define int long long
const long long MOD = 1e9 + 7;
const long long INF = numeric_limits<long long>::max();
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()


signed main()
{
    FAST 
    int n ; cin >> n ;
    vector <int> a(n,0) ; for(int &x : a) cin >> x ;
    vector <int> b = a ;
    sort(all(a) ) ;

    int f = 0 ;

    for(int i = 0 ; i < n ; i++){

        if(a[i]!=b[i]) f++ ;

        if(f>2){ cout << "NO" ; return 0 ;}

    }

    cout << "YES" ;
}

