#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long t;
    cin >> t;

    while (t--) {
        long long n, m;
        cin >> n >> m;

        // If n or m is 1, print "YES"
        if (n == 1 || m == 1) {
            cout << "YES\n";
            continue;
        }

        // If n is less than m, print "NO"
        if (n < m) {
            cout << "NO\n";
            continue;
        }

        // Find the smallest prime factor of n
        long long smallestFactor = n;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                smallestFactor = i;
                break;
            }
        }

        // If the smallest factor is less than or equal to m, print "NO"
        if (smallestFactor <= m) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }

    return 0;
}