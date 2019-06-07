#include "fontions.h"
std::vector<long> listPiece;
std::string type("Frcfa");
void load_piece(){
listPiece.push_back(1);
listPiece.push_back(5);
listPiece.push_back(10);
listPiece.push_back(15);
listPiece.push_back(25);
listPiece.push_back(50);
listPiece.push_back(100);
listPiece.push_back(500);
}

std::string get_type(){
    return ::type;
}
size_t num_piece(){
   return  ::listPiece.size();
}
long get_piece(size_t i){
    return ::listPiece[i];
}
void set_piece(size_t i, long val){
    ::listPiece[i] = val;
}

long num_piece_of(long long &somme, long piece){
    long nb = 0;
    while (piece <= somme) {
       nb++;
       somme-= piece;
    }
    return nb;

}
long long convertion(const char * chaine)
{
    unsigned i = 0;
    long long nombre = 0;

    while(chaine[i] != '\0'){
        if( chaine[i] > 47 && chaine[i] <  59){

            nombre =  nombre*10 +  chaine[i] - 48;

        }else{
            return -1;
        }
        i++;
    }
    return nombre ;
}
