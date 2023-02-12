#include <bits/stdc++.h>
using namespace std;

#define int long long
const long long MOD = 1e9 + 7;
const long long INF = numeric_limits<long long>::max();
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()


signed main()
{
    FAST 

    set<int> s ;

    const int N = 1e5 ;

    for(int i = 1 ; i <= N ; i++)
    {
        s.insert(i*i) , s.insert(i*i*i) ;
    }

    vector<int> v ;
    for(auto &x : s){v.push_back(x) ;}



    t_case
    {
        
        int x ; cin >> x  ;

        int y = sqrt(x) , z = cbrt(x) ;

        auto it = lower_bound(all(v) , x) ;

        if(it==v.begin()){
            if(v.front() <= x )
            {
                cout << 1 << "\n" ;
            }

            else cout << "NO\n" ;

            continue ;
        }

        else{
            int pos = it - v.begin() ;

            if(v[pos] <= x)
            {
                cout << pos + 1 << "\n" ;
            }

            else {
                cout << pos  << "\n" ;
            }
            
        }

                                        
                                        
                                       
    }
}

