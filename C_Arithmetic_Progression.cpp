#include <bits/stdc++.h>
using namespace std;

#define int long long
const long long MOD = 1e9 + 7;
const long long INF = numeric_limits<long long>::max();
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()


int check(vector<int> &v )
{
    int d = v[1] - v[0] ;

    for(int i = 1 ; i < v.size() ; i++)
    {
        if(v[i] - v[i-1] != d)
        {
            return -1 ;
        } 
    }
    return d ;
}

signed main()
{
    FAST 
    int n ; cin >> n ;

    vector<int> v(n) ; for(int &i : v) cin >>  i ; 

    ranges::sort(v) ;

    if(n==1){ cout << -1 << "\n" ; return 0 ;}
    else if(n==2)
    {
        int d = v[1] - v[0] ; 

        set<int> s ; 
                        s.insert(v.front() - d) , 
                        s.insert(v.back() + d ) ;

        if(d%2==0) s.insert(v.front() + d/2)  ;
        
        cout << s.size() << "\n" ;
        for(auto x : s ) cout << x << " " ;
        return 0 ;
    }

    else if(check(v)!=-1)
    {
        int d = check(v) ;
        set<int> s ; 
        s.insert(v.front() - d) , 
        s.insert(v.back() + d ) ;

        cout << s.size() << "\n" ;
        for(auto x : s ) cout << x << " " ;
    }

    else 
    {

        int d1 = v[1] - v[0] ;
        int d2 = 0 ;

        for(int i = 1 ; i < n ; i++)
        {
            if(v[i]-v[i-1] != d1) {d2  = v[i] - v[i-1] ; break ; }
        }


        if(max(d1,d2) != 2*min(d1 , d2)) 
        {
            cout << 0 << "\n" ;
            exit(0) ;
        }

        int f1{} , f2{} ;

        for(int i = 1 ; i < n ; i++)
        {   
            int dif = v[i] - v[i-1] ;

            if(dif == d1)
            {
                f1++ ;
            }

            else if( dif == d2  )
            {
                f2++;
            }

            else
            {
                cout << 0 ; exit(0) ;
            } 
            
        }

        int d = 0 ;

        if(f1 == 1 and f2>1)
        {   
            d = d2 ;
        }

        else if(f2==1 and f1>1)
        {   
            d = d1;
        }

        else if(f1==1 and f2==1)
        {
            d = min(d1,d2) ;
        }

        else 
        { 
            cout << 0 ; 
            exit(0) ; 
        }

        for(int i = 1 ; i < n ; i++)
        {
            if(v[i] - v[i-1] == 2*d)
            {
                cout << 1 << "\n" ;
                cout << v[i] - d << "\n" ;
                exit(0) ;
            }
        }

        cout << 0 ;

    }
}

 