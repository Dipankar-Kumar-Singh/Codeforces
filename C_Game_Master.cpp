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
        vector<int> order1 , order2 ; 
        int n ; cin >> n ;

        vector<pair<int,int>> a , b ;

        for(int i = 1 ; i <= n ; i++)
        {
            int x ; cin >> x  ;
            pair p = {x,i} ;
            a.push_back(p) ;
        }

        for(int i = 1 ; i <= n ; i++)
        {
            int x ; cin >> x  ;
            pair p = {x,i} ;
            b.push_back(p) ;
        }

        sort(all(a)) , sort(all(b)) ;

        map< int , int > map1 , map2 ;

        for(int i = 0 ; i < n ; i++)
        {
            int id = i+1 ;
            int power_map_a = a[i].first ,  person_pos_map_a = a[i].second ;
            int power_map_b = b[i].first ,  person_pos_map_b = b[i].second ;

            order1.push_back(person_pos_map_a) , order2.push_back(person_pos_map_b) ;

            map1[person_pos_map_a]  = id ;
            map2[person_pos_map_b] =  id ;

        }

        vector<int> max_prefix_a(n+1) , max_prefix_b ;
        

        int mxa {} , mxb {} ;

        for(int i = 0 ; i < n ; i++)
        {   
            //  cout << order1[i] << " " ;
            //  cout << order2[i] << "\n" ;

             int cur_player  = order1[i] ;
             mxa = max(mxa , map2[cur_player]) ;
             max_prefix_a[i+1] = max( max_prefix_a[i] , mxa ) ;
        }


        for(int i = 0 ; i < n ; i++)
        {

            int cur_player = order1[i] ;
            int cur_id = i ; 

            int A = max_prefix_a[i+1] ; 
            

            int MX {} ;

            for(int j = i+1 ; j < n ; j++)
            {
                MX = max(MX , map2[order1[j]]) ;
            } 

            int B = MX ;

            if(A>B) cout << 1 ; else cout << 0 ;
 
        }

        cout << "\n" ;
    }
}

