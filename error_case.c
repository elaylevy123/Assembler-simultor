/*
// Maman14 project for assembler to a pre-defined assembly language
// Project Owners: Ofir Shmuel and Yonatan Ben Yosef
// Semester: 2023a
*/

#include "error_case.h"

void memAllocFail(void){

    printf("ERROR : You have memory allocation error.\n");
    exit(0);
}

void chkNumArgs (int args){
    if (args < 2){
        printf("ERROR : You need to write at list one file name.\n ");
        exit(0);
    } /* end if */
}

FILE *chkFileOpen(FILE *fd, char *fileToOpen, char *mode, int *error){

    if (!(fd = fopen(fileToOpen, mode))) {

        printf("ERROR : the file %s is not open.\n", fileToOpen);
        *error = 1;
        return NULL;
    } /* end if */
    return fd;
}

void illLblName(int *error, int line){

    printf("Error in line : %d\n", line);
    printf("The label name is the name of a register or directive or instruction command\n");
    printf("or the label has characters other than A-Z or a-z or 0-9 \n\n");
    *error = 1;
}

void chkLineLen(int *error, int line){

    printf("Error in line : %d\n", line);
    printf("The line length is longer than 81 characters.\n\n");
    *error = 1;
}

void lngLblName(int *error, int line){

    printf("Error in line : %d\n", line);
    printf("The label name is longer than 30 characters.\n\n");
    *error = 1;
}

void illMcrName(int *error, int line){

    printf("Error in line : %d\n", line);
    printf("The macro name is the name of a register or directive or instruction command\n");
    printf("or the macro has characters other than A-Z or a-z or 0-9\n\n");
    *error = 1;
}

void noSpace(int *error, int line){

    printf("Error in line : %d\n", line);
    printf("There is no space or tab after command word, before the parameters.\n\n");
    *error = 1;
}

void noParam(int * error, int line){

    printf("Error in line : %d\n", line);
    printf("You didn't insert parameters after command word.\n\n");
    *error = 1;
}

void spaceInLbl(int *error, int line){

    printf("Error in line : %d\n", line);
    printf("There are spaces in the label statement.\n\n");
    *error = 1;
}

void dblLblName(int *error, int line){

    printf("Error in line : %d\n", line);
    printf("Two different statements about a label with the same label name.\n\n");
    *error = 1;
}

void extraTxt(int *error, int line){

    printf("Error in line : %d\n", line);
    printf("Extraneous text.\n\n");
    *error = 1;
}

void undefDirCmd(int *error, int line){

    printf("Error in line : %d\n", line);
    printf("Undefined directive command.\n\n");
    *error = 1;
}

void undefInsCmd(int *error, int line){

    printf("Error in line : %d\n", line);
    printf("Undefined instruction command.\n\n");
    *error = 1;
}

void invalidComma(int *error, int line){

    printf("Error in line : %d\n", line);
    printf("Invalid comma.\n\n");
    *error = 1;
}

void invalidDataParam(int *error, int line){

    printf("Error in line : %d\n", line);
    printf("Invalid data parameter, Only integers preceded by '-' or '+' or nothing are allowed.\n\n");
    *error = 1;
}

void invalidStr(int *error, int line){

    printf("Error in line : %d\n", line);
    printf("Invalid string, string must to start with \" and finish with \".\n\n");
    *error = 1;
}

void multipleCommas(int *error, int line){

    printf("Error in line : %d\n", line);
    printf("Multiple consecutive commas.\n\n");
    *error = 1;
}

void missingComma(int *error, int line){

    printf("Error in line : %d\n", line);
    printf("Missing a comma.\n\n");
    *error = 1;
}

void irrLbl(int *error, int line){

    printf("Error in line : %d\n", line);
    printf("Setting a label before .extern or .entry makes the label irrelevant.\n\n");
    *error = 1;
}

void illParam(int *error, int line){

    printf("Error in line : %d\n", line);
    printf("Illegal parameter.\n\n");
    *error = 1;
}

void invalidNumParam(int *error, int line){

    printf("Error in line : %d\n", line);
    printf("Invalid parameter of type number, numbers are defined as follows : start with '#' and \n");
    printf("can include the symbols '-', '+' and any integer number \n\n");
    *error = 1;
}

void invalidRegParam(int *error, int line){

    printf("Error in line : %d\n", line);
    printf("Invalid parameter of register type, the registers begin with 'r' and after a number from 0 to 7.\n\n");
    *error = 1;
}

void exceededDataAmount(int *error){

    printf("ERROR : We have exceeded the maximum amount of data that can be used to run the program.\n\n");
    *error = 1;
}

void noLblStatement(int *error, int line){

    printf("Error in line : %d\n", line);
    printf("There is no label statement or the name of the label does \n");
    printf("not exist in the symbol table.\n\n");
    *error = 1;
}

void lblCantEnt(int *error, int line){

    printf("Error in line : %d\n", line);
    printf("The label name is defined as external.\n\n");
    *error = 1;
}
