#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool columns_compare(pair<int, int> p1, pair<int, int> p2) {
    if (p1.second != p2.second)
        return p1.second < p2.second;
    return p1.first < p2.first;
}

bool rows_compare(pair<int, int> p1, pair<int, int> p2) {
    if (p1.first != p2.first)
        return p1.first < p2.first;
    return p1.second < p2.second;
}

void make_borders(vector<pair<int, int>> &points, int amount, int len, bool push_rows = false) {
    pair<int, int> p1 = {0, 0};
    pair<int, int> p2 = {0, 0};
    for (int i = 1; i <= amount; i++) {
        if (push_rows) {
            p1 = {0, i};
            p2 = {len + 1, i};

        } else {
            p1 = {i, 0};
            p2 = {i, len + 1};
        }
        points.push_back(p1);
        points.push_back(p2);
    }

}

int main() {
    int m, n, k;
    int answer = 0;

    cin >> m >> n >> k;

    vector<pair<int, int>> points;
    vector<pair<int, int>> single_squares;

    make_borders(points, m, n, false);
    make_borders(points, n, m, true);

    for (int i = 0; i < k; i++) {
        pair<int, int> p;
        cin >> p.first >> p.second;
        points.push_back(p);
    }

    //Посмотрим на полосы в строках
    std::sort(points.begin(), points.end(), rows_compare);
    for (int i = 0; i < points.size() - 1; i++) {
        if (points[i].first == points[i + 1].first) {
            // Если расположены через одну клетку(т.е. расстояние =2),
            // то запомним их.
            // Иначе если расстояние больше,
            // то тогда получили найс результат.
            if (points[i + 1].second - points[i].second == 2) {
                pair<int, int> p = {points[i + 1].first, points[i + 1].second - 1};
                single_squares.push_back(p);
            } else if (points[i + 1].second - points[i].second > 2) {
                answer++;
            }
        }
    }

    //Посмотрим на полосы в столбцах
    std::sort(points.begin(), points.end(), columns_compare);
    for (int i = 0; i < points.size() - 1; i++) {
        if (points[i].second == points[i + 1].second) {
            // Если расположены через одну клетку(т.е. расстояние =2),
            // то запомним их.
            // Иначе если расстояние больше,
            // то тогда получили найс результат.
            if (points[i + 1].first - points[i].first == 2) {
                pair<int, int> p = {points[i + 1].first - 1, points[i + 1].second};
                single_squares.push_back(p);
            } else if (points[i + 1].first - points[i].first > 2) {
                answer++;
            }
        }
    }
    //если мы два раза записали одиночную клетку - значит она существует и в строке и столбце, а значит это квадратик
    std::sort(single_squares.begin(), single_squares.end(), columns_compare);
    if (single_squares.size() > 1) {
        int i = 0;
        while (i < single_squares.size() - 1) {
            if (single_squares[i] == single_squares[i + 1]) {
                answer++;
                i++;
            }
            i++;
        }
    }
    cout << answer;

//    cout << std::endl;
//
//    for (auto & point : points) {
//        cout << point.first << ' ' << point.second << std::endl;
//    }
//    std::sort(points.begin(), points.end(), columns_compare);


}