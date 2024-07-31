/**
 * @brief     C file for the pixel convertion file
 *            These functions are used to replaced the math.h lib 
 * 
 * @author    CAZIN Némo
 * @date      2024
 */

#include "convert.h"



/**
 * @brief Convert RGB values of a pixel to HSV
 * 
 * @param red   The red value of the pixel
 * @param green The green value of the pixel
 * @param blue  The blue value of the pixel
 */
void rgb_to_hsv(unsigned char* red, unsigned char* green, unsigned char* blue)
{
    float hue = 0, saturation = 0, value = 0;
    int max = max_three_int(*red, *green, *blue);
    int min = min_three_int(*red, *green, *blue);
    //Hue check
    if(max == min){
        hue = 0;
    }
    else if(max == *red){
        hue = (60*(*green - *blue) / (max - min) + 360)%360;
    }
    else if(max == *green){
        hue = (60.0*(*blue - *red) / (max - min) + 120.0);
    }
    else if(max == *blue){
        hue = (60.0*(*red - *green) / (max - min) + 240.0);
    }
    //Saturation check
    if (max == 0){
        saturation = 0;
    }
    else{
        saturation = (float) (max - min) / max*100;
    }
    //Value set
    value = (float) (max / 255.00) * 100.00;
    *red = hue;
    *green = saturation;
    *blue = value;    
}



void hsv_to_rgb(float* hue, float* saturation_100, float* value_100)
{
    float temp_red = 0, temp_green = 0, temp_blue = 0;
    float saturation = 0, value = 0;
    saturation = *saturation_100 /100.0;
    value = *value_100 /100.0;
    float chrominance = saturation * value;
    float X = chrominance * (1.0 - fabs(float_modulo(*hue/60.0, 2.0) - 1.0));
    float m = value - chrominance;
    float hi = ((int)*hue/60)%6;
    if(hi == 0){
        temp_red = chrominance;
        temp_green = X;
        temp_blue = 0;
    }
    else if(hi == 1){
        temp_red = X;
        temp_green = chrominance;
        temp_blue = 0;
    }
    else if(hi == 2){
        temp_red = 0;
        temp_green = chrominance;
        temp_blue = X;
    }
    else if(hi == 3){
        temp_red = 0;
        temp_green = X;
        temp_blue = chrominance;
    }
    else if(hi == 4){
        temp_red = X;
        temp_green = 0;
        temp_blue = chrominance;
    }
    else if(hi == 5){
        temp_red = chrominance;
        temp_green = 0;
        temp_blue = X;
    }
    *hue = (temp_red+m)*255;
    *saturation_100 = (temp_green+m)*255;
    *value_100 = (temp_blue+m)*255;   
    }