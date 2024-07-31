/**
 * @brief     H file for the inout file
 * 
 * @author    Originally from Jeremie Dequidt and Laure Gonnord and modified by Julien Forget
 *            New modifications by Némo Cazin
 * @date      2024
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#ifndef _INOUT_H_
  #define _INOUT_H_
#endif

#define MAX_INTENSITY 255
#define HEIGHT 600
#define WIDTH 800
#define PIX_SIZE 3



/**
 * @brief Load a PPM image into a char array
 * 
 * @param file_name Name of the input file
 * @param image Array where to store the pixel intensities
 * @return 1 if loaded, 0 otherwise
 */
int load_image(const char *file_name, unsigned char image[HEIGHT][WIDTH][PIX_SIZE]);



/**
 * @brief Save a PPM image from a char array
 * 
 * @param file_name Name of the output file
 * @param image Array storing the pixel intensities
 * @return 1 if saved, 0 otherwise
 */
int save_image(const char *file_name, unsigned char image[HEIGHT][WIDTH][PIX_SIZE]);