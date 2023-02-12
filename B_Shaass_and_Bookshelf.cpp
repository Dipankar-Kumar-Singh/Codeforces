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
    vector<int> ones , twos ;

    vector<pair<int,int>> v(n);
    for (auto &[x, y] : v)
    {
        cin >> x >> y;

        if (x == 1)
            ones.push_back(y);
        else
            twos.push_back(y);
    }

    // No of Ones ---> 0 --> max(ones.size()) ; 
    // NO of Twos --> 0 --> max(twos.size()) ;

    sort(all(ones)) ;
    sort(all(twos)) ;

    int ans = numeric_limits<long long>::max() ;

    int n1 = ones.size() ;
    int n2 = twos.size() ;

    for(int i = 0 ; i <= n1 ; i++)
    {
        for(int j = 0 ; j <= n2 ; j++ )
        {
            
            // Taking i bools from Ones 
            // j books for tows and 
            // placing them on ... Vertial ..
            // sumOfwidht = sumOfremaing ones .. + someOfReaningtwos

            int sumOfwidth = 0 ;

            for (int k = 0; k < n1- i; k++)
                sumOfwidth += ones[k];
  
            for (int k = 0; k < n2- j; k++)
                sumOfwidth += twos[k];

            int thickness = (i + j*2) ; 

            if(sumOfwidth <= thickness)
            {

                ans = min(ans,thickness) ;
            }
        }
    }

    cout << ans << nl ;
    
}
signed main(){   FAST       solve() ;  }



