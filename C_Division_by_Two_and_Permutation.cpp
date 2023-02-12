#include <bits/stdc++.h>
using namespace std;

#define int long long
const long long MOD = 1e9 + 7;
const long long INF = numeric_limits<long long>::max();
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()



bool found_all(vector<int> &found , int n )
{
    for(int i = 1 ; i <= n  ; i++ )
    { 
        if(!found[i]) return 0 ;
    }

    return 1 ;
}

signed main()
{
    FAST 
    t_case
    {
        multiset<int> s , missing ; 

        bool fd = 0 ; 


        int n ; cin >> n ; 
        vector<int> found(n+1,0) ;

        for(int i = 0 ; i < n ; i++)
        {
            int x ; cin >> x ;
            s.insert(x) ;
        }


        while (1)
        {
            for(int i = 0 ; i < n ; i++)
            {
                int num  = i+1 ;
                if(found[num]) continue ;
                if(s.count(num))
                {
                    found[num] = 1 ;
                    auto it = s.find(num);
                    s.erase(it) ;
                }
            }

            multiset<int> new_set ;
            for(auto x : s)
            {
                auto it = s.find(x) ;
                int half = (x)/2 ; 
                new_set.insert(half) ;
            }

            s.clear() ; 
            s = new_set ;
            new_set.clear() ;


            int mn = INF ;
            for(int i = 1 ; i <= n ; i++)
            {
                if(!found[i])
                    mn = min(mn,i) ;
            }

            int num_set  = *min_element(all(s)) ;

            if(found_all(found,n))
            {
                cout << "YES\n" ; break ; 
            }

            if(num_set < mn)
            {
                cout << "NO\n" ; break ; ;
            }
  
        }                                   
    }
}

