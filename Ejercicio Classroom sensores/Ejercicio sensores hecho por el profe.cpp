
/*
Se te contrata para trabajar en un proyecto en la localidad de Toro Vivo, para un empresa petrolera.
En el relevamiento, nos comentan que tienen una base de datos la cual contiene información
sobre muchos sensores IOT distribuidos a lo largo de la plataforma.

Los mismos se encuentran almacenados en un archivo con el siguiente formato CSV:
<sensor_id>,<timestamp>,<value_type>,<value>;

sensor_id: es el id del sensor, compuesto por 2 números.
timestamp: es la fecha y hora en formato ISO 8601.
value_type: es el tipo de valor, puede ser: "temperature", "pressure", "flow" o "level".
value: es el valor del sensor, es un numero de 3 dígitos.

Los sensores se encuentran distribuidos en distintos puntos de la plataforma, y se van actualizando
en tiempo real.

Se pide:
- Desarrollar una función llamada parse_sensor que dada un string separado por comas con los datos del sensor y un sensor vacio, ese mismo sensor con los datos parseados.
- Desarrollar una función llamada get_highest_value que dada una lista de sensores, devuelva el valor mas alto de alguno de los sensores.
- Desarrollar una función llamada get_lowest_value que dada una lista de sensores, devuelva el valor mas bajo de alguno de los sensores.
- Desarrollar una función llamada get_average_value que dada una lista de sensores, devuelva el valor promedio de alguno de los sensores.
-
- Desarrollar una función llamada get_range_value que dado un vector de sensores, todos del mismo tipo, devuelva una túpla con el valor mas alto y el mas bajo (un vector de 2 enteros).
- Desarrollar una función llamada find_sensor_by_id que dado un vector de sensores y un id, devuelva el sensor con ese id.
- Desarrollar una función llamada get_sensor_information que reciba un vector de sensores y un id, y muestre por pantalla, el rango de valores, el valor promedio, su tipo y la ultima lectura


- En el main, se pide:
Leer el archivo CSV los datos de los sensores y guardarlos en un vector de sensores.
Mostrar por cada tipo de sensor:
    El rango de valores
    El valor promedio
    La ultima lectura
Pedir al usuario que ingrese un id de sensor.
obtener el sensor por el id ingresado y mostrar por pantalla la información del sensor.
*/

#include <stdio.h>
#define SENSOR_SIZE 5

struct Sensor{
    int id;
    int timestamp;
    int value;
    int value_type;
};


void parse_sensor(Sensor *empty_sensor){
    printf("Ingrese el id del sensor: ");
    scanf("%d", &empty_sensor->id);
    printf("Ingrese el timestamp del sensor: ");
    scanf("%d", &empty_sensor->timestamp);
    printf("Ingrese el valor del sensor: ");
    scanf("%d", &empty_sensor->value);
};

int get_highest_value(Sensor sensors[]){
    int highest_value = sensors[0].value;
    for (int i = 1; i < SENSOR_SIZE; i++){
        if (sensors[i].value > highest_value){
            highest_value = sensors[i].value;
        }
    }   
    return highest_value;
}

int get_lowest_value(Sensor sensors[]){
    int lowest_value = sensors[0].value;
    for (int i = 1; i < SENSOR_SIZE; i++){
        if (sensors[i].value < lowest_value){
            lowest_value = sensors[i].value;
        }
    }
    return lowest_value;
}

float get_average_value(Sensor sensors[]){
    int sum = 0;
    for (int i = 0; i < SENSOR_SIZE; i++){
        sum += sensors[i].value;
    }
    return (float)sum / SENSOR_SIZE;
}


/*
Aca hubo que usar vector, no hay problema si lo hicieron de otra manera.
Es por una cuestion que aun no vimos.
*/
#include <vector>
using namespace std;

vector<int> get_range_value(Sensor sensors[]){
    int highest_value = get_highest_value(sensors);
    int lowest_value = get_lowest_value(sensors);

    return {highest_value, lowest_value};
}

Sensor find_sensor_by_id(Sensor sensors[], int id){
    /*
    Este approach tiene un problema, y es que si hay dos sensores con el mismo id,
    el ultimo encontrado sera el que se guarde en found_sensor
    */
    struct Sensor found_sensor;

    for (int i = 0; i < SENSOR_SIZE; i++){
        if (sensors[i].id == id){
            found_sensor = sensors[i];
        }
    }

    return found_sensor;

    /*
    -- Alternativa: --
    Esta es una alternativa un poco mejor que la anterior, ya que no hace falta recorrer todo el array.
    Esto con arrays muy largos y busquedas muy caras (osea un if complejo y un array de por ejemplo 100 millones de elementos)
    termina siendo mas lento que la alternativa de abajo
    */
    // for (int i = 0; i < SENSOR_SIZE; i++){
    //     if (sensors[i].id == id){
    //         return sensors[i];
    //     }
    // }
}

void get_sensor_information(Sensor sensors[], int id){
    Sensor sensor = find_sensor_by_id(sensors, id);
    
    vector<int> range = get_range_value(sensors);
    
    float average = get_average_value(sensors);
    printf("Sensor: %d, %d, %d\n", sensor.id, sensor.timestamp, sensor.value);
    printf("Rango: %d, %d\n", range[0], range[1]);
    printf("Promedio: %f\n", average);
}



int main(){
    Sensor sensors[SENSOR_SIZE];
    
    // Llenamos todos los sensores
    for (int i = 0; i < SENSOR_SIZE; i++){
        parse_sensor(&sensors[i]);
    }

    // Pedimos al usuario que ingrese un id de sensor
    // o en su defecto cambiamos la variable un_id_que_hayas_elegido
    int un_id_que_hayas_elegido = 1;
    // -- Alternativa: --
    // int un_id_que_hayas_elegido;
    // printf("Ingrese un id de sensor: ");
    // scanf("%d", &un_id_que_hayas_elegido);

    // Mostramos la información del sensor
    get_sensor_information(sensors, un_id_que_hayas_elegido);
    
    return 0;
}
