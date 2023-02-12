#include <bits/stdc++.h>
using namespace std;

#define int long long
#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 

void solve_with_even_giver_element_present(int &moves , vector < int> &odd , vector <int > &even )
{
    while (!odd.empty())
    {
        if (even.empty()) break ;
        int e = even.back();    even.pop_back();
        int o1 = odd.back(), o2 = 0;     odd.pop_back();
        e--;  o1++;
        even.push_back(o1);

        if (!odd.empty())
        {
            o2 = odd.back();   odd.pop_back();
            e--;    o2++;      even.push_back(o2);
            if (e)  even.push_back(e);
        }
        else
        {
            e--;  if(e) even.push_back(e);
        }
        moves++;
    }
}


int solve_when_only_odd_element_left_as_doner(int &moves , vector < int> &odd , vector <int > &even )
{
    
        if (!odd.empty())
        {
            int o1{-1}, o2{-1}, o3{-1};
            o1 = odd.back();
            odd.pop_back();
            if (!odd.empty())
            {
                o2 = odd.back();
                odd.pop_back();
            }
            if (!odd.empty())
            {
                o3 = odd.back();
                odd.pop_back();
            }

            vector<int> temp = {o1, o2, o3};

            sort(all(temp), greater<int>());

            if (temp.front() <= 1)
            {
                return -1;
            }

            int a = temp[0], b = temp[1], c = temp[2];
            a -= 2;    moves++;

            if (a % 2 == 0 and a > 0)
                even.push_back(a);
 
            else
                odd.push_back(a);

            if (b != -1)
            {
                b++;
                even.push_back(b);
            }

            if (c != -1)
            {
                c++;
                even.push_back(c);
            }
        }
        return 0 ;
}

long long solve()
{
    int n;  cin >> n;
    vector<int> v(n), odd, even;

    for (auto &x : v)  cin >> x;
    if(v.size() ==3 and v[1]&1) return -1 ;

    for (int i = 1; i < n - 1; i++)
    {
        int x = v[i];
        if(x) ((x&1) ? odd : even).push_back(x) ;
    }
    long long moves = 0; sort(all(odd)) , sort(all(even)) ;
    while (1)
    {
        if (odd.empty()) break ;
        solve_with_even_giver_element_present(moves, odd, even);
        if(solve_when_only_odd_element_left_as_doner(moves,odd,even) == -1) return -1 ;;
    }

    long long x = accumulate(all(even),0LL)/2 ;
    return (x+moves) ;
}

signed main()
{
    FAST 
    t_case  cout  << solve() << nl ;                        
}

