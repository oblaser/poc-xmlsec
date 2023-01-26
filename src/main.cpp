/*
author          Oliver Blaser
date            26.01.2023
copyright       -
*/

#include <iostream>

#ifdef WIN32
#include <Windows.h>
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
        const char* const dbg_argv[] = { (argc >= 1 ? argv[0] : ""), // bin name

            // XML file
            "../testFiles/sign1-res.xml",
            //"../testFiles/sign2-res.xml",

            // key file
            "../testFiles/rsapub.pem"
        };

        argc = (sizeof(dbg_argv) / sizeof(dbg_argv[0]));
        argv = (char**)dbg_argv;
    }
#endif


    for (int i = 0; i < argc; ++i)
    {
        cout << argv[i] << endl;
    }


#if defined(_DEBUG) && 1
    cout << /*omw::foreColor(26) <<*/ "===============\nreturn " << r << "\npress enter..." << /*omw::normal <<*/ endl;
    int dbg___getc_ = getc(stdin);
#endif

    return r;
}
