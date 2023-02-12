    #include <bits/stdc++.h>
    using namespace std;



    #define int long long
    #define TestCases int TOTALTC ; cin >> TOTALTC ; for(_case = 1 ; _case <=  TOTALTC ; _case++)
    #define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    #define all(x)  (x).begin() , (x).end()
    #define nl "\n" 
    int _case = 1 ;


    set<int> positionOfA(int n)
    {
        set<int> s ;
        for(int i = 2 ; i <= 3 * n ; i+=3) s.insert(i) ;
        return s ;
    }

    void solve()
    {
        int n;   cin >> n;
        string s ;
        for (int i = 0; i < n; i++)
            s += "BAN" ;

        int i = 0 ;
        int j = s.size() - 1 ;

        vector<pair<int,int>> ans ;

        while (i < j)
        {
            if(s[j] == 'B')
            {
                j--; 
                continue;
            }

            // B ---> A or N ;

            if (s[i] == 'A' or s[i] == 'N')
            {
                i++;
                continue;
            }

            if( s[i] == 'B' and s[j] != 'B')
            {
                ans.push_back({i,j}) ;
                swap(s[i],s[j]) ;
                i++ ;
                j-- ;
            }
        }

        cout << ans.size() << nl ;
        for(auto [x , y ] : ans)
        {
            cout << x + 1 << " " << y + 1 << nl;
        }
    }
    signed main(){   FAST      TestCases      solve() ;  }



