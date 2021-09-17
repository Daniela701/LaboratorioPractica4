#include "redes.h"
#include "enrutador.h"
#include <fstream>
#include <array>
#include <stdlib.h>

Redes::Redes()
{
    list<string>::iterator it;
    bool pass, pass2;
    string conexiones,enrut,letra;
    int cont,cost,t,longi;

    cout<<"Nombre los enrutadores con una sola letra de la A-G (Solo Mayusculas)"<<endl;
    cout<<"Ahora ingrese las conexiones directas (<Enrutador Origen> <Enrutador Destino>, costo) (Ej:AB,7):"<<endl;
    cout<<"Digite el numero 0 cuando ya no quiera digitar mas conexiones"<<endl;
    cout<<"Primera conexion:"<<endl;
    cin>>conexiones;
    longi=conexiones.size();
    letra=conexiones[0];
    nombres.push_back(letra);

    while(conexiones!="0"){

        enrut="";
        pass=false;
        pass2=false;
        cont=0;
        cost=0;

        if(letra[0]!=conexiones[0]){
            letra=conexiones[0];
            it=nombres.begin();
            while(it!=nombres.end()){
                if(letra==*it){
                    pass2=true;
                    break;
                }
                it++;
            }
            if(pass2==false){
                nombres.push_back(letra);
            }
        }

        for(int i=0; i<longi;i++){
            if(conexiones[i]==','){
                pass=true;
                i++;
            }
            if (pass){
                if(cont>0){
                    cost*=10;
                    t=conexiones[i];
                    t-=48;
                    cost+=t;
                }
                else{
                    cost=conexiones[i];
                    cost-=48;
                }
                cont++;
            }
            else{
               enrut+=conexiones[i];
            }
        }
        enrutadores.push_back(enrut);
        costos.push_back(cost);

        cout<<"Digite el siguiente"<<endl;
        cin>>conexiones;
        longi=conexiones.size();

    }
}

Redes::Redes(string namef){

    file=namef;
    ifstream read;
    list<string>::iterator it;
    bool pass,pass2;
    string conexiones,enrut,letra;
    int cont,cost,t,longi;

    read.open("../LabPractica4/Redes/"+file+".txt");
    if (!read.is_open()){ //verificamos si se pudo abrir
        cout<<"Error al abrir el archivo..."<<endl;
        exit(1);
    }
    system("CLS");
    cout<<"Archivo leido"<<endl;
    read>>conexiones;
    longi=conexiones.size();
    letra=conexiones[0];
    nombres.push_back(letra);

    while(!read.eof()){

        enrut="";
        pass=false;
        pass2=false;
        cont=0;
        cost=0;

        if(letra[0]!=conexiones[0]){
            letra=conexiones[0];
            it=nombres.begin();
            while(it!=nombres.end()){
                if(letra==*it){
                    pass2=true;
                    break;
                }
                it++;
            }
            if(pass2==false){
                nombres.push_back(letra);
            }
        }

        for(int i=0; i<longi;i++){
            if(conexiones[i]==','){
                pass=true;
                i++;
            }
            if (pass){
                if(cont>0){
                    cost*=10;
                    t=conexiones[i];
                    t-=48;
                    cost+=t;
                }
                else{
                    cost=conexiones[i];
                    cost-=48;
                }
                cont++;
            }
            else{
               enrut+=conexiones[i];
            }
        }
        enrutadores.push_back(enrut);
        costos.push_back(cost);
        read>>conexiones;
        longi=conexiones.size();
    }
}

