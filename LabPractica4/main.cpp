#include <iostream>
#include "redes.h"
#include <stdlib.h>

using namespace std;

int main()
{
    int op;
    string archivo;
    cout<<"**********************"<<endl;
    cout<<"* Bienvenido Usuario *"<<endl;
    cout<<"**********************"<<endl;
    cout<<"Elija una de las siguientes opciones (Digite el numero correspondiente): "<<endl;
    cout<<"1. Crear su propia red (manualmente)"<<endl;
    cout<<"2. Cargar una tipologia de red desde un archivo"<<endl;
    cout<<"3. Salir"<<endl;
    cin>>op;

    if (op==1){
        Redes mired;
        mired.CargarEnrutadores();
    }
    else if(op==2){
        system("CLS");
        cout<<"Por favor digite el nombre del archivo a cargar"<<endl;
        cout<<"(Verifique que el archivo se encuentre en la carpeta Redes)"<<endl;
        cin>>archivo;
        Redes red1(archivo);
        red1.CargarEnrutadores();
    }
    else if(op==3){
        system("CLS");
        cout<<"Saliendo..."<<endl;
    }
    else{
        cout<<"Digito un numero o caracter incorrecto"<<endl;
    }

    return 0;
}
