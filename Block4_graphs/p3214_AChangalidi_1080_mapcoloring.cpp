#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> graph[100];
vector<int> colors(100, -1);

void bfs(int start) {
    queue<int> neighbours;
    neighbours.push(start);
    colors[start] = 0;

    while (!neighbours.empty()) {
        int cur_point = neighbours.front();
        neighbours.pop();
        for (int point_to : graph[cur_point]) {
            if (colors[point_to] == colors[cur_point]) {
                cout << "-1";
                exit(0);
            }
            if (colors[point_to] == -1) {
                colors[point_to] = !colors[cur_point];
                neighbours.push(point_to);
            }
        }
    }
}

void dfs(int start, int color) {
    colors[start] = color;
    for (int point_to : graph[start]) {
        if (colors[point_to] == colors[start]) {
            cout << "-1";
            exit(0);
        }
        if (colors[point_to] == -1) {
            dfs(point_to, !colors[start]);
        }
    }

}

int main() {
    // граф
    int n; // число вершин
    int start = 0; // стартовая вершина (вершины везде нумеруются с нуля)
    cin >> n;
    // чтение графа
    for (int point = 0; point < n; point++) {
        int neighbour = 666;
        while (neighbour != -1) {
            cin >> neighbour;
            neighbour--;
            if (neighbour != -1) {
                graph[point].push_back(neighbour);
                graph[neighbour].push_back(point);
            }
        }
    }

//    // обход в ширину, пока не посетим все вершины
//    for (int i = 0; i < n; i++) {
//        if (colors[i] == -1) {
//            bfs(i);
//        }
//    }

    // ИЛИ обход в глубину
    for (int i = 0; i < n; i++) {
        if (colors[i] == -1) {
            dfs(i, 0);
        }
    }


    // вывод ответа
    for (int i = 0; i < n; i++) {
        cout << colors[i];
    }

    return 0;
}