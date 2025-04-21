#include <cs50.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // check for one command line argument
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }
    char name[8];
    // open memory card
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("File not found\n");
        return 1;
    }
    uint8_t buffer[512];
    FILE *img = NULL;
    int file_count = 0;
    // read 512 bytes into the buffer
    while (fread(buffer, 1, 512, input) == 512)
    {
        // check for jpeg
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            ;

            // if already writing jpeg close it
            if (img != NULL)
            {
                fclose(img);
            }
            // create a new jpeg file
            sprintf(name, "%03i.jpg", file_count++);
            img = fopen(name, "w");

            // if noimage found print error
            if (img == NULL)
            {
                printf("couldnt create image\n");
                fclose(input);
                return 1;
            }
        }
        // if jpeg open write to it
        if (img != NULL)
        {
            fwrite(buffer, 1, 512, img);
        }
    }
    // close
    if (img != NULL)
    {
        fclose(img);
    }
    fclose(input);
    return 0;
}
