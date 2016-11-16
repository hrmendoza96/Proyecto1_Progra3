#include <iostream>
#include <string>
using namespace std;

int** crearMatriz(int**,int);
void freeMatriz(int**, int);
bool validarNumero(int);
void imprimirMenu();
void imprimirMatriz(int**, int, string, string, int,int);

int main(int argc, char const *argv[]) {
  int opcion=0;
  string jugador1="Jugador 1";
  string jugador2="Jugador 2";
  int size=0;
  int** matriz = NULL;
  int puntoJ1=0;
  int puntosJ2=0;
  /*
  El jugador 1 es par y el 2 Impar
  */
  int turno=0;
  bool win=false;

  do{
    imprimirMenu();
    cin>>opcion;
    if(opcion==1){
      cout << "Jugador 1, Ingrese su nuevo alias: " << endl;
      cin >> jugador1;
      cout << "Jugador 2, Ingrese su nuevo alias: " << endl;
      cin >> jugador2;
    }
    if(opcion==2){
      do{ // ciclo que se asegura que los jugadores ingresen el tamano correcto
        cout << "Ingresar el tamano de la matriz(debe ser mayor o igual a 3):" << endl;
        cin >> size;
        if(size<3){
          cout << "Ingreso un numero menor a 3" << endl;
        }
      }while(size<3); // mientras size sea menor a 3 entonces se volvera a repetir


      if(size>=3){ // Logra entrar al juego
        matriz= crearMatriz(matriz, size);
        cout << endl;
        imprimirMatriz(matriz, size, jugador1, jugador2, puntoJ1, puntosJ2);
        do{
          if(turno%2==0){
            

          }else{


          }

        }while(win==true);

      }





    }
    if(opcion==3){
      cout << "Este es el Proyecto 1 de Programacion 3 de Harold Mendoza\ncon numero de cuenta 11541045" << endl;

    }
    if(opcion==4){
      cout << "Se va muy pronto(?).." << endl;
    }

  }while(opcion!=4);


  freeMatriz(matriz, size);


  return 0;
}


void imprimirMenu(){
  cout << "|| Bienvenido al TIC TAC TOE de Numeros Primos ||" << endl;
  cout << "========================== MENU ==========================" << endl;
  cout << "1) Cambiar Nombres de Jugadores" << endl;
  cout << "2) Iniciar Juego" << endl;
  cout << "3) About" << endl;
  cout << "4) Salir" << endl;
}

int** crearMatriz(int**  matriz, int size){
  matriz = new int*[size];

  for (int i = 0; i < size; i++) {
    matriz[i] = new int[size];
  }

  return matriz;

}

void imprimirMatriz(int**  pMatriz, int pSize, string Pjugador1, string Pjugador2,
  int puntosJug1, int puntosJug2){//inicio metodo

  cout << " "; // imprime un espacio antes del cero de la posicion de la matriz
  for (int i = 0; i < pSize; i++) {
    cout << i << " ";
  }
  cout << endl;
  for (int i = 0; i < pSize; i++) { //Imprime la raya se separacion
    cout << "===";
  }
  cout << endl;

  for (int i = 0; i < pSize; ++i)
  {

        cout << i <<  "|";


    for (int j = 0; j < pSize; ++j)
    {
      cout << pMatriz[i][j] << " ";
    }
    cout << endl;
  }


  cout << Pjugador1<< " : "<< puntosJug1 << endl;
  cout << Pjugador2<< " : "<< puntosJug2 << endl;


} // fin metodo imprimir

void freeMatriz(int** matriz, int size){
  for (int i = 0; i < size; ++i)
  {
    delete[] matriz[i];
    matriz[i] =  NULL;
  }

  delete[] matriz;
  cout << "Memoria liberada" << endl;

}
