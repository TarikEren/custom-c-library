#ifndef CUSTOM_C_LIBRARY_STRING_H
#define CUSTOM_C_LIBRARY_STRING_H

#include <stdio.h>
#include <stdlib.h>

typedef struct string {
    int length;
    char* data;
}string;

int char_to_int(char data);
int str_length(const char* data);
string* init_string(char* data);
void remove_str(string* str);
int move_str(string* old_str, string* new_str);


#endif
