/**
 * @brief     H file for the maths file
 *            These functions are used to replaced the math.h lib 
 * 
 * @author    CAZIN Némo
 * @date      2024
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifndef _MATHS_H_
    #define _MATHS_H_
#endif

float float_modulo(float value, float modulo);

int max_two_int (int x, int y);

int max_three_int (int x, int y, int z);

int min_two_int (int x, int y);

int min_three_int(int x, int y, int z);