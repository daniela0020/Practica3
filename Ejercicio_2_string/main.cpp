#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;
void PrimerMetodo(unsigned int n);
void SegundMetodo(unsigned int n);
unsigned int Binario(char* cadena);

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
        SegundMetodo(n);
    }

    return 0;
}
void PrimerMetodo(unsigned int n){
    string cadena2,Nombre;
    char numbin[8];
    unsigned short int tam = 1;
    unsigned short int tamanio = 0, tamfin = 0;
    unsigned short int con1=0,con0 = 0,conin = 0, conin2 =1;
    char decimal;
    ifstream fin;               //stream de entrada, lectura
    ofstream fout;              //stream de salida, escritura
    cout<<"Ingrese nombre del archivo fuente: ";
    cin>>Nombre;
    cout << "Cuantos elementos tiene el archivo: ";
    cin>>tamanio;
    try{

           fin.open(Nombre);        //abre el archivo para lectura
           if(!fin.is_open()){
               throw '2';
           }
           int i=0;
           unsigned short int con = 0;
           while(fin.good()){              //lee caracter a caracter hasta el fin del archivo
                      char temp =fin.get();
                      if(fin.good()){
                          cadena2 += temp;     //Asigna cada caracter leido a la cadena de caracteres
                      }
                  }

          fin.close();                //Cierra el archivo de lectura.
          tam = 0;
          while (tam < tamanio) {
              if(tam>=n) {
                  for(unsigned short int con = tam-n; conin < n; con ++){
                       if (cadena2[con] == '0'){
                           con0 += 1;
                       }
                       else {
                           con1 += 1;
                       }
                       conin += 1;
                  }
                  if(con0 == con1){
                      for(unsigned short int con = 0; con < n; con ++){
                          if (cadena2[tam] == '0'){
                              cadena2[tam]= '1';
                          }
                          else {
                              cadena2[tam] = '0';
                          }
                          tam += 1;
                      }
                  }
                  if (con0 > con1) {
                      for(unsigned short int con = 0; con < n; con ++){
                          if (con % 2 != 0){
                              if (cadena2[tam] == '0'){
                                  cadena2[tam] = '1';

                              }
                              else {
                                  cadena2[tam] = '0';

                              }
                          }
                          tam += 1;
                      }
                  }
                  if (con1 > con0) {
                      for(unsigned short int con = 0; con < n; con ++) {
                          if (conin2 % 3 == 0){
                              if (cadena2[tam] == '0'){
                                  cadena2[tam] = '1';

                              }
                              else {
                                  cadena2[tam] = '0';

                              }
                          }
                          conin2 += 1;
                          tam += 1;
                     }
                 }
              }
              else {
                  for(unsigned short int con = 0; con < n; con ++){
                      if (cadena2[tam] == '0'){
                          cadena2[tam]= '1';

                      }
                      else {
                          cadena2[tam] = '0';

                      }
                      tam += 1;
                   }
             }

             con0 = 0;
             con1 = 0;

             conin2 = 0;
             conin = 0;
          }
      cout<<"Ingrese nombre del archivo de salida: ";
      cin>>Nombre;
      fout.open(Nombre);       //abre el archivo para escritura
      if(!fout.is_open()){
          throw '1';
      }
      con = 0;
      while(con < tam) {
          for(conin = 0; conin<8; conin++) {
             numbin[conin] = cadena2[con];
             con += 1;
          }
          decimal = Binario(numbin);
          fout<< decimal;                     //escribe
       }
      fout.close();                   //cierra el archivo

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
void SegundMetodo(unsigned int n) {
    string Nombre,cadena2,copiacad2;
    unsigned short int tam = 1;
    unsigned short int tamanio = 0;
    unsigned short int ant =0,conin = 0;
    char decimal;
    char numbin[8];
    ifstream fin;               //stream de entrada, lectura
    ofstream fout;              //stream de salida, escritura
    cout<<"Ingrese nombre del archivo fuente (incluyendo el .txt): ";
    cin>>Nombre;
    cout << "Cuantos elementos tiene el archivo: ";
    cin>>tamanio;
    try{

           fin.open(Nombre);        //abre el archivo para lectura
           if(!fin.is_open()){
               throw '2';
           }
           int i=0;
           unsigned short int con = 0;
           while(fin.good()){              //lee caracter a caracter hasta el fin del archivo
                      char temp =fin.get();
                      if(fin.good()){
                          cadena2 += temp;     //Asigna cada caracter leido a la cadena de caracteres
                      }
               }
           fin.close();                //Cierra el archivo de lectura.
           copiacad2 = cadena2;
           while (conin < tamanio ) {
               ant = conin;
               for(unsigned short int con = 0; con < n; con ++) {
                   if (conin < tamanio){
                       cadena2[conin] = copiacad2[conin+1];
                       conin += 1;
                   }
                   else {
                       break;
                   }
               }
               cadena2[conin-1] = copiacad2[ant];
           }
           cout<<"Ingrese nombre del archivo de salida: ";
           cin>>Nombre;
           fout.open(Nombre);       //abre el archivo para escritura
           if(!fout.is_open()){
               throw '1';
           }
           con = 0;
           while(con < tamanio) {
               for(conin = 0; conin<8; conin++) {
                  numbin[conin] = cadena2[con];
                  con += 1;
               }
               decimal = Binario(numbin);
               fout<< decimal;                     //escribe
            }
           fout.close();                   //cierra el archivo
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
unsigned int Binario(char* cadena){
   unsigned int conin = 0;
   unsigned int sum = 0;
   unsigned int mult = 1;
   for (unsigned int con = 8; conin < 8; con-- ) {
       for (unsigned int con2 = 1; con2 <conin; con2++){
           mult = mult*2;
       }
       if (cadena[con]=='1'){
          sum += mult;
       }
       mult = 1;
       conin += 1;
   }
   return sum;
}
