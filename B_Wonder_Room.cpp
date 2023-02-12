#include <bits/stdc++.h>
using namespace std;

#define int long long
const long long MOD = 1e9 + 7;
const long long INF = numeric_limits<long long>::max();
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 

void print(vector<int> ans , int area , bool c)
{
    sort(all(ans)) ;
    if(c == 1)
        reverse(all(ans));

    cout << area << nl << ans[0] << " " <<ans[1] ;
    
}

signed main()
{
    FAST 

    int n ,a, b ;
    cin >> n >> a >> b ;

    bool c = a > b ;


    int target = 6*n ;
    int start = target ;

    if(a*b >= target)
    {
        cout << a*b << nl << a << " " << b ;
        exit(0) ;
    }
    if(a > b) swap(a,b) ;

    for(int area = target ; area < INF ; area++)
    {
        int sq = sqrt(area);
        for (int i = a; i <= sq; i++)
        {
            if (area % i == 0 and area / i >= b)
            {
                print({i, area / i}, area, c);
                exit(0);
            }
        }
    }

    while (true)
    {
        for (int i = a; i * i <= target; i++)
        {
            if (target % i == 0 and target / i >= b)
            {
                print({i, target / i}, target, c);
                exit(0);
            }
        }

        target++ ;
    }



}

