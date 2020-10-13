#ifndef CDEF_H
#define CDEF_H

#include <string>
using namespace std;

class CDef {
    static string c1[];
    string m_def;
    int m_lang;

    public :
        CDef() {}
        CDef(const string& def,int langue =0){
            this->m_def = def;
            this->m_lang = langue;
        }
        CDef(const CDef& cdef){
            this->m_def = cdef.m_def;
            this->m_lang = cdef.m_lang;
        } // copie
        ~CDef() {
        }

        string getDef() const { return this->m_def;}
        int getLang() const { return this->m_lang;}
        void setDef(string def) { this->m_def = def;}
        void setLang(int lang){ this->m_lang = lang;}
        string getAll() {
            string all = m_def + " | " + c1[m_lang];
            return all;
        }

        static string CodLang(int langue) {
            int i = 0;
            while(!c1[i].empty()) {
                if ( i == langue) return c1[i];
                i++;
            }
            return c1[i];
        }
};

string CDef::c1[] = { "EN", "FR", "DE", "SP", "IT", "JP", "RU", ""};
#endif