#include "enrutador.h"
#include <fstream>
#include <array>

Enrutador::Enrutador(list<string> cdirecta,list<int> costos)
{
    list<string>::iterator it;
    list<int>::iterator it2;

    it=cdirecta.begin();
    it2=costos.begin();

    while(it!=cdirecta.end() and it2!=costos.end()){
        RutaDirecta[*it]=*it2;
        it++;
        it2++;
    }

 }
map<string,int> Enrutador::GetTablaRutaDirecta(){

    return RutaDirecta;
}

map<string,int> Enrutador::TablaDeEnrtActualizada(list<string> conexiones,list<int> costos){

    list<string>::iterator it;
    list<int>::iterator it2;
    string ultima,ultima2,ultima3,cadena,cadm;
    int longitud,menor=999,cont=1;

    it=conexiones.begin();
    it2=costos.begin();
    cadena=*it;
    longitud=cadena.size();
    ultima2=cadena[longitud-1];

    while(it!=conexiones.end() and it2!=costos.end()){
        cadena=*it;
        longitud=cadena.size();
        ultima=cadena[longitud-1];
        if(ultima==ultima2){
            if(cont==1){
                for(auto iterador=RutaDirecta.begin();iterador!=RutaDirecta.end();++iterador){
                    ultima3=iterador->first;
                    ultima3=ultima3[1];
                    if(ultima2==ultima3){
                        menor=iterador->second;
                        cadm=iterador->first;
                        cont=0;
                    }
                }
            }
            if(*it2<menor){
                menor=*it2;
                cadm=*it;
            }
            it++;
            it2++;

        }
        else{
            ultima2=ultima;
            cont=1;
            TablaDeEnrutamiento[cadm]=menor;
            menor=999;
            cadm="";
        }
    }
    TablaDeEnrutamiento[cadm]=menor;

    return TablaDeEnrutamiento;
}
