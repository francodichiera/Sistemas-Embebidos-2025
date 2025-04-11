#include <stdio.h>

#define maximo 3

struct Sensor
    {
    int id;        
    int timestamp;  
    int value_type;
    int value;  
    };

void  parse_sensor (Sensor *sensorvacio) //firma de la funcion
{
    printf("Ingrese ID del sensor %d:");
    scanf("%d",  &sensorvacio->id);
        
    printf("Ingrese fecha y hora del sensor : ");
    scanf("%f", &sensorvacio->timestamp);
        
    printf("Ingrese tipo de valor temperature(1), pressure(2), flow (3) o level (4): ");
    scanf("%d", &sensorvacio->value_type);
    
    printf("Ingrese valor del sensor numero de 3 digitos %d:");
    scanf("%d",  &sensorvacio->value);
}

Sensor get_highest_value(Sensor sensores[], int num_sensores)
{   // incializamos un sensor
    Sensor highest_sensor = sensores[0];  

    // Recorremos el arreglo de sensores
    for (int i = 0; i < num_sensores; i++) 
    {
        if (sensores[i].value > highest_sensor.value)
        {
            highest_sensor = sensores[i];  // Si encontramos un valor más alto, actualizamos
        }
    }

    return highest_sensor;
}


Sensor get_lowest_value(Sensor sensores[], int num_sensores) 
{
    Sensor lowest_sensor = sensores[0];  

    for (int i = 0; i < num_sensores; i++) 
    {
        if (sensores[i].value < lowest_sensor.value) 
        {
            lowest_sensor = sensores[i];  // Si encontramos un valor más bajo, lo actualizamos
        }
    }

    return lowest_sensor;
}

float  get_average_value(Sensor sensores[], int num_sensores) 
{
    int sum = 0;

    for (int i = 0; i < num_sensores; i++) 
    {
        sum += sensores[i].value;
    }

    return (float)sum / num_sensores;  // Calcular el promedio
}

void get_range_value(Sensor sensores[], int num_sensores) 
{
    Sensor highest_sensor = get_highest_value(sensores, num_sensores);
    Sensor lowest_sensor = get_lowest_value(sensores, num_sensores);
    
    int range[2];
    range[0] = lowest_sensor.value;
    range[1] = highest-sensor.value;
   
    printf("Rango de valores: [%d, %d]\n", range[0], range[1]);
  
}

Sensor find_sensor_by_id (Sensor sensores[], int num_sensores, int id)
{
    for (int i = 0; i < num_sensores; i++) 
    {
        if (sensores[i].id == id) 
        {
            return sensores[i];  
        }
    }
    // Retornar un "sensor no encontrado"
    Sensor sensor_not_found = {-1}; 
    return sensor_not_found;
}

Sensor get_sensor_information(Sensor sensores[], int num_sensores, int id)
struct Sensor sensor = find_sensor_by_id(sensores, num_sensores, id);
    
    if (sensor.id == -1)
    {
        printf("Sensor con ID %d no encontrado.\n", id);
        return;
    }

    printf("Sensor ID: %d\n", sensor.id);
    printf("Timestamp: %d\n", sensor.timestamp);
    printf("Tipo de valor: %d\n", sensor.value_type);  // Puedes cambiar esto para mostrar cadenas
    printf("Ultima lectura: %d\n", sensor.value);

    get_range_value(sensores, num_sensores);  // Opción para imprimir el rango
    double promedio = get_average_value(sensores, num_sensores);
    printf("Promedio de los valores: %.2f\n", promedio);
}
//*******TERMINAR MAIN*******
int main() 
{
    Sensor sensores[maximo];
    Sensor highest_sensor = get_highest_value(sensores, maximo);
    return 0;
}
