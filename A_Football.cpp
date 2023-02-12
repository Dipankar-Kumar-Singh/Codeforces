#include <bits/stdc++.h>
using namespace std;

#define int long long
const long long MOD = 1e9 + 7;
const long long INF = numeric_limits<long long>::max();
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()

#define EX exit(0) ;
signed main()
{
    // FAST 
     string s ; cin >> s ;
     int n = s.size() ;


    if( n < 7 ) {cout << "NO" ; EX}

    char c = s[0] ;

    int ct = 0 ;
    
    for(int i = 0 ; i < n ;i++){
        if(s[i] == c){ct++;}
        else if( s[i] != c )
            { ct = 1 ; c = s[i] ;}

        if( ct >= 7){
            cout << "YES" ; exit(0) ;
        }
    }

    cout << "NO" ;

}

