#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *file1, *file2;
    int size = 20;
    char fileName1[size], fileName2[size], choice, ch;

    printf("Do you want to append(A) or overwrite(O)\n");
    choice = getchar();

    printf("Enter source filename and then destination filename:\n");
    scanf("%s %s", fileName1, fileName2);
    printf("Entered files are: %s and %s\n", fileName1, fileName2);

    file1 = fopen(fileName1, "r");

    if (file1 == NULL)
    {
        printf("Can't read file %s\n", fileName1);
        exit(1);
    }

    if (choice == 'A')
    {
        file2 = fopen(fileName2, "a");
        if (file1 == NULL)
        {
            printf("Can't append to file %s\n", fileName1);
            exit(1);
        }

        ch = fgetc(file1);
        while (ch != EOF)
        {
            fputc(ch, file2);
            ch = fgetc(file1);
        }

        printf("Contens of file %s was copied and added to %s\n", fileName1, fileName2);
    }
    else if (choice == 'O')
    {

        file2 = fopen(fileName2, "w");
        if (file1 == NULL)
        {
            printf("Can't append to file %s\n", fileName1);
            exit(1);
        }

        ch = fgetc(file1);
        while (ch != EOF)
        {
            fputc(ch, file2);
            ch = fgetc(file1);
        }

        printf("Contens of file %s has been copied and written over %s\n", fileName1, fileName2);
    }
    else
    {
        printf("Not a valid command. Your valid commands are:\nA for append\nO for overwrite\n");
        exit(1);
    }

    fclose(file1);
    fclose(file2);
    return 0;
}