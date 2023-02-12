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
    t_case
    {
        int n , k ; cin >> n >> k ;
        vector<int> v(n) , positve , negative ;
        int maxxxx  = 0 ;
        for(auto &x : v)
        { 
            cin >> x ; 
            if(abs(x) > maxxxx){
                maxxxx = max(maxxxx , abs(x)) ;
            }
            if(x>=0) positve.push_back(x) ;
            else negative.push_back(x) ;
        }

        sort(all(positve)) , sort(all(negative)) ;
        reverse(all(positve))  ;

        int dis = 0 ;

        for(int i = 0 ; i < positve.size() ; i+=k)
        {  
            dis += (positve[i])*2 ;
        } ;

        for(int i = 0 ; i < negative.size() ; i+=k)
        {
            dis += abs((negative[i])*2) ;
        }

        dis -= abs(maxxxx)       ;

        cout << dis << "\n" ;                    
    }
}

