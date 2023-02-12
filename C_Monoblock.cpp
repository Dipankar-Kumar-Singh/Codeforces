#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int total ; cin >> total ;  for(test = 1 ; test <=  total ; test++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n"  
int const INF  = 1e18 ;
int test = 0 ;


int optimized(vector<int> &v)
{
    int ans = 0 ;
    int n = v.size() ;
    for(int i = 0 , curr = v.front()  ; i < n ; i++) 
    {
        if(v[i] == curr) 
        {
            ans += 1 * (n - i);
        }

        else 
        {
            curr = v[i] ;

            int onLeft = i + 1 ;
            int onRight_inc_Itself = n - i ;

            ans += onLeft * onRight_inc_Itself ;
        }

    }

    return ans ;
}

int afterUpdate(int i , int value , vector<int> &v , int ans)
{
    int n = v.size()  ;   

    int j = i + 1 ;

    if(i==n-1)
    {
        // if (v[i] != v[i - 1])
        //     ans += (i + 1);

        if (v[i] == v[i - 1])
        {
            ans -= 1 ;

            if(value == v[i-1])
            {
                ans += 1 ;
            }

            else 
            {
                ans += (i + 1);
            }
        }

        else 
        {
             // 1 4 4 3 2

             ans -= (i + 1);
             ans += (value == v[i - 1] ? 1 : (i + 1)) ;

        }
        
        v[i] = value ;

        return ans ;
    }

    int oldA =  n - i;
    int oldB =  n - j;

    if ((i - 1) >= 0)
    {
        if (v[i - 1] != v[i])
            oldA = (i + 1) * (n - i);
    }

    if (v[i] != v[j])
        oldB = (j + 1) * (n - j);


    ans -= (oldA + oldB);

    v[i] = value;

    int newA = n - i;
    
    if ((i - 1) >= 0)
        newA = ((v[i - 1] == v[i]) ? (n - i) : (i + 1) * (n - i));

    int newB = ((v[i] == v[j]) ? (n - j) : (j + 1) * (n - j));

    ans += (newA + newB) ;

    return ans ;
}


void solve()
{

    int n ; cin >> n ;
    int m ; cin >> m ;
    vector<int> v(n) ; for(auto &x : v) cin >> x ;

    int ans = optimized(v) ;

    while(m--)
    {
        int i , val ; 
        cin >> i >> val ;
        i-- ;
        ans = afterUpdate(i,val,v,ans) ;
        cout << ans << nl ;
    } 

}

signed main()
{  
    FAST     
    solve() ; 
}