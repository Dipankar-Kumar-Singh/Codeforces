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
    int n , q ; 
    cin >> n >> q; 
     
    vector<int> in(n,0) ; 
    vector<int> v(n+1,0) ;

    for(auto &i : in) cin >> i ;

    while(q--){
        int l , r ; cin >> l >> r ;
        v[l-1]++ ; --v[r] ;    
    }

    vector<int> pr(n+1,0) ;
    vector<int> p ;

    for(int i = 1 ; i <= n ; i++ ){
        
        pr[i]  = pr[i-1] + v[i-1] ;
        p.push_back(pr[i]) ;
    } 

    sort(all(p)) ;
    sort(all(in)) ;


    // cout << "sz p :" << p.size() << "  sz of in " << in.size()<< "\n\n\n";;

    // for(auto x:in){ cout << x << " " ; } cout << "\n\n";
    // for(auto x:p){ cout << x << " " ; } cout << "\n\n";
    

    int ans = 0 ;
    for(int i = 0 ; i < n ;i++){
        ans += (p[i]*in[i]) ;
    }

    cout << ans ;


}




/***
 *    ▓█████▄     ██▓    ██▓███      ▄▄▄          ███▄    █     ██ ▄█▀    ▄▄▄          ██▀███  
 *    ▒██▀ ██▌   ▓██▒   ▓██░  ██▒   ▒████▄        ██ ▀█   █     ██▄█▒    ▒████▄       ▓██ ▒ ██▒
 *    ░██   █▌   ▒██▒   ▓██░ ██▓▒   ▒██  ▀█▄     ▓██  ▀█ ██▒   ▓███▄░    ▒██  ▀█▄     ▓██ ░▄█ ▒
 *    ░▓█▄   ▌   ░██░   ▒██▄█▓▒ ▒   ░██▄▄▄▄██    ▓██▒  ▐▌██▒   ▓██ █▄    ░██▄▄▄▄██    ▒██▀▀█▄  
 *    ░▒████▓    ░██░   ▒██▒ ░  ░    ▓█   ▓██▒   ▒██░   ▓██░   ▒██▒ █▄    ▓█   ▓██▒   ░██▓ ▒██▒
 *     ▒▒▓  ▒    ░▓     ▒▓▒░ ░  ░    ▒▒   ▓▒█░   ░ ▒░   ▒ ▒    ▒ ▒▒ ▓▒    ▒▒   ▓▒█░   ░ ▒▓ ░▒▓░
 *     ░ ▒  ▒     ▒ ░   ░▒ ░          ▒   ▒▒ ░   ░ ░░   ░ ▒░   ░ ░▒ ▒░     ▒   ▒▒ ░     ░▒ ░ ▒░
 *     ░ ░  ░     ▒ ░   ░░            ░   ▒         ░   ░ ░    ░ ░░ ░      ░   ▒        ░░   ░ 
 *       ░        ░                       ░  ░            ░    ░  ░            ░  ░      ░     
 *     ░                                                                                       
 */