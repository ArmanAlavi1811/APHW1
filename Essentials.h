#include <iostream>



void empty_buffer(){
    char c;

    while((c=getchar()) != '\n');

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

void return_to_menu_prompt(){
    // After an action is complete, this function asks the user to enter an input
    //before showing the menu again.
    empty_buffer();
    char *foo;

    printf("\nEnter any input to continue: ");
    scanf("s" ,foo);
    empty_buffer();
}