void Redes::CargarEnrutadores(){

    string op="",enrt="";
    while(op!="0"){
        map<string,int> RutaDirectaA,RutaDirectaB,RutaDirectaC,RutaDirectaD,RutaDirectaE,RutaDirectaF,RutaDirectaG;
        map<string,int> TeA,TeB,TeC,TeD,TeE,TeF,TeG;
        bool pass=false;

        pass=CargarRutasDirectas("A");

        if(pass){
            CalcularRutas("A");
            Enrutador A(e,c);
            RutaDirectaA=A.GetTablaRutaDirecta();
            TeA=A.TablaDeEnrtActualizada(TEe,TEc);

        }
        e=vacioS;
        c=vacioI;
        TEe=vacioS;
        TEc=vacioI;

        pass=CargarRutasDirectas("B");

        if(pass){
            CalcularRutas("B");
            Enrutador B(e,c);
            RutaDirectaB=B.GetTablaRutaDirecta();
            TeB=B.TablaDeEnrtActualizada(TEe,TEc);

        }
        e=vacioS;
        c=vacioI;
        TEe=vacioS;
        TEc=vacioI;

        pass=CargarRutasDirectas("C");

        if(pass){
            CalcularRutas("C");
            Enrutador C(e,c);
            RutaDirectaC=C.GetTablaRutaDirecta();
            TeC=C.TablaDeEnrtActualizada(TEe,TEc);
        }

        e=vacioS;
        c=vacioI;
        TEe=vacioS;
        TEc=vacioI;

        pass=CargarRutasDirectas("D");

        if(pass){
            CalcularRutas("D");
            Enrutador D(e,c);
            RutaDirectaD=D.GetTablaRutaDirecta();
            TeD=D.TablaDeEnrtActualizada(TEe,TEc);
        }

        e=vacioS;
        c=vacioI;
        TEe=vacioS;
        TEc=vacioI;

        pass=CargarRutasDirectas("E");

        if(pass){
            CalcularRutas("E");
            Enrutador E(e,c);
            RutaDirectaE=E.GetTablaRutaDirecta();
            TeE=E.TablaDeEnrtActualizada(TEe,TEc);
        }

        e=vacioS;
        c=vacioI;
        TEe=vacioS;
        TEc=vacioI;

        pass=CargarRutasDirectas("F");

        if(pass){
            CalcularRutas("F");
            Enrutador F(e,c);
            RutaDirectaF=F.GetTablaRutaDirecta();
            TeF=F.TablaDeEnrtActualizada(TEe,TEc);
        }

        e=vacioS;
        c=vacioI;
        TEe=vacioS;
        TEc=vacioI;

        pass=CargarRutasDirectas("G");

        if(pass){
            CalcularRutas("G");
            Enrutador G(e,c);
            RutaDirectaG=G.GetTablaRutaDirecta();
            TeG=G.TablaDeEnrtActualizada(TEe,TEc);
        }

        cout<<"Elija una de las siguientes opciones:"<<endl;
        cout<<"0. Salir"<<endl;
        cout<<"1. Agregar enrutadores (si aun no se ha excedio del limite de 7 enrutadores)"<<endl;
        cout<<"2. Remover enrutadores"<<endl;
        cout<<"3. Cambiar enlaces y costos"<<endl;
        cout<<"4. Mostrar tabla de enrutamiento (caminos con los costos minimos)"<<endl;
        cout<<"5. Mostrar tabla de conexiones directas vs tabla de enrutamiento"<<endl;
        cin>>op;

        if(op=="1"){
            AgregarEnrutadores();
        }
        else if(op=="2"){
            RemoverEnrutadores();
        }
        else if(op=="3"){
            CamEnlacesyCostos();
        }
        else if(op=="4"){
            cout<<"Escriba el nombre del enrutador del cual desea ver la tabla de enrutamiento"<<endl;
            cin>>enrt;

            if(enrt=="A"){
                for(auto iterador=TeA.begin(); iterador!=TeA.end(); ++iterador){
                    cout<<iterador->first<<" , "<<iterador->second<<endl;
                }
            }
            else if(enrt=="B"){
                for(auto iterador=TeB.begin(); iterador!=TeB.end(); ++iterador){
                    cout<<iterador->first<<" , "<<iterador->second<<endl;
                }
            }
            else if(enrt=="C"){
                for(auto iterador=TeC.begin(); iterador!=TeC.end(); ++iterador){
                    cout<<iterador->first<<" , "<<iterador->second<<endl;
                }
            }
            else if(enrt=="D"){
                for(auto iterador=TeD.begin(); iterador!=TeD.end(); ++iterador){
                    cout<<iterador->first<<" , "<<iterador->second<<endl;
                }
            }
            else if(enrt=="E"){
                for(auto iterador=TeE.begin(); iterador!=TeE.end(); ++iterador){
                    cout<<iterador->first<<" , "<<iterador->second<<endl;
                }
            }
            else if(enrt=="F"){
                for(auto iterador=TeF.begin(); iterador!=TeF.end(); ++iterador){
                    cout<<iterador->first<<" , "<<iterador->second<<endl;
                }
            }
            else if(enrt=="G"){
                for(auto iterador=TeG.begin(); iterador!=TeG.end(); ++iterador){
                    cout<<iterador->first<<" , "<<iterador->second<<endl;
                }
            }
            else{
                cout<<"Digito el nombre de un enrutador no existente"<<endl;
            }
        }
        else if(op=="5"){
            cout<<"Escriba el nombre del enrutador del cual desea ver la tabla de conexiones directas vs tabla de enrutamiento "<<endl;
            cin>>enrt;

            if(enrt=="A"){
                for(auto iterador=RutaDirectaA.begin(); iterador!=RutaDirectaA.end(); ++iterador){
                    cout<<iterador->first<<" , "<<iterador->second<<endl;
                }
                cout<<"*********************************"<<endl;
                for(auto iterador=TeA.begin(); iterador!=TeA.end(); ++iterador){
                    cout<<iterador->first<<" , "<<iterador->second<<endl;
                }
            }
            else if(enrt=="B"){
                for(auto iterador=RutaDirectaB.begin(); iterador!=RutaDirectaB.end(); ++iterador){
                    cout<<iterador->first<<" , "<<iterador->second<<endl;
                }
                cout<<"*********************************"<<endl;
                for(auto iterador=TeB.begin(); iterador!=TeB.end(); ++iterador){
                    cout<<iterador->first<<" , "<<iterador->second<<endl;
                }
            }
            else if(enrt=="C"){
                for(auto iterador=RutaDirectaC.begin(); iterador!=RutaDirectaC.end(); ++iterador){
                    cout<<iterador->first<<" , "<<iterador->second<<endl;
                }
                cout<<"*********************************"<<endl;
                for(auto iterador=TeC.begin(); iterador!=TeC.end(); ++iterador){
                    cout<<iterador->first<<" , "<<iterador->second<<endl;
                }
            }
            else if(enrt=="D"){
                for(auto iterador=RutaDirectaD.begin(); iterador!=RutaDirectaD.end(); ++iterador){
                    cout<<iterador->first<<" , "<<iterador->second<<endl;
                }
                cout<<"*********************************"<<endl;
                for(auto iterador=TeD.begin(); iterador!=TeD.end(); ++iterador){
                    cout<<iterador->first<<" , "<<iterador->second<<endl;
                }
            }
            else if(enrt=="E"){
                for(auto iterador=RutaDirectaE.begin(); iterador!=RutaDirectaE.end(); ++iterador){
                    cout<<iterador->first<<" , "<<iterador->second<<endl;
                }
                cout<<"*********************************"<<endl;
                for(auto iterador=TeE.begin(); iterador!=TeE.end(); ++iterador){
                    cout<<iterador->first<<" , "<<iterador->second<<endl;
                }
            }
            else if(enrt=="F"){
                for(auto iterador=RutaDirectaF.begin(); iterador!=RutaDirectaF.end(); ++iterador){
                    cout<<iterador->first<<" , "<<iterador->second<<endl;
                }
                cout<<"*********************************"<<endl;
                for(auto iterador=TeF.begin(); iterador!=TeF.end(); ++iterador){
                    cout<<iterador->first<<" , "<<iterador->second<<endl;
                }
            }
            else if(enrt=="G"){
                for(auto iterador=RutaDirectaG.begin(); iterador!=RutaDirectaG.end(); ++iterador){
                    cout<<iterador->first<<" , "<<iterador->second<<endl;
                }
                cout<<"*********************************"<<endl;
                for(auto iterador=TeG.begin(); iterador!=TeG.end(); ++iterador){
                    cout<<iterador->first<<" , "<<iterador->second<<endl;
                }
            }
            else{
                cout<<"Digito el nombre de un enrutador no existente"<<endl;
            }
        }
    }
 }

