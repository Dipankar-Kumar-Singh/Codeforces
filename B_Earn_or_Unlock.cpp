#include <bits/stdc++.h>
using namespace std;
#define int     long long
#define all(x)  begin(x) , end(x)
#define nl      "\n" 

// so finally understood the solution ... 
// of tourist and other people ..
// wow . bitset is so powerfull 


void solve(int& __case__)
{
    int n ; 
    cin >> n ;

    vector<int> v(n) ;
    for(auto &x : v) {
        cin >> x ;
    }

    
    // if 5th bit is set ... 
    // and it means ... 
    // 5 tak unlock karna possible hai .. 
    // ( it got unlocked by some other number )

    constexpr int N = 2e5  + 10 ;
    bitset<N> b ; 
    b[1] = 1 ;
    
    for(int i = 0 ; i < n; i++){
        bitset<N> bcopy = b ; 
        bcopy = bcopy >> i + 1 ;
        bcopy = bcopy << i + 1 + v[i]  ;
        b |= bcopy ;
    }


   // b[i] |= ( b >> (i + 1) <<  i + 1 + v[i])
    int sum = 0 ;
    int ans = 0 ;

    for(int i = 1 ; i < N ; i++) {
        if(i - 1 < n ) {
            // this point belong to array .. 
            // note .. last element can unlock .. 1e5 more element ( that are not present )
            sum += v[i - 1] ;
        }
        if(b[i]) {
            // if this point is unlocked .. then .. sum of unlock key must be equal to i - 1 ;
            // x unlock .. _ , _ , _ , _ : total x points , 
            // thus .. if 50th point is unlocked ... then it means .. 
            // total sum of points that contributed to this unlock is i - 1 : 49 ; ( 1st one is already unlocked.. it's effect start from 2 )

            int sum_till_now = sum ; 
            int cost_of_unlocking = i - 1 ;

            int sum_actual = sum_till_now - cost_of_unlocking ;
            ans = max(ans , sum_actual) ;
        }
    }

    cout << ans << nl ;
}

signed main()
{   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int testCases = 1 , case_ = 1;     
        solve(case_);
}
