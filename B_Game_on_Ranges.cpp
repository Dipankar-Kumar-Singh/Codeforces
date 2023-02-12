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

        map<int,int> marked ;

        set<pair<int,int>> s ;

        set<int> rem ;

        for(int i = 1 ; i <= n ; i++)
        {
            rem.insert(i) ;
        }
        
        
        // diff l r  ans
        vector< tuple<int,int,int,int> >  v(n) ;

        for(int i = 0 ; i < n ; i++)
        {
            int x , y ; cin >> x >> y ;

            int dif = abs(x - y ) ;
            v[i] = make_tuple(dif,x,y,0) ;

            s.insert({x,y}) ;

        }
        sort(all(v)) ;
        for(auto &[dif,x,y,ans]: v)
        {
            if(dif == 0)
            {
                marked[x] = 1 ;
                ans = x ;
                rem.erase(x) ;
                
                continue ;
            }

            if(!marked[x])
            {
                marked[x] = 1 ;
                ans = x ;
                rem.erase(x) ;
                
            }

            if(!marked[y])
            {
                marked[y] = 1 ;
                ans = y ;
                rem.erase(y) ;
                
            }

            else if(ans == 0)
            {
                for(int k = min(x,y) ; k <= max(y,x) ; k++)
                {
                    if(marked[k]) continue ;

                    // else{ ans = k ; break ;}

                    else
                    {
                        int target = k ;

                        int ll = k -1 ;
                        int rr = k+ 1 ;

                        if(s.count({x,ll}) and s.count({rr,y}))
                        {
                            ans = target ; break ;
                        } ;

                    }
                }

            }

        }


        for(auto [dif,x,y,ans]: v)
        {
            cout <<  x << " " << y << " "  << ans << "\n" ;
        }


        cout << "\n" ;
                                  
                                        
                                       
    }
}