bool Redes::CargarRutasDirectas(string enrt){

    list<string>::iterator iterador1;
    list<int>::iterator iterador2;
    int cont1=0,cont2;
    string letra;
    bool pass=false;

    iterador1=enrutadores.begin();
    while(iterador1!=enrutadores.end()){
          cont2=0;
          cont1++;
          letra=*iterador1;
          letra=letra[0];
          if(letra==enrt){
              pass=true;
              iterador2=costos.begin();
               while(iterador2!=costos.end()){
                    cont2++;
                    if(cont1==cont2){
                        e.push_back(*iterador1);
                        c.push_back(*iterador2);
                    }
                    iterador2++;
                }
            }
          iterador1++;
     }
    return pass;
}

void Redes::CalcularRutas(string enrt){

    list<string>::iterator it1,it2,it3,itaux;
    list<int>::iterator itc1,itc2,itc3;
    string origen,origen2,origen3,destino,rutad,rutas,pos0,pos1;
    int c1,c2,c3,c4,costo1,costo,suma;


    suma=0;
    origen=enrt;
    it1=nombres.begin();
    while(it1!=nombres.end()){
        destino=*it1;
        if(origen!=destino){
            c1=0;
            rutad=origen+destino;
            it2=e.begin();
            while(it2!=e.end()){
                c1++;
                c2=0;
                if(rutad!=*it2){
                    origen2=*it2;
                    origen2=origen2[1];
                    itc1=c.begin();
                    while(itc1!=c.end()){
                        c2++;
                        if(c1==c2){
                            costo1=*itc1;
                        }
                        itc1++;
                    }
                    c2=0;
                    it3=enrutadores.begin();
                    while(it3!=enrutadores.end()){
                        c2++;
                        c3=0;
                        rutas="-"+*it2;
                        suma=costo1;
                        pos0=*it3;
                        pos0=pos0[0];
                        pos1=*it3;
                        pos1=pos1[1];
                        if(origen2==pos0){
                            if(origen!=pos1){
                                if(destino==pos1){
                                    itc2=costos.begin();
                                    while(itc2!=costos.end()){
                                        c3++;
                                        if(c2==c3){
                                            costo=*itc2;
                                        }
                                        itc2++;
                                    }
                                    rutas+="-"+*it3;
                                    TEe.push_back(rutas);
                                    suma+=costo;
                                    TEc.push_back(suma);

                                }
                                else{
                                    itc2=costos.begin();
                                    while(itc2!=costos.end()){
                                        c3++;
                                        if(c2==c3){
                                            costo=*itc2;
                                        }
                                        itc2++;
                                    }
                                    rutas+="-"+*it3;
                                    suma+=costo;
                                    origen3=pos1;
                                    c3=0;
                                    itaux=enrutadores.begin();
                                    while(itaux!=enrutadores.end()){
                                        c3++;
                                        c4=0;
                                        pos0=*itaux;
                                        pos0=pos0[0];
                                        pos1=*itaux;
                                        pos1=pos1[1];
                                        if(origen3==pos0){
                                            if(origen!=pos1){
                                                if(destino==pos1){
                                                    itc3=costos.begin();
                                                    while(itc3!=costos.end()){
                                                        c4++;
                                                        if(c3==c4){
                                                            costo=*itc3;
                                                        }
                                                        itc3++;
                                                    }
                                                    rutas+="-"+*itaux;
                                                    TEe.push_back(rutas);
                                                    suma+=costo;
                                                    TEc.push_back(suma);
                                                }
                                            }
                                        }
                                        itaux++;
                                    }

                                }
                            }
                        }
                        it3++;
                    }
                }
                it2++;
            }
        }
        it1++;
    }
}

