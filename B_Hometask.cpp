#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(_case = 1 ; _case <=  TOTALTC ; _case++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int _case = 1 ;

void solve()
{
   int n;   cin >> n;
   vector<int> v(n);  for (auto &x : v) cin >> x;

   sort(all(v)) ; reverse(all(v)) ;
   int sumofdigit = accumulate(begin(v),end(v),0LL) ;
   set<int> s ; for(auto x : v ) s.insert(x) ;


    if(sumofdigit==0)
    {
        cout << 0 ; 
        return ;
    }

   if(v.back()==0)
   {
        if(sumofdigit%3==0)
            for(auto x : v) cout << x  ; 
        else 
        {
            for(auto x : s) 
            {
                if((sumofdigit - x)%3==0)
                {
                    if(sumofdigit-x==0)
                    {
                        cout << 0 ; 
                        return ;
                    }

                    bool skiped = 0 ;
                    for(auto e : v)
                    {
                        if(e==x and skiped==0) {skiped = 1 ; continue;}
                        cout << e ;
                    }
                    return ;
                }
            }

            int nearest = (sumofdigit/3)*3 ;
            int delta = sumofdigit - nearest ;

            for(int d = delta ; (nearest - d) >= 0 ; d+=3)
            {
                if(nearest-d==0)
                {
                    if(s.count(0))
                    {
                        cout << 0 ;
                        return ;
                    }
                }

                for(int i = 0 ; i <= min(d,9LL) ; i++)
                {
                    int x  = i , y = d - x ;
                    if(x>=10 or y>=10) continue;;

                    if(x==y)
                    {
                        if(count(all(v),x)>=2)
                        {
                            bool skippedx = 0 ;
                            bool skippedy = 0 ;

                            for(auto e : v)
                            {
                                if(e==x and skippedx==0) skippedx = 1 ;
                                else if(e==y and skippedy==0) skippedy= 1 ; 
                                else cout << e ;
                            }

                            return ;
                        }
                    }

                    else if(s.count(x) and s.count(y))
                    {
                        bool skippedx = 0 ;
                        bool skippedy = 0 ;

                        for(auto e : v)
                        {
                            if(e==x and skippedx==0) skippedx = 1 ;
                            else if(e==y and skippedy==0) skippedy = 1 ;
                            else cout << e ;
                        }

                        return ;
                    }
                }
            }

            if(s.count(0))
            {
                cout << 0 ; 
                return ;
            }

            cout << -1 ;
        }
   }

   else 
   {
        cout << -1 ;
        return ;
   }
}
signed main(){   FAST    solve() ;  }



