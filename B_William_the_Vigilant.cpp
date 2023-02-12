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

int p = 0 ;
string old ;

int solve(string s){
    int ans = 0 ;
    for(int i = 0 ; i < s.size() ; i++){
        if(s[i]=='a'){
            if(s[i+1] == 'b'){
                if(s[i+2] == 'c'){
                    ans ++ ;
                    i = i+ 1;
                }
            }
        }
    }
    return ans ;
}

bool check(string &s , int loc){

    if(loc<0) return 0 ;
    else if(loc>=s.size()) return 0 ;

    if(s[loc] == 'a') 
        if(s[loc+1] == 'b') 
            if(s[loc+2] == 'c')
                return true ;
    return 0 ;
}



signed main()
{
    FAST 
    int n  , q ; cin >> n >> q ;
    string s ;  cin >> s ;

    old = s ;
    
    p = solve(s) ;

    int ans = p ;

    while (q--)
    {
        
        int loc = 0 ; char c ; 
        cin >> loc >> c ; loc-- ;

        ans -= check(s,loc-1) ;
        ans -= check(s,loc-2) ; 
        ans -= check(s,loc) ;

        s[loc] = c ;

        ans += check(s,loc) ;
        ans += check(s,loc-1) ;
        ans += check(s,loc-2) ;

        cout << ans << "\n" ;


    }
    


}

