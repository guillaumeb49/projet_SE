#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "processing.h"
#include "mem_targa.h"

/**
 * @desc Put the image (i_img) in monochrome (*p_img)
 **/
void image_mono(image_desc i_img, image_desc *p_img)
{
  int planeSize;
  uint8_t *iBlue  = i_img.pBlue;
  uint8_t *iGreen = i_img.pGreen;
  uint8_t *iRed   = i_img.pRed;
  uint8_t *oBlue, *oGreen, *oRed, *oBlueEnd;

  /* Memory allocation for each plan of dest image : */
  planeSize = mallocImage(p_img, i_img.width, i_img.height);
  oBlue  = p_img->pBlue;
  oGreen = p_img->pGreen;
  oRed   = p_img->pRed;

  /* Transformation application */
  oBlueEnd = oBlue + sizeof(uint8_t) *planeSize;
  while (oBlue < oBlueEnd) {
    uint8_t newValue = (*iBlue + *iGreen + *iRed)/3;
    *oBlue = newValue;
    *oGreen = newValue;
    *oRed = newValue;
    iBlue++; iGreen++; iRed++;
    oBlue++; oGreen++; oRed++;
  }
}

void image_cesar(image_desc i_img, image_desc *p_img,int key)
{
  int planeSize,i=0;
  uint8_t *iBlue  = i_img.pBlue;
  uint8_t *iGreen = i_img.pGreen;
  uint8_t *iRed   = i_img.pRed;
  uint8_t *oBlue, *oGreen, *oRed;

  /* Memory allocation for each plan of dest image : */
  planeSize = mallocImage(p_img, i_img.width, i_img.height);
  oBlue  = p_img->pBlue;
  oGreen = p_img->pGreen;
  oRed   = p_img->pRed;

  /* Transformation application */
  while (i < planeSize) {
    oBlue[i]  = (iBlue[i]+key)%255;
    oGreen[i] = (iGreen[i]+key%255);
    oRed[i]   = (iRed[i]+key)%255;
    i++;
  }
}
/**
 * @desc Clone the image (i_img) into (*p_img)
 **/
void image_clone(image_desc i_img, image_desc *p_img)
{
  int planeSize;
  uint8_t *iBlue  = i_img.pBlue;
  uint8_t *iGreen = i_img.pGreen;
  uint8_t *iRed   = i_img.pRed;
  uint8_t *oBlue, *oGreen, *oRed;
  /* Allocation memoire pour l'image */
  planeSize = mallocImage(p_img, i_img.width, i_img.height);
  oBlue = p_img->pBlue;
  oGreen = p_img->pGreen;
  oRed = p_img->pRed;
  int i = 0;
  /* Transformation */
  while (i < planeSize) {
    oBlue[i] = iBlue[i];
    oGreen[i] = iGreen[i];
    oRed[i] = iRed[i];
    i++;
  }
}
/**
 * @desc Extract the color plane from image (i_img) and save its plane into (*p_img)
 **/
void extract_color(image_desc i_img, image_desc *p_img, Plane plane)
{
  int planeSize;
  uint8_t *iBlue  = i_img.pBlue;
  uint8_t *iGreen = i_img.pGreen;
  uint8_t *iRed   = i_img.pRed;
  uint8_t *oBlue, *oGreen, *oRed, *oBlueEnd;
  int   linelength = sizeof (uint8_t) * i_img.width;
  /* Memory allocation for each plan of dest image : */
  planeSize = mallocImage (p_img, i_img.width, i_img.height);
  oBlue = p_img->pBlue;
  oGreen = p_img->pGreen;
  oRed = p_img->pRed;
  /* Transformation application */
  oBlueEnd = oBlue + planeSize;
  while (oBlue < oBlueEnd)
  {
    *oBlue  = (plane == BLUE) ? *iBlue : 0;
    *oGreen = (plane == GREEN) ? *iGreen : 0;
    *oRed   = (plane == RED) ? *iRed : 0;

  /* (Pointer arithmetic) If this does not look intuitive to you,
   * please refer to the image_clone (where an index i is used
   * instead of incrementing pointers)
   * --> while condition is done on i instead of being done on oBlue
   * --> *oBlue = xxx becomes oBlue[i] = xxx (with i incremented at each iteration of the loop)
   * --> iBlue++; becomes i++;
   */
    iBlue++; iGreen++; iRed++;
    oBlue++; oGreen++; oRed++;
  }
}
