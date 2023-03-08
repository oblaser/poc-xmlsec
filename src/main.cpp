/*
author          Oliver Blaser
date            26.01.2023
copyright       -
*/

#include <iostream>

#include "xmlsec/verify1.h"
#include "xmlsec/verify2.h"
#include "xmlsec/verify3.h"
#include "xmlsec/verify4.h"

#ifdef WIN32
#include <Windows.h>
#endif


#define USE_XMLSEC_VERIFY1          (0)
#define USE_XMLSEC_VERIFY2          (1)
#define USE_XMLSEC_VERIFY3          (0)
#define USE_XMLSEC_VERIFY4          (0)

#if ((USE_XMLSEC_VERIFY1 + USE_XMLSEC_VERIFY2 + USE_XMLSEC_VERIFY3 + USE_XMLSEC_VERIFY4) != 1)
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
            "../../testFiles/xmlsec/sign1-res.xml",
            //"../../testFiles/xmlsec/sign1-res_with_public-key.xml",
            //"../../testFiles/xmlsec/sign2-res.xml",
            //"../../testFiles/xmlsec/sign2-res_with_public-key.xml",
            //"../../testFiles/xml-01_signed.xml",
            //"../../testFiles/xml-01_signed_with_public-key.xml",

            "../../testFiles/xmlsec/rsapub.pem"
            //"../../testFiles/rsapub.pem"
#elif USE_XMLSEC_VERIFY3 || USE_XMLSEC_VERIFY4
            //"../../testFiles/xmlsec/sign3-res.xml",
            "../../testFiles/xmlsec/verify4-res.xml",
            //"../../testFiles/xmlsec/verify4-bad-res.xml",
            //"../../testFiles/xml-01_signed.xml",
            //"../../testFiles/xml-01_signed_with_public-key.xml",

            "../../testFiles/xmlsec/ca2cert.pem",
            "../../testFiles/xmlsec/cacert.pem",
            //"../../testFiles/rsacert.pem"
#endif
        };

        argc = (sizeof(dbg_argv) / sizeof(dbg_argv[0]));
        argv = (char**)dbg_argv;
    }
#endif


    for (int i = 0; i < argc; ++i)
    {
        cout << "arg " << (((argc > 9) && (i < 10)) ? " " : "") << i << "    " << argv[i] << endl;
    }
    cout << "==================================" << endl;


#if USE_XMLSEC_VERIFY1
    r = verify1_main(argc, argv);
#elif USE_XMLSEC_VERIFY2
    r = verify2_main(argc, argv);
#elif USE_XMLSEC_VERIFY3
    r = verify3_main(argc, argv);
#elif USE_XMLSEC_VERIFY4
    r = verify4_main(argc, argv);
#endif



#if defined(_DEBUG) && 1
    cout << /*omw::foreColor(26) <<*/ "===============\nreturn " << r << "\npress enter..." << /*omw::normal <<*/ endl;
    //int dbg___getc_ = getc(stdin);
#endif

    return r;
}
