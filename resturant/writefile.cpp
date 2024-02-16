#include "resturant_operation.h"
#include <iostream>
using namespace std;
void writefile(information_student_or_orders *&phead) {
    FILE* writefile = fopen("resturant.bin", "wb");

    for (information_student_or_orders* temp_phead = phead; temp_phead != nullptr; temp_phead = temp_phead->next_student) {
        
        fwrite(temp_phead, sizeof(*temp_phead) - sizeof(food_ordered*), 1, writefile);
        for (food_ordered* temp_food = temp_phead->foods; temp_food != nullptr; temp_food = temp_food->next_food) {
            fwrite(temp_food, sizeof(food_ordered) - sizeof(food_ordered*), 1, writefile);
        }
    }

    fclose(writefile);
}