#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "helper.h"

#include "helpers.h"

#define STANDARD_HZ 440.00
#define STANDARD_OCTAVE 4.00

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    int numerator = atoi(&fraction[0]);
    int denominator = atoi(&fraction[2]);
    int eighths = ( 8 / denominator ) * numerator;
    return eighths;
}

// Calculates frequency (in Hz) of a note
int frequency(string note) //example A4
{
    // terminal calculator is bc. Example: echo 'scale=3; 1/4;' | bc

    // TODOs
    /*
        frequency, f, of some note is 2^n/12 x 440 where n is the number of semitones
        from that note to A4 (440hz).

        Implement support for A0 through A8, no other notes. Run notes to check.
        Compare your function's output against your own calculations on paper
        or on a calculator.
    */

    // get the octave as an int (given_octave)
    // set standard octave = 4
    // exponent = abs(given_octave - standard_octave)
    // frequency = pow(2, exponent) * 440;

    int octave_pos = 1;
    bool is_sharp = false;
    bool is_flat = false;

    if (note[1] == '#')
    {
        octave_pos = 2;
        is_sharp = true;
    }

    if (note[1] == 'b')
    {
        octave_pos = 2;
        is_flat = true;
    }

    float given_octave, exponent, frequency;

    given_octave = atof(&note[octave_pos]);
    exponent = fabs(given_octave - STANDARD_OCTAVE);

    if ( given_octave > STANDARD_OCTAVE)
        frequency = STANDARD_HZ * pow(2, exponent);

    if ( given_octave <= STANDARD_OCTAVE)
        frequency = STANDARD_HZ / pow(2, exponent);

    int semitones = 0;
    char given_letter = note[0];
    char white_keys[] = {'C', '#', 'D', '#', 'E', 'F', '#', 'G', '#', 'A', '#', 'B'};
    int a_index = 9;
    if (given_letter != 'B')
    {
        while(white_keys[a_index] != given_letter)
        {
            semitones--;
            a_index--;
        }
    }
    else
    {
        while(white_keys[a_index] != given_letter)
        {
            semitones++;
            a_index++;
        }
    }
    // adjust frequency to correct note letter (no sharps or flats added yet)
    frequency *= pow(2, (float)semitones/12);

    /*
        Add support for # and b but only for A0 through A8 (example A#0 - A#8 and Ab0 - Ab8).

        frequency, f, of some note is 2^n/12 x 440 where n is the number of semitones
        from that note to A4 (440hz).
    */
    // to move a semitone up take frequency and multiply by 2^1/12
    // to move a semitone down take frequency and divide by 2^1/12
    if (is_sharp)
        frequency *= pow(2, (float)1/12);
    if (is_flat)
        frequency /= pow(2, (float)1/12);
    /*
        Add support for B. Then for C. Then beyond.
        This was the final todo but I implemented the code on lines 69-92
    */

    // when this function is called it is held in an int variable f
    // so it is explicitly cast as an int by the caller
    return round(frequency);
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    if(strncmp(s, "", 1) == 0)
        return true;
    else
        return false;
}