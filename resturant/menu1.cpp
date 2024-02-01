#include <iostream>
#include <string.h>
#include <cstdlib>
using namespace std;
#include "resturant_operation.h"
#define Reset "\033[0m"
#define Red "\033[31m"
#define Green "\033[32m"
#define Yellow "\033[33m"
#define Blue "\033[34m"


void menu1(information_student_or_orders *&phead) {
    cout << Yellow << "\nThis is Menu\n" << Reset;
    cout << Blue << "----------------------------\n" << Reset;
    cout << "zereshk polo\n";
    cout << "ghorme sabzi\n";
    cout << "kebab\n";
    cout << "tahchin\n";
    cout << "Dizi\n";
    cout << "Bademjan\n";
    cout << "khoresh mast\n";
    cout << "Doogh\n";
    cout << "beh limoo\n";
    cout << Red << "Exit(enter 0):\n" << Reset;
    int n;
    cin >> n;
    if (n == 0) {
        Heil_Hitler(phead);
    }
    cout << "---------------------------------------\n";
}