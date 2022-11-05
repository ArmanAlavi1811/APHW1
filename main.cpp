#include <iostream>

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

    cout<<"please choose an option: ";

    cin>>my_input;

    while(my_input < start || my_input > end){
        cout<<"The given input was invalid, try again: ";
        cin>>my_input;
    }

    return my_input;
}

class worker{
private:
    char *name = (char*)malloc(21 * sizeof(char));
    int income;
public:
    char *skill;

    //worker(char *name, int income, char *skill){};

    friend class manager;
};

class customer{
private:
    char *name;

public:

    friend class manager;
};

class manager{
private:

    char *name;
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

        worker new_worker;
        cout<<"enter the worker's name: "<<endl;
        cin>>new_worker.name;
        new_worker.income = 1000;
        new_worker.skill = "khar";
        workers_list[number_of_workers] = new_worker;

        number_of_workers++;
    }

    void show_workers(){
        cout<<"number of workers: "<<number_of_workers<<endl;
        for (int i = 0; i < number_of_workers; i++){
            cout<<workers_list[i].name<<" "<<workers_list[i].income<<" "<<workers_list[i].skill<<endl;
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
                break;
            case 2:
                Manager.show_workers();
                break;
            case 0:
                cout<<"bye";
                return 0;
        }
        
    }

}