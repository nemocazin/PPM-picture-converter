#include <stdio.h>
#include <stdlib.h>
#include "inout.h"
#include "print.h"
#include "maths.h"
#include "functions.h"

#ifndef _CONVERT_H_
    #define _CONVERT_H_
#endif

#define WAY_SIZE 200

void rgb_to_hsv(unsigned char* red, unsigned char* green, unsigned char* blue);

void hsv_to_rgb(float* hue, float* saturation_100, float* value_100);