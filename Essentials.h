#include <iostream>
#include <string>

#include <stdio.h>
#include "Jobs & Problems.h"

#define Minimum_Job_Time 5
#define PROBLEMS_COUNT 16

#define Max_Workers 50
#define Max_Customers 10

#define Mult_Parts 0
#define One_Part 1
#define No_Parts 2

using namespace std;

static int Time_Tracker = 0; /*Time tracker changes everytime the manager finishes (or cancels) a task in the menu and the menu
restarts. After 5 cycles, the workers will have finished their tasks and the customers will pay the fee.*/

void empty_buffer(){
    char c;

    while((c=getchar()) != '\n');

}

void str_cpy(char copied_to[], char copied_from[]){
    int counter;
    counter = 0;

    while (copied_from[counter]){
        copied_to[counter] = copied_from[counter];
        counter++;
    }
}

int str_len(char string[]){
    int counter;
    counter = 0;

    while (string[counter]) counter++;
    return counter;
}

void get_string(char string[]){
    // This function reads a string and also converts uppercase letters to lowercase
    int counter;
    char c;
    
    counter = 0;

    while ( (c = getchar()) != '\n'){
        string[counter] = c;
        counter++;
    }

    string[counter] = '\0';
}

int str_compare (char str_1[], char str_2[]){
    int counter;
    counter = 0;

    while (str_1[counter] && str_1[counter] == str_2[counter]) counter++;

    return str_1[counter] - str_2[counter];
}

void return_to_menu_prompt(){
    // After an action is complete, this function asks the user to enter an input
    //before showing the menu again.
    empty_buffer();
    char *foo;

    cout<<"Press Enter to continue: ";
    scanf("s" ,foo);
    empty_buffer();
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