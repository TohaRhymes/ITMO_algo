#include <iostream>
#include <cstdlib>
using namespace std;

int max_w(int w_a[], int size, int n) {
    //size - max weight of one box (=half of all weight)
    int d[size + 1][2];
    for (int w = 0; w <= size; w++) {
        d[w][0] = 0;
        d[w][1] = 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= size; w++) {
            //d[w][i] = d[w][i - 1];
            d[w][1] = d[w][0];
            if (w_a[i] <= w) {
                //d[w][i] = max (d[w][i], d[w - w_a[i]][i - 1] + w_a[i]);
                d[w][1] = max(d[w][1], d[w - w_a[i]][0] + w_a[i]);
            }
        }
        for (int w = 0; w <= size; w++) {
            d[w][0] = d[w][1];
        }
    }
    return d[size][0];
}

int main() {
    int n;
    cin >> n;
    int w_a[n + 1];
    int sum_weight = 0;
    w_a[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> w_a[i];
        sum_weight += w_a[i];
    }
    int first_bag = max_w(w_a, (sum_weight + 1) / 2, n);
    int second_bag = sum_weight - first_bag;
    cout << abs(second_bag - first_bag);
    return 0;
}

