#include <iostream>
#include <stdio.h>

#define Minimum_Job_Time 5
#define PROBLEMS_COUNT 16

#define Max_Workers 50
#define Max_Customers 10

#define Mult_Parts 0
#define One_Part 1
#define No_Parts 2

using namespace std;

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