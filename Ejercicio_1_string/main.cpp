#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;
void PrimerMetodo(unsigned int n);
void SegundMetodo(unsigned int n);
void Binario(int num,int* cadena);

int main()
{
    unsigned int n; unsigned short int metodo;
    cout << "Ingrese semilla de codificacion (Un numero entero positivo): ";
    cin >> n;
    cout << "Seleccione el metodo de codificacion, primer metodo ingrese 1, segundo metodo ingrese 2: ";
    cin >> metodo;
    if (metodo == 1){
        PrimerMetodo(n);
    }
    else{
       // SegundMetodo(n);
    }

    return 0;
}
void PrimerMetodo(unsigned int n){
    string Nombre, cadena2, copiacad2;
    unsigned short int tam = 1;
    unsigned short int tamanio = 0;
    int numbin[8];
    cout << "¿Cuantos elementos tiene el archivo? ";
    cin>>tamanio;
    tamanio = tamanio*8;
    unsigned short int con1=0,con0 = 0,conin = 0, conin2 =1 ;
    ifstream fin;               //stream de entrada, lectura
    ofstream fout;              //stream de salida, escritura
    cout<<"Ingrese nombre del archivo fuente (incluyendo el .txt): ";
    cin>>Nombre;
    try{


        fin.open(Nombre);        //abre el archivo para lectura
        if(!fin.is_open()){
            throw '2';
        }
        unsigned short int con = 0;
        while(fin.good()){              //lee caracter a caracter hasta el fin del archivo
            char temp=fin.get();
            if(fin.good()){
                Binario(temp,numbin);
                while (con<8) {
                    cadena2 += numbin[con];     //Asigna cada caracter leido a la cadena de caracteres
                    con += 1;
                }
                con = 0;
            }
        }
        fin.close();                //Cierra el archivo de lectura.
        copiacad2 = cadena2;
        tam = 0;
        while (tam < tamanio) {
              if(tam>=n) {
                  for(unsigned short int con = tam-(n-1); conin < n; con ++){
                      if (copiacad2[con] == 0){
                          con0 += 1;
                      }
                      else {
                          con1 += 1;
                      }
                      conin += 1;
                  }
                  if(con0 == con1){
                      for(unsigned short int con = 0; con < n; con ++){
                          if (cadena2[tam] == 0){
                              cadena2[tam]= 1;
                          }
                          else {
                              cadena2[tam] = 0;
                          }
                          tam += 1;
                      }
                  }
                  if (con0 > con1) {
                      for(unsigned short int con = 0; con < n; con ++){
                          if (con % 2 != 0){
                              if (cadena2[tam] == 0){
                                  cadena2[tam] = 1;
                              }
                              else {
                                  cadena2[tam] = 0;
                              }
                          }
                          tam += 1;
                      }
                  }
                  if (con1 > con0) {
                      for(unsigned short int con = 0; con < n; con ++) {
                          if (conin2 % 3 == 0){
                              if (cadena2[tam] == 0){
                                  cadena2[tam] = 1;
                              }
                              else {
                                  cadena2[tam] = 0;
                              }
                          }
                          conin2 += 1;
                          tam += 1;
                     }
                 }
              }
              else {
                  for(unsigned short int con = 0; con < n; con ++){
                      if (cadena2[tam] == 0){
                          cadena2[tam]= 1;
                      }
                      else {
                          cadena2[tam] = 0;
                      }
                      tam += 1;
                   }
             }
             con0 = 0;
             con1 = 0;
             conin2 = 0;
             conin = 0;

          }
        fout.open("CodifMetodo1String.txt");       //abre el archivo para escritura
        if(!fout.is_open()){
            throw '1';
        }
        for (unsigned short int in = 0;in < tamanio; in++){
              fout<<cadena2[in];              //escribe la palabra
        }
        fout.close();                      //cierra el archivo
    }

    catch (char c){
        cout<<"Error # "<<c<<": ";
        if(c=='1'){
            cout<<"Error al abrir el archivo para escritura.\n";
        }
        else if(c=='2'){
            cout<<"Error al abrir el archivo para lectura.\n";
        }
    }
    catch (...){
        cout<<"Error no definido\n";
    }

}
void Binario(int num, int* cadena){
    short int con = 7;
    cadena[0] = 0;
    while (num > 0) {
        unsigned short int elem = num % 2;
        num = num / 2;
        cadena[con] = elem;
        con -= 1;
    }
}

/*
string str1, str2, str3;
ifstream fin;               //stream de entrada, lectura
ofstream fout;              //stream de salida, escritura

cout<<"Ingrese una palabra: ";
cin>>str1;                          //lee una cadena sin espacios

//getline(cin,str1);      //lee una cadena con espacios

try{
    fout.open("archivo3.txt");       //abre el archivo para escritura
    if(!fout.is_open()){
        throw '1';
    }
    fout<<str1;                     //escribe la palabra
    fout.close();                   //cierra el archivo

    fin.open("archivo3.txt");        //abre el archivo para lectura
    if(!fin.is_open()){
        throw '2';
    }



    getline(fin,str3);           //lee una linea y la almacena en el string str3

    fin.seekg(0);                 //vuelve al principio del archivo

    while(fin.good()){              //lee caracter a caracter hasta el fin del archivo
        char temp=fin.get();
        if(fin.good()){
            str2 +=temp;     //Asigna cada caracter leido a la cadena de caracteres
        }
    }
    fin.close();                //Cierra el archivo de lectura.


}
catch (char c){
    cout<<"Error # "<<c<<": ";
    if(c=='1'){
        cout<<"Error al abrir el archivo para escritura.\n";
    }
    else if(c=='2'){
        cout<<"Error al abrir el archivo para lectura.\n";
    }
}
catch (...){
    cout<<"Error no definido\n";
}

if(str1==str2 && str1==str3)
    cout<<"Funciona!!!!\n";
*/
