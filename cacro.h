#ifndef CACRO_H
#define CACRO_H

#include "cacrobase.h"
#include <list>

class CDef;

class CAcro : public CAcrobase {
    private:
        string m_acron;
        list<CDef> liste;
    public:
        CAcro() : m_acron("?") {}
        CAcro(string acron) { this->m_acron = acron;}
        CAcro(const CAcro& cn) { 
            this->m_acron = cn.m_acron;
            this->liste = cn.liste;
        }

        string getAcro() { return this->m_acron; }
        void setAcro(string acron) { this->m_acron = acron;}

        virtual string acro() const {
            return this->m_acron;
        }
        virtual int size() const {
            return liste.size();
        }
        virtual CDef& def(int index) {
            list<CDef>::iterator i = liste.begin();
            if( index > this->size() ) // si la liste n'est pas assez grande on lit le dernier
            {
                return liste.back();
            }
            advance(i,index);
            return *i;
        }
        virtual void addDef(const CDef& def){
            liste.push_back(def);
        };
};
#endif