
// CÉSAR CARLOS RUBIO PASTOR
// EJERCICIO: 28. Nos Invaden!

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;


/*
* Desarrollo de la idea: tras leer ambos lados, se ordenan de mayor a menor y se va recorriendo la lista, de forma que el mayor de los de la defensa se enfrenta al mayor invasor
*   *contra el que pueda ganar*, y así. Porque si no le puede ganar él, no lo puede ganar ninguno más pequeño.
*   
*/

int defensaCiudades(const vector<int> invasores, const vector<int> defensores){
    int ciudadesDefendidas = 0;
    
    //Ordenación de los vectores 

    

    int ejerDef = 0;
    int ejerInv = 0;

    //Mientras no haya ejercito invasor más pequeño que defensor, avanzo en el vector de invasores
    while (ejerDef < defensores.size() && ejerInv < invasores.size()) { //Coste O(N) donde N es el nº de ciudades total. Porque en cada iteración (N - ejerInv) decrece.
        if (invasores[ejerInv] <= defensores[ejerDef]){
            ejerDef++;
            ciudadesDefendidas++;
        }
        ejerInv++;
    }

    return ciudadesDefendidas;
}

bool resuelveCaso() {
    
    int numCiudades;

    if (!(std::cin >> numCiudades))
        return false;

    vector<int> invasores, defensores;

    for (int i = 0; i < numCiudades; i++) {
        int invasor;
        std::cin >> invasor;
        invasores.push_back(invasor);
    }

    for (int i = 0; i < numCiudades; i++) {
        int defensor;
        std::cin >> defensor;
        defensores.push_back(defensor);
    }

    std::sort(invasores.begin(), invasores.end(), greater<int>()); //O(n logn) donde n es la cantidad de ciudades/invasores
    std::sort(defensores.begin(), defensores.end(), greater<int>()); //O(n logn) donde n es la cantidad de ciudades/defensores


    cout << defensaCiudades(invasores, defensores) << '\n';



    //Resolver problema
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
