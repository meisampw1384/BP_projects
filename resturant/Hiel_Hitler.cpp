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


void Heil_Hitler(information_student_or_orders *&phead) {
    cout << Yellow << "  Heil Hitler   " << Reset;
    cout << Yellow << "\n------------------\n" << Reset;
    while (1) {
        int n;
        cout << "for menu Enter" << Green << " 1\n" << Reset;
        cout << "for New order Enter" << Green << " 2\n" << Reset;
        cout << "for Order delivered Enter" << Green << " 3\n" << Reset;
        cout << "for Cancel order Enter" << Green << " 4\n" << Reset;
        cout << "for change order Enter" << Green << " 5\n" << Reset;
        cout << "for Review Enter" << Green << " 6\n" << Reset;
        cout << Red << "for exit of the program Enter " << " 0\n" << Reset;
        cout << "------------------------------------------------\n";
        cout << "Enter the number:";
        cin >> n;
        if (n == 0) {
        writefile(phead);  
        exit(0);
        }
        switch (n) {
        case 1:
            menu1(phead);
            break;
        case 2:
            New_order(phead);
            break;
        case 3:
            order_delivered(phead);
            break;
        case 4:
            cancel_order(phead);
            break;
        case 5:
            change_order(phead);
            break;
        case 6:
            Review(phead);
            break;
        }
    }
}
