#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 

void inc(int id , int len , int delta , vector<int> &a , vector<int> &b , int &ans)
{
    int toInc = b[id] -  a[id] ;
    // size --> 6 ... 

    // 0 1 2 3 4 5 
    //       3 4 5 6 

    // --->> 3 4 5 6

    int start = id , end = id + len -1 ; 

    if(end >= a.size())
    {
        int d = a.size() - (end) ;
        id -= d ;
        toInc -= (d+1) ; 
    }

    ans+= toInc ; 

    start = id , end = id + len -1 ;

    cerr << "id  = " << id << nl ;


    for(int i = start ; i <= end ; i++)
    {
        a[i]+= delta++ ;
    }

    cerr << nl ;
    for(auto x : a ) cerr << x << " " ; cerr << nl << nl ;
}

// void increment(int id , )

signed main()
{   FAST  

    int n , k ; cin >> n >> k ;
    vector<int> v(n) ;
    for(auto &x  : v) cin >> x ;

    vector<int> a(n) ;

    int ans = 0 ; 

    for(int i = 0 ; i < n ; i++)
    {       
        if(v[i]>a[i])
        {
            int delta = v[i] - a[i] ; 
            inc(i,k,delta,a,v,ans) ;
            // ans +=  (delta) ;
        }
    }
    
    cout << ans << nl ; 

    
    

}

