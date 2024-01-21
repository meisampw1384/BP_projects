#include <iostream>
#include <cstring>

using namespace std;

void shiftleft(char *a, int len, int y) {
    char *result2 = (char *)malloc((len + 1) * sizeof(char));
    y = y % len;
    int c = 0;
    for (int i = 0; i < len; i++) {
        result2[c++] = a[(i + y) % len];
    }
    result2[c] = '\0';
    strcpy(a, result2);
    free(result2);  
}

void shiftright(char *a, int len, int y) {
    char *result1 = (char *)malloc((len + 1) * sizeof(char)); 
    int c = 0;
    y = y % len;
    for (int i = 0; i < len; i++) {
        result1[(y + i) % len] = a[i];
    }
    for (int i = 0; i < len; i++) {
        a[i] = result1[i];
    }
    a[len] = '\0';
    free(result1); 
}

void sumstring(char *a, char sum[], int len_a, int len_sum) {
    char *result3 = (char *)malloc((len_a + len_sum + 1)*sizeof(char));
    int i;
    for (i = 0; i < len_a; i++) {
        result3[i] = a[i];
    }
    for (int j = 0; j < len_sum; j++) {
        result3[i++] = sum[j];
    }
    result3[i] = '\0';
    strcpy(a, result3);
    free(result3); 
}

void multiplies_string(char *a, int y, int len_a) {
    char *result4 = (char *)malloc((y * len_a + 1) * sizeof(char));
    int c = 0;
    for (int i = 1; i <= y; i++) {
        for (int j = 0; j < len_a; j++) {
            result4[c++] = a[j];
        }
    }
    result4[c] = '\0';
    strcpy(a, result4);
    free(result4);  
}

void substract_string(char *a, char substract[], int len_a, int len_substract) {
    bool found = false;
    for (int i = 0; i <= len_a - len_substract; i++) {
        bool match = true;
        for (int j = 0; j < len_substract; j++) {
            if (a[i + j] != substract[j]) {
                match = false;
                break;
            }
        }
        if (match) {
            found = true;
            for (int k = i + len_substract; k <= len_a; k++) {
                a[k - len_substract] = a[k];
            }
            len_a -= len_substract;
            break;
        }
    }
    if (found) {
        a[len_a] = '\0';
    }
}

int main() {
    char *a = (char *)malloc(1024* sizeof(char));
    char result[500][1024];
    int c = 0;
    cin >> a;

    char x;
    cin >> x;
    while (x != 'x') {
        if (x == '*') {
            int y;
            cin >> y;
            multiplies_string(a, y, strlen(a));
            strcpy(result[c++], a);
        } else if (x == '>') {
            int y;
            cin >> y;
            shiftright(a, strlen(a), y);
            strcpy(result[c++], a);
        } else if (x == '<') {
            int m;
            cin >> m;
            shiftleft(a, strlen(a), m);
            strcpy(result[c++], a);
        } else if (x == '+') {
            char sum[1024];
            cin >> sum;
            sumstring(a, sum, strlen(a), strlen(sum));
            strcpy(result[c++], a);
        } else if (x == '-') {
            char substract[1024];
            cin >> substract;
            substract_string(a, substract, strlen(a), strlen(substract));
            strcpy(result[c++], a);
        }

        cin >> x;
    }
    for (int i = 0; i < c; i++) {
        cout << result[i] << endl;
    }

    free(a);
    return 0;
}

