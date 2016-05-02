/**
 *
 * Systeme d'exploitation
 *
 *
 */



//#include "server.h"

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


static void * ThreadServeur(void *p_data);


// Cle de chiffrement / dechiffrement
unsigned char key[16] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};



/**
*
*	@brief Fonction principale du serveur 
*
*/
int main(int argc, char *argv[])
{

	// Thread principal du serveur
	pthread_t thread_serveur;	


	pthread_create(&thread_serveur, NULL, ThreadServeur,NULL);

	pthread_join (thread_serveur, NULL);


	
   return EXIT_SUCCESS;
}


/**
*	@brief Fonction principale du Thread serveur
*
*
*/
static void * ThreadServeur(void *p_data)
{
	printf("Test\n");

	return NULL;
}





