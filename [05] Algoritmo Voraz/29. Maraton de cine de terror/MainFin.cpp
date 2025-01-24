
// CÉSAR CARLOS RUBIO PASTOR
// EJERCICIO: Maraton de cine de terror

#include <iostream>

#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


// Con un struct y guardando minuto en el que empieza y minuto en el que termina podemos resolver y ordenar.
struct Pelicula {
    int inicio; //Minuto en del dia en el que empieza
    int fin;    //Minuto en del dia en el que termina
};

int maxPeliculasPosibles(const vector<Pelicula>& p) {
    int nMaxPeliculas = 0;



    return nMaxPeliculas;
}

bool resuelveCaso() {

    //Leer caso de prueba: cin>>...

    int nPelis;
    vector<Pelicula> peliculas;


    if (!(std::cin >> nPelis))
        return false;
    if (nPelis == 0)
        return false;
    
    for (int i = 0; i < nPelis; i++) {

        //Parseo de la hora y duracion para que sea más fácil de operar

        string horaInicio;
        int duracion;

        cin >> horaInicio >> duracion;

        int h = stoi(horaInicio.substr(0, 2));
        int m = stoi(horaInicio.substr(3, 2));

        Pelicula p;
        p.inicio = h * 60 + m;
        p.fin = p.inicio + duracion + 10; // + los 10 minutos entre películas.

        peliculas.push_back(p);

    }

    sort(peliculas.begin(), peliculas.end(), [](const Pelicula& a, const Pelicula& b) {
        return a.fin < b.fin;
        });


    maxPeliculasPosibles(peliculas);



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
