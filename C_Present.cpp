#include "bits/stdc++.h"
using namespace std;


/* -------------------------------------------------------------------------- */
/*                                THANKS ROHIT  🙂                              */
/* -------------------------------------------------------------------------- */

#define int long long
const long long MOD = 1e9 + 7;
const long long INF = numeric_limits<long long>::max();
#define all(x)  (x).begin() , (x).end()
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define nl "\n" 
#define N 100010 

vector < int > seg (4*N) ;
vector < int > lazy (4*N) ;
vector < int > v ;


int final = INF ;

void build(int node , int s , int e )
{

    if (s == e)
    {
        // if range == 1 element then fill 
        seg[node] = v[s] ; 
        return ; 
    }

    // else break the reange into smaller peice untill range == 1 element

    int mid = midpoint(s,e) ;

    build(node*2 + 1 , s , mid  ) ;
    build(node*2 + 2 , mid + 1 , e ) ;

    if(s != e )
    {
        seg[node] = min( seg[ node*2 + 1 ] , seg[ node*2 + 2 ] ) ; 
    }
}

void solvelazy(int node , int s , int e )
{

    seg[node] += lazy[node]  ;

    if(s != e)
    {
        lazy[node*2 + 1 ] += lazy[node] ; 
        lazy[node*2 + 2 ] += lazy[node] ;
    }

    lazy[node] =  0 ;
}

void update(int node , int s , int e , int l , int r , int val)
{

    solvelazy(node,s,e) ;

    if( s>r or e<l) return ;

    if( s>= l and e <= r)
    {
        // if found a fully inside our update range segment 
        // do apply update in lazy way [ apply at first layer]
        lazy[node] += val ;
        solvelazy(node,s,e) ;
    
        return ;
    }

    // split the range untill we find ranges which are completely inside out range  [ l ,r ]
    
    int mid = midpoint(s,e) ;

    update(node * 2 + 1, s,     mid, l, r, val);
    update(node * 2 + 2, mid + 1, e, l, r, val);

    if(s!=e)  
    {
        seg[node]  = min(seg[node*2 + 1] , seg[node*2 + 2] ) ;
    }
}


int query(int node , int s , int e)
{

    solvelazy(node , s , e) ;

    if(s == e)
    {
        final = seg[node] ; 
        return s ;
    }

    int mid = midpoint(s,e) ;

    solvelazy(node*2 + 1 , s , mid ) ;
    solvelazy(node*2 + 2 , mid +1 , e ) ;

    if(seg[node*2+1] <= seg[node*2 + 2] )
    {
        
        int index = query(node*2 + 1 , s , mid ) ;
        // lazy apply hua hoga .... so seg[node] bhi update hona chaiye 

        seg[node] = min(seg[node*2 + 1 ] , seg[node*2 + 2] ) ;
  
        return index ;
    }

    else 
    {
        int index = query(node*2+2 , mid + 1 , e ) ;
        seg[node] = min(seg[node*2 + 1 ] , seg[node*2 + 2] ) ;
        return index ;
    }

}


void segment_tree_sol()
{
    int n , m , w;
    cin >> n >>  m >> w ;
    v.clear() ;
    v.resize(n) ; for(int & i : v) cin >> i  ;
    

    build(0,0,n-1) ;


    while (m--)
    {
        int index = query(0,0,n-1) ;
        update(0,0,n-1,index , index + w - 1  ,1) ;
    }

    int ans = query(0,0,n-1 ) ;
    cout << final ;




}



signed main()
{
    FAST 

    // binary_serach_sol() ;
    // TLE_SOLVE() ;

    segment_tree_sol() ;

 
}


// void segment_tree_sol()
// {



// }

// int clean_swap(int s , int len , vector<int> &v)
// {
//     int cost =  v[s] ;
//     for(int i = s ; i <  min((s + len) , (int)v.size())  ; i++)
//     {
//         v[i]  -=  cost ;  
//     }
//     return cost ;
// }

// bool isPossible(int target , vector<int> &v , int w , int cost)
// {
//     int n = v.size() ; int total_cost =  0 ;
//     vector<int> mask  ;

//     for(auto &x : v)
//         if(x < target) 
//             mask.push_back(target-x) ;
//         else 
//             mask.push_back(0) ; 

//     for(int i = 0 ; i < n ; i++)
//     {
//         if(mask[i] > 0)
//         {
//             total_cost += clean_swap(i,w,mask) ;
//         }

//         if(total_cost > cost) return 0 ;
        
//     }
//     return (total_cost <= cost) ;
// }

// void binary_serach_sol()
// {
//     int n , m , w;
//     cin >> n >>  m >> w ;
//     vector<int> v(n) ; for(int & i : v) cin >> i  ;

//     int l = -1 , r = 2e9 + 8000 ;

//     while (r-l>1)
//     {
//         int mid = midpoint(l,r);

//         if(isPossible(mid,v,w,m))
//         {
//             l = mid ;
//         }

//         else r = mid ;
//     }

//     if(isPossible(l+1,v,w,m)) l = l+1 ;
//     if(l == - 1) l = *min_element(all(v)) ;

//     cout << l ; 
// }


// void TLE_SOLVE()
// {
//     int n , m , w;
//     cin >> n >>  m >> w ;
//     vector<int> v(n) ; for(int & i : v) cin >> i  ;

//     set<int> min_heap ;
//     // unordered_map<int,int> fr ;
//     // unordered_map<int,set<int>> loc_set ; 

//     map<int,int> fr ;
//     map<int,set<int>> loc_set ; 

//     for(int i =  0 ; i < n ; i++)
//     {
//         loc_set[v[i]].insert(i) ;
//         fr[v[i]]++ ;
//         min_heap.insert(v[i]) ;
//     }


//     while ( m-- )
//     {
//         auto e = *min_heap.begin() ;
//         auto loc = loc_set[e] ;

//         int first_id = *loc.begin() ;

//         for(int i = first_id ; i < min(n,(first_id + w)) ; i++)
//         {
//             loc_set[v[i]].erase(i) ;
            
//             fr[v[i]]-- ;
            
//             if(fr[v[i]] == 0)
//             {
//                 min_heap.erase(v[i]) ;
//             }

//             v[i]++ ;
//             fr[v[i]]++ ;
//             loc_set[v[i]].insert(i) ;
//             min_heap.insert(v[i]) ;
            
//         }

//     }

//     cout << *min_heap.begin() << nl ;
// }


