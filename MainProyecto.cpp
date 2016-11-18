#include <iostream>
#include <string>
using namespace std;

int** crearMatriz(int**,int);
void freeMatriz(int**, int);
bool validarNumero(int);
void imprimirMenu();
void imprimirMatriz(int**, int, string, string, int,int);
bool verificarFilas(int**, int);
bool verificarFilas2(int**, int);
bool verificarColumnas(int**, int);
bool verificarColumnas2(int**, int);
bool verificarDiagonal(int**, int);
bool verificarDiagonal2(int**, int);
bool verificarDiagonalOpuesta(int**, int);
bool verificarDiagonalOpuesta2(int**, int);
bool verificarEmpate(int**, int);

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
  bool empate=false;

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
          if(turno%2==0){ //jugador 1
//=============================Jugador 1 =======================================
            cout << endl << endl;
            cout <<"Turno " <<jugador1 << " :" << endl;
            int x=0; //j
            int y=0; //i
            do{ // ciclo que se asegura que los jugadores ingresen coordenadas correctas
              cout << "Ingrese la coordenada que desea modificar: "<<endl;
              cout << "X: ";
              cin >> x; //asigna x
              if(x<0 || x>=size){
                cout << "Ingreso un numero fuera del tablero" << endl;
              }
            }while(x<0 || x>=size);
            do{ // ciclo que se asegura que los jugadores ingresen coordenadas correctas
              cout << endl;//salto de linea
              cout << "Y: ";
              cin >> y; //asigna y
              if(y<0 || y>=size){
                cout << "Ingreso un numero fuera del tablero" << endl;
              }
            }while(y<0 || y>=size);
            if(matriz[y][x]==0){ //si no ha sido ocupada
              int num_asignar=0;
              cout << endl;
              cout << "Ingresa el numero que desea dentro de esa posicion(de 1 a 9): " << endl;
              cin>> num_asignar;
              if(num_asignar>0 && num_asignar<10){
                matriz[y][x]=num_asignar;
                cout << endl;
                imprimirMatriz(matriz, size, jugador1, jugador2, puntoJ1, puntosJ2);
                cout << endl;
                win = verificarFilas(matriz, size);
                if(win == false){
                  win = verificarFilas2(matriz, size);
                }
                if(win==false){
                  win = verificarColumnas(matriz, size);
                  if(win==false){
                    win = verificarColumnas2(matriz,size);
                  }
                    if(win==false){
                      win = verificarDiagonal(matriz, size);
                      if(win==false){
                        win = verificarDiagonal2(matriz,size);
                      }
                        if(win==false){
                          win = verificarDiagonalOpuesta(matriz, size);
                          if(win==false){
                            win = verificarDiagonalOpuesta2(matriz, size);
                          }
                          if(win == false){
                            empate=verificarEmpate(matriz,size);
                            if(empate==true){
                              cout << endl;
                              win = true;
                              cout << "Empate, punto para nadie." << endl;
                              cout << endl;
                            }
                          }else{
                            cout << endl;
                            cout << "Gane!" << endl;
                            cout << "Punto para " << jugador1 << "! "<<endl;
                            puntoJ1++;
                          } // fin if diagonal opuesta
                        }else{
                          cout << endl;
                          cout << "Gane!" << endl;
                          cout << "Punto para " << jugador1 << "! "<<endl;
                          puntoJ1++;
                        } // fin if diagonal
                    }else{
                      cout << endl;
                      cout << "Gane!" << endl;
                      cout << "Punto para " << jugador1 << "! "<<endl;
                      puntoJ1++;

                    }//fin if columnas
                }else{
                  cout << endl;
                  cout << "Gane!" << endl;
                  cout << "Punto para " << jugador1 << "! "<<endl;
                  puntoJ1++;

                } // fin if filas
              }else{
                cout << endl;
                cout << "Ingreso un numero fuera del rango del 1 al 9" << endl;;
              }
            }else{
              cout << endl;
              cout << "Posicion ocupada, pierde turno" << endl;
            }

//=============================Jugador 2 =======================================
          }else{ // jugador 2
            cout << endl << endl;
            cout <<"Turno " <<jugador2 << " :" << endl;
            int x=0; //j
            int y=0; //i
            do{ // ciclo que se asegura que los jugadores ingresen coordenadas correctas
              cout << "Ingrese la coordenada que desea modificar: "<<endl;
              cout << "X: ";
              cin >> x; //asigna x
              if(x<0 || x>=size){
                cout << "Ingreso un numero fuera del tablero" << endl;
              }
            }while(x<0 || x>=size);
            do{ // ciclo que se asegura que los jugadores ingresen coordenadas correctas
              cout << endl;//salto de linea
              cout << "Y: ";
              cin >> y; //asigna y
              if(y<0 || y>=size){
                cout << "Ingreso un numero fuera del tablero" << endl;
              }
            }while(y<0 || y>=size);
            if(matriz[y][x]==0){ //si no ha sido ocupada
              int num_asignar=0;
              cout << endl;
              cout << "Ingresa el numero que desea dentro de esa posicion(de 1 a 9): " << endl;
              cin>> num_asignar;
              if(num_asignar>0 && num_asignar<10){
                matriz[y][x]=num_asignar;
                cout << endl;
                imprimirMatriz(matriz, size, jugador1, jugador2, puntoJ1, puntosJ2);
                cout << endl;
                win = verificarFilas(matriz, size);
                if(win == false){
                  win = verificarFilas2(matriz, size);
                }
                if(win==false){
                  win = verificarColumnas(matriz, size);
                  if(win==false){
                    win = verificarColumnas2(matriz,size);
                  }
                    if(win==false){
                      win = verificarDiagonal(matriz, size);
                      if(win==false){
                        win = verificarDiagonal2(matriz,size);
                      }
                        if(win==false){
                          win = verificarDiagonalOpuesta(matriz, size);
                          //===========
                          if(win==false){
                            win = verificarDiagonalOpuesta2(matriz, size);
                          }
                          if(win == false){
                            empate=verificarEmpate(matriz,size);
                            if(empate==true){
                              cout << endl;
                              win=true;
                              cout << "Empate, punto para nadie." << endl;
                              cout << endl;
                            }
                          }else{
                            cout << endl;
                            cout << "Gane!" << endl;
                            cout << "Punto para " << jugador1 << "! "<<endl;
                            puntoJ1++;
                          }
                        }else{
                          cout << endl;
                          cout << "Gane!" << endl;
                          cout << "Punto para " << jugador2 << "! "<<endl;
                          puntosJ2++;
                        } // fin if diagonal
                    }else{
                      cout << endl;
                      cout << "Gane!" << endl;
                      cout << "Punto para " << jugador2 << "! "<<endl;
                      puntosJ2++;

                    }//fin if columnas
                }else{
                  cout << endl;
                  cout << "Gane!" << endl;
                  cout << "Punto para " << jugador2 << "! "<<endl;
                  puntosJ2++;

                } // fin if filas
              }else{
                cout << endl;
                cout << "Ingreso un numero fuera del rango del 1 al 9" << endl;;
              }
            }else{
              cout << endl;
              cout << "Posicion ocupada, pierde turno" << endl;
            }


          }
          turno++;

        }while(win!=true);
        cout << endl;



      }

    }
    if(opcion==3){
      cout << jugador1 << " : " << puntoJ1 << endl;
      cout << jugador2 << " : " << puntosJ2 << endl;
      cout << endl;
    }
    if(opcion==4){
      cout << endl;
      cout << "Este es el Proyecto 1 de Programacion 3 de Harold Mendoza\ncon numero de cuenta 11541045" << endl;
      cout << endl;
    }
    if(opcion==5){
      cout  << endl;
      cout << "Se va muy pronto(?).." << endl;
    }

  }while(opcion!=5);


  freeMatriz(matriz, size);


  return 0;
}

