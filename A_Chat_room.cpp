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
    string s ; 
    cin >> s ;
    int pos = 0 ;
    string rev_hello = "hello" ;

    int counter= 0 ;

    for(int i = 0 ; i < rev_hello.size() ; i++){

        char c = rev_hello[i] ;

        bool found = false ;
        for( pos ; pos < s.size() ; pos++ ){
            if(s[pos] == c ) { found = 1 ; ++pos ; break ;  }
        }

        if(found) counter++ ; 

    }


    if(counter == 5) cout << "YES" ; else cout << "NO" ;
    
    
}

