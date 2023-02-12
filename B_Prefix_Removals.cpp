#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n"  

void solve(int Test)
{
   

    string s ; cin >> s;

    map<char,int> fr ;

    int n = s.size() ;

    for(int i = n ; i >= 0 ; i--)
    {
        fr[s[i]]++ ;
    }

    int pt = 0 ;

    for(int i = 0 ; i < n ;i++)
    {
        pt = i ;
        fr[s[i]]-- ;
        if(fr[s[i]]==0) break; 
    }

    string ans ;
    for(int i = pt ; i < n ;i++)
    {
        ans += s[i] ;

    }

    cout << ans << nl ;





    
}

signed main(){

    FAST 
    int Total_Test ; cin >> Total_Test ;
    for(int TEST = 1 ; TEST <=  Total_Test ; TEST++)
    {
        solve(TEST) ;
    }
}