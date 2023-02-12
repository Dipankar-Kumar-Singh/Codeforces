#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
const ll MOD = 1e9 + 7;
const ll INF = numeric_limits<long long>::max();
#define F first      
#define S second     
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()


signed main()
{
    FAST 
    t_case
    {
        int n ; cin >> n ; 

        deque<int> d , org ;

        for(int i = 0 ; i < n ; i++){
            int x ; cin>>x ;
            d.push_back(x)  ;
        }

        vector<int> v ;
        for(auto &x:d){v.push_back(x) ; }

        int mx_index = max_element(all(v)) - v.begin() ;

        if(mx_index == 0 or mx_index == n-1) {}
        else {cout << -1 << "\n" ; continue ;}

        while (!d.empty())
        {
            
            int f = d.front() ;
            int b = d.back() ;

            int max = (f>b) ;

            if(max==1){d.pop_front();} else if(max==0) d.pop_back();

            if(max==1){
                org.push_front(f) ;
            }
            else org.push_back(b) ;
        }

        for(auto &x:org){cout << x << " " ; }
        cout << "\n" ;
        

        
                
                                        
                                       
    }
}

