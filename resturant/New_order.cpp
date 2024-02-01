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
void New_order(struct information_student_or_orders*& phead) {
    FILE* read_number_of_order;
    read_number_of_order = fopen("shomaresefaresh.bin", "rb");
    int c;
    fread(&c, sizeof(c), 1, read_number_of_order);
    fclose(read_number_of_order);
    information_student_or_orders* New_student = new information_student_or_orders;
    information_student_or_orders* temp = phead;
    New_student->foods = nullptr; 

    cout << Green << "Enter the Data of New student:\n";
    cout << "---------------------------------------\n" << Reset;
    cout << "Enter the name of student: ";
    cin.ignore();
    cin.getline(New_student->name, sizeof(New_student->name));
    cout << "Enter the Number of students: ";
    cin >> New_student->num_of_students;
    for (temp;temp!=nullptr;temp=temp->next_student){
        if (temp->num_of_students==New_student->num_of_students&&strcmp(temp->Orderstatus,"ongoing")==0){
            cout<<Red<<"You cannot place another order, because you already have another order and you can change the previous order!\n"<<Reset;
            Heil_Hitler(phead);
            break;
        }
    }
    temp=phead;
    menu();
    cout << "Enter the number of the food you want (enter -1 to stop): ";

    int i = 0, n;
    food_ordered* temp_food = nullptr; 

    while (true) {
        cin >> n;
        if (n == -1) {
            break;
        }

        food_ordered* new_food = new food_ordered;
        new_food->next_food = nullptr;

        switch (n) {
            case 0:
                strcpy(new_food->food_ordered, "zereshk polo");
                break;
            case 1:
                strcpy(new_food->food_ordered, "ghorme sabzi");
                break;
            case 2:
                strcpy(new_food->food_ordered, "kebab");
                break;
            case 3:
                strcpy(new_food->food_ordered, "tahchin");
                break;
            case 4:
                strcpy(new_food->food_ordered, "Dizi");
                break;
            case 5:
                strcpy(new_food->food_ordered, "Bademjan");
                break;
            case 6:
                strcpy(new_food->food_ordered, "khoresh mast");
                break;
            case 7:
                strcpy(new_food->food_ordered, "Doogh");
                break;
            case 8:
                strcpy(new_food->food_ordered, "beh limoo");
                break;
        }

        if (temp_food == nullptr) {
            New_student->foods = new_food;
            temp_food = New_student->foods;
        } else {
            temp_food->next_food = new_food;
            temp_food = temp_food->next_food;
        }

        i++;
    }

    New_student->Number_of_food = i;
    cout << "-------------------------------\n";

    New_student->num_of_order = c + 1;
    c++;
    
    strcpy(New_student->Orderstatus, "ongoing");
    New_student->next_student = nullptr;

    if (phead == nullptr) {
        phead = New_student;
    } else {
        while (temp->next_student != nullptr) {
            temp = temp->next_student;
        }
        temp->next_student = New_student;
    }
    FILE* writefile;
    writefile = fopen("shomaresefaresh.bin", "wb");
    fwrite(&c, sizeof(c), 1, writefile);
    fclose(writefile);

}