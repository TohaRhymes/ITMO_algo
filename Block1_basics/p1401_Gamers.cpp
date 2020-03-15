#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

//n - pow of full square (there will be 2^n x 2^n matrix),
int n;
int colour = 1;
vector<vector<int>> matrix;

//n_cur - current pow of square (size = 2^n_cur),
//x_del, y_del - coordinates of deleted cell
//x_cur, y_cur - coordinates of the top-left cell
void game(int n_cur, int y_del, int x_del, int y_cur, int x_cur) {
    int size = pow(2, n_cur);
    if (n_cur < 1)
        return;
    if (n_cur == 1) {
        for (int i = y_cur; i < y_cur + 2; i++) {
            for (int j = x_cur; j < x_cur + 2; j++) {
                if (i != y_del || j != x_del) {
                    int c = colour;
                    matrix[i][j] = colour;
                }
            }
        }
        colour++;
        return;
    } else {
        if (y_del < y_cur + size / 2 && x_del < x_cur + size / 2) {
            game(n_cur - 1, y_del, x_del, y_cur, x_cur);
            //deleted cell is in the top-left quarter
            matrix[y_cur + size / 2][x_cur + size / 2] = colour;
            matrix[y_cur + size / 2 - 1][x_cur + size / 2] = colour;
            matrix[y_cur + size / 2][x_cur + size / 2 - 1] = colour;

            int c = colour;
            colour++;
            game(n_cur - 1, y_cur + size / 2, x_cur + size / 2, y_cur + size / 2, x_cur + size / 2);
            game(n_cur - 1, y_cur + size / 2 - 1, x_cur + size / 2, y_cur, x_cur + size / 2);
            game(n_cur - 1, y_cur + size / 2, x_cur + size / 2 - 1, y_cur + size / 2, x_cur);


        } else if (y_del < y_cur + size / 2 && x_del >= x_cur + size / 2) {
            game(n_cur - 1, y_del, x_del, y_cur, x_cur + size / 2);
            //deleted cell is in the top-right quarter
            matrix[y_cur + size / 2][x_cur + size / 2] = colour;
            matrix[y_cur + size / 2 - 1][x_cur + size / 2 - 1] = colour;
            matrix[y_cur + size / 2][x_cur + size / 2 - 1] = colour;

            int c = colour;
            colour++;
            game(n_cur - 1, y_cur + size / 2, x_cur + size / 2, y_cur + size / 2, x_cur + size / 2);
            game(n_cur - 1, y_cur + size / 2 - 1, x_cur + size / 2 - 1, y_cur, x_cur);
            game(n_cur - 1, y_cur + size / 2, x_cur + size / 2 - 1, y_cur + size / 2, x_cur);

        } else if (y_del >= y_cur + size / 2 && x_del < x_cur + size / 2) {
            game(n_cur - 1, y_del, x_del, y_cur + size / 2, x_cur);
            //deleted cell is in the bottom-left quarter
            matrix[y_cur + size / 2][x_cur + size / 2] = colour;
            matrix[y_cur + size / 2 - 1][x_cur + size / 2] = colour;
            matrix[y_cur + size / 2 - 1][x_cur + size / 2 - 1] = colour;
            colour++;
            game(n_cur - 1, y_cur + size / 2, x_cur + size / 2, y_cur + size / 2, x_cur + size / 2);
            game(n_cur - 1, y_cur + size / 2 - 1, x_cur + size / 2, y_cur, x_cur + size / 2);
            game(n_cur - 1, y_cur + size / 2 - 1, x_cur + size / 2 - 1, y_cur, x_cur);

        } else {
            game(n_cur - 1, y_del, x_del, y_cur + size / 2, x_cur + size / 2);
            //deleted cell is in the buttom-right quarter
            matrix[y_cur + size / 2 - 1][x_cur + size / 2 - 1] = colour;
            matrix[y_cur + size / 2 - 1][x_cur + size / 2] = colour;
            matrix[y_cur + size / 2][x_cur + size / 2 - 1] = colour;
            colour++;
            game(n_cur - 1, y_cur + size / 2 - 1, x_cur + size / 2 - 1, y_cur, x_cur);
            game(n_cur - 1, y_cur + size / 2 - 1, x_cur + size / 2, y_cur, x_cur + size / 2);
            game(n_cur - 1, y_cur + size / 2, x_cur + size / 2 - 1, y_cur + size / 2, x_cur);
        }

        return;

    }

}


int main() {
    // x,y - coordinates of the deleted cell
    int x, y;
    cin >> n >> y >> x;
    int size = pow(2, n);
    matrix.resize(size);
    for (auto &row : matrix) {
        row.resize(size);
    }
    x--;
    y--;
    matrix[y][x] = 0;
    game(n, y, x, 0, 0);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}

