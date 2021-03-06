#include "mystring.h"

// Function to get the length of string
size_t mystrlen(const char *str)
{
    return strlen(str);
}
// Function to get the copy of a string
char* mystrcpy(char* str, const char* str1)
{
    return strcpy(str,str1);
}
// Function to concatinate two strings
char* mystrcat(char *str, const char *str1)
{
    return strcat(str,str1);
}
// Function to compare two strings
int mystrcmp(const char *str, const char *str1)
{
    return strcmp(str,str1);
}
