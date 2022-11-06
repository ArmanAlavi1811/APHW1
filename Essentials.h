#include <iostream>
#include <stdio.h>

#define Minimum_Job_Time 5
#define PROBLEMS_COUNT 16

void empty_buffer(){
    char c;

    while((c=getchar()) != '\n');

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

    printf("\nEnter any input to continue: ");
    scanf("s" ,foo);
    empty_buffer();
}