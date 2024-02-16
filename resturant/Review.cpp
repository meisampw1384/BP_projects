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

void Review(information_student_or_orders *&phead) {
    information_student_or_orders *temp = phead;
    cout<<'\n';
    while (temp) {
        cout << Green << temp->num_of_order <<"    "<< temp->num_of_students <<"    "<< temp->name <<"    "<< temp->Orderstatus <<"    ";
        food_ordered *temp_food = temp->foods;
        char name_foods[9][30]={"zereshk polo","ghorme sabzi","kebab","tahchin","Dizi","Bademjan","khoresh mast","Doogh","beh limoo"};
        int numberfood[10]={0};
        while(temp_food){
            for (int i=0;i<9;i++){
                if(strcmp(name_foods[i],temp_food->food_ordered)==0){
                    ++numberfood[i];
                }
            }
            temp_food=temp_food->next_food;
        }
        for (int i=0;i<9;i++){
            if (numberfood[i]!=0){
                cout<<numberfood[i]<<" "<<name_foods[i]<<" -- ";
            }
        }
        cout << '\n';
        temp = temp->next_student;
    }
    cout << Red << "Exit(enter 0):";
    int n;
    cin >> n;
    if (n == 0) {
        Heil_Hitler(phead);
    }
    cout << Yellow << "\n--------------------------------------------------------------------------------------------\n" << Reset;
}