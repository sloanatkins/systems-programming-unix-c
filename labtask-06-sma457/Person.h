#ifndef PERSON_H
#define PERSON_H
//-----------------------------------------------------------------------------
#include "mystrings.h"
#include "boolean.h"
//-----------------------------------------------------------------------------
typedef struct {
    String FirstName;
    String LastName;
    int Age;
} PersonType;
//-----------------------------------------------------------------------------
//----Read all elements with prompt
void PersonRead(String WhichPerson,PersonType *ThePerson);

//----Write all elements
void PersonWrite(PersonType ThePerson);

//----Check if this person is greater
boolean PersonGreater(PersonType LargerPerson,PersonType SmallerPerson);
//-----------------------------------------------------------------------------
#endif
