#include <iostream>
using namespace std;
#include "resturant_operation.h"

void readfile(information_student_or_orders *&phead) {
    FILE* readfile = fopen("resturant.bin", "rb");

    while (true) {
        information_student_or_orders* new_student = new information_student_or_orders;

        if (fread(new_student, sizeof(information_student_or_orders) - sizeof(food_ordered*), 1, readfile) == 0) {
            break;
        }

        new_student->next_student = nullptr;
        new_student->foods = nullptr;

        int count;
        count=new_student->Number_of_food;

        food_ordered* temp_food = nullptr;

        for (int i = 0; i < count; ++i) {
            food_ordered* newfood=new food_ordered;
            fread(newfood,sizeof(food_ordered)-sizeof(food_ordered*),1,readfile);

            newfood->next_food = nullptr;

            if (temp_food == nullptr) {
                new_student->foods = newfood;
                temp_food = new_student->foods;
            } else {
                temp_food->next_food = newfood;
                temp_food = temp_food->next_food;
            }
        }

        if (phead == nullptr) {
            phead = new_student;
        } else {
            information_student_or_orders* temp_student = phead;
            while (temp_student->next_student != nullptr) {
                temp_student = temp_student->next_student;
            }
            temp_student->next_student = new_student;
        }
    }

    fclose(readfile);
}