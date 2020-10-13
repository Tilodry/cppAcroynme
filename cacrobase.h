#ifndef CACROBASE_H
#define CACROBASE_H

#include "cdef.h"
#include <string>
using namespace std;

class CAcrobase {

    public:
        virtual string acro() const = 0;
        virtual int size() const = 0;
        virtual CDef& def(int index) = 0;
        virtual void addDef(const CDef& def)= 0;
};

#endif