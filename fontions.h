#ifndef FONTIONS
#define FONTIONS
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdarg>
#include <string>
#include <sstream>

long long convertion(const char * chaine);
long num_piece_of(long long &somme, long piece);
void load_piece();
size_t num_piece(void);
long get_piece(size_t i);
std::string cat_many(int nbCh, ...);
std::string get_type();
template < typename T> std::string to_str(T nombre){
    std::stringstream strs;
    strs << nombre;
    std::string g(strs.str().c_str());
    return g;
};
#endif // FONTIONS

