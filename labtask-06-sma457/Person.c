//-----------------------------------------------------------------------------
#include <stdio.h>
#include "Person.h"
//-----------------------------------------------------------------------------
//----Reads an integer and returns TRUE if successful
boolean ReadIntegerString(int *AnInt) {

    String AString;

    if (!ReadString(AString)) {
        return(FALSE);
    } else {
        if (!IsInteger(AString)) {
            return(FALSE);
        } else {
            *AnInt = ToInteger(AString);
            return(TRUE);
        }
    }
}
//-----------------------------------------------------------------------------
//----Prompt user for names and ages, and read
void PersonRead(String WhichPerson,PersonType *ThePerson) {

    printf("Enter the first and last names, and age for the %s person: ",
    WhichPerson);
    ReadString(ThePerson->FirstName);
    ReadString(ThePerson->LastName);
    if (!ReadIntegerString(&(ThePerson->Age))) {
        ThePerson->Age = 0;
    }
}
//-----------------------------------------------------------------------------
//----Write person and age
void PersonWrite(PersonType ThePerson) {

    printf("%s %s %d\n",ThePerson.FirstName,ThePerson.LastName,ThePerson.Age);
}
//-----------------------------------------------------------------------------
boolean PersonGreater(PersonType LargerPerson,PersonType SmallerPerson) {

//----Compare last names
    return(StringGreater(LargerPerson.LastName,SmallerPerson.LastName));
}
//-----------------------------------------------------------------------------
