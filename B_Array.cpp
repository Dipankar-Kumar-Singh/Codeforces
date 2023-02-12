#include <bits/stdc++.h>
using namespace std;

#define int long long
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);


int k  = 0 ;
int n  = 0  ; 

signed main()
{
    FAST 

    cin >> n >> k ;
    
    vector<int> in(n,0) ;
    set<int>s  ;

    vector<int> v ;
    v.push_back(0) ;

    for(int &i:in) 
        cin >> i  ;

    if(k==1) { cout << 1 << " " << 1 ; return 0 ; }

    int l = n , r = -1 ;

    for(int i = 0 ; i < n ; i++){

        s.insert(in[i]) ;
        int sz = s.size() ;

        if(sz == k) {
            r = i + 1 ;
            s.clear() ;
            for(int j = i ; j>=0 ; j--){
                s.insert(in[j]) ; 
                if(s.size()==k){
                    cout << j+1 << " " << i+1 ; 
                    return 0 ;
                }
            }
        }
    } 

    cout << -1 << " " << -1 ; 
    return 0 ;
}

