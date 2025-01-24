
// CÉSAR CARLOS RUBIO PASTOR
// EJERCICIO: Árboles Libres

#include <iostream>
#include "Grafo.h"
#include <queue>
#include <fstream>
using namespace std;



/*
* Para ver si es un arbol libre, tenemos que mirar que todo par de vértices estén conectados por un solo camino. 
* Para ello, una forma óptima podría ser recorrer el grafo en profundidad, de forma que cada vez que se llegue a un vértice, 
* este se marque y si se vuelve a llegar, ya devuelva false.
*/
bool esLibre(Grafo grafo) {

}

bool resuelveCaso() {

    if (!std::cin)
        return false;
    
    int V;
    int A;

    cin >> V;
    cin >> A;

    Grafo grafo(V); //Inicializa el grafo
        
    for (int i = 0; i < A; i++) { //Construye el grafo
        int a1, a2;
        cin >> a1;  cin >> a2;

        grafo.ponArista(a1, a2);
    }

    //Resuelve el problema
    esLibre(grafo) ? cout << "SI" << endl : cout << "NO" << endl;
        
    //Escribir resultado
    return true;
}


int main() {

    // ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // restablecimiento de cin
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("pause");
#endif
    return 0;
}
