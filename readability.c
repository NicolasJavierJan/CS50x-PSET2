#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>

int main(void)
{
    // Ask User for input
    string text = get_string("Text: ");

    // Count the number of characters
    float l = 0;
    float w = 0;
    float s = 0;

    while (text[0] > 0)
    {
        // Count the number of LETTERS
        if (text[0] >= 'a' && text[0] <= 'z')
        {
            l++;
        }
        if (text[0] >= 'A' && text[0] <= 'Z')
        {
            l++;
        }
        // Count the number of WORDS
        if (text[0] == 32)
        {
            w++;
        }
        // Count the number of SENTENCES
        if (text[0] == 46 || text[0] == 33 || text[0] == 63)
        {
            s++;
        }

        text++;
    }
    w++;

    // Coleman-Liau index

    float L = l / w * 100;
    float S = s / w * 100;

    float index = 0.0588 * L - 0.296 * S - 15.8;

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    if (index > 16)
    {
        printf("Grade 16+\n");
    }
    if (index >= 1 && index <= 16)
    {
        printf("Grade %0.0f\n", roundf(index));
    }
}