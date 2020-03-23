#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

#define ll long long
#define M_PI 3.14159265358979323846

struct Point {
    ll x;
    ll y;
    double angle;
    int index;
};

bool compare(Point point1, Point point2){
    return point1.angle < point2.angle;
}

//n - amount of points
int n;
Point* points;

void sort_points_by_angle(int left, int right) {
    int i = left;
    int j = right;


    //chose the median point between first, central and last point for indexes in [left; right]
    Point* a = &points[left];
    Point* b = &points[(left + right) / 2];
    Point* c = &points[right];

    if ((compare(*a, *b) and !compare(*a, *c)) or (compare(*a, *c) and !compare(*a, *b))){
        swap(*a, *b);
    }else if((compare(*c, *b) and !compare(*c, *a)) or (compare(*c, *a) and !compare(*c, *b))){
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

int main() {
    cin >> n;
    points = new Point[n];

    ll min = LLONG_MAX;
    ll i_min = -1;

    //Input all points and search for the most left point (with minimum x)
    for (int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        if (x < min) {
            min = x;
            i_min = i;
        }
        points[i].x = x;
        points[i].y = y;
        points[i].index = i;
    }


    //Calculate the angle between them and the most left point
    for (int i = 0; i<n; i++){
        if (i==i_min){
            points[i].angle = -1e10f;
        } else if(points[i].x == points[i_min].x){
            points[i].angle = points[i].y > points[i_min].y? 90:-90;
        }else{
            points[i].angle = atan((double) (points[i].y - points[i_min].y) / (double)(points[i].x - points[i_min].x)) * 180.0 / M_PI;
        }
    }

    sort_points_by_angle(0, n - 1);

    cout << points[0].index + 1 << " " << points[n / 2].index + 1 << endl;

    return 0;
}