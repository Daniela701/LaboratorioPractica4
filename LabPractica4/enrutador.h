#ifndef ENRUTADOR_H
#define ENRUTADOR_H
#include <iostream>
#include <map>
#include <list>
using namespace std;


class Enrutador
{
private:
    //contenedores
    map<string,int> RutaDirecta, TablaDeEnrutamiento;
public:
    Enrutador(list<string>,list<int>);
    map<string,int> GetTablaRutaDirecta();
    map<string,int> TablaDeEnrtActualizada(list<string>,list<int>);

};

#endif // ENRUTADOR_H
