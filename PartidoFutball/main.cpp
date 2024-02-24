#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
//costante
#define NUMERO_EQUIPOS 6
//funcion para generar numero aleatorio
int generar_pts() {
    return rand() % 11;
}

//inprimir las posisiones
//funcion con 5 arreglos como argumentos
void print_tab(string equipos[], int partidosJugados[], int partidosganados[], int partidosPerdidos[], int partido_empate[]) {
    //titulo
    cout<<"\n Laboratorio numero 1, Grupo 4\n"<<endl;
    //encabezado
    cout << "Tabla de clasficatoria:\n " << endl;
    cout << setfill('=') << setw(55) << "=" << endl;
    cout << setfill(' ');
    cout << left << setw(10) << "|Equipo" << setw(10) << "|jugados" << setw(10) << "| ganados" << setw(10) << "|perdidos" << setw(10) << "|empates" << setw(10) << "|pts|" << endl;
    cout << setfill('=') << setw(55) << "=" << endl;
    cout << setfill(' ');

    //ciclo for para escribir la divicion de las columnas
    for (int i = 0; i < NUMERO_EQUIPOS; i++)
    {
        int pts = partidosganados[i] * 3 + partido_empate[i];
        cout << left << setw(10) << "| " + equipos[i] << setw(10) << "| " + to_string(partidosJugados[i]) << setw(10) << "| " + to_string(partidosganados[i]) << setw(10) << "| " + to_string(partidosPerdidos[i]) << setw(10) << "| " + to_string(partido_empate[i]) << setw(10) << "| " + to_string(pts) + " |" << endl;
        cout << setfill('-') << setw(55) << "-" << endl;
        cout << setfill(' ');
    }
}

// Funcion para print res de la tab

void print_tabla_res(string equipos[], int resultados[6][6]) {
    cout << "---Tabla de los Partidos jugados----:" << endl;
    cout << setfill('=') << setw(35) << "=" << endl;
    cout << setfill(' ');
    cout << left << setw(10) << "| Equipo 1" << setw(10) << "| Equipo 2" << setw(20) << "| Resultado |" << endl;
    cout << setfill('=') << setw(35) << "=" << endl;
    cout << setfill(' ');

    //ciclo for para imprimir las diviciones de las columnas y filas
    for (int i = 0; i < NUMERO_EQUIPOS; i++) {
        for (int j = i + 1; j < NUMERO_EQUIPOS; j++) {
            cout << left << setw(10) << "|" + equipos[i] << setw(10) << "|" + equipos[j] << setw(20);
            if (resultados[i][j] == -1) {
                cout << "| Empate |" << endl;
            } else {
                cout << "|" + to_string(resultados[i][j]) + "-" + to_string(resultados[j][i]) + "|" << endl;
            }
        }
    }
    cout << setfill('-') << setw(35) << "-" << endl;
    cout << setfill(' ');
}

int main() {

    srand(time(0));

    // Inizialicion de vectores con 0 de los valores de la columnas
    string equipos[NUMERO_EQUIPOS];
    int partidosJugados[6] = {0};
    int partidosganados[6] = {0};
    int partidosPerdidos[6] = {0};
    int partido_empate[6] = {0};

    // Matriz para almacenar los resultados de los partidos
    int resultados[6][6] = {0};




    // Ingreso de nombres de los equipos
    cout << "Ingrese los nombres de los 6 equipos de football :" << endl;
    for (int i = 0; i < NUMERO_EQUIPOS; i++)
     {
        cout << "Equipo " << i + 1 << ": ";
        cin >> equipos[i];
    }




    // Se crean los partidos generados de equipo vs equipo
    for (int i = 0; i < NUMERO_EQUIPOS; i++) {
        for (int j = i + 1; j < NUMERO_EQUIPOS; j++)
        {
            int golesEquipo1 = generar_pts();
            int golesEquipo2 = generar_pts();
            resultados[i][j] = golesEquipo1;
            resultados[j][i] = golesEquipo2;
            partidosJugados[i]++;
            partidosJugados[j]++;
            if (golesEquipo1 > golesEquipo2)
            {
                partidosganados[i]++;
                partidosPerdidos[j]++;
            }
            else if (golesEquipo1 < golesEquipo2)
            {
                partidosganados[j]++;
                partidosPerdidos[i]++;
            }
            else {
                partido_empate[i]++;
                partido_empate[j]++;
            }
        }
    }



    // Print de la tabla de posiciones
    print_tab(equipos, partidosJugados, partidosganados, partidosPerdidos, partido_empate);



    // Print de la tabla de resultados de los partidos
    print_tabla_res(equipos, resultados);
// Calc equipo ganador y del equipo perdedor
    int maxpts = 0;
    int equipoGanador = -1;
    int minpts = 100;
    int equipoBaja = -1;
    for (int i = 0; i < NUMERO_EQUIPOS; i++)
    {
        int pts = partidosganados[i] * 3 + partido_empate[i];
        if (pts > maxpts)
        {
            maxpts = pts;
            equipoGanador = i;
        }
        if (pts < minpts)
        {
            minpts = pts;
            equipoBaja = i;
        }
    }

    cout << "Mayor: " << equipos[equipoGanador] << endl;
    cout << "Menor: " << equipos[equipoBaja] << endl;

    // Preguntar al usuario si desea volver a generar o calcular otro campeonato
    char respuesta;
    cout << "Desea volver a generar otra tabla? (s/n): ";
    cin >> respuesta;
    if (respuesta == 's' || respuesta == 'S') {
        // Limpieza
        for (int i = 0; i < NUMERO_EQUIPOS; i++)
        {
            partidosJugados[i] = 0;
            partidosganados[i] = 0;
            partidosPerdidos[i] = 0;
            partido_empate[i] = 0;
            for (int j = 0; j < NUMERO_EQUIPOS; j++)
             {
                resultados[i][j] = 0;

             }

        }

        // Volver a generar el campeonato
        main();

    }

    return 0;
}
