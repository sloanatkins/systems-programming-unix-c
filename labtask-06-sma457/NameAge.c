//-----------------------------------------------------------------------------
//----Write a program that reads in a list of people's names and ages,
//----and writes them out in alphabetical order by name.
//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include "Person.h"
//-----------------------------------------------------------------------------
int main(void) {

    PersonType Person1,Person2,TempPerson;

//----Prompt user for names and ages, and read
    PersonRead("first",&Person1);
    PersonRead("second",&Person2);

//----Compare last names and swap if out of order
    if (PersonGreater(Person1,Person2)) {
        TempPerson = Person1;
        Person1 = Person2;
        Person2 = TempPerson;
    }

//----Output the names and ages
    printf("In alphabetical order by last name they are:\n");
    PersonWrite(Person1);
    PersonWrite(Person2);

//----End program
    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------
