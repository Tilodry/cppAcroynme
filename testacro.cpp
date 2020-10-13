#include "cacro.h"
#include <iostream>
using namespace std;
int main()
{
    CAcro acronyme;
    CDef def_acronyme("Société Nationale des Chemins de fer français",1);

    cout << "(acronyme) défaut: " << acronyme.acro() << endl;
    cout << "(acronyme) nombre de définition: " << acronyme.size() << endl;
    cout << "Ajout d'un acronyme et d'une définiton dans (acronyme)" << endl;
    acronyme.setAcro("SNCF");
    acronyme.addDef(def_acronyme);
    cout << "(acronyme :" << acronyme.getAcro() <<") définition[0] : " << acronyme.def(0).getAll() << endl;
    cout << "(acronyme) nouveau nombre de définition: " << acronyme.size() << endl;
    cout << "Création d'un nouvel objet (acronyme2) copie de (acronyme)" << endl;
    CAcro acronyme2(acronyme);
    cout << "(acronyme :" << acronyme.getAcro() <<") définition[0] : " << acronyme2.def(0).getAll() << endl;
    cout << "(acronyme4) nouveau nombre de définition: " << acronyme2.size() << endl;

    return 0;
} 