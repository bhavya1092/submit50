#include <cs50.h>

#include <stdint.h>

#include <stdio.h>

#include <stdlib.h>



typedef uint8_t BYTE;



int

main(void)

{



    // open card.raw file

    FILE *inptr = fopen ("card.raw", "r");

    if (inptr == NULL)

    {

        printf("could not open card.raw file\n");

        return 1;

    }



    // size of a block in FAT file system

    int block_size = 512;



    // buffer store one block

    BYTE buffer[block_size];



    // store image filename

    char image_name[8];



    // recovered jpgs will be named with a number starting from 1

    int number = 1;



    // keep track of when an image is found

    bool image_found = false;



    // pointer to current jpeg file on hard disk

    FILE *outptr = NULL;



    // look for jpgs until EOF is reached

    while (feof(inptr) == false)

    {

        // read 512 btye block into buffer

        fread(buffer, block_size, 1, inptr);



        // check buffer for jpeg signature

        if (buffer[0] == 255 && buffer[1] == 216 && buffer[2] == 255 &&

            (buffer[3] == 224 || buffer[3] == 225))

        {

            // if a previous jpeg was found close file

            if (image_found == true)

            {

                fclose(outptr);

            }



            image_found = true;



            // name new image

            sprintf(image_name, "%.3d.jpg", number);

            number++;



            // create new jpg image file on hard disk

            outptr = fopen (image_name, "w");

            if (outptr == NULL)

            {

                printf("could not create jpeg file\n");

                return 2;

            }



            // write 512 byte block to jpg file on disk

            fwrite(buffer, block_size, 1, outptr);

        }



        // continue writing parts of a jpg to file on disk

        else if (image_found == true)

        {

            fwrite(buffer, block_size, 1, outptr);

        }

    }



    // close card.raw

    fclose(inptr);



    // close last jpg

    fclose(outptr);

    return 0;

}