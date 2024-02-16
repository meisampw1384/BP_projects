#include <iostream>
#include <cstring>
#include <iomanip>
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
} *phead = nullptr;

void Heil_Hitler();
void readfile();
void menu1();
void menu();
void New_order(information_student_or_orders*& phead);
void order_delivered(information_student_or_orders*& phead);
void cancel_order(information_student_or_orders*& phead);
void change_order(information_student_or_orders*& phead);
void Review(information_student_or_orders*& phead);

int main() {
    readfile();
    Heil_Hitler();
    return 0;
}

void readfile() {
    FILE* readfile;
    readfile = fopen("resturant.bin", "rb");

    while (true) {
        information_student_or_orders tempinformation;
        fread(&tempinformation, sizeof(information_student_or_orders), 1, readfile);

        if (feof(readfile)) {
            break;
        }

        tempinformation.next_student = nullptr;

        if (tempinformation.Number_of_food > 0) {
            tempinformation.foods = new food_ordered;
            food_ordered* tempfood = tempinformation.foods;

            fread(tempfood, sizeof(food_ordered), 1, readfile);

            for (int i = 1; i < tempinformation.Number_of_food; ++i) {
                tempfood->next_food = new food_ordered;
                fread(tempfood->next_food, sizeof(food_ordered), 1, readfile);
                tempfood = tempfood->next_food;
            }

            tempfood->next_food = nullptr;
        } else {
            tempinformation.foods = nullptr;
        }

        information_student_or_orders* newStudent = new information_student_or_orders;
        memcpy(newStudent, &tempinformation, sizeof(information_student_or_orders));
        newStudent->next_student = nullptr;

        if (phead == nullptr) {
            phead = newStudent;
        } else {
            information_student_or_orders* temp = phead;
            while (temp->next_student != nullptr) {
                temp = temp->next_student;
            }
            temp->next_student = newStudent;
        }
    }

    fclose(readfile);
}



void Heil_Hitler() {
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
            FILE* writefile;
            writefile = fopen("resturant.bin", "wb");
           information_student_or_orders* tempStudent = phead;
    while (tempStudent != nullptr) {
        fwrite(tempStudent, sizeof(information_student_or_orders) - sizeof(food_ordered*), 1, writefile);

        fwrite(&(tempStudent->Number_of_food), sizeof(int), 1, writefile);

        food_ordered *tempFood = tempStudent->foods;
        while (tempFood != nullptr) {
            fwrite(tempFood, sizeof(food_ordered) - sizeof(food_ordered*), 1, writefile);
            tempFood = tempFood->next_food;
        }

        tempStudent = tempStudent->next_student;
    }

    fclose(writefile);
    exit(0);
}
        }
        switch (n) {
        case 1:
            menu1();
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

void menu1() {
    cout << Yellow << "\nThis is Menu\n" << Reset;
    cout << Blue << "----------------------------\n" << Reset;
    cout << "zereshk polo\n";
    cout << "chorme sabzi\n";
    cout << "kebab\n";
    cout << "tahchin\n";
    cout << "Dizi\n";
    cout << "Bademjan\n";
    cout << "khoresh mast\n";
    cout << "Doogh\n";
    cout << "beh limoo\n";
    cout << Red << "Exit(enter 0):\n" << Reset;
    int n;
    cin >> n;
    if (n == 0) {
        Heil_Hitler();
    }
    cout << "---------------------------------------\n";
}

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

void New_order(information_student_or_orders*& phead) {
    FILE* read_number_of_order;
    read_number_of_order = fopen("D:\\project\\kargah\\shomaresefaresh.bin", "rb");
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

    menu();
    cout << "Enter the number of the food you want (enter -1 to stop): ";

    int i = 0, n;
    food_ordered* current_food = nullptr; 

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
                strcpy(new_food->food_ordered, "chorme sabzi");
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

        if (current_food == nullptr) {
            New_student->foods = new_food;
            current_food = New_student->foods;
        } else {
            current_food->next_food = new_food;
            current_food = new_food;
        }

        i++;
    }

    New_student->Number_of_food = i;
    cout << "-------------------------------\n";

    New_student->num_of_order = c + 1;
    c++;
    FILE* writefile;
    writefile = fopen("D:\\project\\kargah\\shomaresefaresh.bin", "wb");
    fwrite(&c, sizeof(c), 1, writefile);
    fclose(writefile);

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
}

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
    strcpy(temp->Orderstatus, "delivered");
}

void cancel_order(information_student_or_orders*& phead) {
    information_student_or_orders* temp = phead;
    cout << "\nWhich order do you want to cancel?\n";

    while (temp != nullptr) {
        cout << Green << temp->name << '-' << Reset << temp->num_of_order << '\n';
        temp = temp->next_student;
    }
    temp = phead;
    cout << "\nEnter the number of order:";
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        temp = temp->next_student;
    }
    if (strcmp("delivered", temp->Orderstatus) != 0) {
        strcpy(temp->Orderstatus, "Cancelled");
    } else {
        cout << Red << "The order is delivered and you cannot cancel the order!\n" << Reset;
        cout << '\n';
    }
}

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
        Heil_Hitler();
    }
    if (strcmp(temp->Orderstatus, "Cancelled") == 0) {
        cout << Red << "The order is cancelled!\n" << Reset;
        cout << "---------------------\n";
        Heil_Hitler();
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
        Heil_Hitler();
    }
    switch (n) {
    case 1: {
        if (temp->Number_of_food == 1) {
            cout << Red << "You must have at least two dish!\n";
            cout << "--------------------------\n";
            Heil_Hitler();
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
            strcpy(tempfood->food_ordered, "chorme sabzi");
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
                strcpy(new_food->food_ordered,"chorme sabzi");
                 
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
void Review(information_student_or_orders *&phead) {
    information_student_or_orders *temp = phead;
    cout << Yellow << "Num of order" << '\t' << "Num of std" << '\t' << "name of std" << '\t' << "status of order" << '\t' << "ordered food" << '\n';
    cout << "-------------------------------------------------------------------------------------------------------\n" << Reset;
    while (temp) {
        cout << Green << temp->num_of_order << '\t' << temp->num_of_students << '\t' << temp->name << '\t' << temp->Orderstatus << '\t';
        food_ordered *tempFood = temp->foods;
        while (tempFood) {
            cout << tempFood->food_ordered << "-";
            tempFood = tempFood->next_food;
        }
        cout << '\n';
        temp = temp->next_student;
    }
    cout << Red << "Exit(enter 0):";
    int n;
    cin >> n;
    if (n == 0) {
        Heil_Hitler();
    }
    cout << Yellow << "\n--------------------------------------------------------------------------------------------\n" << Reset;
}