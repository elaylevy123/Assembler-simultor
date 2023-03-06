#include "memory_utilities.h"

/* This function creates a new empty macro table by allocating memory */

mcrHead *crtMcrTbl(){

    mcrHead *list = malloc(sizeof(mcrHead));

    if(list == NULL)
        memAllocFail();

    list->head = NULL;
    return list;
}
/* The function used to store some values used throughout the assembly process, 
such as the value of the data counter (DC) and instruction counter (IC), 
as well as other information that is relevant to the assembly process. */

essentials *crtEsn(){

    essentials *asmParam = malloc(sizeof(essentials));

    if(asmParam == NULL)
        memAllocFail();

    asmParam->DC = 0;
    asmParam->IC = 100;

    return asmParam;
}

symHead *crtSymTbl(){

    symHead *list = malloc(sizeof(symHead));

    if(list == NULL) /* Check if memory allocation was successful, and call memAllocFail() if it was not */
        memAllocFail();

    list->head = NULL;
    return list;
}

/* This function creates a new linked list for data nodes by allocating memory for a headData struct and initializing it. */

headData *crtDataTbl(){

    headData *list = malloc(sizeof(headData));

    if(list == NULL)
        memAllocFail();

    list->head = NULL;
    return list;
}

void addMcrTbl(mcrHead *headMcr, char name[MAX_LINE], int posFirstLine, int linesAmount){

    mcrTbl *p = malloc(sizeof(mcrTbl));
    mcrTbl *tmp = headMcr->head;

    if (!p)
        memAllocFail();

    /* save all the parameters of the macro we want to save */
    strcpy(p->mcrName, name) ;
    p->pos_FirstMcrLine = posFirstLine;
    p->numOfLines = linesAmount;
    p->next = NULL;

    if(!(headMcr->head)) /* if the first macro is not install */
        headMcr->head = p;

    else{

        while (tmp->next != NULL) /* we want to insert p to the last macro in the list */
            tmp = tmp->next;

        tmp->next = p;
    } /* end else */
}

void addSymTbl(symHead *sym, char *labelName, char *type, int IC){

    symTbl *p = malloc(sizeof(symTbl));
    symTbl  *tmp ;

    if (!p)
        memAllocFail();

    /* save all the parameters of the Label we want to save */
    strcpy(p->symName, labelName) ;
    strcpy(p->sign, type);
    p->value = IC;
    p->next = NULL;

    if(!(sym->head)) /* if the first label is not install */
        sym->head = p;

    else{

        tmp = sym->head;

        while (tmp->next != NULL) /* we want to insert p to the last label in the list */
            tmp = tmp->next;

        tmp->next = p;
    } /* end else */
}

void addDataLine(headData *headDataTbl, int num, int IC){

    dataTbl *p = malloc(sizeof(dataTbl));
    dataTbl *tmp = headDataTbl->head;

    if(p == NULL)
        memAllocFail();

    /* save the parameter of the data line we want to save */
    p->data =  crtEnc();
    addDataParam(p->data, num);
    p->firstIC = IC;
    p->next = NULL;

    if (!headDataTbl->head) /* if the first data line is not install */
        headDataTbl->head = p;

    else{

        while(tmp->next != NULL) /* we want to insert p to the last data line in the list */
            tmp = tmp->next;

        tmp->next = p;
    } /* end else */
}

/* the function checks whether the "i"-th bit of the "num" value is set to 1 using the bitwise AND operator with the value (1<<i).
If the "i"-th bit is indeed set to 1,
the function sets the corresponding bit of the "param" field of the encoder structure to 1 using the bitwise OR operator
with the value (1<<i). */

void addDataParam(encoder *enc, int num){

    int i;

    for(i = 0; i < 14; i++){

        if(num & (1<< i))
            enc->param |= (1 << i);
    } /* end for loop */
}

void initEncode(encoder *enc){

    enc->param = 0;
}

/* The function then checks whether the memory allocation was successful by testing if the returned pointer "p" is NULL.
If the memory allocation failed, the function calls another function named "memAllocFail" */

encoder *crtEnc(){

    encoder *p = malloc(sizeof(encoder));

    if(!p)
        memAllocFail();

    p->param = 0;

    return p;
}
/*  that checks whether a given string "name" is a valid identifier in the assembly language being implemented.
The function returns 1 if "name" is an invalid identifier and 0 if it is a valid identifier */

int invalidName(char *name){

    int i ;
    /* name of instructors, directives and registers */
    char *directives [MAX_DIRECTIVES] = {".data", ".string", ".entry", ".extern"};
    char *instructions [MAX_INSTRUCTIONS] = {"mov", "cmp", "add", "sub", "lea", "not", "clr", "inc", "dec", "jmp", "bne", "red", "prn", "jsr", "rts", "stop"};
    char *registers [MAX_REGISTERS] = {"r0", "r1", "r2", "r3", "r4", "r5", "r6", "r7"};

    for (i = 0 ; i < MAX_INSTRUCTIONS ; i++){

        if(!strcmp(name, instructions[i]))
            return 1;
    } /* end for loop */

    for (i = 0 ; i < MAX_DIRECTIVES ; i++){

        if(!strcmp(name, directives[i]))
            return 1;
    } /* end for loop */

    for (i = 0 ; i < MAX_REGISTERS; i++){

        if(!strcmp(name, registers[i]))
            return 1;
    } /* end for loop */

    return 0;
}

/*This function frees the memory allocated of the macro table */

void freeDataTbl(headData *list){

    dataTbl *tmp = list->head;

    while(list->head != NULL){

        list->head = list->head->next;
        free(tmp->data);
        free(tmp);
        tmp = list->head;
    } /* end while loop */

    free(list);
}

/* This function frees the memory allocated of the macro table */

void freeMcrTbl(mcrHead *list){

    mcrTbl *tmp = list->head;

    while(list->head != NULL){

        list->head = list->head->next;
        free(tmp);
        tmp = list->head;
    } /* end while loop */

    free(list);
}

/* This function frees the memory allocated of the symbol table */

void freeSymTbl(symHead *list){

    symTbl *tmp = list->head;

    while(list->head != NULL){

        list->head = list->head->next;
        free(tmp);
        tmp = list->head;
    } /* end while loop */

    free(list);
}
