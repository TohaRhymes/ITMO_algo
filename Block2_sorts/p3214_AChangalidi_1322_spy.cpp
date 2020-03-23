#include <iostream>

using namespace std;

struct Letter {
    char letter;
    int index;
};

bool compare(Letter letter1, Letter letter2) {
    if (letter1.letter != letter2.letter) {
        return letter1.letter < letter2.letter;
    } else {
        return letter1.index < letter2.index;
    }
}

//ind - index of string-answer
//letters - array of Burrows-Wheeler transformed letters
//n - total amount of letters (length of the word) = letters.length()
int ind;
Letter *letters;
int n;

void sort_letters_by_alphabet(int left, int right) {
    int i = left;
    int j = right;

    //chose the median point between first, central and last letter for indexes in [left; right]
    Letter *a = &letters[left];
    Letter *b = &letters[(left + right) / 2];
    Letter *c = &letters[right];

    if ((compare(*a, *b) and !compare(*a, *c)) or (compare(*a, *c) and !compare(*a, *b))) {
        swap(*a, *b);
    } else if ((compare(*c, *b) and !compare(*c, *a)) or (compare(*c, *a) and !compare(*c, *b))) {
        swap(*c, *b);
    }

    Letter x = letters[(left + right) / 2];

    //quick sort!
    while (i <= j) {
        while (compare(letters[i], x)) {
            i++;
        }
        while (compare(x, letters[j])) {
            j--;
        }
        if (i <= j) {
            swap(letters[i], letters[j]);
            i++;
            j--;
        }
    }

    if (i < right) {
        sort_letters_by_alphabet(i, right);
    }
    if (left < j) {
        sort_letters_by_alphabet(left, j);
    }
}


int main() {
    // input al variables and sort array by alphabet (remembering indexes)
    string s;
    cin >> ind >> s;
    ind--;
    n = s.length();
    letters = new Letter[n];
    for (int i = 0; i < n; i++) {
        letters[i].letter = s[i];
        letters[i].index = i;
    }
    sort_letters_by_alphabet(0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << letters[ind].letter;
        ind = letters[ind].index;
    }
}
