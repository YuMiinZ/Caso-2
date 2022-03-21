//Elaborado por Ericka Yu Min

#include <iostream>
#include <fstream>
#include <chrono>
using namespace std;

int partirRandom(int arr[], int izquierda, int derecha){
    /*
    Funcionamiento: Selecciona un pivote de manera aleatoria para luego ordenarlo.

    Entradas:
    -arr[](int): Arreglo que se utilizar� para ordenar
    -izquierda(int): Posici�n de lado izquierdo del arreglo.
    -derecha(int): Posici�n de lado derecho del arreglo.

    Salidas:
    -left(int): Retorna el �ndice de la partici�n.
    */
    int pivot = izquierda,left = izquierda,next = left+1, random = izquierda+rand()%(derecha-izquierda);
    swap(arr[random], arr[izquierda]);
    while (next <= derecha) {
        while(arr[next]<arr[pivot]){
            left++;
            swap(arr[left], arr[next]);
            next++;
        }
        next++;
    }
    swap(arr[left], arr[pivot]);

    return left;
}

void quickSort(int arr[], int izquierda, int derecha){
    if(izquierda<derecha){
        int pivote=partirRandom(arr,izquierda,derecha);
        quickSort(arr, izquierda, pivote-1); //mitad izquierda
        quickSort(arr, pivote+1, derecha); //mitad derecha
    }
}

int partir(int arr[], int izquierda, int derecha){
    /*
    Funcionamiento: Selecciona un pivote de manera aleatoria para luego ordenarlo.

    Entradas:
    -arr[](int): Arreglo que se utilizar� para ordenar
    -izquierda(int): Posici�n de lado izquierdo del arreglo.
    -derecha(int): Posici�n de lado derecho del arreglo.

    Salidas:
    -left(int): Retorna el �ndice de la partici�n.
    */
    int pivot = izquierda,left = izquierda,next = left+1, random = izquierda+rand()%(derecha-izquierda);
    //swap(arr[random], arr[izquierda]);
    while (next <= derecha) {
        while(arr[next]<arr[pivot]){
            left++;
            swap(arr[left], arr[next]);
            next++;
        }
        next++;
    }
    swap(arr[left], arr[pivot]);

    return left;
}

void quickSort2(int arr[], int izquierda, int derecha){
    if(izquierda<derecha){
        int pivote=partir(arr,izquierda,derecha);
        quickSort(arr, izquierda, pivote-1); //mitad izquierda
        quickSort(arr, pivote+1, derecha); //mitad derecha
    }
}

void insertionSort(int arr[], int tamanio){
    /*
    Funcionamiento: Ordena el arreglo verificando cada elemento de este comenzando por la posici�n 1 y lo compara
    con los elementos de la izquierda, si el elemento de la izquierda es mayor que el pivote actual se realizar� el acomodo.

    Entradas:
    -arr[](int): Arreglo a ordenar
    -tamanio(int): Tama�o del arreglo.

    Salidas: N/A
    */
    auto start = std::chrono::system_clock::now();
    int pivote, izquierda,aux, contadorFor=0,contadorWhile=0;
    for(int posi=1;posi<tamanio;posi++){
        contadorFor++;
        pivote=arr[posi];
        izquierda=posi-1;
        while(pivote>-1 && arr[izquierda]>pivote){
            contadorWhile++;
            arr[izquierda+1]=arr[izquierda];
            izquierda--;
        }
        arr[izquierda+1]=pivote;
    }

    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double,milli> diff = end - start;
    std::cout << "Tiempo de ejecuci�n: " <<diff.count() << " ms\n"<<"Cantidad de iteraciones en el for: "<<contadorFor<<
    "\nCantidad de iteraciones del while: "<<contadorWhile;
}

void mostrarArreglo(int arr[], int tamanio){
    /*
    Funcionamiento: Muestra todos los elementos del arreglo.

    Entradas:
    -arr[](int): Arreglo a mostrar.
    -tamanio(int): Tama�o del arreglo a mostrar

    Salidas: Imprime todos los elementos en consola.
    */
    cout<<"Arreglo\n";
    for(int posi=0;posi<tamanio;posi++){
        cout<<arr[posi]<<" ";
    }
    cout<<"\n\n";
}

