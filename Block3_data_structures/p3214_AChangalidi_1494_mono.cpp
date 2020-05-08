#include <iostream>
#include <stack>

using namespace std;


int main() {
    int n;
    cin >> n;
    stack<int> balls;
    balls.push(0);
    bool is_cheater = false;
    int prev_max = 0;

    for (int i = 0; i < n; i++) {
        int ball;
        cin >> ball;
        if (ball > prev_max) {
            for (int j = prev_max + 1; j < ball; j++) {
                balls.push(j);
            }
            prev_max = ball;
        } else {
            if (ball == balls.top()) {
                balls.pop();
            } else {
                is_cheater = true;
            }
        }
    }
    cout << (is_cheater ? "Cheater" : "Not a proof");

}