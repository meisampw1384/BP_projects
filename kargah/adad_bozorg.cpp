#include <iostream>
#include <string>
#include <string.h>
using namespace std;

void reverse(string &x) {
    for (int i = 0; i < x.length() / 2; i++) {
        swap(x[i], x[x.length() - i - 1]);
    }
}

void sum(char a[], char b[], int len_a, int len_b) {
    int c = 0, i = len_a - 1, j = len_b - 1;
    string result = "";
    while (i >= 0 ||j >= 0|| c > 0) {
        if (i >= 0) {
            c = c + a[i] - '0';
            i--;
        }
        if (j >= 0) {
            c = c + b[j] - '0';
            j--;
        }
        result += char(c % 10 + '0');
        c = c / 10;
    }
    reverse(result);
    cout << result;
}

int main() {
    char a[50];
    char b[50];
    cin >> a;
    cin >> b;
    sum(a, b, strlen(a), strlen(b));
    return 0;
}