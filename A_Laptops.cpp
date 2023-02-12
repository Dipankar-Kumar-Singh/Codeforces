#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define ll long long
const ll MOD = 1e9 + 7;
const ll INF = numeric_limits<long long>::max();
#define F first      
#define S second     
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()


void print(bool a){
    
    cout <<  (a ? "Happy Alex" : "Poor Alex") ;

}

#define P first 
#define Q second 

int bs(vector<int> &v , int t )
{
    int l =0 , r = v.size() ;
    while (l<=r)
    {   int mid = l + (r-l)/2 ; 
        if(v[mid]==t){return mid ; }
        else if (v[mid]>t){ r = mid -1 ; }
        else if (v[mid]<t){ l = mid +1 ; }  
    }
    return -1 ; 
} 

signed main()
{
    FAST 
    int n ; cin >> n ;
    vector<int> a(n) , b(n) ;
    vector<pair<int,int>> v ;

    for (int i = 0; i < n; i++)
    {
        int x , y ; cin >> x >> y ;
        v.push_back({x,y});
        a[i] = x , b[i] = y ;
    }

    sort(all(v)) ;

    bool possible =  0 ;

    for(int i = 0  ; i < n and !possible; i++){

        int cp = v[i].first , cq = v[i].second ;

        if(cp == cq) continue ; 
        else possible = 1 ;

        if(possible) break ;
    }
    

    print(possible) ;
}

