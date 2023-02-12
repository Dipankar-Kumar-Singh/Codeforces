#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 

int lenOfLongSubarr(vector<int> &A, int N, int K)
{
 
    int i = 0, j = 0, sum = 0;
    int maxLen = INT_MIN;
   
    while (j < N) {
        sum += A[j];
        if (sum < K) {
            j++;
        }
        else if (sum == K) {
            maxLen = max(maxLen, j-i+1);
            j++;
        }
        else if (sum > K) {
            while (sum > K) {
                sum -= A[i];
                 i++;
            }
              if(sum == K){
              maxLen = max(maxLen, j-i+1);
            }
            j++;
        }
    }

    return maxLen;
}

void solve()
{
    int n ; cin >> n ; int sum ; cin >> sum ;
    vector<int> v (n) ; for(auto &x : v) cin >> x ;

    int ans = v.size() - lenOfLongSubarr(v, n, sum);

    if (accumulate(all(v), 0LL) < sum)
    {
        cout << -1 << nl;
        return;
    }

    cout << ans << nl;
}
signed main(){   FAST      TestCases      solve() ;  }
