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
    int n , m; 

    cin >> n >> m ;

    int x = n ;
    set<int> s ;
    // s.insert(x);
    bool found = false ;

    while(1)
    {   
        x = x%m ;
        if(x==0){cout << "Yes" ; return 0 ;}
        if(s.find(x) != s.end()) { cout << "No"; return 0;}
        s.insert(x) ;
        x = x%m + x%m ;
    }
}

