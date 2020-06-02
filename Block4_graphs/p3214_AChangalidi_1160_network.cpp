#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    int n, m;
    cin >> n >> m;
    // <вес, <вершина_1, вершина_2>>
    vector<pair<int, pair<int, int> > > graph(m);
    for (int i = 0; i < m; i++) {
        int w, v1, v2;
        cin >> v1 >> v2 >> w ;
        v1--;
        v2--;
        graph[i] = {w, {v1, v2}};
    }
    // сортируем по возрастанию, чтобы брать минимальные ребра
    sort(graph.begin(), graph.end());

    int max_l = 0;
    int amount = 0;
    vector<pair<int, int> > MST;

    // массив принадлежностей к тому или иному классу
    vector<int> tree_id(n);

    for (int i = 0; i < n; ++i)
        tree_id[i] = i;
    for (int i = 0; i < m; ++i) {
        int a = graph[i].second.first;
        int b = graph[i].second.second;
        int length = graph[i].first;
        if (tree_id[a] != tree_id[b]) {
            max_l = length;
            MST.push_back(make_pair(a, b));
            int old_id = tree_id[b];
            int new_id = tree_id[a];
            for (int j = 0; j < n; ++j)
                if (tree_id[j] == old_id)
                    tree_id[j] = new_id;
        }
        if(max_l==length)
            amount++;
    }
    cout << max_l << endl;
    cout << MST.size() << endl;
//    std::sort(MST.begin(), MST.end());
    for (auto edge : MST) {
        cout << ++edge.first << ' ' << ++edge.second<< endl;
    }
//    cout << amount << endl;
//    for (auto edge : graph) {
//        if(edge.first<=max_l)
//            cout << ++edge.second.first << ' ' << ++edge.second.second<< endl;
//    }

}