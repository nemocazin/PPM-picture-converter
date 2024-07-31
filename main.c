#include <stdio.h>
#include <stdlib.h>
#include "src/convert.h"
#include "src/functions.h"

int main(int argc, char** argv)
{
    unsigned char image[HEIGHT][WIDTH][PIX_SIZE];
    unsigned int select = 0;
    unsigned char red = 0, green = 0, blue = 0;
    float hue = 0, saturation = 0, value = 0;
    while(1){
        menu_display();
        scanf("%d", &select);
        if (select == 0)
            return 0;
        else if (select == 1)
            copy(image);
        else if (select == 2)
            blur(image);
        else if (select == 3)
        {
            printf("You have selected the RGB to HSV converter\n");
            printf("Choose the value of red to convert (0 to 255) : \n");
            scanf("%hhu", &red);
            printf("Choose the value of green to convert (0 to 255) : \n");
            scanf("%hhu", &green);
            printf("Choose the value of blue to convert (0 to 255) : \n");
            scanf("%hhu", &blue);
            rgb_to_hsv(&red, &green, &blue);
            printf("Hue worth %d, Saturation worth %d, Value worth %d\n", red, green, blue);
            //Erreur au niveau du cast de red. Lorsque les conversions dépassent 255, red retourne à 0.
        }
        else if (select == 4)
        {
            printf("You have selected the HSV to RGB converter\n");
            printf("Choose the value of hue to convert (0 to 360) : \n");
            scanf("%f", &hue);
            printf("Choose the value of saturation to convert (0 to 100) : \n");
            scanf("%f", &saturation);
            printf("Choose the value of value to convert (0 to 100) : \n");
            scanf("%f", &value);
            hsv_to_rgb(&hue, &saturation, &value);
            printf("Red worth %f, Green worth %f, Blue worth %f\n", hue, saturation, value);
        }
        else if (select == 5)
            monochrom(image);
        else if (select == 6)
            mosaic(image);
    }
}