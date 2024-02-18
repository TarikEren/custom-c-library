#ifndef CUSTOM_C_LIBRARY_DYNAMIC_ARRAY_H
#define CUSTOM_C_LIBRARY_DYNAMIC_ARRAY_H

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef enum array_type {
    INT,
    CHAR,
    FLOAT,
}Type;

typedef struct dynamic_array {
    Type type;
    int size;
    void** array;
}dynamic_array;

dynamic_array* init_dynamic_array(Type arr_type);
void free_dynamic_array(dynamic_array* array);
void dynamic_append(dynamic_array* array, void* data);
void dynamic_pop(dynamic_array* array);
void* peek(dynamic_array** array);
int search(dynamic_array** array, void* data);

#endif