string leerArchivo(string fileName){
    ifstream file;
    string text,line;

    file.open(fileName,ios::in);//Abrir en modo lectura
    if(file.fail()){
        cout<<"Error a la hora de abrir el archivo.";
        exit(1);
    }
    else{
        while(!file.eof()){
            getline(file, line);
            text=text + line;
        }
        file.close();
    }
    return text;
}

void llenarArregloRandom(int arr[],int cantidad, int arr2[]){
    for(int posi=0;posi<cantidad;posi++){
        arr[posi]=rand();
        arr2[posi]=rand();
    }
}

void llenarArregloOrdenado(int arr[],int cantidad, int arr2[]){
    for(int posi=0;posi<cantidad;posi++){
        arr[posi]=posi;
        arr2[posi]=posi;
    }
}


void llenarArregloInverso(int arr[],int cantidad, int arr2[]){
    for(int posi=0;posi<cantidad;posi++){
        arr[posi]=cantidad-posi;
        arr2[posi]=cantidad-posi;
    }
}

int buscarApariciones(string text,string pattern){
    /*
    Funcionamiento: M�todo que se encarga de contar la cantidad de apariciones en las que aparece el patr�n a buscar en el texto.

    Entradas:
    -text(string): Texto que se utilizar� para buscar.
    -pattern(string): Caracteres claves que se quiere buscar en el texto.

    Salida: Retorna la cantidad de veces que aparece dicho patr�n en el texto.

    Notas: Esta funci�n cuenta con una complejidad de O(n), ya que lo que hace es recorrer todas posiciones del texto original hasta encontrar
    una coincidencia con el primer caracter del patr�n, luego de haberlo encontrado lo que hace es recorrer otra vez desde esa posici�n hasta la
    longitud del patr�n -1 (porque sabemos que el ya hubo la primera coincidencia y gracias a ella es que entramos al segundo for). Dentro de
    este segundo ciclo que recorre desde posi2=1 hasta la longitud del patr�n -1, lo que hace es seguir comparando los siguientes caracteres a ver
    si todas coinciden, reflejando as� un comportamiento lineal.
    */

    auto start = std::chrono::system_clock::now();
    int cont=0,apariciones=0,posi2=1, contadorFor=0,contadorWhile=0;

     for(int posi=0;posi<text.length();posi++){
        contadorFor++;
        if(text[posi]==pattern[0]){
            while(text[posi+posi2]==pattern[posi2]&&posi2+posi<text.length()){
                contadorWhile++;
                posi2++;
            }
            apariciones+=((posi2==pattern.length())?1:0);
            posi+=((posi2==pattern.length()-1)?pattern.length()-1:0);
            posi2=1;
        }
     }

    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double,milli> diff = end - start;
    std::cout << "Tiempo de ejecuci�n: " <<diff.count() << " ms\n"<<"Cantidad de iteraciones en el for: "<<contadorFor<<
    "\nCantidad de iteraciones del while: "<<contadorWhile;

     return apariciones;

}


