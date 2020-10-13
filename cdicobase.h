#ifndef CDICOBASE_H
#define CDICOBASE_H

#include "cdef.h" // cacro.h non inclus car on utilise pas ses méthodes
#include <iostream>
#include <fstream>
using namespace std;

class CAcro;

class CDicobase {
    private:
        string path;
        fstream stream; // l'attribut stream représente le flux de données
        // entre le fichier et le programme

    public:
        CDicobase(const string& path =0){ // le constructeur reçoit le chemin du fichier
            this->path = path;
            stream.open(this->path.c_str(),ios::in); // il ouvre le fichier à l'emplacement
        }

        virtual ~CDicobase() {
            if(stream) stream.close();
        }

        bool isOpen() const { return stream.is_open();} // verifier si le fichier est ouvert
        bool load() { // charger le fichier
            if ( !isOpen()) return false;

            string line, acro;

            while( getline(stream, line) ) {
                size_t pos = line.rfind('\r');
                if( pos != string::npos) {
                    line.replace(pos,1,"\0");
                }
                if(line[0] == '*') {
                    line.erase(0,1);
                    acro = line;
                }
                if(line[0] == '+') {
                    int cod = line[1] - '0';
                    line.erase(0,3);
                    addDef(acro, CDef(line, cod));
                    //cerr << "line.erase -> addDef() " << line << endl;
                    //cerr << "lecture def " << acro << endl;
                }
            }
            return true;
        }

        virtual int size() const = 0; // taille du fichier 
        virtual CAcro& acro(int index) = 0; // choisis acronyme
        virtual void addDef(string acro, const CDef& cdef) = 0; // ajouter def
        virtual void sort() = 0;  // trier
};

#endif