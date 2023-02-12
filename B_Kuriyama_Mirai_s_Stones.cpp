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

    int n  ; cin >> n ; vector<int> v(n);
    for(int &x : v ) cin >> x ;

    vector<int> p(n+1,0) , ps(n+1,0) , sv = v;

    sort(all(sv)) ;

    for(int i = 0 ; i < n ; i++){
        p[i+1] = p[i] + v[i] ;
    }

    for(int i = 0 ; i < n ; i++){
        ps[i+1] = ps[i] + sv[i] ;
    }

    t_case
    {
        
        int q , l , r ; 
        cin >> q >> l >> r ;
        r ; l ;

        if(q==1) 
            cout << p[r] - p[l-1] << "\n";
        else 
        cout << ps[r] - ps[l-1] << "\n" ;


                                  
                                        
                                       
    }
}