int main(){
    //----------------------Ordenando---------------------------
    //int arr1[]={8,5,4,2,10,1};
    int arr1[2800],arr2[2800];
    llenarArregloInverso(arr1,2800,arr2);//Generar un arreglo de manera aleatoria con x cantidad de elementos para las pruebas.

    //mostrarArreglo(arr1,sizeof(arr1)/sizeof(arr1[0]));
    auto start = std::chrono::system_clock::now();
    quickSort(arr1,0,(sizeof(arr1)/sizeof(arr1[0]))-1);
    //mostrarArreglo(arr2,sizeof(arr2)/sizeof(arr2[0]));
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double,milli> diff = end - start;
    std::cout << "Tiempo de ejecuci�n con pivote ALEATORIO " <<diff.count() << " ms\n";

    start = std::chrono::system_clock::now();
    //mostrarArreglo(arr2,sizeof(arr2)/sizeof(arr2[0]));
    quickSort2(arr2,0,(sizeof(arr2)/sizeof(arr2[0]))-1);
    //mostrarArreglo(arr2,sizeof(arr2)/sizeof(arr2[0]));
    end = std::chrono::system_clock::now();
    diff = end - start;
    std::cout << "Tiempo de ejecuci�n con pivote FIJO " <<diff.count() << " ms\n";

    insertionSort(arr1,(sizeof(arr1)/sizeof(arr1[0])));
    //mostrarArreglo(arr,sizeof(arr)/sizeof(arr[0]));

    //----------------------B�squeda Texto----------------------
    string text=leerArchivo("10mb.txt"), pattern="casa";
    int apariciones=buscarApariciones(text, pattern);
    cout<<"\n\nSe ha encontrado la palabra "<<apariciones<<" veces.";

}


