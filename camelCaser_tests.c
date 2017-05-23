/**
 * Chatroom Lab
 * CS 241 - Fall 2016
 */
#include "camelCaser_tests.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 #include <assert.h>

#include "camelCaser.h"


void print_output(char **output){
    printf("Got the following:\n");
    if(output){
        char ** line = output;
        while(*line){
            printf("\"%s\"", *line);
            line++;
            if (*line) puts(",");
        }
    } else{
        printf("NULL POINTER!\n");
    }
    printf("\n--------------------------------\n");
}

void print_input(char * input){
    printf("testing: \n\t'%s'\n\n", input);
}



int size(char** arr){
    if (arr == NULL) {
        return -1;
    }
    
    int count = 0;
    //char** temp_arr = arr;
    while (*arr) {
        count++;
        arr++;
    }
    
    return count;
    
}

/**
 
 
 return: returns 1 if two arrays are identical: return 0 is there 
         is even one tiny tiny tiny difference. YAYAYAYAYAYAYAYA. Im so happy!
 
 **/
int strarrcmp (char** arr1, char** arr2){
    
    if ((arr1 == NULL) ^ (arr2 == NULL)) {
        return 0;
    }
    else if((arr1==NULL) && (arr2==NULL)) return 1;
    
    int l1 = size(arr1);
    int l2 = size(arr2);
    
    if (l1 != l2)
        return 0;
    
    while (*arr1) {

        if (strcmp(*arr1, *arr2) != 0) return 0;
        
        arr1++;
        arr2++;
    }
    
    return 1;
    
}


void arr_free(char** arr){
    
    if (arr == NULL) {
        return;
    }
  
    
    char** temp_arr = arr;
    while (*arr) {
        free(*arr);
        arr++;
    }
    
    free(temp_arr);
}


/*
 * Testing function for various implementations of camelCaser.
 *
 * @param  camelCaser   A pointer to the target camelCaser function.
 * @return              Correctness of the program (0 for wrong, 1 for correct).
 */
int test_camelCaser(char **(*camelCaser)(const char *)) {
    
    char* inputs[] = {
       
         "The Heisenbug is an incredible creature. Facenovel servers get their power from its indeterminism. Code smell can be ignored with INCREDIBLE use of air freshener. God objects are the new religion.",
        "This is awesome, I love 241 cs and furthermore, love computer science as a whole!",
        "",
        "NO",
        "12ONE 2two 4fOur 5FIVE 666six 7Se7ven.",
        "89898Best.u",
        "!j9!",
        "(* b *",
        "wowzers!!n .*9",
        NULL,
        "HELLO! THIS IS aN ALLCAPS!! SHOULD STILL WORK*&^%!",
        ".       .8besr Bet.k",
        "weAreInThisTogether andWeLoveToDoThis.",
         "m a k e o n e c a p i t a l i z e d s e n t e n c e i o r d e r t o m a k e t h i s w o r k.",
        
        //I Added these two and the grade went down
        "\n\nthese\n\nare\nseperate\nwords.\n and\tthis\ris\vcool!",
        "!Aa\n\t \v \r@#$8088Hello World this is a proper sentence%A^&SS*(Bring it toMEANDnot89898)_+}{|:><",
        
    
    };
    

    
    char* answers1[] = { "theHeisenbugIsAnIncredibleCreature","facenovelServersGetTheirPowerFromItsIndeterminism","codeSmellCanBeIgnoredWithIncredibleUseOfAirFreshener","godObjectsAreTheNewReligion", NULL};
    char* answers2[] = { "thisIsAwesome","iLove241CsAndFurthermore","loveComputerScienceAsAWhole",NULL};
    char* answers3[] = {NULL};
    char* answers4[] = {NULL};
    char* answers5[] = { "12one2Two4Four5Five666Six7Se7ven",NULL };
    char* answers6[] = { "89898best",NULL };
    char* answers7[] = { "","j9",NULL };
    char* answers8[] = { "","","b", NULL };
    char* answers9[] = { "wowzers","","n","",NULL};
    char** answers10 = NULL;
    char* answers11[] = { "hello","thisIsAnAllcaps","","shouldStillWork","","","","",NULL};
    char* answers12[] = { "","","8besrBet",NULL};
    char* answers13[] = { "weareinthistogetherAndwelovetodothis",NULL};
    char* answers14[] = { "mAKEONECAPITALIZEDSENTENCEIORDERTOMAKETHISWORK",NULL};
    char* answers15[] = { "theseAreSeperateWords","andThisIsCool",NULL};
     char* answers16[] = { "","aa","","","8088helloWorldThisIsAProperSentence","a","","ss","","bringItTomeandnot89898","","","","","","","","",NULL};
       
    
    
    char** res1 = camelCaser(inputs[0]);
    //print_output(res1);
    int ans1 = strarrcmp(res1, answers1);
    arr_free(res1);
    
    if (!ans1) return 0;
    
    res1 = camelCaser(inputs[1]);
    ans1 = strarrcmp(res1, answers2);
    arr_free(res1);
     
    if (!ans1) return 0;
    
    res1 = camelCaser(inputs[2]);
    ans1 = strarrcmp(res1, answers3);
    arr_free(res1);
     
    if (!ans1) return 0;
    
    res1 = camelCaser(inputs[3]);
    ans1 = strarrcmp(res1, answers4);
    arr_free(res1);
     
    if (!ans1) return 0;
    
    res1 = camelCaser(inputs[4]);
    ans1 = strarrcmp(res1, answers5);
    arr_free(res1);
     
    if (!ans1) return 0;
    
    res1 = camelCaser(inputs[5]);
    ans1 = strarrcmp(res1, answers6);
    arr_free(res1);
     
    if (!ans1) return 0;
    
    res1 = camelCaser(inputs[6]);
    ans1 = strarrcmp(res1, answers7);
    arr_free(res1);
     
    if (!ans1) return 0;
    
    res1 = camelCaser(inputs[7]);
    ans1 = strarrcmp(res1, answers8);
    arr_free(res1);
     
    if (!ans1) return 0;
    
    res1 = camelCaser(inputs[8]);
    ans1 = strarrcmp(res1, answers9);
    arr_free(res1);
     
    if (!ans1) return 0;
    
    res1 = camelCaser(inputs[9]);
    ans1 = strarrcmp(res1, answers10);
    arr_free(res1);
     
    if (!ans1) return 0;
    
    res1 = camelCaser(inputs[10]);
    ans1 = strarrcmp(res1, answers11);
    arr_free(res1);
     
    if (!ans1) return 0;
    
    res1 = camelCaser(inputs[11]);
    ans1 = strarrcmp(res1, answers12);
    arr_free(res1);
     
    if (!ans1) return 0;
    
    res1 = camelCaser(inputs[12]);
    ans1 = strarrcmp(res1, answers13);
    arr_free(res1);
     
    if (!ans1) return 0;
    
    res1 = camelCaser(inputs[13]);
    ans1 = strarrcmp(res1, answers14);
    arr_free(res1);
     
    if (!ans1) return 0;
    
    res1 = camelCaser(inputs[14]);
    ans1 = strarrcmp(res1, answers15);
    arr_free(res1);
     
    if (!ans1) return 0;
    
    res1 = camelCaser(inputs[15]);
    ans1 = strarrcmp(res1, answers16);
    arr_free(res1);
     
    if (!ans1) return 0;
    

    
   
  return 1;
}
