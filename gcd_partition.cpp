#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll gcd(ll a, ll b)
{

    if (b == 0)
        return a;

    return gcd(b, a % b);
}

ll sgcd(ll a, ll b)
{
    if (b > a)
        swap(a, b);

    return gcd(a, b);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, a;
        cin >> n;
        ll sum[n + 1];

        for (ll i = 0; i <= n; i++)
            sum[i] = 0;

        for (ll i = 1; i <= n; i++)
        {
            cin >> a;
            sum[i] = sum[i - 1] + a;
        }

        ll max_gcd = 1;

        for (ll i = 1; i < n; i++)
            max_gcd = max(max_gcd, sgcd(sum[i], sum[n] - sum[i]));

        cout << max_gcd << endl;
    }
}