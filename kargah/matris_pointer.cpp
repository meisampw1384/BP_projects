#include <iostream>
#include <cstring>
using namespace std;

struct Matrix {
    int **Mat;
    int len;
    int height;
};

void input(int ***array, int len, int height) {
    *array = (int **)malloc(len * sizeof(int*));
    for (int i = 0; i < len; i++) {
        (*array)[i] = (int *)malloc(height * sizeof(int));
        for (int j = 0; j < height; j++) {
            cin >> (*array)[i][j];
        }
    }
}

void freeMatrix(int **array, int len) {
    for (int i = 0; i < len; i++) {
        free(array[i]);
    }
    free(array);
}

void subtract(int **array1, int **array2, int ***result, int len, int height) {
    *result = (int **)malloc(len * sizeof(int*));
    for (int i = 0; i < len; i++) {
        (*result)[i] = (int *)malloc(height * sizeof(int));
        for (int j = 0; j < height; j++) {
            (*result)[i][j] = array1[i][j] - array2[i][j];
        }
    }
}

void addition(int **array1, int **array2, int ***result, int len, int height) {
    *result = (int **)malloc(len * sizeof(int*));
    for (int i = 0; i < len; i++) {
        (*result)[i] = (int *)malloc(height * sizeof(int));
        for (int j = 0; j < height; j++) {
            (*result)[i][j] = array1[i][j] + array2[i][j];
        }
    }
}

int main() {
    struct Matrix Mat[2];

    cin >> Mat[0].len>> Mat[0].height;
    input(&Mat[0].Mat, Mat[0].len, Mat[0].height);

    cin >> Mat[1].len>> Mat[1].height;
    input(&Mat[1].Mat, Mat[1].len, Mat[1].height);

    char amaliat[20];
    int **result;

    cin >> amaliat;

    if (strcmp("addition", amaliat) == 0) {
        addition(Mat[0].Mat, Mat[1].Mat, &result, Mat[0].len, Mat[0].height);
    } else if (strcmp("subtract", amaliat) == 0) {
        subtract(Mat[0].Mat, Mat[1].Mat, &result, Mat[0].len, Mat[0].height);
    }

    for (int i = 0; i < Mat[0].len; i++) {
        for (int j = 0; j < Mat[0].height; j++) {
            cout << result[i][j] << " ";
        }
        cout << '\n';
    }

    freeMatrix(result, Mat[0].len);
    freeMatrix(Mat[0].Mat, Mat[0].len);
    freeMatrix(Mat[1].Mat, Mat[1].len);

    return 0;
}