//=======================================Filas==================================
bool verificarFilas(int** matriz, int size){
  int numeroEvaluar=0;
  int contadorFil=0;
  bool esPrimo=false;

  do{ // Verificar Cada Fila

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if(contadorFil==i){
          numeroEvaluar+= matriz[i][j];
          if(j<size-1){
            numeroEvaluar=numeroEvaluar*10;
          }
      }
    }
  }

  cout << "numero evaluar Filas : " << numeroEvaluar << endl;
  cout << endl;

  esPrimo=validarNumero(numeroEvaluar);

  if(esPrimo==true){
    contadorFil=size;
  }else{
      contadorFil++;
      numeroEvaluar=0;
  }

}while(contadorFil<size);

  return esPrimo;


}

//================================Fila 2========================================
bool verificarFilas2(int** matriz, int size){
  int numeroEvaluar=0;
  int contadorFil=0;
  bool esPrimo=false;

  do{ // Verificar Cada Fila

  for (int i = 0; i < size ; i++) {
    for (int j = size-1; j >= 0; j--) {
      if(contadorFil==i){
          numeroEvaluar+= matriz[i][j];
          if(j>0){
            numeroEvaluar=numeroEvaluar*10;
          }
      }
    }
  }

  cout << "numero evaluar Filas 2: " << numeroEvaluar << endl;
  cout << endl;

  esPrimo=validarNumero(numeroEvaluar);

  if(esPrimo==true){
    contadorFil=size;
  }else{
      contadorFil++;
      numeroEvaluar=0;
  }

}while(contadorFil<size);

  return esPrimo;


}

//=================================Columnas=====================================


bool verificarColumnas(int** matriz, int size){
  int numeroEvaluar=0;
  int contadorCol=0;
  bool esPrimo=false;

  do{ // Verificar Cada Fila

  for (int j = 0; j < size; j++) {
    for (int i = 0; i < size; i++) {
      if(contadorCol==j){
          numeroEvaluar+= matriz[i][j]; // recorre la matriz por columnas
          if(i<size-1){ // se multiplicara por 10 solo size veces menos 1
            numeroEvaluar=numeroEvaluar*10;
          }
      }
    }
  }
  cout << "numero evaluar Columnas : " << numeroEvaluar << endl;
  cout << endl;

  esPrimo=validarNumero(numeroEvaluar);

  if(esPrimo==true){
    contadorCol=size;
  }else{
      contadorCol++;
      numeroEvaluar=0;
  }

}while(contadorCol<size);

  return esPrimo;


}

