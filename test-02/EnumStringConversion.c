//-------------------------------------------------------------------------------------------------
//----Convert a string to an animal
AnimalType StringToAnimal(char * AnimalType) {

    if (!strcasecmp(AnimalType,"mammal")) {
        return(mammal);
    }
    if (!strcasecmp(AnimalType,"insect")) {
        return(insect);
    }
    if (!strcasecmp(AnimalType,"bird")) {
        return(bird);
    }
    if (!strcasecmp(AnimalType,"fish")) {
        return(fish);
    }
    return(error);
}
//-------------------------------------------------------------------------------------------------
//----Convert an animal to a string
char* AnimalToString(AnimalType TheType) {

    switch (TheType) {
        case mammal:
            return("mammal");
            break;
        case insect:
            return("insect");
            break;
        case bird:
            return("bird");
            break;
        case fish:
            return("fish");
            break;
        default:
            return("error");
            break;
    }
}
//-------------------------------------------------------------------------------------------------
