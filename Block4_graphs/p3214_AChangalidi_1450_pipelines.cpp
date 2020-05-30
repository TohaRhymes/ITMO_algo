#include <iostream>
#include <vector>
#include <limits>

using namespace std;

struct edge {
    int from, to, weight;
};

const int INF = std::numeric_limits<int>::min() / 2;
vector<edge> edges;
vector<int> distances(500, INF);

int main() {
    // Ввод всех значений

    int n, m;

    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int from, to, weight;
        cin >> from >> to >> weight;
        edges.push_back({from - 1, to - 1, weight});
    }

    int start, finish;
    cin >> start >> finish;
    start--;
    finish--;

    distances[start] = 0;

    for (;;) {
        bool stop = true;
        for (int j = 0; j < m; j++)
            if (distances[edges[j].from] > INF && distances[edges[j].to] < distances[edges[j].from] + edges[j].weight) {
                distances[edges[j].to] = distances[edges[j].from] + edges[j].weight;
                stop = false;
            }
        if (stop)
            break;
    }

    if (distances[finish] > INF) {
        cout << distances[finish];
    } else {
        cout << "No solution";
    }


}