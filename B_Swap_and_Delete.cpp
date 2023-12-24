#include <bits/stdc++.h>
using namespace std;
#define int     long long
#define all(x)  begin(x) , end(x)
#define nl      "\n" 
// #include"/home/dk/debugging.h"

void solve(int& __case__)
{
    int one_1 = 0 , zero_0 = 0 ; 

    string s ; cin >> s ;

    for(auto& i : s){
        if(i == '1') one_1++ ;
        else zero_0++ ;
    }

    string t  ;
    int ans = 0 ;

    for(int i = 0 ; i < s.size() ; i++){
        
        if((one_1 + zero_0) == 0 ){
            break;
        }

        if(s[i] == '1') {
            if(zero_0 > 0){
                t += '0' ;
                zero_0-- ;
            }
            else{
                if(one_1 > 0){
                    while(one_1--){
                        ans++ ;
                    }
                } else break;
            }
        } else {
            if(one_1 > 0){
                t += '1' ;
                one_1-- ;
            }
            else{
                if(zero_0 > 0){
                    while(zero_0--){
                        ans++ ;
                    }
                } else break;
            }
        }
    }

    cout << ans << nl ;

}

signed main()
{   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int testCases = 1 , case_ = 1;     
    cin >> testCases; for (int case_ = 1; case_ <= testCases; case_++) 
        solve(case_);
}
