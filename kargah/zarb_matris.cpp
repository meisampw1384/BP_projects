#include <iostream>
using namespace std;
#define MAX_SIZE 10

void matrix_input(int mat[][MAX_SIZE], int len) {
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            cin >> *(*(mat +i)+j);
        }
    }
}

void matrix_multiply(int matA[][MAX_SIZE], int matB[][MAX_SIZE], int result[][MAX_SIZE], int len) {
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            result[i][j]=0;
            for (int k = 0; k < len; k++) {
               *(*(result+i)+j)+=(*(*(matA+i)+k)) * (*(*(matB+k)+j));
            }
        }
    }
}

void matrix_print(int mat[][MAX_SIZE], int len) {
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            cout <<*(*(mat+i)+j)<< " ";
        }
        cout << endl;
    }
}

int main() {
    int len;
    cin >> len;
    int a[len][MAX_SIZE];
    int b[len][MAX_SIZE];
    int result[len][MAX_SIZE];

    matrix_input(a, len);
    matrix_input(b, len);
    matrix_multiply(a, b, result, len);
    matrix_print(result, len);

    return 0;
}