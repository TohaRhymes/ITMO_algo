#include <iostream>

using namespace std;


struct Sign {
    int amount;
    int speed;
};

bool compare(Sign sign1, Sign sign2) {
    return sign1.amount > sign2.amount;
}

//k - amount of types of signs
//signs - signs[i] - amount of signs with limit = i
//n - total amount of signs = sum(a[i])
int k;
Sign *signs;
int n;

void sort_signs_by_amount(int left, int right) {
    int i = left;
    int j = right;

    //chose the median point between first, central and last sign for indexes in [left; right]
    Sign *a = &signs[left];
    Sign *b = &signs[(left + right) / 2];
    Sign *c = &signs[right];

    if ((compare(*a, *b) and !compare(*a, *c)) or (compare(*a, *c) and !compare(*a, *b))) {
        swap(*a, *b);
    } else if ((compare(*c, *b) and !compare(*c, *a)) or (compare(*c, *a) and !compare(*c, *b))) {
        swap(*c, *b);
    }

    Sign x = signs[(left + right) / 2];

    //quick sort!
    while (i <= j) {
        while (compare(signs[i], x)) {
            i++;
        }
        while (compare(x, signs[j])) {
            j--;
        }
        if (i <= j) {
            swap(signs[i], signs[j]);
            i++;
            j--;
        }
    }

    if (i < right) {
        sort_signs_by_amount(i, right);
    }
    if (left < j) {
        sort_signs_by_amount(left, j);
    }
}


int main() {
    cin >> k;
    signs = new Sign[k];

    //Input all signs (remembering their speeds and calculating amount of all signs
    for (int speed = 0; speed < k; speed++) {
        int amount;
        cin >> amount;
        signs[speed].amount = amount;
        signs[speed].speed = speed + 1;
        n += amount;
    }
    //Sort in descending order of amounts
    sort_signs_by_amount(0, k - 1);

    //answer - array of answers
    int *answer = new int[n];
    //pointer on sign
    int sign_pointer = 0;
    //ставим сначала на четные, потом на нечетные места все знаки через один, по порядочку, как только заканчивается одна партия, переходим к следующей.
    for (int i = 0; i < (n + 1) / 2; i++) {
        answer[i * 2] = signs[sign_pointer].speed;
        signs[sign_pointer].amount--;
        if (signs[sign_pointer].amount == 0) {
            sign_pointer++;
        }
    }
    if (sign_pointer != 0) {
        for (int i = 0; i < n / 2; i++) {
            answer[i * 2 + 1] = signs[sign_pointer].speed;
            signs[sign_pointer].amount--;
            if (signs[sign_pointer].amount == 0) {
                if (sign_pointer != k - 1) {
                    sign_pointer++;
                } else {
                    break;
                }
            }
        }
    } else {
        int stop_pointer = sign_pointer;
        sign_pointer = k - 1;
        for (int i = 0; i < n / 2; i++) {
            answer[i * 2 + 1] = signs[sign_pointer].speed;
            signs[sign_pointer].amount--;
            if (signs[sign_pointer].amount == 0) {
                if (sign_pointer != stop_pointer) {
                    sign_pointer--;
                } else {
                    break;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << answer[i] << ' ';
    }
}
