
#include <iostream>
#include <windows.h>

using namespace std;

struct student {
    int num_of_student;
    char name[30];
    student* next;
} *node = NULL;

void Addstudent(student *&node) {
    student *temp, *Newstudent;
    temp = node;
    while (temp) {
        if (temp->next) {
            temp = temp->next;
        } else {
            break;
        }
    }
    Newstudent = new student;
    cout << "Enter student name and number: ";
    cin >> Newstudent->name >> Newstudent->num_of_student;
    Newstudent->next = NULL;
    if (node == NULL) {
        node = Newstudent;
    } else {
        temp->next = Newstudent;
    }
}

void Delete_of_list() {
    student *temp;
    if (node == NULL) {
        cout << "The list is not existed";
    } else {
        temp = node;
        node = node->next;
        delete temp;
        cout << "Node is deleted";
    }
}

void createlist(int n) {
    student *new1, *temp;
    for (int i = 1; i <= n; i++) {
        new1 = new student;
        cout << "Enter student name and number: ";
        cin >> new1->name >> new1->num_of_student;
        new1->next = NULL;
        if (node == NULL) {
            node = new1;
        } else {
            temp = node;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = new1;
        }
    }
}

void countlist(student *&node){
student *temp;
temp=node;
int counter=0;
while (temp){
    counter++;
    temp=temp->next;
}
cout<<counter<<'\n';
}

int main() {
    while (true) {
        cout << "Welcome to my program!";
        cout << "\nIf you want to create a list, write 1";
        cout << "\nIf you want to add a student, write 2";
        cout << "\nIf you want to delete a student, write 3";
        cout << "\nIf you want to count list, write 4";
        cout << "\nIf you want to exit, write 0";
        int n;
        cout << "\nWrite the number: ";
        cin >> n;
        switch (n) {
            case 1:
                if (node == NULL) {
                    int node_val;
                    cout << "Enter the Number of nodes: ";
                    cin >> node_val;
                    createlist(node_val);
                } else {
                    cout << "List is already created!";
                }
                break; // Added break statement 

            case 2:
                Addstudent(node);
                break;
            case 3:
                Delete_of_list();
                break;
            case 4:
                countlist(node);
                break;
            case 0: // Added the case for 0
                exit(0);
            default:
                break;
        }

        if (n == 0) {
            exit(0);
        }
    }

    return 0;
}