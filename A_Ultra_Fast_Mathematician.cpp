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
    string a , b ; 
    cin >> a >> b ; 


    string ans ;

    for(int i = 0  ; i < a.size() ;  i++){

        char x = a[i] ;
        char y = b[i] ;

        if(x==y) { ans.push_back('0') ; }
        else ans.push_back('1') ;

    }


    cout << ans ;

    

}

