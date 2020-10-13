#include "cdef.h"
#include <iostream>
using namespace std;
int main()
{
    CDef test;
    test.setDef("LOLOLOLOLOL");
    test.setLang(1);
    cout << test.getDef() << " || " << test.getLang() << endl;
    CDef test2(test);
    CDef test3 = test;
    cout << test2.getDef() << " || " << test2.getLang() << endl;
    cout << test3.getDef() << " || " << test3.getLang() << endl;        
    return 0;
}