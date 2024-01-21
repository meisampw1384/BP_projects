#include <iostream>
#include <cstring>
using namespace std;

struct students {
    int number;
    char *family;
    char *name;
};

void input(char *&array, int len) {
    array = (char *)malloc((len + 1) * sizeof(char));
    cin.ignore(); 
    cin.getline(array, len + 1);
}

void sortname(students std[], int tedad) {
    for (int i = 0; i < tedad; i++) {
        for (int j = i + 1; j < tedad; j++) {
            if (strcmp(std[i].name, std[j].name) > 0) {
                students temp = std[i];
                std[i] = std[j];
                std[j] = temp;
            }
        }
    }
}

void sortnum(students std[], int tedad) {
    for (int i = 0; i < tedad; i++) {
        for (int j = i + 1; j < tedad; j++) {
            if (std[i].number > std[j].number) {
                students temp = std[i];
                std[i] = std[j];
                std[j] = temp;
            }
        }
    }
}

void sortlast(students std[], int tedad) {
    for (int i = 0; i < tedad; i++) {
        for (int j = i + 1; j < tedad; j++) {
            if (strcmp(std[i].family, std[j].family) > 0) {
                students temp = std[i];
                std[i] = std[j];
                std[j] = temp;
            }
        }
    }
}

int main() {
    char amaliat[30];
    int n;
    cin >> n;
    students *std = new students[n];

    for (int i = 0; i < n; i++) {
        int len_name, len_family;
        cin >> len_name;
        input(std[i].name, len_name);
        cin >> len_family;
        input(std[i].family, len_family);
        cin >> std[i].number;
    }
    cin >> amaliat;

    if (strcmp("sort_name", amaliat) == 0) {
        sortname(std, n);
    }
    else if (strcmp("sort_last", amaliat) == 0) {
        sortlast(std, n);
    }
    else if (strcmp("sort_no", amaliat) == 0) {
        sortnum(std, n);
    }

    for (int i = 0; i < n; i++) {
        cout << std[i].name << endl;
        cout << std[i].family << endl;
        cout << std[i].number << endl;
    }

    delete[] std; 

    return 0;
}