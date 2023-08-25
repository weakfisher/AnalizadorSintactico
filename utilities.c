
#include "utilities.h"




char *maximador(Trie arbol, char * palabra,long longitud){
    char *resultado = malloc(sizeof(char)*longitud+1); 
    int masLargoInd = 0;
    int indicePalabra=0;
    bool errorEncontrado= false;
    for (int i = 0; i < longitud && !errorEncontrado; i++) {
        int index = char_to_index(palabra[i]);
        Trie nodo = arbol->hijos[index];
        if (nodo) 
            {
            masLargoInd++;
            if (nodo->terminal )
            { 
                indicePalabra = masLargoInd;
            }
            arbol = nodo;
        }
        else
        {
            errorEncontrado = true;
        }
    }
    // Si no se encuentra una palabra se libera a resulta y null
    if (indicePalabra == 0)
    {
        free(resultado);
        return NULL;
    }
    // Si se encuentra una palabra se inserta en resultado y se devuelve
    int i  = 0;
    while( i <indicePalabra)
        {
            resultado[i]= palabra[i];
            i++;
        }
    resultado[i]='\0';
    return resultado;

        

    
}


void analizador(Trie raiz, char *palabra,FILE* output) {
    long len = (long)strlen(palabra);
    Trie aux = raiz;
    char * palabraFinal = malloc(sizeof(char)*len*2); // Declaro el string donde se va a ubicar la palabra espaciada
    strcpy(palabraFinal,"\0");
    bool seRecuperoErrores = false;
    int i=0;
    while(i < len)
    {

        int index = char_to_index(palabra[i]);
        Trie nodoObtenido = aux->hijos[index];
        if (!nodoObtenido)
        {
            seRecuperoErrores = true;
            aux = raiz;
            i++;
        }

        else{
            char * stringTemporal = maximador(raiz,(palabra+i),len-i); // Declaro el string con la maxima palabra 
            if (stringTemporal != NULL){
            int largoString = strlen(stringTemporal);
            
            i += largoString;
                
            strcat(palabraFinal,stringTemporal);
            strcat(palabraFinal," ");
            free(stringTemporal);
            }
            else{
                i++;
            }
            aux = raiz;
        }
    }
    if(!seRecuperoErrores)

        fprintf(output,"%s -- No se encontraron errores\n",palabraFinal);
    else 
    {
        fprintf(output,"%s -- Se recupero de errores\n",palabraFinal);
    }
    free(palabraFinal);
}
