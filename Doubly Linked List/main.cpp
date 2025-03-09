//
//  main.cpp
//  Doubly Linked List
//
//  Created by Fev1L on 09.03.2025.
//

#include <iostream>
#include <cstring>

using namespace std;

struct List {
    char name[30];
    List* next;
    List* prev;
};

List* head = nullptr;

void CreateList() {
    head = nullptr;
}

void add_from_the_head(const char* newname) {
    List* n = new List;
    strncpy(n->name, newname, sizeof(n->name) - 1);
    n->name[sizeof(n->name) - 1] = '\0';

    n->next = head;
    n->prev = nullptr;

    if (head != nullptr) {
        head->prev = n;
    }

    head = n;
}

void add_from_the_tail(const char* newname) {
    List* n = new List;
    strncpy(n->name, newname, sizeof(n->name) - 1);
    n->name[sizeof(n->name) - 1] = '\0';

    n->next = nullptr;

    if (head == nullptr) {
        head = n;
        n->prev = nullptr;
        return;
    }

    List* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = n;
    n->prev = temp;
}

bool add_after(const char* after) {
    char newname[30];
    List* n = head;

    while (n != nullptr) {
        if (strcmp(n->name, after) == 0) {
            cout << after << " Found!" << endl;
            cout << "Enter name you want to add: ";
            cin >> newname;

            List* list = new List;
            strncpy(list->name, newname, sizeof(list->name) - 1);
            list->name[sizeof(list->name) - 1] = '\0';

            list->next = n->next;
            list->prev = n;

            if (n->next != nullptr) {
                n->next->prev = list;
            }

            n->next = list;
            return true;
        }
        n = n->next;
    }
    cout << "Element was not found!" << endl;
    return false;
}

void remove_element(const char* smbdy) {
    if (head == nullptr) {
        cout << "List is empty!!" << endl;
        return;
    }

    List* n = head;

    while (n != nullptr) {
        if (strcmp(n->name, smbdy) == 0) {
            if (n->prev != nullptr) {
                n->prev->next = n->next;
            } else {
                head = n->next;
            }

            if (n->next != nullptr) {
                n->next->prev = n->prev;
            }

            delete n;
            cout << smbdy << " deleted!" << endl;
            return;
        }
        n = n->next;
    }

    cout << "Element was not found!" << endl;
}

void print_all() {
    if (head == nullptr) {
        cout << "List is empty!!" << endl;
        return;
    }

    int counter = 1;
    List* n = head;
    while (n != nullptr) {
        cout << counter << ". " << n->name << endl;
        n = n->next;
        counter++;
    }
}

void search(const char* name) {
    int counter = 1;
    List* n = head;
    bool found = false;

    while (n != nullptr) {
        if (strcmp(n->name, name) == 0) {
            cout << counter << ". " << n->name << endl;
            found = true;
        }
        n = n->next;
        counter++;
    }

    if (!found) {
        cout << "Element was not found!" << endl;
    }
}
void remove_last(){
    if (head == nullptr) {
        cout << "List is empty!!" << endl;
        return;
    }

    List* n = head;

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        cout << "Last element was deleted!" << endl;
        return;
    }

    while (n->next != nullptr) {
        n = n->next;
    }

    n->prev->next = nullptr;

    delete n;
    cout << "Last element was deleted!" << endl;
}
void reverse_list(){
    if (head == nullptr) {
        cout << "List is empty!!" << endl;
        return;
    }

    List* current = head;
    List* temp = nullptr;

    while (current != nullptr) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != nullptr) {
        head = temp->prev;
    }

    cout << "List was successfully deployed!" << endl;
}
void remove_by_letter(char letter){
    if (head == nullptr) {
        cout << "List is empty!!" << endl;
        return;
    }

    List* n = head;

    while (n != nullptr) {
        List* nextNode = n->next;

        if (n->name[0] == letter) {
            if (n == head) {
                head = n->next;
                if (head != nullptr) {
                    head->prev = nullptr;
                }
            } else {
                if (n->prev != nullptr) {
                    n->prev->next = n->next;
                }
                if (n->next != nullptr) {
                    n->next->prev = n->prev;
                }
            }
            delete n;
        }
        n = nextNode;
    }

    cout << "All elements that starts '" << letter << "', deleted!" << endl;
}
void insert_element(const char* smbdy){
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }

    char newname[30];
    List* n = head;

    while (n != nullptr) {
        if (strcmp(n->name, smbdy) == 0) {
            List* nextNode = n->next;
            if (n->prev != nullptr) {
                n->prev->next = n->next;
            } else {
                head = n->next;
            }

            if (n->next != nullptr) {
                n->next->prev = n->prev;
            }

            delete n;

            cout << "Введіть ім'я, що потрібно додати: ";
            cin >> newname;

            List* list = new List;
            strncpy(list->name, newname, sizeof(list->name) - 1);
            list->name[sizeof(list->name) - 1] = '\0';

            list->next = nextNode;
            list->prev = n->prev;

            if (nextNode != nullptr) {
                nextNode->prev = list;
            }

            if (n->prev != nullptr) {
                n->prev->next = list;
            }

            if (n->prev == nullptr) {
                head = list;
            }

            cout << "Element aded!" << endl;
            return;
        }
        n = n->next;
    }

    cout << "Element was not found!" << endl;
}
int main() {
    CreateList();
    
    bool end = false;
    string answear;
    

    add_from_the_head("Alice");
    add_from_the_tail("Bob");
    add_from_the_tail("Charlie");
    add_from_the_head("David");

    print_all();
    do{
        cout<<"Type comand you want to use[stop, search, insert, add, remove, remove_last, reverse_list, remove_by_letter]: "<<endl;
        cin>>answear;
        if(answear == "stop"){
            exit(0);
        }else if(answear == "search"){
            cout << "Who you want to search?: " << endl;
            char ans[30];
            cin>>ans;
            search(ans);
            print_all();
        }else if(answear == "add"){
            cout << "After who you want to add new person?: " << endl;
            char ans[30];
            cin>>ans;
            add_after(ans);
            print_all();
        }else if(answear == "remove"){
            cout << "Who you want do remove?: " << endl;
            char ans[30];
            cin>>ans;
            remove_element(ans);
            print_all();
        }else if(answear == "remove_last"){
            remove_last();
            print_all();
        }else if(answear == "reverse_list"){
            reverse_list();
            print_all();
        }else if(answear == "remove_by_letter"){
            cout << "Enter letter: " << endl;
            char ans;
            cin>>ans;
            remove_by_letter(ans);
            print_all();
        }else if(answear == "insert"){
            cout << "Who you want do insert?: " << endl;
            char ans[30];
            cin>>ans;
            insert_element(ans);
            print_all();
        }else{
            cout<<"Not valid comand!"<<endl;
        }
    }while(end == false);

    return 0;
}