void Redes::AgregarEnrutadores(){

    list<string>::iterator it;
    int cont=0;
    string nuevo,op;
    bool pass=true;

    it=nombres.begin();
    while(it!=nombres.end()){
        cont++;
        it++;
    }
    if(cont>=7){
        system("CLS");
        cout<<"Ya ha excedido el limite de enrutadores posibles"<<endl;
    }
    else{
        system("CLS");
        cout<<"Escriba el nombre del nuevo enrutador, de la A-G (Mayusculas)(No repetir letras)"<<endl;
        cin>>nuevo;
        it=nombres.begin();
        while(it!=nombres.end()){
            if(nuevo==*it){
                cout<<"Ese enrutador ya existe"<<endl;
                pass=false;
            }
            it++;
        }
        if(pass){
            nombres.push_back(nuevo);
            system("CLS");
            cout<<"Ahora digite por favor las conexiones directas al nuevo enrutador (<Enrutador Origen> <Enrutador Destino>, costo) "<<endl;
            cout<<"Digite el numero 0 cuando ya no quiera agregar mas conexiones"<<endl;
            cout<<"Primera conexion:"<<endl;
            cin>>op;

            while(op!="0"){
                enrutadores.push_back(op);
                cout<<"Digite el siguiente"<<endl;
                cin>>op;
            }
            system("CLS");
            cout<<"Enrutador agregado con exito"<<endl;
        }
    }

}

