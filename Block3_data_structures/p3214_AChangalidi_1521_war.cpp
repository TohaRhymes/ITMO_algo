#include <iostream>

using namespace std;

int counter = 1;

void build(pair<int, int> tree[], int cur_v, int left_board, int right_board) {
    if (left_board == right_board) {
        tree[cur_v].first = 1;
        tree[cur_v].second = counter++;
    } else {
        int splitter = (left_board + right_board) / 2;
        build(tree, cur_v * 2, left_board, splitter);
        build(tree, cur_v * 2 + 1, splitter + 1, right_board);
        tree[cur_v].first = tree[cur_v * 2].first + tree[cur_v * 2 + 1].first;
        tree[cur_v].second = -1;
    }
}


int update(pair<int, int> tree[], int cur_v, int left_board, int right_board, int k_pos) {
    tree[cur_v].first--;
    if (left_board == right_board) {
        // пошлем солдата драить туалеты
        return tree[cur_v].second;
    } else {
        int splitter = (left_board + right_board) / 2;
        if (tree[2 * cur_v].first >= k_pos)
            update(tree, cur_v * 2, left_board, splitter, k_pos);
        else
            update(tree, cur_v * 2 + 1, splitter + 1, right_board, k_pos - tree[2 * cur_v].first);
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    //pair<сколько доступных вершин в поддереве; номер солдата (у не-листа = -1)>
    pair<int, int> tree[4 * n];

    build(tree, 1, 1, n);

//    for(int i = 0; i<20; i++){
//        cout<< tree[i].first << " "<< tree[i].second<<endl;
//    }

    int cur_k = k;

    for (int i = 0; i < n; ++i) {
        cout << update(tree, 1, 1, n, cur_k) << endl;
        if (i != n - 1) {
            cur_k = (cur_k - 1 + k) % (n - 1 - i);
            if (cur_k == 0)
                cur_k += n - 1 - i;
        } else return 0;
    }


}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//