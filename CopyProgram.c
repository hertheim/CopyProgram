#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main()
{
    FILE *file1, *file2; // Declearing FILE variables becaus we need FILE type to use fopen() function.
    int SIZE = 20; // Global variable so we can easily change it one place instead of multiple. 
    char fileName1[SIZE], fileName2[SIZE], choice, ch; // Defines char variables. Allocates needed memory.

    printf("Do you want to append(A) or overwrite(O)\n");
    choice = getchar(); // Asks the user for an input. Gets the first character from the input line.
    
    if(choice != 'A' && choice != 'O') // Checks if inputted character is not equal to command char 'A' and 'O'.
    {
        printf("Not a valid command.\nYour valid commands are:\nA for append\nO for overwrite\n");
        exit(1); // Terminates the program and returns the value 1. 
    }
    
    printf("Enter source filename and then destination filename:\n"); // Asks the user for spesific file names.
    scanf("%s %s", fileName1, fileName2); // Retrives first and second string variable from input line.
    
    file1 = fopen(fileName1, "r"); // Attempts to open fileName1 for reading. It only works if the file already exists.
    if (file1 == NULL) // Checks if fileName1 is a existing file. If not runs the codeblock under.
    {
        printf("Could not read file <%s>: %s\n", fileName1, strerror(errno)); // Prints name of file and the text representation of the value errno.
        exit(1); // Terminates the program and returns the value 1.
    }

    printf("Entered files are: %s and %s\n", fileName1, fileName2); //Informs user which files where selected.
    
    if (choice == 'A') //Checks if fist character inputted is 'A'.
    { 
        file2 = fopen(fileName2, "a"); // Opens fileName2 for wrtriting and appending. If file does not exist, it will be created.
        if (file2 == NULL) // Checks if an error occurs. If it does and the file has not been created or already exists, it will run the codeblock under.
        {
            printf("Could not open file %s for appending: %s\n", fileName2, strerror(errno)); // Prints name of file and the text representation of the value errno.
            exit(1); // Terminates the program and returns the value 1.
        }

     ch = fgetc(file1); // Sets the value of char ch to the first character in file1.
        while (ch != EOF) // As long as char ch is not "End of file(EOF)" the while loop will execute.
        {
            fputc(ch, file2); // Puts the value of char ch into file2.
            ch = fgetc(file1); // Sets the value of char ch to the next character in file1;
        }

        printf("Contens of file %s was copied and added to %s\n", fileName1, fileName2); // Notifies the user of the action that has happened.

    }else if (choice == 'O')
    {
        file2 = fopen(fileName2, "w");
        if (file2 == NULL) // Checks if an error occurs. If it does and the file has not been created or already exists, it will run the codeblock under.
        {
            printf("Could not open file %s for writing: %s\n", fileName2, strerror(errno));
            exit(1); // Terminates the program and returns the value 1.
        }

        ch = fgetc(file1); // Sets the value of char ch to the first character in file1.
        while (ch != EOF) // As long as char ch is not "End of file(EOF)" the while loop will execute.
        {
            fputc(ch, file2); // Puts the value of char ch into file2.
            ch = fgetc(file1); // Sets the value of char ch to the next character in file1;
        }

        printf("Contens of file %s has been copied and written over %s\n", fileName1, fileName2); // Notifies the user of the action that has happened.
    }
    fclose(file1); // Closes the file.
    fclose(file2); // Closes the file.
    return 0; // Terminates the program and returns the value 0.
}