void Redes::RemoverEnrutadores(){

    list<string> Auxiliar,aux1;
    list<int> aux2;
    list<string>::iterator it1,it2;
    list<int>::iterator it3;
    string enrt, primera;

    system("CLS");
    cout<<"Escriba el nombre del enrutador a eliminar"<<endl;
    cin>>enrt;

    it1=nombres.begin();
    while(it1!=nombres.end()){
        if(*it1!=enrt){
            Auxiliar.push_back(*it1);
        }
        it1++;
    }
    nombres=Auxiliar;

    it2=enrutadores.begin();
    it3=costos.begin();
    while(it2!=enrutadores.end() and it3!=costos.end()){
        primera=*it2;
        primera=primera[0];
        if(primera!=enrt){
            aux1.push_back(*it2);
            aux2.push_back(*it3);
        }
        it2++;
        it3++;
    }
    enrutadores=aux1;
    costos=aux2;

    system("CLS");
    cout<<"Enrutador eliminado correctamente"<<endl;

}

void Redes::CamEnlacesyCostos(){

    list<string>::iterator it1;
    list<int>::iterator it2;
    list<string> Auxiliar;
    list<int> aux;
    string op="",enlace="", nuevo="",enrt="", enrt2="";
    int longitud=0, longitud2=0,numero, numero2,num,cont=0;
    bool pass=false;

    system("CLS");
    cout<<"Digite:"<<endl;
    cout<<"1. Para cambiar solo un enlace"<<endl;
    cout<<"2. Para cambiar un enlace y tambien su costo"<<endl;
    cout<<"ADVERTERNCIA: Debe ser muy cuidadoso al hacer este proceso, ya que si lo digita incorrectamente el programa no dara el resultado esperado"<<endl;
    cin>>op;

    if(op=="1"){

        system("CLS");
        cout<<"Escriba el enlace a cambiar (<Origen><Destino>)"<<endl;
        cin>>enlace;
        cout<<"Escriba el nuevo enlace (<Origen><Destino>)"<<endl;
        cin>>nuevo;

        it1=enrutadores.begin();
        while(it1!=enrutadores.end()){
            if(*it1!=enlace){
                Auxiliar.push_back(*it1);
            }
            else{
                Auxiliar.push_back(nuevo);
            }
            it1++;
        }
    }
    else if(op=="2"){

        system("CLS");
        cout<<"Escriba el enlace a cambiar con su costo (<Origen><Destino>,costo)"<<endl;
        cin>>enlace;
        cout<<"Escriba el nuevo enlace con su nuevo costo(<Origen><Destino>,costo)"<<endl;
        cin>>nuevo;

        longitud=enlace.size();
        longitud2=nuevo.size();

        for(int i=0; i<longitud;i++){
            if(enlace[i]==','){
                pass=true;
                i++;
            }
            if(pass){
                if(cont>0){
                    numero*=10;
                    num=enlace[i];
                    num-=48;
                    numero+=num;
                }
                else{
                    numero=enlace[i];
                    numero-=48;
                }
                cont++;
            }
            else{
                enrt=enlace[i];
            }
        }
        pass=false;
        cont=0;
        it1=enrutadores.begin();
        it2=costos.begin();
        while(it1!=enrutadores.end() and it2!=costos.end()){
            if(*it1!=enrt){
                Auxiliar.push_back(*it1);
                aux.push_back(*it2);
            }
            else{
                for(int i=0; i<longitud2;i++){
                    if(nuevo[i]==','){
                        pass=true;
                        i++;
                    }
                    if(pass){
                        if(cont>0){
                            numero2*=10;
                            num=enlace[i];
                            num-=48;
                            numero2+=num;
                        }
                        else{
                            numero2=enlace[i];
                            numero2-=48;
                        }
                        cont++;
                    }
                    else{
                        enrt2=enlace[i];
                    }
                }
                Auxiliar.push_back(enrt2);
                aux.push_back(numero2);
            }
            it1++;
            it2++;
        }

    }
    else{
        system("CLS");
        cout<<"Digito un numero o caracter no reconocido"<<endl;
    }
    system("CLS");
    cout<<"Cambio exitoso"<<endl;
}

