#include <bits/stdc++.h>
using namespace std;
#define int     long long
#define all(x)  begin(x) , end(x)
#define nl      "\n" 



void solve(int& __case__)
{
    int n , k ; cin >> n >> k ;
    vector<int> v(n) ;

    auto cmp = [](pair<int, int> p1, pair<int, int> p2) {
        auto &[x1, id1] = p1;
        auto &[x2, id2] = p2;
        return (x1 > x2) || ((x1 == x2) && id1 < id2);
    };

    set<pair<int,int>,decltype(cmp)> s ;

    vector<int> ans ;

    for(int i = 0 ; i < n ; i++){
        cin >> v[i] ;
        v[i] = (v[i] - 1) % k ;
        s.insert({v[i],i}) ;
    }

    while(s.size() >= 2){
        auto [ x , id ] = *s.begin() ; s.erase(s.begin()) ;
        x -=  k ;
        if(x <= 0 ) {
            ans.push_back(id) ;
        } else {
            s.insert({x , id}) ;
        }
    }

    auto& [ element , index ] = *s.begin() ;
    ans.push_back(index) ;

    for(auto &x : ans ) cout << x + 1 << " " ; cout << nl ; 
}

signed main(){   
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int testCases = 1 , case_ = 1;     
    cin >> testCases; for (int case_ = 1; case_ <= testCases; case_++) solve(case_);
}
