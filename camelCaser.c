/**
 * Chatroom Lab
 * CS 241 - Fall 2016
 */
#include "camelCaser.h"
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char **camel_caser(const char *input_str) {
    
    // No NULL's ALLOWED!!!!!
    if(!input_str) return NULL;
    
    //The argument was mean and it decided to be CONSTANT:(( WAHHHHHHHHHHHHH!!
    char* input = strdup(input_str);
    
    /** look into the future **/
    // get number of punction terminating sentences
    int sentence_count = 0;
    char* temp_input = input;
    while(*temp_input){
        *temp_input = tolower(*temp_input);
        if (ispunct(*temp_input)) {
            sentence_count++;
        }
        temp_input = temp_input + 1;
        
    }
    // ----REMOVE ME----
    //printf("SENTENCE COUNT: %d\n", sentence_count);
    /****/
    
    //allocate correct number of slots for pointers to strings e.g. number of sentences
    char** result_arr = (char**)malloc(sizeof(char*) * (sentence_count + 1));
    result_arr[sentence_count] = (char*)NULL;
    
    //One MASSSSSIIIIIVEEEEEE WHILE loop. Yuppers.
    int result_arr_counter = 0;
    temp_input = input;
    while (*temp_input) {
        
        /** look into the future **/
        int reached_end = 0;
        int letter_count = 0;
        char* sentence = temp_input;
        while (!ispunct(*(sentence))) {
            if(!isspace(*sentence)) letter_count ++;
            if (!(*sentence)){
                reached_end = 1;
                break;
            }
            sentence++;
        }
        
        if (reached_end)
            break;
        
        //printf("LETTER COUNT: %d\n", letter_count);
        /******************/
        
        
        
        /****** Allocate proper string *****/
        //buffer to hold string
        char* i_string = (char*)malloc(letter_count + 1);
        i_string[letter_count] = '\0';
        
        //copy contents from original to new buffer camelCased
        int string_count = 0;
        int to_uppercase = 0;
        int seen_alpha = 0;
        sentence = temp_input;
        while (!ispunct(*sentence)){
            
            char c = *sentence;
            
            //not space
            if (!isspace(c)) {
                if (to_uppercase) {
                    c = toupper(c);
                    if (isalpha(c)){
                        to_uppercase = 0;
                    
                    }
                }
                
                seen_alpha = 1;
                i_string[string_count] = c;
                string_count++;
            }
            
            //is space
            if(isspace(c) && seen_alpha){
                to_uppercase = 1;
            }
            sentence++;
            
        }
        
        result_arr[result_arr_counter] = i_string;
        result_arr_counter++;
        
        //we now have letter count
        temp_input = sentence + 1;
        
        
    }
    
    /**************/
    
    
    
    //Fill in the blank: for every malloc there is a _______. YUP YOU GOT IT!
    free(input);
    
    return result_arr;



}
