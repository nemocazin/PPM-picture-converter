/**
 * @brief     C file for the maths file
 *            These functions are used to replaced the math.h lib 
 * 
 * @author    CAZIN Némo
 * @date      2024
 */

#include "maths.h"



/**
 * @brief Modulating a floating-point number 
 *        
 * @param value The value we want to modulate
 * @param modulo The modulator
 * 
 * @return The rest
 */
float FloatModulo (float value, float modulo)
{
    return value - (int)(value / modulo) * modulo;
}



/**
 * @brief Get the maximum between 2 numbers
 * 
 * @param x First number
 * @param y Second number
 * 
 * @return The maximum between these 2 numbers
 */
int MaxTwoInt (int x, int y)
{
    if(x < y)
    {
        return y;
    }
    else
    {
        return x;
    }
}



/**
 * @brief Get the maximum between 3 numbers
 * 
 * @param x First number
 * @param y Second number
 * @param z Second number
 * 
 * @return The maximum between these 3 numbers
 */
int MaxThreeInt (int x, int y, int z)
{
    return (MaxTwoInt(MaxTwoInt(x,y),z));
}



/**
 * @brief Get the minimum between 2 numbers
 * 
 * @param x First number
 * @param y Second number
 * 
 * @return The minimum between these 2 numbers
 */
int MinTwoInt (int x, int y){
    if (x < y)
    {
        return x;
    }
    else 
    {
        return y;
    }
}



/**
 * @brief Get the minimum between 3 numbers
 * 
 * @param x First number
 * @param y Second number
 * @param z Second number
 * 
 * @return The minimum between these 3 numbers
 */
int MinThreeInt (int x, int y, int z)
{
    return (MinTwoInt(MinTwoInt(x,y),z));
}