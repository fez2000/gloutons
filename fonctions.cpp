#include "fontions.h"
std::vector<long> listPiece;
std::string type;
void load_config(){
    std::ifstream userParam("userConfig.txt");
    if(userParam){
        char t[500];
        userParam.getline(t,500);
        ::type.append(t);
        int a;
        while (userParam >> a) {
            listPiece.push_back(a);
        }
    }else{
        reset_config();
    }

}
void reset_config(){
    std::ofstream userParam("userConfig.txt");
    userParam << "Francfa"<<std::endl<<"1"<<std::endl<<"5"<<std::endl<<"10"<<std::endl<<"15"<<std::endl<<"25"<<std::endl<<"50"<<std::endl<<"100";
    ::listPiece.clear();
    ::type.clear();
    userParam.close();
    load_config();
}
std::string get_type(){
    return ::type;
}
std::string to_str_p(){
    int i = ::listPiece.size(), j =0;
    std::string p;
    while (j < i) {
        p += std::string(" ") + to_str(listPiece[j]);
       j++;
    }
    return p;
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
