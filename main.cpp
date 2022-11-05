#include "Essentials.h"
#include "Jobs & Problems.h"

using namespace std;

void menu(){
    cout<<"1- hire a new worker"<<endl;
    cout<<"2- Add a customer"<<endl;
    cout<<"4- Fire a worker"<<endl;
    cout<<"0- Exit"<<endl;
}

int is_valid_input(int start, int end){
    // checks to see if a an input is inside a given interval
    int my_input;

    cout<<"please choose a option: ";

    cin>>my_input;

    while(my_input < start || my_input > end){
        cout<<"The given input was invalid, try again: ";
        cin>>my_input;
    }

    return my_input;
}

class customer{
private:
    char *name = (char*)malloc(21 * sizeof(char));
public:

    friend class manager;
};

class worker{

private:
    char *name = (char*)malloc(21 * sizeof(char));
    int income;
    customer *assigned;

public:
    char *task = (char*)malloc(51 * sizeof(char));

    friend class manager;
};

class manager{
private:

    char *name = (char*)malloc(21 * sizeof(char));
    int money;
    worker workers_list[50];
    customer customers_list[50];

public:

    int number_of_workers;
    int number_of_customers;

    manager(char *name):name(name){
        money = 0;
        number_of_workers = 0;
        number_of_customers = 0;
    }

    void hire(){
        
        int input;
        worker new_worker;
        
        cout<<"enter the worker's name: "<<endl;
        cin>>new_worker.name;
        cout<<endl;

        cout<<"Please assign a task"<<endl;
        for (int i = 0; i < 5; i ++){
            cout<<(i + 1)<<"- "<<Job_titles[i]<<" Monthly Salary: "<< Jobs_minimum_wage[i]<<"$"<<endl;
        }

        input = is_valid_input(1, 5);
        input--;

        new_worker.task = Job_titles[input];
        new_worker.income = Jobs_minimum_wage[input];


        workers_list[number_of_workers] = new_worker;
        cout<<workers_list[number_of_workers].name<<" "<<workers_list[number_of_workers].income<<" "<<workers_list[number_of_workers].task<<endl;

        number_of_workers++;
    }

    void show_workers(){
        cout<<"number of workers: "<<number_of_workers<<endl;
        for (int i = 0; i < number_of_workers; i++){
            cout<<workers_list[i].name<<" "<<workers_list[i].income<<" "<<workers_list[i].task<<endl;
        }
    }

};

int main(){

    char my_name[20];
    cout<<"Enter thy name, manager"<<endl;
    cin>>my_name;

    manager Manager(my_name);

    cout<<"Welcome, manager "<<my_name<<endl;
    

    while(true){


        menu();

        int menu_input = is_valid_input(0,4);
        
        switch(menu_input){
            case 1:
                Manager.hire();
                return_to_menu_prompt();
                break;
            case 2:
                Manager.show_workers();
                return_to_menu_prompt();
                break;
            case 0:
                cout<<"bye";
                return 0;
        }
    }
}