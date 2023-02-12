#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(_case = 1 ; _case <=  TOTALTC ; _case++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int _case = 1 ;

int n ;

int lenCal(int s , int e)
{
    if(s==e) return 1 ;

    if(s < e)
    {
        return (e - s + 1 );
    }

    else if(s > e)
    {
        // circular use ..
        // 7 --> 1 
        return ((n - s + 1) + (e -1 + 1) ) ;
    }

    return 0 ;
}


void solve()
{
    cin >> n ;
    int m  ; cin >> m ; 
    vector<int> v(m);  
    for (auto &x : v) cin >> x;

    if(m==0)
    {
        cout << 0 << nl ;
        return ;
    }

    // else if(n==m)
    // {
    //     cout << n << nl ;
    //     return ;
    // }

    sort(begin(v),end(v)) ;
    multiset<int , greater<int>> ss ;
    
    for(int i = 0 ; i < m ; i++)
    {
        int s = v[i] ;
        int e  = 0 ;

        if( i == m - 1 ) e = v[0] ;
        else e = v[i+1] ;

        if((s + 1 == e) ) continue;
        if(s==n and e==1) continue;
    
        s++ ; 
        e-- ;

        if(s==n+1) s = 1 ;
        if(e==0) e = n ;

        int len =  lenCal(s,e) ;

        // cout << "len = " << len << nl ;


        ss.insert(len) ;
    }

    int timer = 0 ;
    int saved = 0 ;

    while(ss.size())
    {   
        int len = *ss.begin() ;
        ss.erase(ss.begin()) ;

        len -= (2*timer) ;

        timer++ ;
        if(len >= 3) 
        timer++ ;

        int save = len - 1 ;
       
        if(len==1)
        {
            saved += len ;
            break;
        }

        if(save <= 0) break;
    
        save = max(save,0LL) ;
        saved += save ;
    }

    int dead = (n - saved );
    dead = max(dead,0LL) ;
    cout << dead << nl ;

}
signed main()
{   
    FAST      
    TestCases      
    solve() ;  
}



