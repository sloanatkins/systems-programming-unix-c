//-----------------------------------------------------------------------------
//----A decent library of string functions for NameAge programs
//-----------------------------------------------------------------------------
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "mystrings.h"
//-----------------------------------------------------------------------------
//----Check if a string is an integer
boolean IsInteger(String TheCString) {

    boolean NoBadDigits = TRUE;
    int StringIndex,StringLength;

    StringIndex = 0;
    StringLength = strlen(TheCString);
    
    while (NoBadDigits && (StringIndex < StringLength)) {
        if (! isdigit(TheCString[StringIndex])) {
            NoBadDigits = FALSE;
        } else {
            ++StringIndex;
        }
    }
    
    return(NoBadDigits);
}
//-----------------------------------------------------------------------------
//----Convert a string to an integer
int ToInteger(String TheCString) {

    return(atoi(TheCString));
}
//-----------------------------------------------------------------------------
//----Reads a string and returns TRUE if successful
boolean ReadString(String TheCString) {

    return(scanf("%s",TheCString) != EOF);
}
//-----------------------------------------------------------------------------
//----Concatenate two strings if not too long
boolean Concatenate(String TheCString,String AnotherString) {

    if (strlen(TheCString) + strlen(AnotherString) < MAX_STRING_SIZE) {
        strcat(TheCString,AnotherString);
        return(TRUE);
    } else {
        return(FALSE);
    }
}
//-----------------------------------------------------------------------------
//----Checks if first string is lexicographically greater than the second
boolean StringGreater(String TheCString,String ASmallerString) {

    return(strcmp(TheCString,ASmallerString) > 0);
}
//-----------------------------------------------------------------------------
//----Checks if first string is the same as the second
boolean StringEqual(String TheCString,String AnotherString) {

    return(strcmp(TheCString,AnotherString) == 0);
}
//-----------------------------------------------------------------------------
//----Checks if first string is lexicographically smaller than the second
boolean StringSmaller(String TheCString,String ALargerString) {

    return(strcmp(TheCString,ALargerString) < 0);
}
//-----------------------------------------------------------------------------
