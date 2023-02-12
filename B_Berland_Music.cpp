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
        int n ; cin >> n ;

        vector<pair<int,int>> v(n)  , lk  , dislk , ans ;

        for(int i = 0  ; i < n ; i++)
        {
            auto &p = v[i] ;

            cin >> v[i].first ;

            v[i].second =  i  ;
        }

        string s ; cin >> s ;

        for(int i = 0 ; i < n ; i++)
        {
            if(s[i]=='1')
            {
                lk.push_back(v[i]) ;
            }

            else
            {
                dislk.push_back(v[i]) ;
            }
        }

        sort(all(lk)) , sort(all(dislk)) ;


        vector<int> final(n) ; 

        int ct = 1 ;

        for(int i  =  0 ; i < dislk.size() ; i++)
        {
            int song_no = dislk[i].second ;
            int old_rating  = dislk[i].first ;
            int &new_rating = dislk[i].first ;


            new_rating = ct ;

            final[song_no] = ct ;
            ct++ ;
        }

        for(int i  =  0 ; i < lk.size() ; i++)
        {   

            int song_no = lk[i].second ;
            int old_rating  = lk[i].first ;
            int &new_rating = lk[i].first ;
            final[song_no] = ct ;
            
            ct++ ;
        }


        for(int x : final) cout << x << " " ;
        cout << "\n" ;

        
        
                                  
                                        
                                       
    }
}

