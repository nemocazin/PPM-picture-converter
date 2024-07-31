/**
 * @brief     H file for the functions file
 * 
 * @author    CAZIN Némo
 * @date      2024
 */

#include <stdio.h>
#include <stdlib.h>
#include "inout.h"
#include "convert.h"

#ifndef _FUNCTIONS_H_
    #define _FUNCTIONS_H_
#endif

/**
 * @brief Load a picture from a repertory 
 * 
 * @param image The image to load
 * 
 * @return 1 if loaded, 0 otherwise
 */
int Load (unsigned char image[HEIGHT][WIDTH][PIX_SIZE]);



/**
 * @brief Save a picture into a repertory 
 * 
 * @param image The image to save
 * 
 * @return 1 if saved, 0 otherwise
 */
int Save (unsigned char image[HEIGHT][WIDTH][PIX_SIZE]);



/**
 * @brief Copy a picture from a repertory 
 * 
 * @param image The image to copy
 * 
 * @return 1 if copy done, 0 otherwise
 */
int Copy (unsigned char image[HEIGHT][WIDTH][PIX_SIZE]);



/**
 * @brief Blur a picture from a repertory 
 * 
 * @param image The image to 
 * 
 * @return 1 if blur done, 0 otherwise
 */
int Blur (unsigned char image[HEIGHT][WIDTH][PIX_SIZE]);



/**
 * @brief Change the color to monochrom of a picture
 * 
 * @param image The image to make monochrom
 * 
 * @return 1 if monochrom done, 0 otherwise
 */
int Monochrom (unsigned char image[HEIGHT][WIDTH][PIX_SIZE]);



/**
 * @brief Make a mosaic from a picture
 * 
 * @param image The image to make use to make the mosaic
 * 
 * @return 1 if mosaic done, 0 otherwise
 */
int Mosaic (unsigned char image[HEIGHT][WIDTH][PIX_SIZE]);