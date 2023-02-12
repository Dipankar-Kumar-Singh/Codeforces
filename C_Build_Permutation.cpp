#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(_case = 1 ; _case <=  TOTALTC ; _case++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int _case = 1 ;

set<int> s ;

bool check(vector<int> &ans)
{
    for(int i = 0 ; i < ans.size() ; i++)
    {
        int x = i + ans[i] ;
        if(s.find(x)==s.end()) return 0 ;
    }
    return 1 ;
}

vector<int> generateAns(int n)
{
   vector<int> v(n);  
   iota(all(v),0) ;

   set<int> nums (all(v)) ;

   vector<int> ans(n) ;
    
   int target = *s.lower_bound(n - 1) ;

    for (int i = n - 1; i >= 0; i--)
    {
        int req = target - i ;

        auto it = nums.find(target - i) ;

        if(it==nums.end())
        {
            target = *s.lower_bound(i) ;
            auto a = nums.find(target-i) ;

            if(a==nums.end()) 
            {
                cout << -1 << nl ;
                return vector<int>();
            }

            ans[i] = *a ;
        }

        else 
        {
            ans[i] = *it ; 
            nums.erase(it) ;
        }
    }

    return ans ;
}

void solve()
{
   int n;   cin >> n;
   vector<int> v(n);  
   iota(all(v),0) ;

   set<int> nums (all(v)) ;

    vector<int> ans(n) ;
    
   int target = *s.lower_bound(n - 1) ;


    for (int i = n - 1; i >= 0; i--)
    {
        int req = target - i ;

        auto it = nums.find(target - i) ;

        if(it==nums.end())
        {
            int newTarget =  0 ;
            newTarget = *s.lower_bound(i) ;

            target = newTarget ;

            auto a = nums.find(target-i) ;

            if(a==nums.end()) 
            {
                cout << -1 << nl ;
                return ;
            }

            ans[i] = *a ;
            nums.erase(*a) ;
        }

        else 
        {
            ans[i] = *it ; 
            nums.erase(it) ;
        }
    }


    for(auto x : ans) cout << x << " " ; cout << nl ;

}
signed main(){   
    FAST     

    for(int i = 0 ; i <= 1000 ; i++) s.insert(i*i) ; 

    cout << boolalpha ;

    TestCases      solve() ;  

}



