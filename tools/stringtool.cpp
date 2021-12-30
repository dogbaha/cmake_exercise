
#include "stringtool.h"
#include <cstdio>
#include <iostream>
// #include <iostream>


void readLine(char * result,int size){
    // std::gets(result);
    std::cin.getline(result,size,'\n');
    // return result;
}

void myprintf(const char * str){
    std::cout<<str<<std::endl<<"by self define log"<<std::endl;
}