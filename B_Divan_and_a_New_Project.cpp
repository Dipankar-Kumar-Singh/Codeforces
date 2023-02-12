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


class building{
    public :
    int rank = 0 ;
    int fr = 0 ;
    int location = 0 ;
};


signed main()
{
    FAST 
    t_case
    {
        
        int n ; cin >> n ; 
        vector<pair<int,int>> v(n) ; 

        for(int i = 0 ; i < n ; i++){

            int visit = 0 ; cin >> visit ;
            int pos = i + 1  ; 

            v[i].first =  visit ;
            v[i].second = pos ;

        }


        sort(all(v)) ; reverse(all(v)) ;

        vector<pair<int,int>> a , b ; 


        int flip_flop = 1 ;
        for(auto&x : v)
        {
            if(flip_flop){
                
                a.push_back(x) ;

            }

            else {

                b.push_back(x) ;
            }

            flip_flop = !flip_flop ;
        } 


        int sum = 0 ;

        vector<int> ans(n,0) ; 

        for(int i = 0 ; i < a.size() ; i++){
            
            int visit = a[i].first ;
            int index = i + 1 ;
            sum += (index * visit * 2);

            int rank = a[i].second ;
            ans[rank-1] = index ;

        }

        for(int i = 0 ; i < b.size() ; i++){
            
            int visit = b[i].first ;
            int index = i + 1 ;
            sum += (index * visit * 2);

            int rank = b[i].second ;
            ans[rank-1] = -index ;
            
        }


        cout << sum << "\n" ;

        cout << 0 << " " ; // headquater

        for(auto x : ans) cout << x << " " ; cout << "\n" ;



                                  
                                        
                                       
    }
}

