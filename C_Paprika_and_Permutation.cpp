#include <bits/stdc++.h>
using namespace std;

#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()

signed main()
{
    FAST 
    t_case
    {
        int  n ; cin >> n ;
        vector<int> v(n) ;
        for(int &x : v) cin >> x ;
        vector<int> missing_numbers  , helper , permulation ;
        map<int,int> found ;

        for(auto &x : v)
        {
            if(( x>=1 and x<=n) and !found[x]) 
                permulation.push_back(x) ;
            else 
                helper.push_back(x) ;

            found[x] = 1 ;
        }

        for(int i = 1 ; i <= n ; i++)
        {
            if(!found[i]) {missing_numbers.push_back(i) ;}
        }

        sort(all(missing_numbers)) ;
        sort(all(helper)) ;

        reverse(all(missing_numbers)) ;
        reverse(all(helper)) ;

        bool could_never_be_found = 0 ;

        if(permulation.size() == n )
        {
            cout << 0 << "\n" ; continue ;
        }

        if(helper.size() < missing_numbers.size())
        {
            could_never_be_found = 1 ;
            cout << "-1\n" ; continue ; 
        }

        int moves = 0 ;

        for(int i = 0 ; i < missing_numbers.size()  ; i++ )
        {
            int hp = helper[i] ;
            int rq = missing_numbers[i] ;

            int y = hp - rq ; 

            if(2*y > hp and  y > 0) moves++ ;
            else {could_never_be_found = 1 ; break ;}
        }

        if(could_never_be_found)
        {
            cout << "-1\n" ; continue ;
        }

        cout << moves << "\n" ;
                                                                          
    }
}

