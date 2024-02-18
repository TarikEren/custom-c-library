#include "dynamic_array.h"

dynamic_array* init_dynamic_array(Type arr_type) {
    dynamic_array* new_array = malloc(sizeof(dynamic_array));
    new_array->size = 0;
    new_array->type = arr_type;
    new_array->array = malloc(sizeof(void*) * new_array->size);
    return new_array;
}

void free_dynamic_array(dynamic_array* array) {
    if (array == NULL) {
        perror("Cannot free NULL\n");
        return;
    }
    free(array->array);
    array->array = NULL;
    free(array);
    array = NULL;
}

void dynamic_append(dynamic_array* array, void* data) {
    if (array == NULL) {
        perror("array cannot be NULL\n");
        return;
    }
    if (array->array == NULL) {
        perror("Cannot append to NULL array\n");
    }
    if (data == NULL) {
        perror("Cannot append NULL\n");
        return;
    }
    array->size += 1;
    void** temp = realloc(array->array, sizeof(void*) * array->size);
    if (temp != NULL) {
        array->array = temp;
        array->array[array->size - 1] = data;
    }
    else {
        perror("Reallocation failed\n");
        return;
    }
}

void dynamic_pop(dynamic_array* array) {
    if (array == NULL) {
        perror("array cannot be NULL\n");
        return;
    }
    if (array->array == NULL) {
        perror("Cannot pop from a NULL array\n");
        return;
    }
    if (array->size == 1) {
        perror("Cannot pop first element\n");
        return;
    }
    array->size -= 1;
    void** temp = realloc(array->array, sizeof(void*) * array->size);
    if (temp != NULL) {
        array->array = temp;
    }
    else {
        perror("Reallocation failed\n");
        return;
    }
}

void* peek(dynamic_array** array) {
    assert(array != NULL);
    assert((*array)->array != NULL);
    assert((*array)->size > 0);
    return (*array)->array[(*array)->size - 1];
}

int search(dynamic_array** array, void* data) {
    if (data == NULL) {
        perror("Cannot search NULL in array\n");
        return -1;
    }
    if (array == NULL) {
        perror("array cannot be NULL\n");
        return -1;
    }
    if ((*array)->array == NULL) {
        perror("Cannot search NULL array\n");
        return -1;
    }
    if ((*array)->size == 0) {
        perror("Cannot search empty array\n");
        return -1;
    }
    void* temp;
    for (int i = 0; i < (*array)->size; i++) {
        temp = (*array)->array[i];
        if (temp == data) {
            return i;
        }
    }
    return -1;
}