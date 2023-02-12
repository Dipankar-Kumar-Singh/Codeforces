#include <bits/stdc++.h>
using namespace std;
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
vector<int> v ;

int get_ans(int l, int r, int hight)
{
    if(l>r) return 0 ;
    int h = min_element(v.begin()+l, v.begin()+r +1 ) - v.begin() ;
    return min( r - l + 1 , get_ans(l,h-1,v[h]) + get_ans(h+1,r,v[h]) + (v[h]) - hight  ) ;
}

signed main()
{
    FAST 
    int n ; cin >> n ; v.resize(n) ;  for(auto &i : v ) cin >> i ; 
    cout << get_ans(0,n-1,0) ;
}

