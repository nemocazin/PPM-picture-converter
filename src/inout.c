/**
 * @brief     H file for the inout file
 * 
 * @author    Originally from Jeremie Dequidt and Laure Gonnord and modified by Julien Forget
 *            New modifications by Némo Cazin
 * @date      2024
 */


#include <dirent.h>
#include <sys/types.h>
#include <string.h>
#include "inout.h"

#define DEBUG false
#define BUF_SIZE 256



/**
 * @brief Load a PPM image into a char array
 * 
 * @param file_name Name of the input file
 * @param image Array where to store the pixel intensities
 * @return 1 if loaded, 0 otherwise
 */
int LoadImage(const char *file_name, unsigned char image[HEIGHT][WIDTH][PIX_SIZE]) {
  FILE *fp;
    unsigned int type;
    int imax, w, h, debug;
    unsigned char buffer[BUF_SIZE];

    /* File opening */
    if ((fp = fopen(file_name, "rb")) == NULL) 
    {
        #ifdef DEBUG
            printf("[load_image] Cannot open file %s\n", file_name);
        #endif
        return NOTLOADED;
    }

    #ifdef DEBUG
        printf("[load_image] File %s opened\n", file_name);
    #endif 

    /* 1- header */
    if (fgets((char *) buffer, BUF_SIZE, fp) == NULL) 
    {
        #ifdef DEBUG
            printf("[load_image] Cannot read file \n");
        #endif
        return NOTLOADED;
    }

    if ((type = buffer[1] - 48) != 6) 
    {
        #ifdef DEBUG
            printf("[load_image] Image type is not P6 (P%d instead)\n", type);
        #endif
        return NOTLOADED;
    }

    /* 2- skipping comments */
    do 
    {
        if (fgets((char *) buffer, BUF_SIZE, fp) == NULL) 
        {
            #ifdef DEBUG
                printf("[load_image] File read error\n");
            #endif
            return NOTLOADED;
        }
    }
    while (buffer[0] == '#');

    /* 3- Sizes */
    if (sscanf((char *) buffer, "%d %d", &w, &h) == 0)
    {
        #ifdef DEBUG
            printf("[load_image] Cannot read image dimensions\n");
        #endif
        return NOTLOADED;
    }

    if (fgets((char *) buffer, BUF_SIZE, fp) == NULL)
    {
        #ifdef DEBUG
            printf("[load_image] Cannot read intensity\n");
        #endif
        return NOTLOADED;
    }

    if (sscanf((char *) buffer, "%d", &imax) == 0) 
    {
        #ifdef DEBUG
            printf("[load_image] Cannot read max intensity\n");
        #endif
        return NOTLOADED;
    }

    if ((w != WIDTH) || (h != HEIGHT) || (imax != MAX_INTENSITY)) 
    {
        #ifdef DEBUG
            printf("[load_image] Image parameters do no match requirements\n");
            printf("w=%d,h=%d,imax=%d\n", w, h, imax);
            return NOTLOADED;
        #endif
    }

    if (image == NULL) 
    {
        return NOTLOADED;
    }

    /* Read pixels */
    if ((debug = fread(image, 1, w * h * PIX_SIZE, fp)) != (w * h * PIX_SIZE)) 
    {
        #ifdef DEBUG
            printf("[load_image] Could not read all pixel intensities (only read %d)\n", debug);
        #endif
        return NOTLOADED;
    }

    /* Everything ok if we get here */
    fclose(fp);
    #ifdef DEBUG
        printf("[load_image] File closed\n");
    #endif
    return LOADED;
}



/**
 * @brief Save a PPM image from a char array
 * 
 * @param file_name Name of the output file
 * @param image Array storing the pixel intensities
 * @return 1 if saved, 0 otherwise
 */
int SaveImage(const char *file_name, unsigned char image[HEIGHT][WIDTH][PIX_SIZE])
{
    FILE *fp;

    /* File opening */
    if ((fp = fopen(file_name, "wb")) == NULL) 
    {
        #ifdef DEBUG
            printf("[save_image] Cannot open file %s\n",file_name);
        #endif
        return NOTSAVED;
    }

    #ifdef DEBUG
        printf("[save_image] File %s opened for writing\n", file_name);
    #endif

    /* Header */
    if (!fprintf(fp, "P6\n# %s\n%d %d\n%d\n", "Converted Picture", WIDTH, HEIGHT, MAX_INTENSITY)) 
    {
        #ifdef DEBUG
            printf
            ("[save_image] Cannot write image parameters\n");
        #endif
        return NOTSAVED;
    }

    #ifdef DEBUG
        printf("[save_image] Header = Image %d x %d pixels, max intensity = %d\n", WIDTH, HEIGHT, MAX_INTENSITY);
    #endif

    /* output in file */
    if (fwrite(image, 1, WIDTH * HEIGHT * PIX_SIZE, fp) != (WIDTH * HEIGHT * PIX_SIZE)) 
    {
        #ifdef DEBUG
            printf("[save_image] Cannot write pixel intensities\n");
        #endif
        return NOTSAVED;
    }

    /* end of function */
    fclose(fp);
    #ifdef DEBUG
        printf("[save_image] File closed\n");
    #endif
    return SAVED;
}