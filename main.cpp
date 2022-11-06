//Student: Arman Alavi
//Studnet ID: 40030476

#include "classes.h"

void menu(){
    cout<<"1- hire a new worker"<<endl;
    cout<<"2- Add a customer"<<endl;
    cout<<"3- Show the list of workers"<<endl;
    cout<<"4- Show the list of customers"<<endl;
    cout<<"5- See total earnings"<<endl;
    cout<<"6- Fire a worker"<<endl;
    cout<<"0- Exit"<<endl;
}

int main(){

    char my_name[30];
    cout<<"Enter your name, manager"<<endl;
    get_string(my_name);
    cout<<endl;

    while( (!str_len(my_name)) || (str_len(my_name) > 29) ){
        if (!str_len(my_name)){
            cout<<"Name cannot be empty, try again: ";
            get_string(my_name);
    
        }else if (str_len(my_name) > 29){
            cout<<"Name cannot be more than 29 characters, try again: ";
            get_string(my_name);
        }
    }

    manager Manager(my_name);

    cout<<"Welcome, manager "<<my_name<<endl<<endl;

    while(true){

        menu();

        int menu_input = is_valid_input(0,9);
        
        switch(menu_input){
            case 1:
                Manager.hire();
                break;
            case 2:
                Manager.assign_worker();
                break;
            case 3:
                Manager.show_workers();
                return_to_menu_prompt();
                break;
            case 4:
                Manager.show_customers();
                return_to_menu_prompt();
                break;
            case 5:
                Manager.show_money();
                return_to_menu_prompt();
                break;            
            case 6:
                Manager.fire();
                break;

            case 0:
                cout<<"bye";
                return 0;
        }

    Time_Tracker++;
    Manager.redo_workers();
    Manager.redo_customers();
    }
}