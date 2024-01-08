#include <bits/stdc++.h>
using namespace std;

void solve(int &__case__)
{
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> g(n + 1);

    for (int node = 1; node <= n; node++)
    {
        int sz = {0};
        std::cin >> sz;
        while (sz--)
        {
            int child{};
            std::cin >> child;
            g[node].push_back(child);
        }
    }

    int LOG = 30;
    std::vector<int> tin, tout;
    tin = tout = std::vector<int>(n + 1);
    int timer = 0;

    std::vector<std::vector<int>> up(n + 1, std::vector<int>(LOG));

    std::function<void(int, int)> dfs = [&](int node, int par) -> void
    {
        tin[node] = timer++;

        up[node][0] = par;
        for (int i = 1; i < LOG; i++)
        {
            up[node][i] = up[up[node][i - 1]][i - 1];
        }

        for (int child : g[node])
        {
            dfs(child, node);
        }

        tout[node] = timer++;
    };

    dfs(1, 1);

    std::function<int(int, int)> lca = [&](int a, int b) -> int
    {
        function<bool(int, int)> isAncestor = [&](int a, int b)
        {
            return (tin[a] <= tin[b] && tout[a] >= tout[b]);
        };

        if (isAncestor(a, b))
            return a;
        if (isAncestor(b, a))
            return b;

        for (int i = LOG - 1; i >= 0; i--)
        {
            if (!isAncestor(up[a][i], b))
            {
                a = up[a][i];
            }
        }

        return up[a][0];
    };

    int q;
    std::cin >> q;

    while (q--)
    {
        int x, y;
        std::cin >> x >> y;
        cout << lca(x, y) << '\n';
    }
}

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int testCases = 1, case_ = 1;
    std::cin >> testCases;
    for (int case_ = 1; case_ <= testCases; case_++)
    {
        cout << "Case " << case_ << ":\n";
        solve(case_);
    }
}

/*
            ██████╗ ██╗██████╗  █████╗ ███╗   ██╗██╗  ██╗ █████╗ ██████╗
            ██╔══██╗██║██╔══██╗██╔══██╗████╗  ██║██║ ██╔╝██╔══██╗██╔══██╗
            ██║  ██║██║██████╔╝███████║██╔██╗ ██║█████╔╝ ███████║██████╔╝
            ██║  ██║██║██╔═══╝ ██╔══██║██║╚██╗██║██╔═██╗ ██╔══██║██╔══██╗
            ██████╔╝██║██║     ██║  ██║██║ ╚████║██║  ██╗██║  ██║██║  ██║
            ╚═════╝ ╚═╝╚═╝     ╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝
*/
