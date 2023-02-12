#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n"


int solveForReminders(multiset<int> &s , int k)
{
    int sum = 0 ;
    while (s.size())
    {
        auto a = *s.begin();  s.erase(s.begin());
        auto it = s.lower_bound(k - a);
        if (it != s.end())
        {
            s.erase(it);
            sum++;
        }
    }
    return sum ;
}

// funtion to get sum  !SECTION - 342 !


int usingTwoPointer(vector<int> &a , int k)
{
    int sum = 0 ;
    sort(all(a),greater<>()) ;
    int n = a.size() ;
    for(int i = 0 , j = n - 1 ; i < j ; i++)
    {
        while(i<j and a[i] + a[j] < k ) j-- ;
        if(i < j) sum++ , j-- ;
    }

    return sum ;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n) , a ;
    for (auto &x : v)        cin >> x;

    int sum = 0;    
    multiset<int> s;

    for (auto &x : v)
        sum += x / k, s.insert(x % k) , a.push_back(x%k) ;

    // sum += solveForReminders(s,k)  ;
    sum += usingTwoPointer(a,k) ;
    cout << sum << nl ;
    return ;

}

signed main()
{   FAST  

    TestCases  
    solve() ;  

}

