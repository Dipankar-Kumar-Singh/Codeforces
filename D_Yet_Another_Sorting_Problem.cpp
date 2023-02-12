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
    int t = 0 ;
    t_case
    {   
        t++ ;
        
        int n ; cin >> n ; 
        vector<pair<int,pair<int,int>>> v(n) ;

        vector<int> org_vec , sorted_vec ;

        bool rep = 0 ;

        for(int i = 1 ; i <= n ; i++)
        {
            cin  >> v[i-1].first ;
            v[i-1].second.first = i ; 
            org_vec.push_back(v[i-1].first) ;
        }
 
        sorted_vec =  org_vec ;
        sort(all(sorted_vec)) ;

        if(sorted_vec == org_vec){ cout << "YES\n" ; continue ;}

        sort(all(v)) ;

        for(int i = 0 ; i < n ; i++)
        {
            v[i].second.second = i + 1 ;
            
            if(i>0)
            {
               rep =  (v[i].first == v[i-1].first) or rep  ;
            }
        }

        int pair_cycle = 0; 

        for(int i = 0 ; i < n ; i++){

            int x = v[i].first , a = v[i].second.first , b = v[i].second.second ;

            // if(a  ==  b ) continue ; // sorted pos == org pos -->skipp

            for(int k = i+1 ; k < n ; k++)
            {   
                int y = v[k].first , c = v[k].second.first , d = v[k].second.second ;

                if( c == b  and a == d )
                {
                    pair_cycle++ ;
                }
            }
        }

        // if(rep){
        //     cout << "YES\n" ; continue ;
        // }

        // if(pair_cycle == 0) cout << "YES\n" ;
        // else if(pair_cycle>0 )
        // {
        //     if((pair_cycle)&1)  cout << "NO\n" ; 
        //     else cout << "YES\n" ;
        // } 


        if(pair_cycle%2==0) cout << "YES\n" ;
        else
        {
            if(rep){cout << "YES\n" ; continue ;}
            else cout << "NO\n" ;
        }
                        
    }
}

