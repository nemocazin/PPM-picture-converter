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



/**
 * @brief Modulating a floating-point number 
 *        
 * @param value The value we want to modulate
 * @param modulo The modulator
 * 
 * @return The rest
 */
float float_modulo(float value, float modulo);



/**
 * @brief Get the maximum between 2 numbers
 * 
 * @param x First number
 * @param y Second number
 * 
 * @return The maximum between these 2 numbers
 */
int max_two_int (int x, int y);



/**
 * @brief Get the maximum between 3 numbers
 * 
 * @param x First number
 * @param y Second number
 * @param z Second number
 * 
 * @return The maximum between these 3 numbers
 */
int max_three_int (int x, int y, int z);



/**
 * @brief Get the minimum between 2 numbers
 * 
 * @param x First number
 * @param y Second number
 * 
 * @return The minimum between these 2 numbers
 */
int min_two_int (int x, int y);



/**
 * @brief Get the minimum between 3 numbers
 * 
 * @param x First number
 * @param y Second number
 * @param z Second number
 * 
 * @return The minimum between these 3 numbers
 */
int min_three_int(int x, int y, int z);