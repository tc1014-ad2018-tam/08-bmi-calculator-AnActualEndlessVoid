/*
 * Este programa fue hecho con el proposito de calcular el indice de masa corporal del usuario utilizando los datos
 * que este nos proporciona
 *
 * Mario Emilio Aguilar Chung
 * 9/13/2018
 * A01411210@itesm.mx
 *
 */
#include <stdio.h>
#include <math.h>

//Aqui establezco la funcion para realizar la operacion de BMI para sistema imperial
void BMIi (double h, double w, double* BMI) {
    w = w * 0.453592;
    h = h*0.3048;
    *BMI = w / pow (h,2);
}

//Aqui establezco la funcion para realizar la operacion de BMI para sistema metrico
void BMIm (double h, double w, double* BMI) {
    *BMI =  (w / pow (h,2));
}

//Aqui establezco la funcion que me dira que categoria de BMI tengo
void BMIgrade (double BMI) {
    if (BMI < 18.5) {
        printf ("Estas debajo de tu peso ideal. Ve a un nutriologo");
    }
    else if ((18.5 <= BMI) && (24.9 >= BMI)) {
        printf ("Felicidades, tienes un BMI adecuado");
    }
    else if ((25 <= BMI) && (29.99 >= BMI)) {
        printf ("Tienes sobrepeso. Ve a un nutriologo");
    }
    else if (30 <= BMI) {
        printf ("Tienes obesidad. Ve a un nutriologo");
    }

}

int main() {
    //Establezco mis variables
    double weight = 0.0;
    double height = 0.0;
    double BMI = 0.0;
    int system;

//Le pido al usuario que elija un sistema de medicion
    printf ("Presiona 1 para usar el sistema metrico \n");
    printf ("Presiona 2 para usar el sistema imperial \n");
    printf ("Eleccion:");
    scanf ("%i", &system);


    //Hago un switch con las posibilidades de sistemas
    switch (system)
    {
        case 1:
            //recolecto los datos
            printf ("Dame tu peso en kilos: \n");
            scanf ("%lf", &weight);

            printf ("Dame tu altura en metros: \n");
            scanf ("%lf", &height);
            //mando a la funcion
            BMIm (height, weight, &BMI);
            break;

        case 2:
            //recolecto los datos
            printf ("Dame tu peso en libras: \n");
            scanf ("%lf", &weight);

            printf ("Dame tu altura en pies: \n");
            scanf ("%lf", &height);
            //mando a la funcion
            BMIi (height, weight, &BMI);
            break;

        default:
            //en caso de que el usuario haya puesto un numero invalido
            printf ("Entrada invalida. Por favor seleccione 1 o 2");
            return 0;

    }
//le muestro al usuario su resultado
    printf ("Tu BMI es de %lf \n", BMI);
    //mando a la funcion
    BMIgrade (BMI);



    return 0;
}