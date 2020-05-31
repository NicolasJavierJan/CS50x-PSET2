#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // Making the user input ONE command argument
    if (argc == 2)
    {
        // Search the command argument for not-numbers
        int n = 0;
        int s = strlen(argv[1]);
        int x = atoi(argv[1]);

        while (n < s)
        {
            if (argv[1][n] >= 48 && argv[1][n] <= 57)
            {
                n++;
            }
            else
            {
                printf("Usage ./caesar key\n");
                exit(1);
            }
        }
        // Ask for plaintext
        string plaintext = get_string("Plaintext: ");
        // Shift by "x" numbers
        int n2 = 0;
        int s2 = strlen(plaintext);

        printf("ciphertext: ");

        while (n2 < s2)
        {
            if (isalpha(plaintext[n2]) == 0)
            {
                printf("%c", plaintext[n2]);
                n2++;
            }
            else if (plaintext[n2] >= 65 && plaintext [n2] <= 90)
            {
                int upper = plaintext[n2] - 65;
                int formula = (upper + x) % 26;
                int upper2 = formula + 65;
                printf("%c", upper2);
                n2++;
            }
            else if (plaintext[n2] >= 97 && plaintext[n2] <= 122)
            {
                int lower = plaintext[n2] - 97;
                int formula2 = (lower + x) % 26;
                int lower2 =  formula2 + 97;
                printf("%c", lower2);
                n2++;
            }
        }
        printf("\n");
    }
    // Error message if there's no input in the command line
    else
    {
        printf("Usage ./caesar key\n");
        exit(1);
    }
}