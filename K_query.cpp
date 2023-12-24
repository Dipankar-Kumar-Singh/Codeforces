// Am I aggressive enough ?? 

#include <bits/stdc++.h>
using namespace std;
#define int     long long
#define all(x)  begin(x) , end(x)
#define nl      "\n" 

int const N = 700 ;

void solve()
{
    vector<vector<int>> block(N) ; 
    int n; cin >> n ; 
    vector<int> a(n) ;
    for(auto &x : a ) cin >> x  ;

    for(int i = 0 ; i < n ; i++){
        block[ i / N ].push_back(a[i]) ;
    }

    for(int i = 0 ; i < N ; i++){
        sort(begin(block[i]),end(block[i])) ;
    }

    auto query = [&](int l , int r, int k) -> int {

        int bl = l / N ;      
        int be = r / N ; 

        int ans = 0 ;
        
        // BC agal se hi deal kar lo esko !! 
        if(bl == be) {
            for(int i = l ; i <= r ; i++) ans += ( a[i] > k ) ;
            return ans ;
        }

        // Range within [ L,end_of_start_block ] 
        for(int i = l ; i < min((bl+1)*N,n) ; i++) {
            ans += ( a[i] > k ) ;
        }

        // Take full block ans ... 
        for(int b = bl + 1 ; b < be ; b++){
            auto &v = block[b] ;
            int id = upper_bound(begin(v),end(v),k) - begin(v);
            // id == n ... no of element greater than k ==> ) 
            int goodNums = v.size() - id ;
            ans += goodNums ;
        }

        // Last part ... 
        // range within [start_of_end_block , R]
        for(int i = (be * N) ; i <= r ; i++){
            if(i >= n ) continue;
            ans += ( a[i] > k ) ;
        }

        return ans ;
    }; 


    auto update = [&](int id, int newVal) {
        int blockId = id / N ;
        int oldValue = a[id] ;
        auto& updateBlock =  block[blockId] ;
        int oldValueIndexInBlock =lower_bound(begin(updateBlock),end(updateBlock),oldValue) - begin(updateBlock);
        updateBlock[oldValueIndexInBlock] = newVal ;
        sort(begin(updateBlock),end(updateBlock)) ;
        a[id] = newVal ;
    };


    int q ; cin >> q ; 
    while(q--) {
        int l, r, k ; 
        cin >> l >> r >> k ; 
        l--, r-- ; 
        cout << query(l,r,k) << nl ;
    }
}

signed main()
{   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    solve();
}