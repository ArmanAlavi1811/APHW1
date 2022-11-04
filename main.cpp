#include <iostream>

using namespace std;

void menu(){
    printf("\n");
    printf("1- Translate Morse to English\n");
    printf("2- Translate English to Morse\n");
    printf("3- Dictionary\n");
    printf("4- How the code works\n");
    printf("5- Toggle non-morse inclusion (defult is off)\n");
    printf("6- Change number of spaces in Corse code\n");
    printf("7- Exit\n");
}

class worker{
private:
    char *name;
    int income;
public:
    char *skill;

    friend class manager;
};

class client{

};

class manager{
private:

    char *name;
    int money;
    worker *workers_list;
    client *clients_list;

public:

    int number_of_workers;
    int number_of_clients;

};

int main(){
    cout<<"Welcome to Morse Code translator by Arman Alavi"<<endl;
    while(true){

    }

}