#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include<bits/stdc++.h>

using namespace std;
const long long INF = 1e11;

inline long long getWeight(long long numa, long long numb, vector<int> &wprice, vector<long long> &splitList) {
    for (int i = 0; i < 10; i++) {
        if ((numa / splitList[i]) % 10 != (numb / splitList[i]) % 10) {
            return wprice[i];
        }
    }
    return wprice[0];
}

vector<long long> distances;

int main() {

    //Constructing Graph
    vector<int> messageWeight(10);
    long long n;
    cin >> n;
    distances = vector<long long>(n, INF);
    vector<vector<pair<int, int> > > wires(n);
    unordered_map<long long, int> NumList;
    set<long long> AllNums;
    for (int i = 0; i < 10; i++) {
        long long weight;
        cin >> weight;
        messageWeight[i] = weight;
    }
    vector<long long> splitList(10);
    for (int i = 1000000000, idx = 0; i |= 0, idx < 10; i /= 10, idx++) {
        splitList[idx] = i;
    }

    //Input No. and connect with other, if we can.
    for (int i = 0; i < n; i++) {
        long long num;
        cin >> num;
        NumList.insert({num, i});
        long long newnum = 0;


        for (int del_change = 0; del_change < 10; del_change++) {
            int a_digit = (int) ((num / splitList[del_change]) % 10);
            for (int m = 0; m < 10; m++) {
                newnum = num - (((num / splitList[del_change]) % 10) * splitList[del_change]) +
                         (splitList[del_change] * m);
                if (newnum == num)continue;
                if (NumList.count(newnum) != 0) {
                    int id = NumList[newnum];
                    wires[i].push_back(make_pair(id, getWeight(newnum, num, messageWeight, splitList)));
                    wires[id].push_back(make_pair(i, getWeight(newnum, num, messageWeight, splitList)));
                }
            }

            for (int swap_change = del_change + 1; swap_change < 10; swap_change++) {
                int b_digit = (int) ((num / splitList[swap_change]) % 10);
                newnum = num - ((a_digit * splitList[del_change]) + (b_digit * splitList[swap_change]));
                newnum += ((b_digit * splitList[del_change]) + (a_digit * splitList[swap_change]));
                if (newnum == num)continue;
                if (NumList.count(newnum) != 0) {
                    int id = NumList[newnum];
                    wires[i].push_back(make_pair(id, getWeight(newnum, num, messageWeight, splitList)));
                    wires[id].push_back(make_pair(i, getWeight(newnum, num, messageWeight, splitList)));
                }
            }
        }

    }



    // Dijkstra
    int start = 0;
    vector<int> children(n);
    priority_queue<pair<int, long long>, vector<pair<int, long long>>, greater<>> pq;
    pq.push(make_pair(0, start));
    distances[start] = 0;
    vector<bool> visited(n, false);
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if (visited[u])continue;
        visited[u] = true;
        for (int i = 0; i < wires[u].size(); i++) {
            int v = wires[u][i].first;
            int weight = wires[u][i].second;
            if (distances[v] > distances[u] + weight) {
                distances[v] = distances[u] + weight;
                children[v] = u;
                pq.push(make_pair(distances[v], v));
            }
        }
    }


    // Output
    if (distances[n - 1] != INF) {
        vector<long long> path;
        for (long long v = n - 1; v != start; v = children[v])
            path.push_back(v);
        path.push_back(start);
        reverse(path.begin(), path.end());
        cout << distances[n - 1] << endl;
        cout << path.size() << endl;
        for (long long i = 0; i < path.size(); i++) {
            cout << path[i] + 1;
            if (i != n - 1) cout << " ";
        }
        cout << endl;
    } else {
        cout << "-1" << endl;
    }
    return 0;
}