/*
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                    Pruebas de Ejecuci�n
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
QuickSort Logar�tmico Pivote Fijo

Prueba 1: Elementos: 2500    Tiempo de duraci�n: 0.9992  ms         Logaritmo: 11.28771
Prueba 2: Elementos: 4500    Tiempo de duraci�n: 1.0037  ms         Logaritmo: 12.13571
Prueba 3: Elementos: 20000   Tiempo de duraci�n: 3.9986  ms         Logaritmo: 14.2877
Prueba 4: Elementos: 20500   Tiempo de duraci�n: 4.9988  ms         Logaritmo: 14.3233

Tasa de crecimiento

Tasa 1:     Tiempo: 0.0045               Logaritmo: 0.848
Tasa 2:     Tiempo: 2.9949               Logaritmo: 2.15199
Tasa 3:     Tiempo: 1.0002               Logaritmo: 0.0356

Conclusi�n:
Se puede ver que utilizando los elementos seleccionados el programa tiene un comportamiento logar�tmico,
debido a su tasa de crecimiento, que de manera tanto como logar�tmica y por tiempo de milisegundos son
muy parecidos. En la tercera tasa tenemos una diferencia un poco m�s notoria, pero fuera de eso todos los
dem�s si tienen un crecimiento similar.

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
QuickSort Logar�tmico Pivote Aleatorio

Prueba 1: Elementos: 2500    Tiempo de duraci�n: 1.0014  ms         Logaritmo: 11.28771
Prueba 2: Elementos: 4500    Tiempo de duraci�n: 2.0002  ms         Logaritmo: 12.13571
Prueba 3: Elementos: 20000   Tiempo de duraci�n: 4.9997  ms         Logaritmo: 14.2877
Prueba 4: Elementos: 20500   Tiempo de duraci�n: 5.9994  ms         Logaritmo: 14.3233

Tasa de crecimiento

Tasa 1:     Tiempo: 0.9988               Logaritmo: 0.848
Tasa 2:     Tiempo: 2.9995               Logaritmo: 2.15199
Tasa 3:     Tiempo: 0.9997               Logaritmo: 0.0356

Notas: Se utiliz� el  mismo arreglo de elementos para cada una de las pruebas con pivote fijo y aleatorio,
es decir, se utiliz� el mismo arreglo para la prueba 1 del algoritmo quicksort con pivote fijo y aleatorio.

Conclusi�n:
La primera observaci�n consiste en que casi que el tiempo de duraci�n utilizando un pivote aleatorio es
mayor que utilizando un pivote fijo, esto pudo ser una mala suerte a la hora de seleccionar el pivote
de manera aleatoria. La segunda observaci�n es que utilizando los mismos elementos se tiene un comportamiento
logar�tmico, ya que su tasa de crecimiento con respecto al tiempo y la tasa de crecimiento logaritmica son muy
simisales, pero con un margen de error casi que de 1 de diferencia en casi que todos los casos demostrados.

En conclusi�n, para un pivote fijo y aleatorio con esta misma cantidad de elementos el algoritmo se comporta
de manera logar�tmica y que al usar un pivote fijo o aleatorio si puede llegar a afectar su tiempo de ejecuci�n,
debido a que tenemos la posibilidad de que el pivote seleccionado de manera aleatoria sea uno bueno o uno malo.

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
QuickSort Cuadr�tico Pivote Aleatorio

Prueba 1: Elementos: 30000    Tiempo de duraci�n: 8.0048  ms
Prueba 2: Elementos: 50000    Tiempo de duraci�n: 10.6848 ms
Prueba 3: Elementos: 70000    Tiempo de duraci�n: 16.3049 ms
Prueba 4: Elementos: 90000    Tiempo de duraci�n: 32.0136 ms

Tasa de crecimiento

Tasa 1: 2,68
Tasa 2: 5,6201
Tasa 3: 15,7087

Conclusi�n:
Al incrementar los elementos de poco a poco su tasa de crecimiento tambi�n se ve duplicado, pero para estas pruebas
lo que se utiliz� fue un arreglo casi que ordenado para que se note la diferencia entre un arreglo ordenado y desordenado,
el peor caso de este algoritmo ocurre cuando el arreglo est� ordenado y luego de varias corridas su tiempo de ejecuci�n
pod�a aumentar o disminuir, pero al final y al cabo su resultado era bastante elevado como los que se ven aqu� reflejados,
en tener un pivote fijo y aleatorio tambi�n puede afectar el algoritmo, ya que puede ocurrir que el primer elemento seleccionado
como pivote fijo sea un pivote no muy eficiente y con uno aleatorio tenemos la posibilidad de que capaz el primer pivote sea
malo y en el segundo sea una mejor selecci�n de pivote, algo que no se tiene con uno fijo.
Otras de las cosas que se peude concluir es que la m�quina puede llegar a afectar el tiempo de ejecuci�n, si se tiene muchos programas
abiertos, el rendimiento ser� menor, por lo tanto durar� m�s y dicho resultado puede cambiar.

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
QuickSort Cuadr�tico Pivote Fijo

Prueba 1: Elementos: 30000   Tiempo de duraci�n: 9.8299  ms
Prueba 2: Elementos: 50000   Tiempo de duraci�n: 14.9817 ms
Prueba 3: Elementos: 70000   Tiempo de duraci�n: 25.2507 ms
Prueba 4: Elementos: 90000   Tiempo de duraci�n: 43.919  ms

Tasa de crecimiento

Tasa 1: 5,1518
Tasa 2: 10,269
Tasa 3: 18,6683

Conclusi�n:
Se puede observar que la tasa de crecimiento por x cantidad de elementos es el doble, aunque cuenta con un peque�o margen de error del 2-3 por ciento.
La prueba n�mero cuatro su tiempo de duraci�n fue mucho mayor con el pivote fijo que utilizando uno aleatorio.

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
InsertSort Lineal

Prueba 1: Elementos: 2500    Tiempo de duraci�n: 0        Iteraciones del for: 2499          Iteraciones del while: 0
Prueba 2: Elementos: 2600    Tiempo de duraci�n: 0        Iteraciones del for: 2599          Iteraciones del while: 0
Prueba 3: Elementos: 2700    Tiempo de duraci�n: 0        Iteraciones del for: 2699          Iteraciones del while: 0
Prueba 4: Elementos: 2800    Tiempo de duraci�n: 0        Iteraciones del for: 2799          Iteraciones del while: 0
Tasa de crecimiento

Tasa 1:     Tiempo: 2.9965
Tasa 2:     Tiempo: 3.0012
Tasa 2:     Tiempo: 9.0069

Conclusi�n:
Utilizando un arreglo ordenado se tiene un comportamiento lineal, debido a que como el insertion sort agarra un pivote y pregunta si los elementos
anteriores a este se encuentra ordenados, por lo tanto siempre realizar� la misma cantidad de iteraciones en el for y no tendr�a que entrar
al segundo ciclo del while, como podemos observar en los resultados sus iteraciones en el while son 0, mientras que los del for son de n-1 iteraciones,
generando as� un comportamiento lineal. Se puede decir que al estar el arreglo ordenado, su tiempo de ejecuci�n es tan r�pido que no se logr� obtener
tiempos de ejecuci�n distintos para esta cantidad de elementos, ya que al probar luego con una gran cantidad de elementos por ejemplo 28000 segu�a obteniendo
el mismo tiempo de ejecuci�n y debido a ello se comenz� a contar lal cantidad de iteraciones realizadas dentro de los ciclos.

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
InsertSort Cuadr�tico

Prueba 1: Elementos: 2500    Tiempo de duraci�n: 19.0007 ms        Iteraciones del for: 2499          Iteraciones del while: 3123750
Prueba 2: Elementos: 2600    Tiempo de duraci�n: 21.9986 ms        Iteraciones del for: 2599          Iteraciones del while: 3378700
Prueba 3: Elementos: 2700    Tiempo de duraci�n: 29.9967 ms        Iteraciones del for: 2699          Iteraciones del while: 3643650
Prueba 4: Elementos: 2800    Tiempo de duraci�n: 35.6397 ms        Iteraciones del for: 2799          Iteraciones del while: 3918600


Conclusi�n:
Para probar que el isnertion sort tiene un comportamiento cuadr�tico se utiliz� un arreglo inverso generando as� el peor caso,
donde siempre se tenga que realizar siempre todas las comparaciones desde la posici�n del pivote hasta la posici�n 0, ya que
el arreglo se encuentra invertido siempre el siguiente pivote ser� el menor de todos los anteriores, por lo tanto, tendr�
que volver a recorrer todo el arreglo hasta el principio y acomodar el pivote actual y as� sucesivamente, en estas pruebas de
ejecuci�n se puede observar que la cantidad de veces que itera el ciclo while es la suma desde 1 hasta n, donde n es la
cantidad de elementos -1.


------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Free text Lineal

Prueba 1: Tama�o: 10MB    Tiempo de duraci�n: 228.15  ms        Iteraciones del for: 10485761      Iteraciones del while: 0
Prueba 2: Tama�o: 10MB    Tiempo de duraci�n: 374.97  ms        Iteraciones del for: 10485760      Iteraciones del while: 0
Prueba 3: Tama�o: 10MB    Tiempo de duraci�n: 156.244 ms        Iteraciones del for: 10485773      Iteraciones del while: 9

Conclusi�n:
Este algoritmo de b�squeda tiene un comportamiento lineal, debido a que es muy similar al insertion sort, solo que este recorre
todas las posiciones del texto buscando una coincidencia con el primer caracter del patr�n y luego de haberlo encontrado averigua
si los siguientes caracteres que siguen en el texto tambi�n coincide con el del patr�n, en el caso de que no es as� continua con
el siguiente caracter originalmente, es decir, cuando encuentra una coincidencia entra a otro ciclo que tambi�n de comporta de manera
lineal para averiguar si es o no el patr�n que se busca, en el caso de que no lo sea, solo continua con el siguiente caracter donde
hab�a quedado antes de entrar al segundo ciclo y en el caso de que s� sea el patr�n que se busca, se salta la cantidad de caracteres
necesarios, porque no ser� necesario seguir averiguando, porque ya se encontr� la coincidencia del patr�n en el texto original.

Para la primera prueba es que el archivo de 10MB est� lleno de espacios y el �ltimo caracter del texto es una "a", por lo tanto,
se hace una b�squeda lineal para encontrar dicho elemento y es por eso que no realiza nin�n ciclo while, porque la letra a buscar
tiene una longitud de 1, por lo tanto, no tiene m�s caracteres del patr�n a verificar.

Para la segunda prueba se elimin� la letra "a" y se busc� los espacios.

En la tercera prueba al principio del archivo se a�adi� la palabra casacasaCcasa, se ve que el se itera 9 veces el ciclo while, debido
a que cuando encuentra la primera c, entra al while verificando si lo que sigue a continuaci�n es asa, como la palabra se encuentra 3
veces, por lo tanto itera 3 veces asa 3*3=9.

*/
