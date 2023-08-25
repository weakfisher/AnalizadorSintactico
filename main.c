#include "trie.h"
#include "utilities.h"



// imprime la frase espaciada
void imprimir_frase(Trie root, FILE* archivoEntrada, FILE * archivoSalida )
{
    char linea[256];

    while(fgets(linea,sizeof(linea),archivoEntrada))
    {   
        if (*linea != '\n')
        {
            linea[strcspn(linea, "\n")] = '\0';
            analizador(root,linea,archivoSalida);
        }
    }
    
    fclose(archivoSalida);
    fclose(archivoEntrada);

}

int main(int argc, char* argv[]){

    if (argc != 4)
    {
        printf("Error en la cantidad de argumentos \n"); 
        return -1;
    }   
    
    Trie root = TrieCreaRoot();
    FILE *archivoEntrada = fopen(argv[1],"r");
    FILE * diccionario = fopen(argv[2],"r");
    FILE * archivoSalida = fopen(argv[3],"w");

    if (archivoEntrada == NULL || archivoSalida == NULL || diccionario== NULL)
    {
        return -1;
    }
    TrieInsertDiccionario(root,diccionario);
    imprimir_frase(root,archivoEntrada,archivoSalida);
    TrieDestruir(root);
    return 0;
}