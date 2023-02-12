#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n"

const int maxN = 1e6 + 3e3;

vector<int> v(maxN);
vector<int> seg(4 * maxN, 0);

int index(int x, int y, int n)
{
    x--, y--;
    return (n * y + x);
}

int query(int n, int s, int e, int l, int r)
{
    if (e < l or s > r)
    {
        return 0;
    }

    if (s >= l and e <= r)
    {
        return seg[n];
    }

    int mid = (s + e) / 2;

    return (
        query(2 * n + 1, s, mid, l, r) +
        query(2 * n + 2, mid + 1, e, l, r));
}

void update(int n, int s, int e, int id)
{
    if (s == e)
    {
        seg[n] = 1 - seg[n];
        return;
    }

    int mid = (s + e) / 2;

    if (id <= mid)
    {
        update(2 * n + 1, s, mid, id);
    }
    else
    {
        update(2 * n + 2, mid + 1, e, id);
    }
    seg[n] = seg[2 * n + 1] + seg[2 * n + 2];
}

signed main()
{
    FAST int n, m, q;
    cin >> n >> m >> q;
    int N = m * n;

    int arr[n][m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char x;  cin >> x;
            arr[i][j] = (x == '*' ? 1 : 0);
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int id = index(i + 1, j + 1, n);
            if (arr[i][j] == 1)
            {
                update(0, 0, N - 1, id);
                cnt++;
            }
        }
    }

    while (q--)
    {
        int x, y;
        cin >> x >> y;

        int id = index(x, y, n);

        if (arr[x - 1][y - 1])
        {
            cnt--;
            arr[x - 1][y - 1] = 0;
        }
        else
        {
            cnt++;
            arr[x - 1][y - 1] = 1;
        }

        update(0, 0, N - 1, id);

        int mx = max(0LL, cnt - 1);
        int present = query(0, 0, N - 1, 0, mx);

        cout << cnt - present << "\n";
    }
}
