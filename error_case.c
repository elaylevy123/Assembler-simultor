
#include "error_case.h"

/*this function is used to handle memory allocation errors by printing an error message and terminating the program*/

void memAllocFail(void){

    printf("ERROR : You have memory allocation error.\n");
    exit(0);
}
/*this function is used to check the number of arguments passed to the program
and terminate the program with an error message if the number of arguments is less than 2*/

void chkNumArgs (int args){
    if (args < 2){
        printf("ERROR : You need to write at list one file name.\n ");
        exit(0);
    } /* end if */
}
/*this function is used to open a file and check if the opening was successful.
If the opening fails, an error message is printed, and an error flag is set.
Otherwise, a pointer to the FILE structure representing the open file is returned*/

FILE *chkFileOpen(FILE *fd, char *fileToOpen, char *mode, int *error){

    if (!(fd = fopen(fileToOpen, mode))) {

        printf("ERROR : the file %s is not open.\n", fileToOpen);
        *error = 1;
        return NULL;
    } /* end if */
    return fd;
}
/* this function is used to handle errors related to invalid label names
in the assembly code by printing an error message and setting an error flag. */

void illLblName(int *error, int line){

    printf("Error in line : %d\n", line);
    printf("The label name is the name of a register or directive or instruction command\n");
    printf("or the label has characters other than A-Z or a-z or 0-9 \n\n");
    *error = 1;
}
/* this function is used to handle errors related to lines that are too long in the assembly code 
by printing an error message and setting an error flag. */

void chkLineLen(int *error, int line){

    printf("Error in line : %d\n", line);
    printf("The line length is longer than 81 characters.\n\n");
    *error = 1;
}
/* this function is used to handle errors related to label names that are too long in the assembly code 
by printing an error message and setting an error flag. */

void lngLblName(int *error, int line){

    printf("Error in line : %d\n", line);
    printf("The label name is longer than 30 characters.\n\n");
    *error = 1;
}
/* this function is used to handle errors related to invalid macro names in the assembly code
by printing an error message and setting an error flag. */

void illMcrName(int *error, int line){

    printf("Error in line : %d\n", line);
    printf("The macro name is the name of a register or directive or instruction command\n");
    printf("or the macro has characters other than A-Z or a-z or 0-9\n\n");
    *error = 1;
}

/* this function is used to handle errors related to spacing in the assembly code 
by printing an error message and setting an error flag */

void noSpace(int *error, int line){

    printf("Error in line : %d\n", line);
    printf("There is no space or tab after command word, before the parameters.\n\n");
    *error = 1;
}
/* this function is used to handle errors related to missing parameters in the assembly code 
by printing an error message and setting an error flag. */

void noParam(int * error, int line){

    printf("Error in line : %d\n", line);
    printf("You didn't insert parameters after command word.\n\n");
    *error = 1;
}
/* this function is used to handle errors related to spaces in the label statement in the assembly code
by printing an error message and setting an error flag. */

void spaceInLbl(int *error, int line){

    printf("Error in line : %d\n", line);
    printf("There are spaces in the label statement.\n\n");
    *error = 1;
}
/* this function is used to handle errors related to duplicate label names in the assembly code 
by printing an error message and setting an error flag. */

void dblLblName(int *error, int line){

    printf("Error in line : %d\n", line);
    printf("Two different statements about a label with the same label name.\n\n");
    *error = 1;
}

/*  this function is used to handle errors related to extraneous text in the assembly code 
by printing an error message and setting an error flag. */

void extraTxt(int *error, int line){

    printf("Error in line : %d\n", line);
    printf("Extraneous text.\n\n");
    *error = 1;
}
/* this function is used to handle errors related to undefined directive commands in the assembly code 
by printing an error message and setting an error flag. */

void undefDirCmd(int *error, int line){

    printf("Error in line : %d\n", line);
    printf("Undefined directive command.\n\n");
    *error = 1;
}

