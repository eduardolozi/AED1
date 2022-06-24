#include <stdio.h>
#include <stdlib.h>
#include "tad.h"

int main() {
    No pessoa;

    init(&pessoa);
    /*
    insereNome(&pessoa, "Camila Suares");
    insereNome(&pessoa, "Ernesto Valverde");
    insereNome(&pessoa, "Leo Messi");
    insereNome(&pessoa, "Andres Iniesta");
    */

    insereNome(&pessoa, "Ter Stegen");
    insereNome(&pessoa, "Jordi Alba");
    insereNome(&pessoa, "Daniel Alves");
    insereNome(&pessoa, "Pique");
    insereNome(&pessoa, "Ronald Araujo");
    insereNome(&pessoa, "Busquets");
    insereNome(&pessoa, "Pedri");
    insereNome(&pessoa, "Frenkie De Jong");
    insereNome(&pessoa, "Dembele");
    insereNome(&pessoa, "Aubameyang");
    insereNome(&pessoa, "Ferran Torres");
    insereNome(&pessoa, "Luva de Pedreiro");

    selectionSort(&pessoa);
    //insertionSort(&pessoa);

    imprimeLista(pessoa);

    return 0;
}