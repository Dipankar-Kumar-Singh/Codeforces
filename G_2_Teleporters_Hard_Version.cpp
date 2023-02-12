#include <bits/stdc++.h>
using namespace std;
#define int     long long
#define all(x)  begin(x) , end(x)
#define nl      "\n" 


class prefixSum{

    public :
    vector<int> p ;
    int n ; 

    prefixSum(vector<int> &v)
    {
        n = v.size() ;
        p = vector<int>(n+1) ;
        partial_sum(begin(v),end(v),p.begin()+1) ;
    }
    
    int query(int l , int r)
    {
        ++l , ++r ;
        if(l > r) return 0 ;
        return p[r] - p[l-1] ;
    }
} ;


void solve(int& __case__)
{

    int n; cin >> n ;
    int c ; cin >> c ;
    int middlePoint = n/2 ;


    vector<int> v(n) ;
    for(auto &x : v) cin >> x ;

    vector<int> partA ;
    vector<int> partB ;

    for(int i = 0 ; i < middlePoint ; i++)
    {
        int cost = v[i] + (i + 1) ;
        partA.push_back(cost) ;
    }

    for(int i = middlePoint ; i < n ; i++)
    {
        int loc = i + 1 ;
        int endPoint = n + 1 ;
        int d = endPoint - loc ;
        int cost = v[i] + d ;
        partB.push_back(cost) ;
    }

    sort(all(partA)) ;
    sort(all(partB)) ;

    vector<int> comb ;
    for(auto &cost : partA) comb.push_back(cost) ;
    for(auto &cost : partB) comb.push_back(cost) ;
    sort(all(comb)) ;

    int best = 0;
    prefixSum data(partB) ;

    vector<pair<int,int>> COST(n) ;
    for(int i = 0 ; i < n; i++)
    {
        int d1 = i + 1 + v[i] ;
        int d2 = n + 1 - (i + 1) + v[i] ;

        COST[i] = {d1,d2} ; 
    }

    int curr = 0 ;

    int firstJump = -1 ;
    for(int i = 0 ; i < n; i++)
    {
        if(COST[i].first <= c)
        {
            firstJump = i ;
            curr += COST[i].first ;
            c -= COST[i].first ;
            best++ ;
            break;
        }
    }

    if(firstJump == -1)
    {
        cout << 0 << nl ;
        return ;
    }

    comb = vector<int>() ;
    for(int i = 0 ; i < n; i++)
    {
        if(i == firstJump) continue; 
        auto [ d1 , d2 ] = COST[i] ;
        comb.push_back(max(d1,d2)) ;
    }


    sort(all(comb)) ;

    // int ans = 0 ;

    for(auto& x : comb) {
        if(c - x < 0) break;
        c -= x ;
        best++ ;
    }

    cout << best << nl ;
    return ;




    int costFromA = 0 ;
    for(int i = 0 ; i < partA.size() ; i++)
    {
        costFromA += partA[i] ;
        int elements_FromA =  i + 1 ;

        if(costFromA > c)  break;

        int l = -1 , r = partB.size() ; 
        while (r - l > 1)
        {
            int mid = midpoint(l,r) ;
            int elements_fromB = mid + 1 ;
            int costFromB = data.query(0,mid) ;

            if(costFromA + costFromB <= c)
                l = mid ;
            else
                r = mid;
        }

        if(l == -1) {
            best = max(elements_FromA,best) ;
            continue;
        }

        int totalElements = elements_FromA + (l + 1) ;
        int costFromB = data.query(0,l) ;
        if(costFromA + costFromB <= c)
            best = max(totalElements,best) ;
        
    }
    cout << best << nl ;
}

signed main()
{   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int testCases = 1 , case_ = 1;     
    cin >> testCases; for (int case_ = 1; case_ <= testCases; case_++) 
        solve(case_);
}
