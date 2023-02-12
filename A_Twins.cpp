#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
const ll MOD = 1e9 + 7;
const ll INF = numeric_limits<long long>::max();
#define F first      
#define S second     
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()


signed main()
{
    FAST 
    int n ; cin >> n ; 

    vector<int> v(n,0) ; for(auto &x:v) cin >> x  ; 

    sort(all(v)) ; reverse(all(v)) ; 

    int a = 0  , b = accumulate(all(v),0)  ;
    int coin = 0 ;

    for(int  i =  0 ; i < n ; i++){

        if(a>b) break ;

        a+=v[i] ; b-=v[i] ;
        coin ++ ;
    }

    cout << coin ;

    

}

