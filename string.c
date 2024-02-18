#include "string.h"

int str_length(const char* data) {
    int length = 0;
    char cur = data[0];
    while (cur != '\0') {
        length++;
        cur = data[length];
    }
    return length;
}

int char_to_int(char data) {
    return data - 0x30;
}

string* init_string(char* data) {
    string* new_str = malloc(sizeof(string));
    new_str->data = data;
    new_str->length = str_length(data);
    return new_str;
}

void remove_str(string* str) {
    if (str == NULL) {
        perror("Failed to free str: str cannot be NULL");
        return;
    }
    free(str);
    str = NULL;
}

int move_str(string* old_str, string* new_str) {
    if (old_str == new_str) {
        perror("Failed to move string: Cannot move a string into itself.\n");
        return -1;
    }
    if (old_str == NULL || new_str == NULL) {
        if (old_str == NULL) {
            perror("Failed to move string: old_str cannot be NULL\n");
            return -1;
        }
        else {
            perror("Failed to move string: new_str cannot be NULL\n");
            return -1;
        }
    }
    else {
        new_str->data = old_str->data;
        remove_str(old_str);
        return 0;
    }
}
