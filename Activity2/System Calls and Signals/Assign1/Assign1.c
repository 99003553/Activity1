#include <stdio.h> 
#include <stdlib.h> 
  
int main() 
{ 
    FILE *fptr, *fptr1; 
    char filenme[100], d; 
  
    printf("Enter the filename for reading \n"); 
    scanf("%s", filenme); 
    // Open one file for reading 
    fptr = fopen(filenme, "r"); 
    if (fptr == NULL) 
    { 
        printf("Cannot open file %s \n", filenme); 
        exit(0); 
    } 
  
    printf("Enter the filename to open for writing \n"); 
    scanf("%s", filenme); 
  
    // Open another file for writing 
    fptr1 = fopen(filenme, "w"); 
    if (fptr1 == NULL) 
    { 
        printf("Cannot open file %s \n", filenme); 
        exit(0); 
    } 
  
    // Read contents from file 
    d = fgetc(fptr); 
    while (d != EOF) 
    { 
        fputc(d, fptr1); 
        d = fgetc(fptr); 
    } 
  
    printf("\nContents copied to %s", filenme); 
  
    fclose(fptr); 
    fclose(fptr1); 
    return 0; 
}
