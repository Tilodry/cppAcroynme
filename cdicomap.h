#ifndef CDICO_H
#define CDICO_H


#include "cdicobase.h"
#include "cacromap.h"

using namespace std;
#include <map>
#include <algorithm>
#include <functional>

class CDef;


class CDico: public CDicobase {
    private:
        map<string,CAcro> acronyms;
        CAcro temp;
    public:
        static CAcro search;
        static bool isKnown(CAcro& arg);

        CDico(const string& path) : CDicobase(path) {}
        
        virtual int size() const {
            return this->acronyms.size();
        }
        virtual CAcro& acro(int index) {   
            map<string,CAcro>::iterator i = acronyms.begin();
            advance(i,index);
            return i->second;
        }
        virtual void addDef(string acro, const CDef& cdef){
            map<string,CAcro>::iterator i;
            CDico::search = acro;
            i = find_if(acronyms.begin(),acronyms.end(),CDico::isKnown);    
            if( i != acronyms.end()) acronyms.insert(pair<string,CAcro>(acro, cdef);
            else {
                this->temp.setAcro(acro);
                this->temp.setDef(cdef);
                
            }
        }
        virtual void sort() {};
        /*virtual void sort() {
            std::sort(acronyms.begin(),acronyms.end(), [](CAcro &s1, CAcro &s2)
            {
                return s1.getAcro() < s2.getAcro();
            });
        }   */
};

CAcro CDico::search = CAcro();

bool CDico::isKnown(CAcro& arg) {
    return arg.acro() == CDico::search.acro();
}

#endif