`Compilacion`
Para compilar se puede invocar make. Esto producira 2 ejecutables llamados 'test' y 'programa'
Luego el ejecutable  'programa' toma 3 argumentos en orden son:
+Archivo de Entrada
+Diccionario a tomar
+Archivo de Salida

y 'test' encarga de ejecutar los test. 
`Descripcion General del Codigo`
La idea del codigo es insertar en un trie las palabras del diccionario de donde queramos obtener las palabras y luego iterar a travez de las k lineas del archivo de entrada para en una funcion (analizador) espaciar la frase mientras al mismo tiempo se busca la max palabra que se puede formar.Cuando obtenemos la frase espaciada simplemente la escribimos en el archivo de salida y pasamos a la siguiente linea del archivo de entrada para seguir con el proceso
`Estructura de datos`
Implemente un trie que tiene un dato el cual es el caracter a guardar y cada nodo tiene hijos a letras del abecedario y un booleano para marcar si un caracter es el terminal de la palabra ingresada en el trie.
Elegi esta estructura porque facilita la verificacion y busqueda de palabras validas.Ademas la ventaja del trie es que el tiempo de insercion y busqueda de string es O(n) donde n es el largo de la palabra/frase.

`Busqueda de maxima palabra`
Un punto clave del analizador es la busqueda y obtencion de la palabra maximal en la frase.El cual busco iternado sobre la frase de la cual quiero obtener una palabra maximal, en el momento en que encuentro el caracter inicial de la palabra comienzo a acceder a los nodos hijos en el trie mientras itero en los caracteres de la frase, en el caso que encuentre un caracter que no tiene hijos es decir que intente acceder a un caracter que no esta en el trie, devuelve NULL, caso contrario sigue buscando hasta que encuentra un terminal, cuando encuentra un terminal marca dicho terminal como max de la palabra, sigue iterando hasta que se alzance el maximo de la frase o encuentre un error. Cuando se logra uno de los dos caso es decir luego de encontrar un terminal se alcanza un maximo o se encuentra un caracter no perteneciente, se devuelve la palabra hasta dicho terminal.

# AnalizadorSintactico
