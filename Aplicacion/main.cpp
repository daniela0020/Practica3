#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;
string aMinuscula(string cadena);
bool Administ();
void ingrUsuarios();
void menu(string cedula);
void Binario(int num,int* cadena);
void Saldo(string cedula);
void retirar(string cedula);
string user(bool*tf);
int Charaint(string numchar);

int main()
{
    string SiNo,cedula;
    bool admit;
    cout << "Acceder como administrador (si,no): ";
    cin >> SiNo;
    SiNo = aMinuscula(SiNo);
    if (SiNo[0] == 's' && SiNo[1] == 'i') {
        admit = Administ();
        if (admit == true){
            ingrUsuarios();
        }
        else {
            cout << "Contrasena incorrecta."<< endl;
        }
    }
    else if (SiNo[0] == 'n' && SiNo[1] == 'o' ){
        cout << "Acceder como usuario (si,no)";
        cin >> SiNo;
        SiNo = aMinuscula(SiNo);
        if (SiNo[0] == 's' && SiNo[1] == 'i') {
            cedula = user(&admit);
            if (admit == true){
                menu(cedula);
            }
            else {
                cout << "Cedula o clave incorrectas."<< endl;
            }
        }

    }
    return 0;
}
string aMinuscula(string cadena) {
  for (int i = 0; i < cadena.length(); i++) {
      cadena[i] = tolower(cadena[i]);
  }
  return cadena;
}
bool Administ() {
  string Caract,clave,clavecop;
  ifstream fin;               //stream de entrada, lectura
  ofstream fout;              //stream de salida, escritura
  cout << "Ingrese la clave: ";
  cin >> Caract;
  unsigned short int tam = 1;
  unsigned short int tamanio = 0,tamanio1 =0;
  unsigned short int ant =0,conin = 0;
  int numbin[8];
  tamanio1 = Caract.length();
  tamanio = tamanio1*8;
  try{
      unsigned short int con = 0;
      char caracter;
      for( unsigned int i = 0; i < tamanio1; i++){      //lee caracter a caracter hasta el fin del archivo
          int temp= Caract[i];
          if(i < tamanio1){
              Binario(temp,numbin);
              while (con<8) {
                  if (numbin[con]==0){
                      caracter = 48;
                  }
                  else {
                      caracter = 49;
                  }
                  clave += caracter;     //Asigna cada caracter leido a la cadena de caracteres
                  con += 1;
              }
              con = 0;
          }
      }
      clavecop = clave;
      while (conin < tamanio ) {
             ant = conin;
             for(unsigned short int con = 0; con < 4; con ++) {
                 if (conin < tamanio){
                     clave[conin+1] = clavecop[conin];
                     conin += 1;
                 }
                 else {
                     break;
                 }
             }
             clave[ant] = clavecop[conin-1];
      }

      fin.open("sudo.txt");        //abre el archivo para lectura
      if(!fin.is_open()){
          throw '2';
      }
      getline(fin,clavecop);           //lee una linea y la almacena en el string
      fin.seekg(0);                 //vuelve al principio del archivo
      fin.close();                //Cierra el archivo de lectura.
      if (clavecop == clave){
          return true;
      }
      else {
          return false;
      }

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
void ingrUsuarios(){
    string Cedula,Clave,Saldo;
    unsigned short int term;
    unsigned int con = 0;
    ifstream fin;               //stream de entrada, lectura
    ofstream fout;              //stream de salida, escritura
    fout.open("Usuarios.txt");       //abre el archivo para escritura
    cout << "Registro de usuarios: " << endl;
    while(true){
        cout << "Cedula: ";
        cin >> Cedula;
        fout<<Cedula;                     //escribe la palabra
        fout<<',';                     //escribe la palabra

        cout <<"Clave (sin ',' ni ';'): ";
        cin >> Clave;
        fout<<Clave;                     //escribe la palabra
        fout<<',';
        cout << "Saldo: ";
        cin >> Saldo;
        fout<<Saldo;
        fout<<';';
        cout << "Ingresa 0 si ya terminaste: ";
        cin >> term;
        if (term == 0){
            break;
        }
        fout << endl;
    }
    fout.close();


}
void menu( string cedula){
    unsigned short int num,num2;
    while (true) {
        cout << "Si quiere consultar su saldo ingrese 1 "<< endl;
        cout << "Si quiere retirar dinero ingrese 2"<< endl;
        cin >> num;
        if (num == 1){
            Saldo(cedula);
        }
        if (num == 2){
            retirar(cedula);
        }
        cout << "Si quiere repetir el menu ingrese 1";
        cin >> num2;
        if (num2 != 1){
            break;
        }
   }
}
void Saldo(string cedula){
    string cedularch,saldo;
    unsigned short int con = 0;
    int saldoint = 0;
    ifstream fin;               //stream de entrada, lectura
    ofstream fout;              //stream de salida, escritura
    try{

            fin.open("Usuarios.txt");        //abre el archivo para lectura
            if(!fin.is_open()){
                throw '2';
            }
            while(fin.good()){              //lee caracter a caracter hasta el fin del archivo
                char temp=fin.get();
                if(fin.good()){
                    if (temp != ',' && con < 1){
                        cedularch += temp;     //Asigna cada caracter leido a la cadena de caracteres
                    }
                    if(temp == ',') {
                        con += 1;
                    }

                    if (temp == ';') {
                        if (cedula == cedularch){
                            break;
                        }
                        con = 0;
                        cedula = "";
                    }
                    else  if (cedula == cedularch && con == 2){
                        if (temp != ','){
                          saldo += temp;
                        }
                    }
                }
            }
            saldoint = Charaint(saldo);
            saldoint = saldoint - 1000;
            cout << "Saldo: " << saldoint << endl;
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

}
int Charaint(string numchar) {
    int longi = numchar.length();
    unsigned short int num = 0;
    unsigned int mul = 1;
    unsigned int suma = 0;
    longi = longi-1;
    for(longi; longi >=  0 ; longi--) {
        char temp = numchar[longi];
        if (temp == '0'){
            num = 0;
        }
        if (temp == '1'){
            num = 1;
        }
        if (temp == '2'){
            num = 2;
        }
        if (temp == '3'){
            num = 3;
        }
        if (temp == '4'){
            num = 4;
        }
        if (temp == '5'){
            num = 5;
        }
        if (temp == '6'){
            num = 6;
        }
        if (temp == '7'){
            num = 7;
        }
        if (temp == '8'){
            num = 8;
        }
        if (temp == '9'){
            num = 9;
        }
        suma += num * (mul);
        mul = mul * 10;

    }
    return suma;
}

string user(bool*tf){
    string cedula,clave,cedularch,clavearch;
    unsigned short int con = 0;
    ifstream fin;               //stream de entrada, lectura
    ofstream fout;              //stream de salida, escritura
    cout << "Cedula: ";
    cin >> cedula;
    cout << "Clave: ";
    cin >> clave;
    try{

            fin.open("Usuarios.txt");        //abre el archivo para lectura
            if(!fin.is_open()){
                throw '2';
            }

            while(fin.good()){              //lee caracter a caracter hasta el fin del archivo
                char temp=fin.get();
                if(fin.good()){
                    if (temp != ',' && con < 2){
                        if (con < 1 ){
                           cedularch += temp;     //Asigna cada caracter leido a la cadena de caracteres
                        }
                        else {
                           clavearch += temp;
                        }
                    }
                    if(temp == ',') {
                        con += 1;
                    }
                    if (temp == ';') {
                        if (cedula == cedularch && clave == clavearch){
                            *tf = true;
                            return cedula;
                        }
                        con = 0;
                        cedula = "";
                        clavearch ="";
                    }
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
       *tf = false;
       return cedula;
}

void retirar(string cedula) {
    string cedularch,saldo,clavearch;
    unsigned short int con = 0;
    int saldoint = 0;
    int dinero = 0;
    ifstream fin;               //stream de entrada, lectura
    ofstream fout;              //stream de salida, escritura
    try{

            fin.open("Usuarios.txt");        //abre el archivo para lectura
            if(!fin.is_open()){
                throw '2';
            }
            while(fin.good()){              //lee caracter a caracter hasta el fin del archivo
                char temp=fin.get();
                if(fin.good()){
                    if (temp != ',' && con < 1){
                        cedularch += temp;     //Asigna cada caracter leido a la cadena de caracteres
                    }
                    if(temp == ',') {
                        con += 1;
                    }

                    if (temp == ';') {
                        if (cedula == cedularch){
                            break;
                        }
                        con = 0;
                        cedula = "";
                    }
                    else  if (cedula == cedularch && con == 2){
                        if (temp != ','){
                          saldo += temp;
                        }
                    }
                }
            }
            saldoint = Charaint(saldo);
            fin.close();                //Cierra el archivo de lectura.
            cout << "Cuanto dinero va a retirar: ";
            cin >> dinero;
            saldoint = saldoint - dinero;
            if (saldoint<0){
                cout << "Esa cantidad excede su saldo ";
            }
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

