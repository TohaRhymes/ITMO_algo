#include <iostream>

using namespace std;


int problem(int n, int k) {
    if (n % k == 0) {
        // m - members in one team
        int m = n / k;
        return m * ((k - 1) * n - (m * k * (k - 1)) / 2);
    } else {
        // m - min members in one team (it gonna be this amount or this+1),
        // e - amounts of commads with m+1 members
        int m = n / k;
        int e = n - m * k;
        // cout << m*(e*(k-e) + (m+1)*e*(e-1)/2;
        // cout << "\n";
        return (m + 1) * (m * e * (k - e) + (m + 1) * e * (e - 1) / 2) + problem((k - e) * m, k - e);
    }
}


int main() {
    // t - teams, n - fighters altogether, k - max amount of teams
    int t;
    cin >> t;
    int n = 0;
    int k = 0;
    for (int i = 0; i < t; i++) {
        cin >> n;
        cin >> k;
        cout << problem(n, k);
        cout << "\n";
    }
    return 0;
}

