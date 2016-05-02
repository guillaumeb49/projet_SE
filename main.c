//
//  main.c
//  fichierTarga
//
//  Created by Mario Aubert on 05/02/16.
//  Copyright © 2016 Mario Aubert. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "mem_targa.h"
#include "processing.h"

int main(void) {
    image_desc *desk   =malloc(sizeof(image_desc));
    image_desc *desk2  =malloc(sizeof(image_desc));
    targa_header *head =malloc(sizeof(targa_header));
    char *path  ="/home/mario/Images/ball.tga";
    char *path2 ="/home/mario/Images/ballBleu.tga";

    printf("Début du programme \n\r");
    readImage(desk,head, path);
    //image_mono(*desk, desk2);
    image_cesar(*desk, desk2,-20);
    writeImage(*desk2,*head, path);
    system("eog /home/mario/Images/ball.tga & eog /home/mario/Images/ballBleu.tga");
    freeImage(desk);
    freeImage(desk2);
    return 0;
}
