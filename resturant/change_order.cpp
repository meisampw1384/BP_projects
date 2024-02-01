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
void change_order(information_student_or_orders*& phead) {
    information_student_or_orders* temp = phead;
    cout << "\nWhich order do you want to change?\n";

    while (temp != nullptr) {
        cout << Green << temp->name << '-' << Reset << temp->num_of_order << '\n';
        temp = temp->next_student;
    }
    int x;
    cout << "Enter the number of order:";
    cin >> x;
    temp = phead;
    for (int i = 1; i < x; i++) {
        temp = temp->next_student;
    }
    food_ordered* tempfood = temp->foods;
    if (strcmp(temp->Orderstatus, "delivered") == 0) {
        cout << Red << "The order is delivered!\n" << Reset;
        cout << "---------------------\n";
        Heil_Hitler(phead);
    }
    if (strcmp(temp->Orderstatus, "Cancelled") == 0) {
        cout << Red << "The order is cancelled!\n" << Reset;
        cout << "---------------------\n";
        Heil_Hitler(phead);
    }

    cout << "What do you want to do?\n";
    cout << "Delete dishes" << Green << "(1)\n" << Reset;
    cout << "Replace dishes" << Green << "(2)\n" << Reset;
    cout << "Add dishes" << Green << "(3)\n" << Reset;
    cout << Red << "Exit(0)" << '\n' << '\n' << Reset;
    int n;
    cout << "Enter number:";
    cin >> n;
    if (n == 0) {
        Heil_Hitler(phead);
    }
    switch (n) {
    case 1: {
        if (temp->Number_of_food == 1) {
            cout << Red << "You must have at least two dish!\n";
            cout << "--------------------------\n";
            Heil_Hitler(phead);
        }
        cout << "\nwhat dishes do you want to delete?\n";
        int i = 0;
        while (tempfood) {
            cout << Green << i << '-' << Reset << tempfood->food_ordered << '\n';
            tempfood = tempfood->next_food;
            i++;
        }
        int x;
        cout << "Enter number:";
        cin >> x;
        cout<<"---------\n";
        food_ordered *beforetemp=nullptr;
        tempfood=temp->foods;
        if (x == 0) {
        temp->foods = tempfood->next_food;
        delete tempfood;
        temp->Number_of_food-=1;
         } 
        else{
        tempfood = temp->foods;
        for (int i = 0; i < x; i++) {
            beforetemp = tempfood;
            tempfood = tempfood->next_food;
        }
        beforetemp->next_food=tempfood->next_food;
        delete tempfood;
        temp->Number_of_food-=1;
    }
    break;
    }
    case 2: {
        cout << "\nwhat dishes do you want to replace?\n";
        int i1 = 0;

        while (tempfood) {
            cout << Green << i1 << '-' << Reset << tempfood->food_ordered << '\n';
            tempfood = tempfood->next_food;
            i1++;
        }
        int x1;
        cout << "Enter number:";
        cin >> x1;
        tempfood=temp->foods;
        for (int i=0;i<x1;i++){
            tempfood=tempfood->next_food;
        }
        cout << '\n';
        cout << "What food do you want to replace?\n";
        menu();
        int y;
        cout << "Enter number:";
        cin >> y;
        switch (y) {
        case 0:
            strcpy(tempfood->food_ordered, "zereshk polo");
            break;
        case 1:
            strcpy(tempfood->food_ordered, "ghorme sabzi");
            break;
        case 2:
            strcpy(tempfood->food_ordered, "kebab");
            break;
        case 3:
            strcpy(tempfood->food_ordered, "tahchin");
            break;
        case 4:
            strcpy(tempfood->food_ordered, "Dizi");
            break;
        case 5:
                strcpy(tempfood->food_ordered, "Bademjan");
                
                break;
        case 6:
                strcpy(tempfood->food_ordered, "khoresh mast");
              
                break;
        case 7:
                strcpy(tempfood->food_ordered, "Doogh");
              
                break;
        case 8:
                strcpy(tempfood->food_ordered, "beh limoo");

                break;
             
                
        }
        break;
    }
    case 3:{
        cout<<"\nwhat food do you want to add?";
        menu();
        cout<<"\nEnter number:";
        int n;
        cin>>n;
        food_ordered *new_food=new food_ordered;
        new_food->next_food=nullptr;
        switch (n) {
            case 0:
                strcpy(new_food->food_ordered,"zereshk polo");
                break;
            case 1:
                strcpy(new_food->food_ordered,"ghorme sabzi");
                 
                break;
            case 2:
                strcpy(new_food->food_ordered,"kebab"); 
                 
                break;
            case 3:
                strcpy(new_food->food_ordered,"tahchin");
                 
                break; 
            case 4:
                strcpy(new_food->food_ordered,"Dizi");    
                          
                break;
            case 5:
                strcpy(new_food->food_ordered,"Bademjan");
                                
                break;
            case 6:
                strcpy(new_food->food_ordered,"khoresh mast");
                
                break;
            case 7:
                strcpy(new_food->food_ordered,"Doogh");
                 
                break;
            case 8:
                strcpy(new_food->food_ordered,"beh limoo");
                 
                break;
            
                
        }
        tempfood=temp->foods;
        while(tempfood->next_food){
            tempfood=tempfood->next_food;
        }
        tempfood->next_food=new_food;
        temp->Number_of_food+=1;
        break;
    }

    }
   
    }