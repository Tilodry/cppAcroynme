#ifndef CDICO_H
#define CDICO_H


#include "cdicobase.h"
#include "cacro.h"

using namespace std;
#include <vector>
#include <algorithm>
#include <functional>

class CDef;


class CDico: public CDicobase {
    private:
        vector<CAcro> acronyms;
    public:
        static CAcro search;
        static bool isKnown(CAcro& arg);

        CDico(const string& path) : CDicobase(path) {}
        
        virtual int size() const {
            return this->acronyms.size();
        }
        virtual CAcro& acro(int index) {
            vector<CAcro>::iterator i = acronyms.begin();
            if( index > this->size() )
            {
                return acronyms.back();
            }
            advance(i, index);
            return *i;
        }
        virtual void addDef(string acro, const CDef& cdef){
            vector<CAcro>::iterator i;
            CDico::search = acro;
            i = find_if(acronyms.begin(),acronyms.end(),CDico::isKnown);    
            if( i != acronyms.end()) i->addDef(cdef);
            else {
                acronyms.push_back( CAcro(acro));
                acronyms.back().addDef(cdef);
            }
        }

        virtual void sort() {
            std::sort(acronyms.begin(),acronyms.end(), [](CAcro &s1, CAcro &s2)
            {
                return s1.getAcro() < s2.getAcro();
            });
        }   
};

CAcro CDico::search = CAcro();

bool CDico::isKnown(CAcro& arg) {
    return arg.acro() == CDico::search.acro();
}

#endif