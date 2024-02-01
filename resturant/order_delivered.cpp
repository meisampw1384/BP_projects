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


void order_delivered(information_student_or_orders*& phead) {
    information_student_or_orders* temp = phead;
    cout << "\nWhich order do you want to deliver?\n";

    while (temp != nullptr) {
        cout << Green << temp->name << '-' << Reset << temp->num_of_order << '\n';
        temp = temp->next_student;
    }
    temp = phead;
    cout << "\nEnter the number of order:\n";
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        temp = temp->next_student;
    }
    if (strcmp(temp->Orderstatus,"Cancelled")==0){
        cout<<Red<<"The order is Cancelled and you cannot deliver the order!\n"<<Reset<<'\n';
    }
    else{
    strcpy(temp->Orderstatus, "delivered");
    }
}