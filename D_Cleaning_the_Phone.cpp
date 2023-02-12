#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(_case = 1 ; _case <=  TOTALTC ; _case++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int _case = 1 ;
int n , m;

vector<pair<int,int>> ones ; // Memroy of Convenience Level 1 [ RevSorted ]
vector<pair<int,int>> twos ; // Memroy of Convenience Level 2 [ RevSorted ]

vector<int> pone ; // prefix of Memroy of Convenience Level 1 
vector<int> ptwo ; // prefix of Memroy of Convenience Level 2 

int memoryFreed_with_one(int x)
{
    if(x + 1 >= pone.size()) return pone.back() ;
    return pone[x] ;
}

int memoryFreed_with_two(int x)
{
    if(x + 1 >= ptwo.size()) return ptwo.back() ;
    return ptwo[x] ;
}

bool isPossible(int ans)
{
    for (int two = 0; two < ans; two ++)
    {
        int one = ans - 2*two ; 
        if(one < 0 ) break;
        int memoryFreed = memoryFreed_with_two(two) + memoryFreed_with_one(one) ;
        if(memoryFreed >= m) return 1 ;
    }
    return 0 ;
}

void solve()
{

    cin >> n >> m ; 
    vector<pair<int, int>> input(n);
    int max_memory_freed = 0 ;
    for (auto &[x, y] : input) cin >> x , max_memory_freed += x ;
    for (auto &[x, y] : input) cin >> y;

    if(max_memory_freed < m) {
        cout << -1 << nl ;
        return ;
    }

    ones.clear() , twos.clear() ;
    for (int i = 0; i < n; i++)
        (input[i].second == 1 ? ones : twos).push_back(input[i]);

    sort(all(ones), greater<>());
    sort(all(twos), greater<>());

    pone = vector<int>(ones.size() + 1);
    ptwo = vector<int>(twos.size() + 1);

    for (int i = 0; i < ones.size(); i++)
        pone[i + 1] = pone[i] + ones[i].first;

    for (int i = 0; i < twos.size(); i++)
        ptwo[i + 1] = ptwo[i] + twos[i].first;

    int l = -1 , r = 5e5 ;
    
    while(r -l > 1)
    {
        int mid = midpoint(l,r) ;
        (isPossible(mid) ? r : l) = mid;
    }

    cout << r << nl ;
}
signed main(){   FAST      TestCases      solve() ;  }



