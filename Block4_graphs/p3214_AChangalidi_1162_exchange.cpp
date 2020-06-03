#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct edge {
    int a, b;
    double rate, cost;
};

vector<edge> edges;
double moneys[101];


int main() {
    // N - the number of currencies,
    // M - the number of exchange points,
    // S - the number of currency Nick has
    // V - the quantity of currency units he has.
    int N, M, S;
    double V;
    cin >> N >> M >> S >> V;

    S--;
    moneys[S] = V;

    for (int i = 0; i < M; i++) {
        int a, b;
        double RAB, CAB, RBA, CBA;
        cin >> a >> b >> RAB >> CAB >> RBA >> CBA;
        a--;
        b--;
        edges.push_back({a, b, RAB, CAB});
        edges.push_back({b, a, RBA, CBA});
    }

    for (int i = 0; i < N; i++) {
        for (auto & edge : edges)
            moneys[edge.b] = max(moneys[edge.b], (moneys[edge.a] - edge.cost) * edge.rate);

    }

    for (auto & edge : edges) {
        if ((moneys[edge.a] - edge.cost) * edge.rate > moneys[edge.b] + 0.000001) {
            cout << "YES";
            exit(0);
        }
    }

    cout << "NO";

}