#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n"

int f(string &s)
{
    int n = s.size();
    int sum = 0;
    for (int i = 0; i + 1 < n; i++)
    {
        int d = (s[i] - '0') * 10 + (s[i + 1] - '0');
        sum += d;
    }
    return sum;
}

int isPossible1(string s, int k)
{
    int n = s.size();
    int moves = 0;
    if (s.front() == '0')
    {
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                swap(s[i], s[0]);
                moves += i;
                break;
            }
        }
    }

    if (s.back() == '0')
    {
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == '1')
            {
                swap(s[i], s.back());
                moves += n - 1 - i;
                break ;
            }
        }
    }

    if (s.front() == '1' and s.back() == '1')
    {
        if (moves <= k)
        {
            return f(s);
        }

        else
            return -1;
    }

    return -1;
}

int isPossible2(string s, int k)
{
    int n = s.size();
    int moves = 0;

    if (s.back() == '0')
    {
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == '1')
            {
                swap(s[i], s.back());
                moves += n - 1 - i;
                break ;
            }
        }
    }

    if (s.back() == '1')
    {
        if (moves <= k)
        {
            return f(s);
        }

        else
            return -1;
    }

    return -1 ;
}

int isPossible3(string s, int k)
{
    int n = s.size();
    int moves = 0;

    if (s.front() == '0')
    {
        for (int i = 0 ; i < n; i++)
        {
            if (s[i] == '1')
            {
                swap(s[i], s[0]);
                moves += i;
                break;
            }
        }
    }

    if (s.front() == '1')
    {
        if (moves <= k)
        {
            return f(s);
        }

        else
            return -1;
    }

    return -1 ;
}

void solve()
{

    int n , k ; cin >> n >> k ;
    string s ; cin >> s ;
    
    // best try ... 1___1

    int a1 = isPossible1(s,k) ;

    if(a1!=-1)
    {
        cout << a1 << nl ;
        return ;
    }

    // second best ... _____1

    int a2 = isPossible2(s,k) ;
    if(a2!=-1)
    {
        cout << a2 << nl ;
        return ;
    }


    // third best ..  1______

    int a3 = isPossible3(s,k) ;
    if(a3!=-1)
    {
        cout << a3 << nl ;
        return ;
    }

    // allast ....   0_______0

    cout << f(s) << nl ;

}

signed main()
{   FAST  

    TestCases  
    solve() ;  

}

