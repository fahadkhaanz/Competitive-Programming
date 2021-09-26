    #include <bits/stdc++.h>
    #define ll long long
    using namespace std;
    void solve()
    {
    int n;
        cin >> n;

        int x = 0;
        vector<int> a(n);
        for (auto &i : a)
        {
            cin >> i;
            x ^= i;
        }

        if (x == 0)
        {
            cout << "-1\n";
            return;
        }

        for (int k = 30; k >= 0; --k)
            if (x >> k & 1)
            {
                vector<int> f(2);
                for (auto &i : a)
                    ++f[i >> k & 1];
                if (f[1] % 4 == 3 && f[0] % 2 == 0)
                    cout << "0\n";
                else
                    cout << "1\n";
                break;
            }
    }

    int main()
    {
        solve();   
    }
