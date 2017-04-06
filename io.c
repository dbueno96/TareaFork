#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <sys/wait.h>
#include <math.h>
#include <unistd.h>
#include "fileutil.c"

int main (int argc, char **argv)
{


	printf("estudiante_1: 1530678\n");
	printf("estudiante_2: 1631037\n"); 
	//declaramos estructura dirent
	DIR *dir; 

	//verificamos que se hayan recibido 2 argumentos
	if( argc != 2) 
	{
		printf("No se ha introducido un directorio\n") ; 
		return 1; 
	
	}

	//abrimos el directorio 
	dir = opendir(argv[1]);
	if(dir == NULL)//verificamos que sea un directorio válido
	{
		printf("Directorio No Válido\n");
		return -1; 
	}
	
	int archivos = 0; 
	int contador = 0; 
	int size = 0; 
	int auxiliar = 0; 
	
	//guardamos en **a los archivos del directorio y en &archivos la cantidad de archivos 
	char **a = guardarArchivos(dir, &archivos) ;

	printf("Total Archivos: %d \n", archivos); 
	
	
	while(archivos > 0)//mientras haya archivos por contar
	{
		archivos--;
		auxiliar = tamArchivo(a[contador]);	//asignamos el valor de tamArchivo para cada fila de a**
		size += auxiliar; //contamos el tamaño total 
		//printf(" %d. %s ocupa %d bytes \n", contador+1 , a[contador], auxiliar) ;  
		contador++;
	}
	
 		
	printf("Total: %d  bytes \n	", size); 
		
	return 0;
}
