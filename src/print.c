/**
 * @brief     C file for the print file
 * 
 * @author    CAZIN Némo
 * @date      2024
 */

#include "print.h"



/**
 * @brief Print the menu at the start
 */
void menu_display()
{
    printf("######################################################################\n");
    printf("#                                                                    #\n");
    printf("#  CHOOSE THE FUNCTION YOU WANT BY WRITING A NUMBER                  #\n");
    printf("#                                                                    #\n");
    printf("#         |1|    Copy a wanted picture                               #\n");
    printf("#         |2|    Blur a wanted picture                               #\n");
    printf("#         |3|    Convert RGB values to HSV values                    #\n");
    printf("#         |4|    Convert HSV values to RGB values                    #\n");
    printf("#         |5|    Monochrom a wanted picture                          #\n");
    printf("#         |6|    Create a mosaic of a wanted picture                 #\n");
    printf("#                                                                    #\n");
    printf("#         |0|    Quit the programm                                   #\n");
    printf("#                                                                    #\n");
    printf("#                                                   By CAZIN Némo    #\n");
    printf("######################################################################\n");
    printf("\n");
    printf("Which function do you want to choose ?\n");  
    fflush(stdout);
}