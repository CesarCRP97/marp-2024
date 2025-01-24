
// CÉSAR CARLOS RUBIO PASTOR
// EJERCICIO: Agujeros en la Manguera

#include <iostream>
#include <list>
#include <fstream>
using namespace std;


//El algoritmo es: se pone la cinta en la posición del primer agujero que haya sin tapar y se incrementa la cantidad de cintas. Después, 
// se calcula posición + longitud, los agujeros que estén antes de esa posición se saltan.
int minCinta(int longitud, list<int> agujeros) {
    int nCintas = 0;


    //En el peor de los casos (cada cinta tapa un agujero) este bucle dará tantas iteraciones como agujeros. 
    // Pero siempre se harán, entre el bucle interno y este las mismas iteraciones
    while (agujeros.size() > 0) { //Si no hay agujeros ->  no entra y nCintas = 0;
        nCintas++;

        //finCinta es la posición de la manguera en la que acaba el trozo de cinta
        int finCinta = agujeros.front() + longitud;

        while (!agujeros.empty() && agujeros.front() <= finCinta) //Este bucle va vaciando la lista, por lo que cada vez es más pequeña hasta que size == 0.
            agujeros.pop_front();

    }

    return nCintas;
}

bool resuelveCaso() {

    // La representación del problema va a ser una lista con los agujeros ordenados (respecto al inicio de la manguera).
    int numagujeros, longitud;
    
    if (!(cin >> numagujeros >> longitud))
        return false;
    
    list<int> agujeros;


    for (int i = 0; i < numagujeros; i++) {
        int posagujero;
        cin >> posagujero;
        agujeros.push_back(posagujero);
    }

    //Escribe el resultado
    cout << minCinta(longitud, agujeros) << "\n";    
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
