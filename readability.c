#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    //ask for user input
    char *text = get_string("Text: ");
//** letter counter function that prints the Letter-count in the text
//**build a word counter function and print the wordcount in the text
//**build a sentence counter function and print the sentence-count in the text

//Put everything into formula
    float L = (letter_counter / word_counter) * 100.00;
    float S = (sentence_counter / word_counter) * 100.00;
    float index  = (0.0588 * L) - (0.296 * S) - 15.8;
    int rounded_index = round(index);

 //If the index is greater than or equal to 16, then print Grade 16+
    if (rounded_index >= 16)
    {
        printf("Grade 16+\n");
    }

    //If the index is less than 1, print before grade 1
    if (rounded_index < 1)
    {
        printf("Before Grade 1\n");
    }

    //Else print the index given by the coleman-liau index computation above
    else
    {
        printf("Grade %i\n", rounded_index);

    }
}