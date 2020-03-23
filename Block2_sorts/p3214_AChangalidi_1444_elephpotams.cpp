#include <iostream>
#include <math.h>

#define ll long long
#define EPS 1e-10
#define M_PI 3.14159265358979323846
using namespace std;

struct Point {
    ll x;
    ll y;
    double angle;
    double distance;
    int index;
};

bool compare(Point point1, Point point2) {
    if (abs((double) point1.angle - (double) point2.angle) < EPS) {
        return point1.distance < point2.distance;
    }
    return point1.angle < point2.angle;
}

//n - amount of points
int n;
Point *points;


void sort_points_by_angle(int left, int right) {
    int i = left;
    int j = right;
    //chose the median point between first, central and last point for indexes in [left; right]
    Point *a = &points[left];
    Point *b = &points[(left + right) / 2];
    Point *c = &points[right];

    if ((compare(*a, *b) and !compare(*a, *c)) or (compare(*a, *c) and !compare(*a, *b))) {
        swap(*a, *b);
    } else if ((compare(*c, *b) and !compare(*c, *a)) or (compare(*c, *a) and !compare(*c, *b))) {
        swap(*c, *b);
    }

    Point x = points[(left + right) / 2];

    //quick sort!
    while (i <= j) {
        while (compare(points[i], x)) {
            i++;
        }
        while (compare(x, points[j])) {
            j--;
        }
        if (i <= j) {
            swap(points[i], points[j]);
            i++;
            j--;
        }
    }

    if (i < right) {
        sort_points_by_angle(i, right);
    }
    if (left < j) {
        sort_points_by_angle(left, j);
    }
}

double angle(double x_coordinate, double y_coordinate) {
    //вычисляем угол между OX и вектором (x_coordinate; y_coordinate)
    if (x_coordinate == 0) {
        //чтобы не делить на 0
        return y_coordinate > 0 ? 90 : -90;
    } else if (x_coordinate > 0) {
        //1 и 4 четверти
        return atan(y_coordinate / x_coordinate) * 180.0 / M_PI;
    } else if (y_coordinate > 0) {
        //2 четверть
        return 180 + atan(y_coordinate / x_coordinate) * 180.0 / M_PI;
    } else {
        //3 четверть
        return -180 + atan(y_coordinate / x_coordinate) * 180.0 / M_PI;
    }
}

int main() {
    cin >> n;
    points = new Point[n];
    //input and sort by angle and dist
    for (int i = 0; i < n; i++) {
        points[i].index = i+1;
        cin >> points[i].x;
        cin >> points[i].y;
        if (i == 0) {
            points[i].angle = (double) -1000;
            points[i].distance = 0;
        } else{
            points[i].angle =
                    angle((double) (points[i].x - points[0].x),  (double) (points[i].y - points[0].y) ) ;
            points[i].distance = sqrt(
                    (double) pow(points[i].y - points[0].y, 2) + (double) pow(points[i].x - points[0].x, 2));
        }
    }
    sort_points_by_angle(0, n - 1);
    ////Можно скушать все тыквы:
    cout << n << '\n';
    ////Проверим, нет ли 2 точек, угол между которыми больше 180 (такая пара м.б. только одна).
    int breakpoint = -1;
    for (int i = 1; i < n - 1; i++) {
        if (points[i + 1].angle - points[i].angle >= 180) {
            breakpoint = i;
            break;
        }
    }
    ////Если нет - печатаем по порядку, если да, то печатаем сначала первую точку, а потом в порядке, чтобы разрыв был границей.
    if (breakpoint == -1) {
        for (int i = 0; i < n; i++) {
            cout << points[i].index <<'\n';
        }
    } else {
        cout << points[0].index << '\n';
        for (int i = breakpoint; i > 0; i--) {
            cout << points[i].index << '\n';
        }
        for (int i = n - 1; i > breakpoint; i--) {
            cout << points[i].index << '\n';
        }
    }

}




