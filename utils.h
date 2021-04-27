#ifndef __UTILS_H
#define __UTILS_H


#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

struct __Question__
{
    int hashq;              // stores the hash value of the question text
    char * type;            // defaults to MCQ for version 1 (type = "MCQ")
    char * text;            // has the text of the question
    double difficulty;      // stores the difficulty level of the question (max = 1)
    int no_options;         // stores the number of options for the question
    char ** options;        // contains the options in an array of strings
    char * correct_option;  // stores the correct option of the question
};

typedef struct __Question__ Question_B; 

#endif
