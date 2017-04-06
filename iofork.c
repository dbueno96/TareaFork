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

	//declaramos estructura DIR*
        DIR *dir; 
	dir =NULL;
	//printf("00");     
	//fflush(stdout);    
	
//	printf("estudiante_1: 1530678");
//	printf("estudiante_2: 1631037"); 

	//Verificamos que se recibn dos parámetros 
	if( argc != 2) 
        {
                printf("No se ha introducido un directorio\n") ; 
                return 1; 

        }
		


	//abrimor el directorio que entra como parámetro 
	dir = opendir(argv[1]);
	 
	//verificamos que no sea directorio null
        if(dir == NULL)
        {
                printf("Directorio No Válido");
                return -1; 
        }


	int pid; 
	int contador = 0;
	int size = 0; 
	int auxiliar = 0; 
	int archivos = 0;
	int fd[2] ; 

	//asignamos a **a el valor de guardarArchivos ( se modifica el valor de *archivos) 
	char ** a = guardarArchivos (dir ,&archivos) ; 
	
	

	int mitad  = (int)(archivos / 2)  ;
	
	//tomamos a fd como pipe de comunicacion entre los hijos de ejecución 
	pipe (fd); 
	
	if(pid = fork()) //si pid es cero (hijo) 
	{

		printf("estudiante_1: 1530678 \n");
		printf("estudiante_2: 1631037\n"); 
		printf("Total Archivos: %d \n", archivos); 	

		int  sizeHijo  = 0; //iniciamos variable del tamaño que mide el proc hijo en cero
		close(fd[1]) ; //cerramos el canal de escritura que no se usa
		
		//trabamos con la primera mitad de los archivos.
		while (mitad > 0)
		{
			auxiliar = tamArchivo ( a[contador]) ; //asigna el tamaño de un archivo
			size += auxiliar; // lleva la suma del tamaño de total calculado
			//printf(" %s pesa %d bytes",a[contador], auxiliar) ; 
			//printf("\n");
			contador++;
			mitad--;

		} 
		
		read(fd[0],&sizeHijo, sizeof(sizeHijo) ) ; //espera hasta que el otro proceso escriba en el canal, y guarda lo que se lee.
		printf("Tamaño total: %d bytes.", size+sizeHijo); 
		printf("\n"); 
	}
	else //cuando es el proceso padre
	{
		close(fd[0]); //cerramos el canal de lectura que no se usa
		contador = mitad ; //contador desde mitad 
		mitad= archivos - mitad; 
		
		while (contador < archivos )
		{
			mitad--;
			auxiliar = tamArchivo(a[contador]) ; // asignamos el valor de 
			size +=auxiliar; // contabiliza el tamaño total calculado
		//	printf(" %s pesa %d bytes", a[contador], auxiliar); 
		//	printf("\n");
			contador++;
		}
		write(fd[1], &size, sizeof(size)); //escribe en el canal el tamaño total calculado por el proc padre
	}
	
	return 0; 
}

