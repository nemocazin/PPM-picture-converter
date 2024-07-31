/**
 * @brief     H file for the pixel convertion file
 *            These functions are used to replaced the math.h lib 
 * 
 * @author    CAZIN Némo
 * @date      2024
 */

#include <stdio.h>
#include <stdlib.h>
#include "inout.h"
#include "print.h"
#include "maths.h"

#ifndef _CONVERT_H_
    #define _CONVERT_H_
#endif

#define WAY_SIZE 200
#define CONVERTIONDONE      1



/**
 * @brief Convert RGB values of a pixel to HSV
 * 
 * @param red   The red value of the pixel
 * @param green The green value of the pixel
 * @param blue  The blue value of the pixel
 * 
 * @return 1 if convertion's done, 0 otherwise
 */
int RGB_To_HSV (unsigned char* red, unsigned char* green, unsigned char* blue);



/**
 * @brief Convert HSV values of a pixel to RGB
 * 
 * @param hue               The hue of the pixel
 * @param saturation_100    The saturation of the pixel (on a scale from 0 to 100)
 * @param value_100         The value of the pixel (on a scale from 0 to 100)
 * 
 * @return 1 if convertion's done, 0 otherwise
 */
int HSV_To_RGB (float* hue, float* saturation_100, float* value_100);