#include <iostream>
#include "cTestConfig.h"
#ifdef USE_LOG
    #include "stringtool.h"
#endif

void outChar(const char * str){
    #ifdef USE_LOG
        myprintf(str);
    #else
        printf(str);
    #endif
}

int main(int argc,char ** argv){

    std::cout<<argv[0]<< " Version " << cTest_version_major << "." << cTest_version_minor << "\n" ;
    if(argc<2){
        outChar(argv[0]);
        outChar("\t number");
        return 0;
    }
    outChar("you input is ");
    outChar(argv[1]);
    return 0;
}