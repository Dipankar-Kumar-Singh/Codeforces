#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(_case = 1 ; _case <=  TOTALTC ; _case++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int _case = 1 ;

auto takeInput(int n)
{
    multiset<int> s ;
    for(int i = 0 ; i < n; i++)
    {
        int x ; cin >> x ;
        s.insert(x) ;
    }
    return s ;
}


void solve()
{
   int n ; cin >> n ;
   multiset<int> a , b ; 

    // multiset<int> a = takeInput(n) , b = takeInput(n) ;

    for(int i = 0 ; i < n; i++)
    {
        int x ; cin >> x ; 
        while(x%2==0) x/=2 ;
        a.insert(x) ;
    }

    for(int i = 0 ; i < n ; i++)
    {
        int x ; cin >> x ; 
        b.insert(x) ;
    }


    while(b.size())
    {
        auto it = b.begin() ;
        int x = *it ;
        if(a.find(x) != a.end())
        {
            a.erase(a.find(x)) ; b.erase(b.find(x)) ;
        }

        else
        {
            if(x==1) break; 
            
            x = x >> 1 ;
            b.erase(it) ;
            b.insert(x) ;
        } 
    }

    if(a.empty() and b.empty())
    {
        cout << "YES\n" ;
    }

    else cout << "NO\n" ;

    

   

   


}
signed main(){   FAST      TestCases      solve() ;  }



