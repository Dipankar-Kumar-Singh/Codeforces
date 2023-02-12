#include <bits/stdc++.h>
using namespace std;
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 

int n1 , n2 ;
vector<int> v1 , v2 ;
int curr_diff = -1e10 ;

int teamA = 0 , teamB = 0 ;

int no_of_element_greater_than_x(vector<int> &v , int x)
{
    int id = (upper_bound(all(v),x) - v.begin()) ;
    int ans =  (v.size() - id) ; 
    return ans ; 
}

bool isPossible(int h)
{
    int bigsA = no_of_element_greater_than_x(v1,h);
    int smallA = (v1.size() - bigsA) ;

    int bigsB = no_of_element_greater_than_x(v2,h);
    int smallB = (v2.size() - bigsB) ;

    int A = bigsA*3 + smallA*2 ;
    int B = bigsB*3 + smallB*2 ;
    int ans = A - B ;

    if(ans > curr_diff)
    {
        curr_diff = ans ;
        teamA = A , teamB = B ;
        return 1 ;
    }
    return 0 ;
}

signed main()
{
    FAST 

    int mxxx = 0 ;
    cin >> n1;  v1.resize(n1) ;
    for (int &i : v1)  cin >> i;

    cin >> n2;  v2.resize(n2);
    for (int &i : v2)    cin >> i;

    sort(all(v1)) , sort(all(v2)) ;

    set<int> s(all(v1)) ; 
    s.insert(all(v2)) ;

    for(auto &x : s) {isPossible(x-1) , isPossible(x) , isPossible(x+1) ;};

    cout << teamA << ":" << teamB ;
}

