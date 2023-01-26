/*
author          Oliver Blaser
date            26.01.2023
copyright       -
*/

#include <iostream>

#include "xmlsec/verify1.h"

#ifdef WIN32
#include <Windows.h>
#endif


#define USE_XMLSEC_VERIFY1          (1)
#define USE_XMLSEC_VERIFY2          (0)

#if ((USE_XMLSEC_VERIFY1 + USE_XMLSEC_VERIFY2) != 1)
#error "compile switch error"
#endif


using std::cout;
using std::endl;

namespace
{
}


int main(int argc, char** argv)
{
    int r = 0;

#if defined(_DEBUG)
    if (argc == 1)
    {
        const char* const binName = argv[0];
        const char* const dbg_argv[] = { binName,

#if USE_XMLSEC_VERIFY1 || USE_XMLSEC_VERIFY2
            //"../../testFiles/xmlsec/sign1-res.xml",
            "../../testFiles/xmlsec/sign2-res.xml",

            "../../testFiles/xmlsec/rsapub.pem"
#elif USE_XMLSEC_VERIFY3
#endif
        };

        argc = (sizeof(dbg_argv) / sizeof(dbg_argv[0]));
        argv = (char**)dbg_argv;
    }
#endif



#if USE_XMLSEC_VERIFY1
    r = verify1_main(argc, argv);
#elif USE_XMLSEC_VERIFY2
#error "not implemented"
#endif



#if defined(_DEBUG) && 1
    cout << /*omw::foreColor(26) <<*/ "===============\nreturn " << r << "\npress enter..." << /*omw::normal <<*/ endl;
    int dbg___getc_ = getc(stdin);
#endif

    return r;
}
