#ifndef REDES_H
#define REDES_H
#include <iostream>
#include <map>
#include <list>
using namespace std;


class Redes
{
private:
    //contenedores
    map<string,int> vacio;
    list<string> enrutadores,nombres,e,vacioS,TEe;
    list<int> costos,c,vacioI,TEc;
    string file;
public:
    Redes();
    Redes(string);
    void CargarEnrutadores();
    bool CargarRutasDirectas(string);
    void CalcularRutas(string);
    void AgregarEnrutadores();
    void RemoverEnrutadores();
    void CamEnlacesyCostos();
};

#endif // REDES_H
