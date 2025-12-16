#ifndef MYSTRINGS_H
#define MYSTRINGS_H
//-----------------------------------------------------------------------------
#include "boolean.h"

#define MAX_STRING_SIZE 80
typedef char String[MAX_STRING_SIZE];
//-----------------------------------------------------------------------------
//----Check if a string is an integer
boolean IsInteger(String TheCString);

//----Convert a string to an integer
int ToInteger(String TheCString);

//----Reads a string and returns TRUE if successful
boolean ReadString(String TheCString);

//----Concatenate two strings if not too long
boolean Concatenate(String TheCString,String AnotherString);

//----Checks if first string is lexicographically greater than the second
boolean StringGreater(String TheCString,String AnotherString);

//----Checks if first string is the same as the second
boolean StringEqual(String TheCString,String AnotherString);

//----Checks if first string is lexicographically smaller than the second
boolean StringSmaller(String TheCString,String AnotherString);
//-----------------------------------------------------------------------------
#endif
