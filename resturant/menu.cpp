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

void menu() {
    cout << Yellow << "\nThis is Menu\n" << Reset;
    cout << Blue << "----------------------------\n" << Reset;
    cout << "zereshk polo" << Green << " (0)" << Reset << "\n";
    cout << "chorme sabzi" << Green << " (1)" << Reset << "\n";
    cout << "kebab" << Green << " (2)" << Reset << "\n";
    cout << "tahchin" << Green << " (3)" << Reset << "\n";
    cout << "Dizi" << Green << " (4)" << Reset << "\n";
    cout << "Bademjan" << Green << " (5)" << Reset << "\n";
    cout << "khoresh mast" << Green << " (6)" << Reset << "\n";
    cout << "Doogh" << Green << " (7)" << Reset << "\n";
    cout << "beh limoo" << Green << " (8)" << Reset << "\n";
    cout << "---------------------------------------\n";
}