#include "Essentials.h"
#include "Jobs & Problems.h"

using namespace std;
static int cycle = 0;


void menu(){
    cout<<"1- hire a new worker"<<endl;
    cout<<"2- Add a customer"<<endl;
    cout<<"3- Show the list of workers"<<endl;
    cout<<"4- Show the list of customers"<<endl;
    cout<<"5- Fire a worker"<<endl;
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

    char *fname = (char*)malloc(21 * sizeof(char));
    char *lname = (char*)malloc(21 * sizeof(char));
    

public:
    int cycle_start;
    friend class manager;
};

class worker{

private:

    char *fname = (char*)malloc(21 * sizeof(char));
    char *lname = (char*)malloc(21 * sizeof(char));
    int income;
    
    customer *assigned;

public:

    int cycle_start;
    bool availability;
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

    /*************************************************************************************************************************************************/

    void hire(){

        if(number_of_workers == 50){
            cout<<"You currently have the maximun number of staff"<<endl;
            return_to_menu_prompt();
            return;
        }
        
        int input;
        worker new_worker;
        
        cout<<"enter the worker's first name: "<<endl;
        cin>>new_worker.fname;
        cout<<endl;

        cout<<"enter the worker's last name: "<<endl;
        cin>>new_worker.lname;
        cout<<endl;

        for(int i = 0; i < number_of_workers; i++){
            if( !str_compare(new_worker.fname, workers_list[i].fname) ){
                if( !str_compare(new_worker.lname, workers_list[i].lname )){
                    cout<<"Worker already hired"<<endl;
                    return_to_menu_prompt();
                    return;
                }                 
            }
        }

        cout<<"Please assign a task"<<endl;
        for (int i = 0; i < 5; i ++){
            cout<<(i + 1)<<"- "<<Job_titles[i]<<" Monthly Salary: "<< Jobs_minimum_wage[i]<<"$"<<endl;
        }

        input = is_valid_input(1, 5);
        input--;

        new_worker.task = Job_titles[input];
        new_worker.income = Jobs_minimum_wage[input];
        new_worker.availability = true;

        workers_list[number_of_workers] = new_worker;
        cout<<"Name: "<<workers_list[number_of_workers].fname<<" "<<workers_list[number_of_workers].lname<<" Salary: "<<
        workers_list[number_of_workers].income<<" "<<workers_list[number_of_workers].task<<" a:"<<workers_list[number_of_workers].availability<<endl;

        number_of_workers++;
        return_to_menu_prompt();
    }

    /*************************************************************************************************************************************************/

    void show_workers(){
        cout<<"number of workers: "<<number_of_workers<<endl;
        for (int i = 0; i < number_of_workers; i++){
            cout<<(i + 1)<<"-"<<"Name: "<<workers_list[i].fname<<" "<<workers_list[i].lname<<" Salary:"<<workers_list[i].income<<"$ "<<
            workers_list[i].task<<" av:"<<workers_list[i].availability<<endl;
        }
        cout<<endl;
    }

    /*************************************************************************************************************************************************/
    
    int show_available_workers(){
        cout<<"number of workers: "<<number_of_workers<<endl;
        int j = 0; //kink it out
        for (int i = 0; i < number_of_workers; i++){
            if(!workers_list[i].availability){
                continue;
            }
            cout<<(j + 1)<<"-"<<"Name: "<<workers_list[i].fname<<" "<<workers_list[i].lname<<" Salary:"<<workers_list[i].income<<"$ "<<
            workers_list[i].task<<endl;
            j++;
        }
        cout<<endl;
        return j;
    }

    /*************************************************************************************************************************************************/
    
    void assign_worker(){
        

        if(number_of_customers == 50){
            cout<<"You can't accepet any more customers"<<endl;
            return_to_menu_prompt();
            return;
        }

        if(!number_of_workers){
            cout<<"No one works here :("<<endl;
            return_to_menu_prompt();
            return;
        }
        
        customer new_customer;
        
        cout<<"enter the customer's first name: "<<endl;
        cin>>new_customer.fname;
        cout<<endl;

        cout<<"enter the customer's last name: "<<endl;
        cin>>new_customer.lname;
        cout<<endl;

        // cout<<"enter the problemo: "<<endl;
        // cin>>new_customer.problem;
        // cout<<endl;

        customers_list[number_of_customers] = new_customer;
        customers_list[number_of_customers].cycle_start = cycle;

        int input;
        int available_workers = show_available_workers();

        if(!available_workers){
            cout<<"All the workers are busy"<<endl;
            return_to_menu_prompt();
            return;
        }

        cout<<"choose a worker to asssign to the task"<<endl;

        input = is_valid_input(1, available_workers) - 1;

        workers_list[input].assigned = &customers_list[number_of_customers];
        workers_list[input].availability = false;
        workers_list[input].cycle_start = cycle;
        number_of_customers++;
        return_to_menu_prompt();

    }

    /*************************************************************************************************************************************************/

    void fire(){

        if(!number_of_workers){
            cout<<"No one works here :("<<endl;
            return_to_menu_prompt();
            return;
        }

        int my_input;
        show_workers();
        cout<<"0- Exit"<<endl;
        my_input = is_valid_input(0, number_of_workers);

        if(my_input == -1){
            return;
        }

        while(!workers_list[my_input].availability){
            cout<<"No"<<endl;
            my_input = is_valid_input(0, number_of_workers);
        }

        for(int i = my_input; my_input < number_of_workers; my_input++){
            workers_list[my_input - 1] = workers_list[my_input];
        }

        number_of_workers--;
    }

    /*************************************************************************************************************************************************/

    void redo_workers(){
        for (int i = 0; i < number_of_workers; i++){
            if(!workers_list[i].availability){
                if( (cycle - workers_list[i].cycle_start >= Minimum_Job_Time) ){
                    workers_list[i].availability = true;
                }
            }
        }
    }

    /*************************************************************************************************************************************************/

    void redo_customers(){
        for(int i = 0; i < number_of_customers; i++){
            if( cycle - customers_list[i].cycle_start >= Minimum_Job_Time){

                for(int j = i; j < number_of_customers; j++){
                    customers_list[j] = customers_list[j + 1];
                }

                i--;
                number_of_customers--;
            }
        }
    }

    /*************************************************************************************************************************************************/

    void show_customers(){
        cout<<"number of customers: "<<number_of_customers<<endl;
        for(int i = 0; i < number_of_customers; i++){
            cout<<customers_list[i].fname<<" "<<customers_list[i].lname<<endl;
        }
    }
};

int main(){

    char my_name[30];
    cout<<"Enter thy name, manager"<<endl;
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
                break;
            case 5:
                Manager.fire();
                break;
            case 9:
                Manager.show_customers();
                break;
                return_to_menu_prompt();
            case 0:
                cout<<"bye";
                return 0;
        }

    cycle++;
    Manager.redo_workers();
    Manager.redo_customers();
    }
}