#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

#include "fileutil.h"



int tamArchivo (char *nombre)
{
	FILE *archivo; 
	
	int contador= 0; 
	
	archivo = fopen(nombre,"rb") ;  // abro el archivo con etiqueta "rb" 
	
	while (fgetc(archivo) != EOF) //MIENTRAS: lo que lea != fin del archivo
 	{
		contador++; //incremento en 1 el contador 

	}

	fclose(archivo) ;
	return contador; 
}

 

char **guardarArchivos(DIR *dir, int *archivos) 
{
	
	
	char**a = (char**)malloc(sizeof(char*));

	int contador = 0; 

	struct dirent *entr; 

	while((entr = readdir(dir)) != NULL ) //
	{
		if((strcmp (entr->d_name,".")) != 0 && (strcmp (entr->d_name,"..") != 0)) 
		{
			FILE *archivo ; //declaro tipo FILE archivo 
			
			archivo =fopen(entr->d_name, "r"); //arhivo retorna una dirección que contiene un FILE 
			
			if(entr->d_type != DT_DIR )
			//if(archivo)
			{
		
				a = (char **)realloc(a, (sizeof(char*) * (contador +1))); //modficamos el tamaño de acuerdo a las filas necesarias
				a[contador] = (char*)malloc( sizeof(entr->d_name) * sizeof(char)); //asigna tamaño a las filas según necesidad
				strcpy ( a[contador], entr->d_name) ;
				contador++;
			}
			
			fclose(archivo) ; //cerramos el archivo 
		}
	}

	closedir(dir) ; //cerramos el directorio
	*archivos  = contador; 
	
	return a; 

}


