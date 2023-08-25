#ifndef __UTILITIES_H_

#define __UTILITIES_H_
#include "trie.h"
#include <ctype.h>
//Maximador toma un trie, una palabra, un indice y una longitud  y busca la sub-palabra mas larga en el trie y la devuelve
char *maximador(Trie arbol, char * palabra,long longitud);

// Analizador toma un trie, un puntero a un palabra y un archivo de salida
// La funcion analiza la frase dada y devuelve la frase espaciada en el archivo de salida
void analizador(Trie raiz, char *palabra,FILE* output);

#endif