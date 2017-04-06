# TareaFork
Estudiante 1: Daniel Felipe Bueno G. 1530678
 Estudiante 2: Nathalia Ceballos 1631037

Makefile : Documento con las instrucciones para crear los ejecutables de los programas 'io' e 'iofork' como se especifíca en las instrucciones 


io.c: 
	Programa que se encarga de acceder a un directerio, contar la cantidad de archivos no directorios en él, y contar la cantidad total de 	byte del directorio. Este proceso se realiza de manera secuencial .

iofork.c:
	Programa que se encarga de acceder a un directorio, contar la cantidad de archivos no directorios en él y contar la cantidad de bytes 	totales del directorio, implementando la instrucción fork para que el proceso se realice con dos hilos de ejecución simultáneos.

	
fileutil.h
	Contiene la definiciones de tipos y los nombres de los procedimientos adicionales que se requieren para la ejecución de io e iofork.En este caso solo contiene dos funciones definidas. Una que cuenta el tamaño de un archivo y otra que guarda los archivos de un directorio dado 

fileutil.c 
	Contiene las implementacion de los procedidimientos definidos en fileutil.c para ser utilizados en los programas de io e iofork 

