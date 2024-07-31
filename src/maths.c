/**
 * @brief     C file for the maths file
 *            These functions are used to replaced the math.h lib 
 * 
 * @author    CAZIN Némo
 * @date      2024
 */

#include "maths.h"

//fmod FROM <math.h> DOESN'T WORK
float float_modulo(float value, float modulo)
{
    float result = value - (int)(value / modulo) * modulo;
    return result;
}

//USED IN max_three_int
int max_two_int (int x, int y)
{
    if(x<y){
        return y;
    }
    else {
        return x;
    }
}

int max_three_int (int x, int y, int z)
{
    return (max_two_int(max_two_int(x,y),z));
}

//USED IN min_three_int
int min_two_int (int x, int y){
    if (x<y){
        return x;
    }
    else {
        return y;
    }
}

int min_three_int(int x, int y, int z)
{
    return (min_two_int(min_two_int(x,y),z));
}