/* this function is used to handle errors related to undefined instruction commands in the assembly code 
by printing an error message and setting an error flag. */

void undefInsCmd(int *error, int line){

    printf("Error in line : %d\n", line);
    printf("Undefined instruction command.\n\n");
    *error = 1;
}

/* This function is used to handle errors related to invalid comma usage in the assembly code 
by printing an error message and setting an error flag. */

void invalidComma(int *error, int line){

    printf("Error in line : %d\n", line);
    printf("Invalid comma.\n\n");
    *error = 1;
}

/*  This function is used to handle errors related to invalid data parameters in the assembly code 
by printing an error message and setting an error flag.  */

void invalidDataParam(int *error, int line){

    printf("Error in line : %d\n", line);
    printf("Invalid data parameter, Only integers preceded by '-' or '+' or nothing are allowed.\n\n");
    *error = 1;
}

/*  This function is used to handle errors related to invalid string declarations in the assembly code 
by printing an error message and setting an error flag. */

void invalidStr(int *error, int line){

    printf("Error in line : %d\n", line);
    printf("Invalid string, string must to start with \" and finish with \".\n\n");
    *error = 1;
}

/* This function is used to handle errors related to multiple consecutive commas in the assembly code 
by printing an error message and setting an error flag. */

void multipleCommas(int *error, int line){

    printf("Error in line : %d\n", line);
    printf("Multiple consecutive commas.\n\n");
    *error = 1;
}

/* This function is used to handle errors related to a missing comma in the assembly code.
It prints an error message and sets an error flag. */

void missingComma(int *error, int line){

    printf("Error in line : %d\n", line);
    printf("Missing a comma.\n\n");
    *error = 1;
}

/* This function is used to handle errors related to defining an irrelevant label in the assembly code 
by printing an error message and setting an error flag. */

void irrLbl(int *error, int line){

    printf("Error in line : %d\n", line);
    printf("Setting a label before .extern or .entry makes the label irrelevant.\n\n");
    *error = 1;
}

/* This function is used to handle errors related to illegal parameters in the assembly code 
by printing an error message and setting an error flag.*/

void illParam(int *error, int line){

    printf("Error in line : %d\n", line);
    printf("Illegal parameter.\n\n");
    *error = 1;
}

/* This function is used to handle errors related to invalid number parameters in the assembly code 
by printing an error message and setting an error flag.*/

void invalidNumParam(int *error, int line){

    printf("Error in line : %d\n", line);
    printf("Invalid parameter of type number, numbers are defined as follows : start with '#' and \n");
    printf("can include the symbols '-', '+' and any integer number \n\n");
    *error = 1;
}

/* This function is used to handle errors related to invalid register parameters in the assembly code 
by printing an error message and setting an error flag. */

void invalidRegParam(int *error, int line){

    printf("Error in line : %d\n", line);
    printf("Invalid parameter of register type, the registers begin with 'r' and after a number from 0 to 7.\n\n");
    *error = 1;
}

/* This function is used to handle errors related to exceeding the maximum amount of data that can be used to run the program. 
It prints an error message and sets an error flag. */

void exceededDataAmount(int *error){

    printf("ERROR : We have exceeded the maximum amount of data that can be used to run the program.\n\n");
    *error = 1;
}

/* This function is used to handle errors related to missing or invalid label statements in the assembly code 
by printing an error message and setting an error flag. */

void noLblStatement(int *error, int line){

    printf("Error in line : %d\n", line);
    printf("There is no label statement or the name of the label does \n");
    printf("not exist in the symbol table.\n\n");
    *error = 1;
}

/* This function is used to handle errors where a label is defined as external, but it is also used as an entry label.
This is not allowed in the assembly code, and the function prints an error message and sets an error flag. */

void lblCantEnt(int *error, int line){

    printf("Error in line : %d\n", line);
    printf("The label name is defined as external.\n\n");
    *error = 1;
}
