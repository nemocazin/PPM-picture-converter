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

int load(unsigned char image[HEIGHT][WIDTH][PIX_SIZE]);

int save(unsigned char image[HEIGHT][WIDTH][PIX_SIZE]);

void copy(unsigned char image[HEIGHT][WIDTH][PIX_SIZE]);

void blur(unsigned char image[HEIGHT][WIDTH][PIX_SIZE]);

void monochrom(unsigned char image[HEIGHT][WIDTH][PIX_SIZE]);

void mosaic(unsigned char image[HEIGHT][WIDTH][PIX_SIZE]);