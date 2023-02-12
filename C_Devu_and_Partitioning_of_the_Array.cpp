#include <bits/stdc++.h>
using namespace std;

#define int long long
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 

void better_approac()
{
    int n , k , p ;  
    cin >> n >> k >> p ; 
    stack<int>  odd , even ;
    stack<int> ans[k];

    for (int i = 0; i < n; i++)
    {
        int x ;  cin >> x;
        ((x % 2 == 0) ? even : odd ).push(x) ;
    }

    int even_base = p , odd_base = k - p ;

    int extra_even =  even.size() - even_base ;
    int extra_odd = odd.size() - odd_base ;

    bool c1 = extra_odd  < 0 or ((extra_odd)%2 !=0 ) ;
    bool c2 = even.size() + (extra_odd/2) < even_base  ;
    if(c1 or c2 ) { cout << "NO" ; exit(0) ;}

    for(int i = 0 ; i < even_base ; i++)
    {
        if(!even.empty())
            {ans[i].push(even.top()) ; even.pop() ;}
        else
            for(int j = 1 ; j <=2 ; j++)
                {ans[i].push(odd.top()) ; odd.pop() ;}
    }


    for(int i = k - odd_base ; i < k ; i++)
        if(!odd.empty())
           { ans[i].push(odd.top()) ; odd.pop() ;}
        
    while (!odd.empty())
        {ans[0].push(odd.top()) ; odd.pop() ;}
    
    while (!even.empty())
        {ans[0].push(even.top()) ; even.pop() ;}
    

    cout << "YES\n" ;
    for(auto v : ans )
    {
        cout << v.size() << " " ;
        while (!v.empty())
        {
            cout << v.top() << " " ;
            v.pop() ;
        }
        cout << nl ;
    }
}

signed main()
{
    FAST 
    better_approac() ;
}

