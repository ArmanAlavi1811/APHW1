#include <iostream>

void empty_buffer(){
    char c;

    while((c=getchar()) != '\n');

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