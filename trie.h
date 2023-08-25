#ifndef __TRIE_H_

#define __TRIE_H_

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Defino el tamanio de mi alfabeto
#define ALPHABET_SIZE 26

// Declaro estructura Trie
// letra = Caracter guardado
// hijos = Array de punteros a los nodos hijos 
// terminal = Un booleano que indica si se alcanzo el final de la palabra
typedef struct TrieN{
    char letra;
    struct TrieN *hijos[ALPHABET_SIZE];
    bool terminal;

}TrieNodo;


// Defino el tipo Trie 
typedef TrieNodo * Trie;

// Crea un nodo tipo TrieNodo con la letra especificada y lo devuelve como puntero Trie
Trie TrieCrear(char  letra);

// Inserta una palabra en el trie, comenzando desde la raiz utilizando los caracteres en la palabra
// raiz = trie
// dato = palabra a insertar
void TrieInsert(Trie raiz, char * dato);


// Crea y devuelve un nodo raiz del trie
Trie TrieCreaRoot();

// Libera la memoria ocupada por el trie 
void TrieDestruir(Trie raiz);

// Trasnforma un char a su index en el alfabeto 
int char_to_index(char c);

// cargar diccionario en trie, toma un puntero a un TrieNode y un puntero a un archivo e inserta las palabras del archivos en el trie
void TrieInsertDiccionario(Trie root,FILE* diccionario);

#endif //__TRIE_H_
