#include <iostream>
#include <string>
#include <vector>
using namespace std;
void dibujarTablero(const vector<string>& fichas)
{
    for(int i = 0, k = 0; i < 3;i++){
        for(int j = 0; j < 3; j++, k ++){
            if(j != 2){
                cout << fichas[k]<<"|";
            }else{
                cout << fichas[k] << "\n";
            }
        }
        if(i != 2){
            cout << "---|---|---\n";
        }else{
            cout << "\n";
        }
    }
}
// Calcular la cantidad de posiciones ocupadas
bool gameOver(const vector<string>& fichas){
    int posicion, lleno = 0;
    // Recorrer todas las posiciones desde el 0 hasta el 8
    for(posicion = 0; posicion < 9; posicion++){
        if (fichas[posicion] == " X " || fichas[posicion] == " O "){
            // Aumentar el contador cada vez que haya una posición ocupada por una X o una O
            lleno += 1;
        }
    }
    // Condición para cuando hay 9 posiciones ocupadas
    if(lleno == 9){
        return true;
    } else{
        return false;
    }
}
// Verificar si la casilla escogida está opcupada o fuera de rango
bool ocupado(const vector<string>& fichas, int temp){
    bool over = gameOver(fichas);
    // Si la posición está fuera del rango, devolver true
    if (temp < 0 || temp > 8){
        cout << "Posicion no valida.\n";
        return true;
    }
    // Si la posición contiene una X o una O, devolver true y mostrar un mensaje
    if (fichas[temp] == " X " || fichas[temp] == " O "){
        cout << "La posicion " << temp + 1 << " esta ocupada.\n";
        return true;
    } else if(over == true){
        // Devlover false cuando todas las casillas están ocupadas para que deje de pedir una entrada la función "movimiento"
        return false;
    } else{
        // Si la posición está vacía, devolver false
        return false;
    }
}
/*bool entrada(int temp){
    string temp = " "+to_string(i+1)+" ";
    if (temp != 1 && temp != 2 && temp != 3 && temp != 4 && temp != 5 && temp != 6 && temp != 7 && temp != 8 && temp != 9){
        cout << "\n" << temp << " es una entrada invalida.\n\n";
        return true;
    }
    else{
        return false;
    }

    return 0;
}*/
int movimiento(int jugador, const vector<string>& fichas){
    int posicion, temp;
    bool ocupada;
    do {
        cout << "Jugador "<< jugador << ", escoja una posicion (Debe ser un valor entero):" ;
        // Almacenar la entrada en la variable temp para evitar que ocupe la posición por detrás de escenas
        cin >> temp;
        // LLamar a la función "entrada" para confirmar si la entrada es un valor entero o una cadena
        // texto = entrada(temp);
        // Restar uno para ajustar el índice del vector
        temp -= 1;
        // Llamar a la función "ocupado" para comprobar si la posición está ocupada
        ocupada = ocupado(fichas, temp);
        //  Sumar uno para ajustar el índice de la posición para cuando salga del bucle (sin esta línea, tomará una posición anterior a la ingresada una vez que escoja una posición libre)
        temp += 1;
    } while (ocupada); // Repetir mientras la posición esté ocupada
    // Pasar el valor temporal a la variable que se va a usar
    posicion = temp;
    // Restar uno para ajustar el índice del vector
    posicion -= 1;
    return posicion;
}
int comprobar(const vector<string>& fichas){
    int contadorJugadorUno = 0, contadorJugadorDos = 0;
    //caso 1
    for(int i = 0; i < 9; i++ ){
        if(i <=2){
            if(fichas[i] == " X "){
                contadorJugadorUno +=1;
            }
            else if(fichas[i] == " O "){
                contadorJugadorDos += 1;
            }
            if(i == 2 && contadorJugadorUno == 3){
                return 1;
            }
            else if(i == 2  && contadorJugadorDos == 3){
                return 2;
            }
        }
        else if(i <= 5){
            if(i == 3){
                contadorJugadorUno = 0;
                contadorJugadorDos = 0;
            }
            if(fichas[i] == " X "){
                contadorJugadorUno +=1;
            }
            else if(fichas[i] == " O "){
                contadorJugadorDos += 1;
            }
            if(i == 5 && contadorJugadorUno == 3){
                return 1;
            }
            else if(i == 5  && contadorJugadorDos == 3){
                return 2;
            }
        }
        else if(i <=8 ){
            if(i == 6){
                contadorJugadorUno = 0;
                contadorJugadorDos = 0;
            }
            if(fichas[i] == " X "){
                contadorJugadorUno +=1;
            }
            else if(fichas[i] == " O "){
                contadorJugadorDos += 1;
            }
            if(i == 8 && contadorJugadorUno == 3){
                return 1;
            }
            else if(i == 8  && contadorJugadorDos == 3){
                return 2;
            }
        }
    }
    // caso 2
    int contador = 0;
    for(int i = 0, j = 0; i <9; i += 3){
        if(fichas[i] == fichas[i+1] && fichas[i+1] == fichas[i+2]){
            if(fichas[i] == " X "){
                return 1;
            }else{
                return 2;
            }
        }
    }
    // caso 3
    for(int i = 0; i < 3; i++){
        if(fichas[i] == fichas[i+3] && fichas[i+3] == fichas[i+6]){
            if(fichas[i] == " X "){
                return 1;
            }else{
                return 2;
            }
        }
    }
    // caso 4
    if(fichas[0] == fichas[4] && fichas[4] == fichas[8]){
        if(fichas[0] == " X "){
            return 1;
        }else{
            return 2;
        }
    }
    // caso 5
    if(fichas[2] == fichas[4] && fichas[4] == fichas[6]){
        if(fichas[2] == " X "){
            return 1;
        }else{
            return 2;
        }
    }
    return 0;
}
int main(){    
    vector<string> fichas;
    int posicion, juego = 0, jugador = 1,cambio = 0;
    bool over;
    cout << "BIENVENIDOS!\n\n";
    for (int i = 0; i < 9; i++){
        string numero = " "+to_string(i+1)+" ";
        fichas.push_back(numero);
    }
    dibujarTablero(fichas);
    while(juego == 0 && over == false){
        if(jugador == 1){
            cambio = movimiento(jugador, fichas);
            fichas[cambio] = " X ";
            jugador = 2;
        } else if(jugador == 2){
            cambio = movimiento(jugador, fichas);
            fichas[cambio] = " O ";
            jugador = 1;
        }
        dibujarTablero(fichas);
        // Llamar a la función "gameOver" para comprobar si todas las posiciones están ocupadas
        over = gameOver(fichas);
        juego = comprobar(fichas);
        if(juego == 1){
            cout << "El jugador 1 gano el juego!\nFELICITACIONES!";
        }else if(juego == 2){
            cout << "El jugador 2 gano el juego!\nFELICITACIONES!";
        }
        // Condición si el tablero está lleno y no hay ganador
        else if(over == true){
            cout << "GAME OVER\nNadie gano. :(\n\nMejor suerte la proxima\n";
        }
    }
}