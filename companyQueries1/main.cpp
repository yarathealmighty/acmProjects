#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

const int MAX_N = 2e5 + 5;

vector<int> boss;
vector<vector<int>> ancestors;

void preprocessAncestors(int n) {
    ancestors.resize(n + 1, vector<int>(20, 0)); // Initialize with 0 instead of -1

    for (int i = 1; i <= n; i++) {
        ancestors[i][0] = boss[i];
    }

    for (int j = 1; (1 << j) <= n; j++) {  // Change to (1 << j) < n
        for (int i = 1; i <= n; i++) {
            if (ancestors[i][j - 1] != 0) {
                ancestors[i][j] = ancestors[ancestors[i][j - 1]][j - 1];
            }
        }
    }
}

int findAncestor(int x, int k) {
    for (int j = 19; j >= 0; j--) {
        if (k & (1 << j)) {
            x = ancestors[x][j];
            if (x == 0) {
                return -1;
            }
        }
    }
    return x;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, q, e, x, k;

    cin >> n >> q;

    boss.resize(n + 1);
    for (int i = 2; i <= n; i++) {
        cin >> e;
        boss[i] = e;
    }

    preprocessAncestors(n);

    for (int i = 0; i < q; i++) {
        cin >> x >> k;
        int result = findAncestor(x, k);
        cout << result << endl;
    }

    return 0;
}
