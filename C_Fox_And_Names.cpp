#include <bits/stdc++.h>
using namespace std;

#define int long long
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()


map<char,bool> seen ;
map<char,vector<char>> g ;
map<char,int> vis ;

string ans ;

void dfs(char c){ 
    vis[c] = 1 ;
    for(auto cc : g[c] ) 
        {   
            if(!vis[cc])  { dfs(cc) ;}
            else if(vis[cc] == 1) {
                cout << "Impossible";
			    exit(0);
            }
        }
    vis[c] = 2 ; 
    ans.push_back(c) ;
}

signed main()
{
    FAST 
    vector<string> vec ;

    int n ; cin >> n ; 
    for(int i = 0 ; i < n ; i++)
    {
        string s ; cin >> s ;
        vec.push_back(s) ; 
    }

    for(int t = 0 ; t < n - 1 ; t++){ 
        int i = 0 ;
        while (vec[t][i] == vec[t+1][i])
        {
            i++ ; 
            if(i == vec[t].size() or i == vec[t+1].size())  break ;
        }

        int n1 = vec[t].size() , n2 = vec[t+1].size() ;

        if(i == n2 and n1 > n2)
        {  cout << "Impossible" ; return 0 ;     } 

        else if(i == n1 and n1 > n2)
            continue ;
    
        char a  = vec[t][i] , b = vec[t+1][i] ;
        if(a!=b)
        {
                seen[a] = seen[b] = 1 ;
                g[a].push_back(b) ;  
        }
    }

        for (int i = 0; i < 26; i++) 
        {   
            char c = 'a' + i ;  
            if(!vis[c] and seen[c])  dfs(c) ;
        }
       
        reverse(all(ans)) ;

        for(auto &c : ans ) cout << c ;

        for (int i = 0; i < 26; i++)
        {
            const char c = char('a' + i);
            if (!seen[c])  cout << c;
    
        }

}

