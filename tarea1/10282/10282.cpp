#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <iterator>
using namespace std;

int main(){
    string linea;
    map<string, string> diccionario;
    map<string, string>::iterator itr;
    while(getline(cin, linea)){
        //bloque de busqueda de palabras
        if(linea == ""){
            while(getline(cin, linea)){
                itr = diccionario.find(linea);
                if(itr == diccionario.end()){
                    cout << "eh" << endl;
                }
                else{
                    cout << itr -> second << endl;
                }
        }
        //bloque de llenado del diccionario
        string palabra_ingles = linea.substr(0, linea.find(" "));
        int size = palabra_ingles.size();
        string palabra_foranea = linea.substr((size+1), linea.find("\n"));
        diccionario[palabra_foranea] = palabra_ingles;
    }
    return 0;
}
