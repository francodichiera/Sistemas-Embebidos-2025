#include <iostream>
#include <stdio.h>

#define size 5

struct Persona
{
  int edad;
  char nombre[20];
  char sexo; //"F" o "M"
  char estudios; //‘N’: no posee, ‘P’: primario, ‘S’: secundario, ‘T’: terciario, ‘U’: universitario
  char indicador_estudios; // ‘I’: incompleto, ‘C’: completo
};
struct Familia
{   
    Persona integrantes[4];
    int domicilio; // un numero o altura 
    char vivienda; // "C" casa , "D" depto
    char apellido[20];
    
};

struct Familia familia[size];

void print_information(struct Persona p) 
{
    printf("Nombre: %s, Edad: %d, Sexo: %c, Estudios: %c, Estado: %c\n", p.nombre, p.edad, p.sexo, p.estudios, p.indicador_estudios);
}

void filter_by_studies(struct Familia familia[], char estudio) 
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (familia[i].integrantes[j].estudios == estudio) 
            {
                print_information(familia[i].integrantes[j]); 
            }
        }
    }
}

void filter_by_age_greater_than(struct Familia familia[], int edad_minima)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 4; j++) 
        {
            if (familia[i].integrantes[j].edad >= edad_minima)
            {
                print_information(familia[i].integrantes[j]); 
            }
        }
    }
}

void filter_by_home_type(struct Familia familia[], char tipo_vivienda) 
{
    for (int i = 0; i < size; i++) 
    {
        if (familia[i].vivienda == tipo_vivienda) 
        {
            printf("Familia: %s, Domicilio: %d\n", familia[i].apellido, familia[i].domicilio); 
        }
    }
}
void find_family_with_most_university_graduates(struct Familia familia[]) 
{
    int max_universitarios = 0;
    int index_familia = -1;

    for (int i = 0; i < size; i++)
    {
        int count_universitarios = 0;
        for (int j = 0; j < 4; j++) 
        {
            if (familia[i].integrantes[j].estudios == 'U' && familia[i].integrantes[j].indicador_estudios == 'C') 
            {
                count_universitarios++;
            }
        }
        if (count_universitarios > max_universitarios)
        {
            max_universitarios = count_universitarios;
            index_familia = i;
        }
    }

    if (index_familia != -1) 
    {
        printf("Familia con más universitarios: %s, Domicilio: %d\n", familia[index_familia].apellido, familia[index_familia].domicilio);
    }
}

void calcular_porcentaje_analfabetismo(struct Familia familia[])
{
    int total_personas = 0;
    int analfabetos = 0;

    for (int i = 0; i < size; i++) 
    {
        for (int j = 0; j < 4; j++) 
        {
            total_personas++;
            if (familia[i].integrantes[j].edad > 10 && familia[i].integrantes[j].estudios == 'N') 
            {
                analfabetos++;
            }
        }
    }

    double porcentaje = 0;
    if (total_personas > 0) 
    {
        porcentaje = (double(analfabetos) / total_personas) * 100;
    }
    
    printf("Porcentaje de analfabetismo: %.2f%%\n", porcentaje);
}


int main() 
{
    Familia familia_perez = {.apellido = "perez"};
    
    Persona juan = {.edad =45, .nombre= "juan"};
    Persona franco = {.edad =17, .nombre= "juan"};
    Persona ana = {.edad =42, .nombre= "juan"};
    Persona maria = {.edad =15, .nombre= "juan"};
    
    familia_perez.integrantes[0]= juan;
    familia_perez.integrantes[1]= franco;
    familia_perez.integrantes[2]= ana;
    familia_perez.integrantes[3]= maria;
    
    
    Familia familia_gomez = {.apellido = "gomez"};

    Persona luis = {.edad = 50, .nombre = "luis"};
    Persona carla = {.edad = 18, .nombre = "carla"};
    Persona sofia = {.edad = 45, .nombre = "sofia"};
    Persona tomas = {.edad = 12, .nombre = "tomas"};

    familia_gomez.integrantes[0] = luis;
    familia_gomez.integrantes[1] = carla;
    familia_gomez.integrantes[2] = sofia;
    familia_gomez.integrantes[3] = tomas;

    Familia familia_fernandez = {.apellido = "fernandez"};

    Persona roberto = {.edad = 38, .nombre = "roberto"};
    Persona lucia = {.edad = 16, .nombre = "lucia"};
    Persona juliana = {.edad = 35, .nombre = "juliana"};
    Persona nico = {.edad = 10, .nombre = "nico"};

    familia_fernandez.integrantes[0] = roberto;
    familia_fernandez.integrantes[1] = lucia;
    familia_fernandez.integrantes[2] = juliana;
    familia_fernandez.integrantes[3] = nico;

    Familia familia_mendez = {.apellido = "mendez"};

    Persona ernesto = {.edad = 60, .nombre = "ernesto"};
    Persona raul = {.edad = 30, .nombre = "raul"};
    Persona claudia = {.edad = 55, .nombre = "claudia"};
    Persona emilia = {.edad = 25, .nombre = "emilia"};

    familia_mendez.integrantes[0] = ernesto;
    familia_mendez.integrantes[1] = raul;
    familia_mendez.integrantes[2] = claudia;
    familia_mendez.integrantes[3] = emilia;
    
     // Llamar a las funciones implementadas
    printf("\nFiltrar personas con estudios primarios completos:\n");
    filter_by_studies(familia, 'P');

    printf("\nCalcular porcentaje de analfabetismo:\n");
    calcular_porcentaje_analfabetismo(familia);
    
    printf("\nEncontrar familia con más graduados universitarios:\n");
    find_family_with_most_university_graduates(familia);

    
    return 0;
}
