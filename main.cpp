//Student: Arman Alavi
//Studnet ID: 40030476

#include "Essentials.h"
#include "Jobs & Problems.h"
#include <string>


static int Time_Tracker = 0; /*Time tracker changes everytime the manager finishes (or cancels) a task in the menu and the menu
restarts. After 5 cycles, the workers will have finished their tasks and the customers will pay the fee.*/

class Part{
public:
    string name;
    int price;

    Part(string name = "n", int price = 0):name(name), price(price){}
};

class Problem{
public:

    /*This class is trickiest and also the jankiest part of the code. the price shows the cost of the job that is being done,
    and total cost that plus the cost of parts. There are 3 different types of problem: Those that don't need any part, those
    that only need 1, and those that need multiple. It has 3 constructors based on which type we use.*/
    string name;
    char technician[50];
    int price;
    int type;
    int total_price;
    int needed_parts_count;
    Part needed_part;
    Part needed_parts [5];

    Problem(string name,char technician[] ,int price, int needed_parts_count, Part needed_parts[]):
    name(name), price(price), needed_parts_count(needed_parts_count),total_price(0)
    {
        str_cpy(this->technician, technician);
        for (int i = 0; i < needed_parts_count; i++){
            this->needed_parts[i] = needed_parts[i];
            this->total_price += needed_parts[i].price;
        }
    this->total_price += price;
    type = Mult_Parts;

    }

    Problem(string name,char technician[] ,int price, Part needed_part):
    name(name), price(price),total_price(0){
        str_cpy(this->technician, technician);
        this->needed_part = needed_part;
        this->total_price += price + needed_part.price;
        type = One_Part;
    }

    Problem(string name,char technician[] ,int price):
    name(name), price(price),total_price(0){
        str_cpy(this->technician, technician);
        total_price = price;
        type = No_Parts;
    }

    friend class manager;
};


void menu(){
    cout<<"1- hire a new worker"<<endl;
    cout<<"2- Add a customer"<<endl;
    cout<<"3- Show the list of workers"<<endl;
    cout<<"4- Show the list of customers"<<endl;
    cout<<"5- See total earnings"<<endl;
    cout<<"6- Fire a worker"<<endl;
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

    //A class that describes the customer. It only has a few attributes because the majority of the job is handled by the manager.

    string car;
    string first_name;
    string last_name;
    int cost;
    
public:
    int Time_Tracker_start;
    friend class manager;
};

class worker{

private:

    /*The worker class is a little more complex than the customer. It has a pointer to customer whose car is being 
    fixed by the worker. The availability variable will show if the worker is busy or not. The task will show the worker's skill*/

    char *first_name = (char*)malloc(21 * sizeof(char));
    char *last_name = (char*)malloc(21 * sizeof(char));
    int income;
    
    customer *assigned = (customer *) malloc(sizeof(customer));

public:

    int Time_Tracker_start;
    bool availability;
    char *task = (char*)malloc(51 * sizeof(char));

    friend class manager;
};

class manager{
private:
    /*The manager is the core of this software. It's attributes are not very complex. A list of customers and a list of workers, and
    the total money made in 1 session and also the number of workers and active customers*/

    char *name = (char*)malloc(21 * sizeof(char));
    int money;
    worker workers_list[Max_Workers];
    customer customers_list[Max_Customers];

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

        if(number_of_workers == Max_Workers){
            cout<<"You currently have the maximun number of staff"<<endl;
            return_to_menu_prompt();
            return;
        }

        /*In this method, the manager can hire a worker. First we get the worker's name and skill and then put the worker in the list.
        We also check to see if a worker who has the same name already exists. Choosing the skill is done by choosing a skill from
        the skillset in the header.*/

        int input;
        worker new_worker;
        
        cout<<"enter the worker's first name: "<<endl;
        cin>>new_worker.first_name;

        cout<<"enter the worker's last name: "<<endl;
        cin>>new_worker.last_name;

