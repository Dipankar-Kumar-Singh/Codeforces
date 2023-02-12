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


bool isVovel( char &c  ){ 

    // if(isupper(c)) c = char(tolower(c)) ;
    string a = "aeiyou" ; 
    bool found = false ;
    for(auto &x:a){ if (x == c){ found = true ; break ;} } 
    return found ;
}

signed main()
{
    FAST 
    string s ; cin >> s ;

    for(auto &c:s)  
            if(isupper(c)) 
                c = char(tolower(c)) ;
       
    
    for(auto &c : s)
    {
        if(isVovel(c)) continue ; 
        else 
        {
            cout << "." ;
            cout << c  ;
        }
    }

    


}

