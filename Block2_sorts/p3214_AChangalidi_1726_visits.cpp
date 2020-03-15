#include <iostream>

using namespace std;

#define ll long long

//n - amount of people
//x - x - coordinates of people's houses
//y - y - coordinates of people's houses
ll n;
ll *x;
ll *y;


void sort_array(ll left, ll right, bool flag) {
    ll i = left;
    ll j = right;
    ll *array;
    if (flag) {
        array = x;
    } else {
        array = y;
    }


    //chose the median point between first, central and last point for indexes in [left; right]
    if ((array[left] > array[(left + right) / 2] and array[left] <= array[right]) or
        (array[left] <= array[(left + right) / 2] and array[left] > array[right])) {
        swap(array[left], array[(left + right) / 2]);
    } else if ((array[right] > array[(left + right) / 2] and array[right] <= array[left]) or
               (array[right] <= array[(left + right) / 2] and array[right] > array[left])) {
        swap(array[right], array[(left + right) / 2]);
    }

    ll xx = array[(left + right) / 2];


    //quick sort!
    while (i <= j) {
        while (array[i] < xx) {
            i++;
        }
        while (xx < array[j]) {
            j--;
        }
        if (i <= j) {
            swap(array[i], array[j]);
            i++;
            j--;
        }
    }

    if (i < right) {
        sort_array(i, right, flag);
    }
    if (left < j) {
        sort_array(left, j, flag);
    }
}

int main() {
    cin >> n;
    x = new ll[n];
    y = new ll[n];

    //Input all array
    for (ll i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    //flag = 1 => x, flag = 0 => y

    sort_array(0, n - 1, 1);
    sort_array(0, n - 1, 0);

    unsigned long long answer = 0l;

    for (ll i = 1; i < n; i++) {
        answer += (x[i] - x[i - 1]) * i * (n - i) + (y[i] - y[i - 1]) * i * (n - i);
    }

    answer = answer / ((n * (n - 1)) / 2l);
    cout << answer;

    return 0;
}