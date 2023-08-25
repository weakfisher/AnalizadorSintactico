#include "trie.h"
#include "utilities.h"
#include <assert.h>
#include <stdio.h>


void test_char_to_index(char c, int resultado){
    int index = char_to_index(c);
    assert(index==resultado);

}


void test_char_to_index_cases(){
     // Test cases
    test_char_to_index('a', 0);
    test_char_to_index('b', 1);
    test_char_to_index('z', 25);

    test_char_to_index('A', 0);
    test_char_to_index('B', 1);
    test_char_to_index('Z', 25);

    test_char_to_index('c', 2);
    test_char_to_index('f', 5);
    test_char_to_index('h', 7);
}

// Este test verificaque la funcion maximador devuelva la maxima palabra en un trie, se considera los casos donde las palabras son en mayusculas y minusclas
//los casos donde se le pasa su equivalente numerico y el caso donde se le pasa un terminal que no es el maximo
void test_maximador(){
    Trie root = TrieCreaRoot();
    char *palabras[]= {"Ga","gato","gaTiTo"};
    TrieInsert(root,palabras[0]);
    TrieInsert(root,palabras[1]);
    TrieInsert(root,palabras[2]);

    char * palabraTmp= maximador(root,"GatitoESCARLATA",strlen(palabras[2]));
    assert (strcmp( palabraTmp,"GATITO"));
    free(palabraTmp);

    palabraTmp =maximador(root,"GATITO",strlen(palabras[2]));
    assert (strcmp( palabraTmp,"GAtito"));
    free(palabraTmp);

    palabraTmp = maximador(root,"GaTiTo",strlen(palabras[2]));
    assert (strcmp( palabraTmp,"gAtIto"));
    free(palabraTmp);

    palabraTmp = maximador(root,"Ga",strlen(palabras[0]));
    assert (strcmp(palabraTmp ,"Ga")==0 );
    free(palabraTmp);

    palabraTmp =maximador(root,"Gato",strlen(palabras[1]));
    assert (strcmp( palabraTmp,"Gato")==0 );
    free(palabraTmp);

    palabraTmp = maximador(root,"",0);
    assert (palabraTmp==NULL );
    free(palabraTmp);


    TrieDestruir(root);
}

int main(){
    test_char_to_index_cases();
    test_maximador();


}