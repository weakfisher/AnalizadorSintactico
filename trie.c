

#include "trie.h"

int char_to_index(char c){
    return (int)tolower(c) - (int)'a';
}

Trie TrieCrear(char  letra){
    Trie nodo = malloc(sizeof(TrieNodo));

    nodo->terminal = false;
    nodo->letra = letra;
    for(int i = 0 ; i <ALPHABET_SIZE ; i++)
    {
        nodo->hijos[i]= NULL;
    }
    return nodo;
}

Trie TrieCreaRoot(){
    Trie arbol = malloc(sizeof(TrieNodo));
    arbol->terminal = false;
    for(int i = 0 ; i < ALPHABET_SIZE ; i++)
    {
        arbol->hijos[i]= NULL;
    }
    return arbol;
}

void TrieInsert(Trie raiz, char * palabra){
    int longitud = strlen(palabra);
    int index;

    Trie actual = raiz;
    for( int i = 0 ; i<longitud; i++)
    {
        char letra = tolower(palabra[i]);
        index = char_to_index(palabra[i]);
        if (!actual->hijos[index])
        {
            actual->hijos[index]=TrieCrear(letra);
    
        }
        actual = actual->hijos[index];
    }
    actual->terminal = true;

}


void TrieDestruir(Trie raiz){
    if(raiz ==NULL){
        return;
    }
    for(int i = 0 ;i<ALPHABET_SIZE; i++)
    {
        TrieDestruir(raiz->hijos[i]);
    }
    free(raiz);
}


void TrieInsertDiccionario(Trie root,FILE* diccionario){
    char linea[256];

    while(fgets(linea,sizeof(linea),diccionario))
       {
        linea[strcspn(linea, "\n")] = '\0';
        if (!isspace(*linea))
        {
            TrieInsert(root,linea);
        }
    }
    fclose(diccionario);
    
}