        for(int i = 0; i < number_of_workers; i++){
            if( !str_compare(new_worker.first_name, workers_list[i].first_name) ){
                if( !str_compare(new_worker.last_name, workers_list[i].last_name )){
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

        cout<<endl<<"Name: "<<workers_list[number_of_workers].first_name<<" "<<workers_list[number_of_workers].last_name<<", Salary: "<<
        workers_list[number_of_workers].income<<"$ ,"<<workers_list[number_of_workers].task<<endl;

        number_of_workers++;
        return_to_menu_prompt();
    }

    /*************************************************************************************************************************************************/

    void show_workers(){

        //Prints the workers
        
        if(!number_of_workers){
            cout<<"Currently you have no employees."<<endl;
            return;
        }

        for (int i = 0; i < number_of_workers; i++){
            cout<<(i + 1)<<"-"<<"Name: "<<workers_list[i].first_name<<" "<<workers_list[i].last_name<<", Salary:"<<workers_list[i].income<<"$ ,"<<
            workers_list[i].task<<", Is Available:";
            if(workers_list[i].availability)
                cout<<"Yes"<<endl;
            else 
                cout<<"No,Working on "<<workers_list[i].assigned->first_name<<" "<<workers_list[i].assigned->last_name<<"'s car."<<endl;
        }
    }

    /*************************************************************************************************************************************************/

    void show_customers(){
        //Prints the customers.
        if(!number_of_customers){
            cout<<"Currently no cars are being repaird."<<endl;
            return;
        }

        for(int i = 0; i < number_of_customers; i++){
            cout<<(i + 1)<<"- "<<"Name: "<<customers_list[i].first_name<<" "<<customers_list[i].last_name<<",Car: "<<
            customers_list[i].car<<", Total Cost: "<<customers_list[i].cost<<"$"<<endl;
        }
    }

    /*************************************************************************************************************************************************/
    
    void assign_worker(){
        /*This is where I spent about 95% my time. I honestly couldn't figure out a better way than to make the manager choose the problem
        from a list. I could've made it so that the manager gets the problem as a string and then makes decisions based on that, but I
        couldn't find a way to make it... sensible. I also couldn't find any other way so I basically created all the parts and the problems
        here.*/
        
        Part Engine("Engine",5500);
        Part Radiator("Radiator", 40);
        Part Battery("Battery", 70);

        Part Door("Door", 900);
        Part Wheel("Wheel", 100);
        Part Lights("Lights", 60);
        Part Windscreen("Windscreen", 100);

        Part Transmission("Transmission", 600);
        Part Brakes("Brakrs",400);

        Part FIS("Fuel Injection System", 450);
        Part Muffler("Muffler", 90);

        Part Motoroil("MotorOil", 6);

        //Problems related to service technician
        Problem Checkup("checkup","Service Technician", 15);
        Problem Change_Oil("Change motor oil", "Service Technician", 15, Motoroil);
        
        //Problems related to motor repairer
        Problem Bad_Engine("Bad Engine", "Motor Repairer", 100);
        Problem Dead_Battery("Dead Battery", "Motor Repairer", 70);
        Problem Destroyed_Engine("Destroyed Enginee", "Motor Repairer", 120, Engine);
        Problem Destroyed_Battery("Destroyed Battery", "Motor Repairer", 80, Battery);

        //Problems related to body repair technician
        Problem Bad_Windscreen("Bad Windscreen", "Body Repair Technician", 50, Windscreen);
        Problem Bad_Headlights("Bad Headlights", "Body Repair Technician", 40, Lights);
        Problem Bad_Wheels("Bad Wheels", "Body Repair Technician", 40, Wheel);
        Part Wreck_Parts[3] = {Windscreen, Lights, Wheel};
        Problem Total_Wreck("Total Wreck", "Body Repair Technician", 100, 3, Wreck_Parts);

        //Problems related to brake and transmission technician
        Problem Bad_TS_Unit("Bad Transmission Unit", "Brake and Transmission Technician", 70,
        Transmission);
        Problem Bad_Brakse("Bad Brakes", "Brake and Transmission Technician", 40, Brakes);
        Part Full_TS_Parts[2] = {Transmission, Brakes};
        Problem Full_TS_Rework("New Transmission Unit", "Brake and Transmission Technician",
        120, 2, Full_TS_Parts);

        //Problems related to tune-up specialist
        Problem Bad_FIS("Bad Fuel Injection System", "Tune-up Specialist", 100, FIS);
        Problem Bad_Muffler("Bad Muffler", "Tune-up Specialist", 90, Muffler);
        Part Tune_Up_Parts[2] = {Muffler, FIS};
        Problem Full_Tune_Up("Full Tune Up", "Tune-up Specialist", 150, 2,Tune_Up_Parts);

        Problem Problems[16] = {Checkup, Change_Oil, Bad_Engine, Destroyed_Engine,
        Dead_Battery, Destroyed_Battery, Bad_Windscreen,Bad_Headlights,Bad_Wheels,
        Total_Wreck, Bad_TS_Unit, Bad_Brakse, Full_TS_Rework, Bad_FIS, Bad_Muffler, Full_Tune_Up};

        if(number_of_customers >= Max_Customers){
            cout<<"You can't accepet any more customers"<<endl;
            return_to_menu_prompt();
            return;
        }

        if(!number_of_workers){
            cout<<"Currently you have no employees."<<endl;
            return_to_menu_prompt();
            return;
        }
        
        customer new_customer;
        
        /*We get the name of the customer and it's car as a string*/
        cout<<"Enter the customer's first name: "<<endl;
        cin>>new_customer.first_name;

        cout<<"Enter the customer's last name: "<<endl;
        cin>>new_customer.last_name;

        cout<<"Enter the customer's car type: "<<endl;
        cin>>new_customer.car;

        cout<<"Choose the problem from the list blow"<<endl;
        /*Here a menu prints all the possible problems. The manager can choose a problem or exit to the main menu.*/

        int input;

        for (int i = 0; i < PROBLEMS_COUNT; i++){
            cout<<(i + 1)<<"- "<<Problems[i].name<<endl;
        }

        cout<<"0 -Exit"<<endl;

        input = is_valid_input(0, PROBLEMS_COUNT) - 1;

        if(input == -1){
            return;
        }

        switch(Problems[input].type){
            /*Based on the problem's type, we print the price of the repair, including the parts' cost.*/
            case Mult_Parts:
                cout<<Problems[input].name<<":  "<<Problems[input].price<<"$"<<endl;
                for (int i = 0; i < Problems[input].needed_parts_count; i++){
                    cout<<Problems[input].needed_parts[i].name<<":  "<<Problems[input].needed_parts[i].price<<"$"<<endl;
                }
                cout<<"Total Price: "<< Problems[input].total_price<<"$"<<endl;
                break;

            case One_Part:
                cout<<Problems[input].name<<":  "<<Problems[input].price<<"$"<<endl;
                cout<<Problems[input].needed_part.name<<":  "<<Problems[input].needed_part.price<<"$"<<endl;
                cout<<"Total Price: "<< Problems[input].total_price<<"$"<<endl;
                break;

            case No_Parts:
                cout<<Problems[input].name<<"  "<<Problems[input].total_price<<"$"<<endl;
                break;
        }

        new_customer.cost = Problems[input].total_price;


        return_to_menu_prompt();

        customers_list[number_of_customers] = new_customer;
        customers_list[number_of_customers].Time_Tracker_start = Time_Tracker;

        show_workers();
        cout<<"0 -Exit"<<endl;

        /*Here we choose a worker for our task. There 2 main conditions
        1-The worker should not be busy.
        2-The worker should have the required skill.
        */
        cout<<"choose a "<<Problems[input].technician<<" to asssign to the task"<<endl;

        int input2 = is_valid_input(0, number_of_workers) - 1;
        
        if(input2 == -1){
            return;
        }           

        while( str_compare(workers_list[input2].task, Problems[input].technician) || !workers_list[input2].availability){
            if(input2 == -1){
                return;
            }
            
            else if( str_compare(workers_list[input2].task, Problems[input].technician) ){
                cout<<"The chosen worker does not have the required skillset, choose another person"<<endl;
                input2 = is_valid_input(0, number_of_workers) - 1;
            }
            else if(!workers_list[input2].availability){
                cout<<"The chose worker is busy, choose another person"<<endl;
                input2 = is_valid_input(0, number_of_workers) - 1;
            }
        }
        

        workers_list[input2].assigned = &customers_list[number_of_customers];
        workers_list[input2].availability = false;
        workers_list[input2].Time_Tracker_start = Time_Tracker;
        number_of_customers++;
        return_to_menu_prompt();

    }

    /*************************************************************************************************************************************************/

    void fire(){

        /*The manager can also fire people. First a list of workers is printed, then the manager chooses a worker to delete. This is done by 
        shifting the workers that are after the fired worker to the left once. The manager can't fire a worker who is busy becasuse it will
        interfere with the fixing of the car*/

        if(!number_of_workers){
            cout<<"Currently you have no employees."<<endl;
            return_to_menu_prompt();
            return;
        }

        int my_input;
        show_workers();
        cout<<"0- Exit"<<endl;
        my_input = is_valid_input(0, number_of_workers) - 1;

        if(my_input == -1){
            return;
        }

        while(!workers_list[my_input].availability){
            cout<<"You can not fire a worker that is currently busy"<<endl;
            my_input = is_valid_input(0, number_of_workers) - 1;
        }

        for(int i = my_input; my_input < number_of_workers; my_input++){
            workers_list[my_input] = workers_list[my_input + 1];
        }

        number_of_workers--;
    }

    /*************************************************************************************************************************************************/

    void redo_workers(){
        /*After each cycle, if a worker's job is finished, they will become available again.*/
        for (int i = 0; i < number_of_workers; i++){
            if(!workers_list[i].availability){
                if( (Time_Tracker - workers_list[i].Time_Tracker_start >= Minimum_Job_Time) ){
                    workers_list[i].availability = true;
                }
            }
        }
    }

    /*************************************************************************************************************************************************/

    void redo_customers(){
        /*After each cycle, if the customer is done, they will transfer the money to manager and then leave. the leaving process is done
        by shifting the customers to the left (similar to firing the workers)*/
        for(int i = 0; i < number_of_customers; i++){
            if( Time_Tracker - customers_list[i].Time_Tracker_start >= Minimum_Job_Time){

                this->money += customers_list[i].cost;

                for(int j = i; j < number_of_customers; j++){
                    customers_list[j] = customers_list[j + 1];
                }

                i--;
                number_of_customers--;
            }
        }
    }

    /*************************************************************************************************************************************************/

    void show_money(){
        cout<<this->money<<"$"<<endl;
    }
};

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