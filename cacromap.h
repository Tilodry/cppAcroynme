#ifndef CACRO_H
#define CACRO_H

#include "cacrobase.h"
#include <map>

class CDef;

class CAcro : public CAcrobase {
    private:
        string m_acron;
        multimap<int,string> liste;
        CDef temp;
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
            multimap<int,string>::iterator i = liste.find(index);
            temp.setDef(i->second);
            temp.setLang(i->first);
            return temp;
        }
        virtual void addDef(const CDef& def){
            liste.insert( pair<int,string>(def.getLang(), def.getDef()) );
        };
};
#endif