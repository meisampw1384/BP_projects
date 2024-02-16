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
int main() {
    information_student_or_orders* phead=nullptr;
    readfile(phead);
    Heil_Hitler(phead);
    return 0;
}