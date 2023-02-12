#include <bits/stdc++.h>
using namespace std;

#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n"  



signed main()
{
    FAST  
    int n ; cin >> n ; 
    int m ; cin >> m ; 
    int k ; cin >> k ;

    int mid = 0 ;
    int l = 1;
    int r = n * m;
    while(l < r){
        mid = l + r >> 1;
        long long cnt = 0;
        for(int i = 1 ; i <= n ; ++i){
            cnt += min(m , (mid) / i);
        }
        if(cnt >= k){
            r = mid;
        }
        else{
            l = mid + 1;
        }
    }
    cout << l; 


    // vector<int> v ;

    // for(int i = 1 ; i <= n ; i++)
    //     for(int j = 1 ; j <= m ; j++) v.push_back((i*j)) ;

    // sort(all(v)) ;

    // cout << v[--k]  ;

  
 

}

