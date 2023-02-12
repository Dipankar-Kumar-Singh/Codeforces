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
    int n ; cin >> n ; int k ; cin >> k ;


    vector<int> v(n+1,0) ;

    for(int i = 0 ; i <= n ; i++){
        v[i] = i ;
    }

    // for(int i = 1 ; i <= n ; i ++){

    //     if(i&1 and k>0)
    //     {
    //         swap(v[i],v[i+1]) ;
    //         k-- ;
    //     }
    // } 


    reverse(v.begin()+1 , v.begin()+1 + k + 1) ;

    for(int i = 1 ; i <= n ; i++){
        cout << v[i] << " " ;
    }



    




}

