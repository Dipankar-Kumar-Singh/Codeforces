#include <bits/stdc++.h>
using namespace std;
#define int     long long
#define all(x)  begin(x) , end(x)
#define nl      "\n" 
// #include"/home/dk/debugging.h"

void solve(int& __case__)
{
    int n ; 
    string s; cin >> s ; 
    n = s.size() ;

    int l = 0 ;
    int r = 0 ;

    stack<char> st ; 
    for(auto c : s ) {
        if( c == ')'){
            if(st.empty()){
                l++ ;
            } else {
                st.pop() ;
            }
        } 
        else if( c == '('){
            st.push(c) ;
        }
    }

    r = st.size() ;

    string prefix (l,'(') ;
    string suffix (r, ')') ;

    s = prefix + s + suffix ; 

    while (s.size() < 2*n)
        s += "()" ;
    

    if(s.size() == 2*n){
        
        vector<char> check ; 
        for(auto c : s) {
            if( c == '(') {
                check.push_back(c) ;
            } else {
                if(check.empty()){
                    cout << "NO" << nl ;
                    return ;
                } else 
                check.pop_back() ;
            }
        }

        cout << "YES" << nl ;
        cout << s << nl ;

    } else {
        cout << "NO" << nl ;
    }
}

signed main()
{   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int testCases = 1 , case_ = 1;     
    cin >> testCases; for (int case_ = 1; case_ <= testCases; case_++) 
        solve(case_);
}



// class Solution {

//     int findLongestS(string s , vector<int> v)
//     {
//         ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
//         int testCases = 1 , case_ = 1;     
//         cin >> testCases; for (int case_ = 1; case_ <= testCases; case_++) 
//         solve(case_);
    
//     }

// };


bool isPossibel(){



}


int main(){

}