//================================Columnas 2====================================
bool verificarColumnas2(int** matriz, int size){
  int numeroEvaluar=0;
  int contadorCol=0;
  bool esPrimo=false;

  do{ // Verificar Cada Fila

  for (int j = 0; j < size; j++) {
    for (int i = size-1; i >=0; i--) {
      if(contadorCol==j){
          numeroEvaluar+= matriz[i][j]; // recorre la matriz por columnas
          if(i>0){ // se multiplicara por 10 solo size veces menos 1
            numeroEvaluar=numeroEvaluar*10;
          }
      }
    }
  }
  cout << "numero evaluar Columnas 2: " << numeroEvaluar << endl;
  cout << endl;

  esPrimo=validarNumero(numeroEvaluar);

  if(esPrimo==true){
    contadorCol=size;
  }else{
      contadorCol++;
      numeroEvaluar=0;
  }

}while(contadorCol<size);

  return esPrimo;


}


//===================================Diagonal==================================
bool verificarDiagonal(int** matriz, int size){
  int numeroEvaluar=0;
  bool esPrimo=false;

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if(i==j){
          numeroEvaluar+= matriz[i][j];
          if(j<size-1){ // se multiplicara por 10 solo size veces menos 1
            numeroEvaluar=numeroEvaluar*10;
          }
      }
    }
  }

  cout << "numero evaluar Diagonal : " << numeroEvaluar << endl;
  cout << endl;

  esPrimo=validarNumero(numeroEvaluar);

  return esPrimo;


}

//===================================Diagonal 2==================================
bool verificarDiagonal2(int** matriz, int size){
  int numeroEvaluar=0;
  bool esPrimo=false;

  for (int i = size-1; i >= 0; i--) {
    for (int j = size-1; j >=0; j--) {
      if(i==j){
          numeroEvaluar+= matriz[i][j];
          if(j>0){ // se multiplicara por 10 solo size veces menos 1
            numeroEvaluar=numeroEvaluar*10;
          }
      }
    }
  }

  cout << "numero evaluar Diagonal 2 : " << numeroEvaluar << endl;
  cout << endl;

  esPrimo=validarNumero(numeroEvaluar);

  return esPrimo;


}

//===========================Diagonal Opuesta===================================
bool verificarDiagonalOpuesta(int** matriz, int size){
  int numeroEvaluar=0;
  bool esPrimo=false;

  for (int i = size-1; i >=0; i--) {
    for (int j = 0; j < size; j++) {
      if(i+j==size-1){
          numeroEvaluar+= matriz[i][j];
          if(i>0){ // se multiplicara por 10 solo size veces menos 1
            numeroEvaluar=numeroEvaluar*10;
          }
      }
    }
  }

  cout << "numero evaluar Diagonal Opuesta : " << numeroEvaluar << endl;
  cout << endl;

  esPrimo=validarNumero(numeroEvaluar);

  return esPrimo;


}

//===========================Diagonal Opuesta 2===================================
bool verificarDiagonalOpuesta2(int** matriz, int size){
  int numeroEvaluar=0;
  bool esPrimo=false;

  for (int i = 0; i < size; i++) {
    for (int j = size-1; j >=0; j--) {
      if(i+j==size-1){
          numeroEvaluar+= matriz[i][j];
          if(i<size-1){ // se multiplicara por 10 solo size veces menos 1
            numeroEvaluar=numeroEvaluar*10;
          }
      }
    }
  }

  cout << "numero evaluar Diagonal Opuesta 2: " << numeroEvaluar << endl;
  cout << endl;

  esPrimo=validarNumero(numeroEvaluar);

  return esPrimo;


}

//=========================Empate===============================================
bool verificarEmpate(int** matriz, int size){
  int cont=0;
  bool empate=false;

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if(matriz[i][j]==0){
        cont++;
      }
    }
  }

  if(cont==0){
    empate=true;
  }

  return empate;


}






void imprimirMenu(){
  cout << endl;
  cout << "|| Bienvenido al TIC TAC TOE de Numeros Primos ||" << endl;
  cout << "========================== MENU ==========================" << endl;
  cout << "1) Cambiar Nombres de Jugadores" << endl;
  cout << "2) NUEVA PARTIDA" << endl;
  cout << "3) Puntuacion" << endl;
  cout << "4) About" << endl;
  cout << "5) Salir" << endl;
  cout << "Ingrese su opcion: ";
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

bool validarNumero(int numero){
  int contEsPrimo=0;
  bool esPrimo=false;
	for(int i = 1; i <numero+1; i++){
		if(numero%i==0){
			contEsPrimo++;
		}

	}

  cout << "Contador si es Primo: " << contEsPrimo << endl;
  if(contEsPrimo==2){
    esPrimo=true;
    cout << "Es Primo: " << esPrimo << endl;
  }

  //cout << "Es Primo: " << esPrimo << endl;
	return esPrimo;


}
