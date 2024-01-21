#include <iostream>
#include <string.h>
#include <cstdlib>
using namespace std;

#define Reset "\033[0m"
#define Red "\033[31m"
#define Green "\033[32m"
#define Yellow "\033[33m"
#define Blue "\033[34m"

struct food_ordered {
    char food_ordered[30];
    struct food_ordered* next_food;
};

struct information_student_or_orders {
    char name[100];
    int num_of_students;
    int num_of_order;
    food_ordered* foods;
    char Orderstatus[30];
    int Number_of_food;
    information_student_or_orders* next_student;
};

void Heil_Hitler(information_student_or_orders*& phead);
void writefile(information_student_or_orders*& phead);
void readfile(information_student_or_orders*& phead);
void menu1(information_student_or_orders*& phead);
void menu();
void New_order(information_student_or_orders*& phead);
void order_delivered(information_student_or_orders*& phead);
void cancel_order(information_student_or_orders*& phead);
void change_order(information_student_or_orders*& phead);
void Review(information_student_or_orders*& phead);
