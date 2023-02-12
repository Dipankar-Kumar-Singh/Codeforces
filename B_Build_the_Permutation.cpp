#include <bits/stdc++.h>
using namespace std;

#define int long long
const long long MOD = 1e9 + 7;
const long long INF = numeric_limits<long long>::max();
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()

void no(){
    cout << "-1\n" ; 
}

signed main()
{
    FAST 
    t_case
    {
        
        int n , a, b ; 
        cin >> n >> a >>  b ; 
        vector<bool> skip_conditions = { abs(a-b)>1 , (a+b)>n-2 } ;
        if(any_of(all(skip_conditions),[](bool c){return c;})){ no() ; continue ;}
        
        vector<int> v  ;
        for(int i = 1 ; i <= n ; i++) v.push_back(i) ;

        if(a==b and a!=0)
        {   
            int ct = 0 ;
            for(int i = 2 ; i < v.size()  ; i+=2)
            {
                swap(v[i],v[i-1]) ;
                ct++ ;
                if(ct==a) break ;
            }
        }

        else if(a>b)
        {            
            int id = v.size()  - 1  ;
            while (a--)
            {
                swap(v[id],v[id-1]) ;
                id-=2 ;
            }
        }

        else if(b>a)
        {
            int id = 1 ;
            while (b--)
            {
                swap(v[id],v[id-1]) ;
                id+=2 ;
            }
        }

        for(auto &x : v ) cout << x << " " ; cout<< "\n" ;                                                            
    }
}

