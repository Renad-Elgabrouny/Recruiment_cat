#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, b;
        cin >> n >> b;

        char grid[1000][1000];
        int num[1000][1000];

        // Read the grid
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
                num[i][j] = grid[i][j] - '0'; 
            }
        }

        // Output the sampled grid
        for (int i = 0; i < n; i += b) {
            for (int j = 0; j < n; j += b) {
                cout << num[i][j];
            }
            cout << endl;
        }
    }

    return 0;
}