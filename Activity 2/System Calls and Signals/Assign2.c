#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE * file;
    char loc[100];

    char cha;
    int line,word,chara;
    /* Input path of files to merge to third file */
    printf("Enter source file location: ");
    scanf("%s", loc);
    /* Open the source files in read mode from location loc */
    file = fopen(loc, "r");
    /* Check if the file is opened successfully */
    if (file == NULL)
    {
        printf("\nUnable to open the file.\n");
        printf("Please check if the file exists and you have the right privilege.\n");

        exit(EXIT_FAILURE);
    }
    // Logic to count the characters, words and lines in a file.
    line = word = chara = 0; // Initialise all with 0
    while ((cha = fgetc(file)) != EOF)
    {
        chara++;

        // Check and count the number of new line 
        if (cha == '\0' || cha == '\n')
            line++;

        // Check and count the number of words 
        if (cha == ' ' || cha == '\t' || cha == '\n' || cha == '\0')
            word++;
    }
    // Need to increment words and line for the last word 
    if (chara > 0)
    {
        word++;
        line++;
    }
    // Print the count of characters, lines and words in the file 
    printf("\n");
    printf("Total characters = %d\n", chara);
    printf("Total words      = %d\n", word);
    printf("Total lines      = %d\n", line);
    // Close the file
    fclose(file);
    return 0;
}
