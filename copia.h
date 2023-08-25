#ifndef __COPIA_H_

#define __COPIA_H_

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

// Declaro estructura Trie
typedef struct TrieN{
    char letra;
    struct TrieN *hijos[26];
    bool terminal;

}TrieNodo;

typedef TrieNodo * Trie;

Trie TrieCrear(char * letra);

void TrieInsert(Trie raiz, char * dato);

#endif //__TRIE_H_
