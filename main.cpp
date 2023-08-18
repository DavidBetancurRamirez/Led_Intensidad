/* Ejercicio de clase de arquitectura
 * Punto 1: hacer que una luz roja se prenda y apague lento, forma triangular
 * Punto 2: Pedir por consola el color hexadecimal y prenderlo de este color
 */

#include "mbed.h"
#include <iostream>
#include <string>
#include <cstdio>

// Blinking rate in milliseconds
#define BLINKING_UNITS      "ms"
#define BLINKING_RATE      50ms

// Objeto para establecer la comunicación serial con el Pc
UnbufferedSerial serial(USBTX, USBRX, 9600);

using namespace std;

void waitForEnter() {
    /*
        * No tuvimos manera de probarlo con la tarjeta
        * Pero es para que al dar enter se pueda volver a cambiar el color del led
    */
    printf("Presiona Enter para ingresar nuevo color...");
    while (getchar() != '\n');
}

void luzTriangular() {
    // Inicializando leds
    PwmOut ledR(LED1);
    // Determinar periodo
    ledR.period(0.01);

    // Tiempo del pwm
    float pwm = 0.00;
    // Para subir o bajar la intensidad de manera triangular
    int multiplicacion = 1;

    while (true) {
        ledR.write(pwm);
        ThisThread::sleep_for(BLINKING_RATE);
        pwm += 0.10 * multiplicacion;
        if (pwm >= 1.00 || pwm <= 0.00) multiplicacion *= -1;
    }
}

void colorLed() {
    // Inicializando leds
    PwmOut ledR(LED1);
    PwmOut ledG(LED2);
    PwmOut ledB(LED3);

    // Determinar periodo de los leds
    ledR.period(0.01);
    ledG.period(0.01);
    ledB.period(0.01);

    // Color del led
    char inputHex[7];
    while (true) {
        printf("\n Ingresa un valor hexadecimal de 6 dígitos (RRGGBB): ");
        scanf("%6s", inputHex);

        unsigned int colorValue;
        if (sscanf(inputHex, "%x", &colorValue) != 1) {
            printf("Valor hexadecimal no válido.\n");
        }

        unsigned char red, green, blue;
        red = (1-(float)((colorValue >> 16) & 0xFF) / 255.0f);
        green = (1-(float)((colorValue >> 8) & 0xFF) / 255.0f);
        blue = (1-(float)(colorValue & 0xFF) / 255.0f);

        ledR = red;
        ledG = green;
        ledB = blue;

        waitForEnter();
    }
}

int main() {
    // luzTriangular();
    colorLed();
}
