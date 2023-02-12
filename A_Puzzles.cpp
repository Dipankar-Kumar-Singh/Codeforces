#include <bits/stdc++.h>

using namespace std;

int main(){
    int n , m ; cin >> n >> m  ;
    vector<int> input(m) ; for(int i = 0 ; i < m ; i++){cin >> input[i] ; }
    sort(input.begin(),input.end()) ;
    int ans = INT_MAX ;
    for(int i = 0 ;  (i+n-1) < m ; i++){
        ans = min ((input[i+n-1] - input[i]) , ans ) ;
    }
    cout << ans ;
}