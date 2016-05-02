#include <stdint.h>

#ifndef _Process
#define _Process

typedef enum { HORIZONTAL, VERTICAL, NONE } Direction;
typedef enum { BLUE, GREEN, RED, NOPLANE } Plane;

/*
 * A simplified targa header.
 * https://fr.wikipedia.org/wiki/Truevision_Targa
 * Convert images so that
 * the header is normalized:
 *  http://www.online-convert.com/fr/resultat/951c76beddcde2745420399719405656
 * OR use unix command (Image Magick) "convert input_file.any output_file.tga"
*/
typedef struct targa_header_ {
  uint8_t  idlength;
  uint8_t  colourmaptype;
  uint8_t  datatypecode;
  uint8_t  unused[5];
  uint16_t origins[2];
  uint16_t width;
  uint16_t height;
  uint8_t  unused2[2];
} targa_header;


/* Structure for manipulating an image */
typedef struct image_desc_
{
  char *fname;               /* Libellé du fichier image (path)                 */
  uint16_t width;
  uint16_t height;
  uint8_t *pRed;               /* Référence sur le plan mémoire de couleur rouge  */
  uint8_t *pBlue;              /* Référence sur le plan mémoire de couleur bleue  */
  uint8_t *pGreen;             /* Référence sur le plan mémoire de couleur verte  */
} image_desc ;

#endif

int min(int x, int y);

int max(int x, int y);


/* Comparison function; use with qsort() */
int compare_char(const void *a, const void *b);
void image_filter(image_desc i_img, image_desc * o_img);
void image_inject(image_desc i_img, image_desc m_img, image_desc * o_img);

/*
 * Creates output layers in ored, ogreen and oblue with an reduction
 * of the image in iRed, iGreen and iBlue. Frees the memory used by
 * iRed, iGreen and iBlue, makes them point to the same place than
 * ored, ogreen and oblue. Updates head and ohead.
 */
void image_reduce(image_desc i_img, image_desc * o_img);
void image_clone(image_desc i_img, image_desc * o_img);
void image_mono(image_desc i_img, image_desc * o_img);
void image_mono_mid(image_desc i_img, image_desc * o_img);
void image_mirror(image_desc i_img, image_desc * o_img, Direction dir);
void image_cesar(image_desc i_img, image_desc *p_img,int key);
void extract_color(image_desc i_img, image_desc * o_img, Plane plane);
