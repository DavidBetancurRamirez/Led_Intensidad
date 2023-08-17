/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include <iostream>
#include <string>

// Blinking rate in milliseconds
#define BLINKING_UNITS      "ms"
#define BLINKING_RATE      500ms

// Objeto para establecer la comunicación serial con el Pc
UnbufferedSerial serial(USBTX, USBRX, 9600);

using namespace std;

string obtenerColor() {
    string input = "";

    while (input.length()!=6) {
        cout << "Ingrese el color del led (Hexadecimal): ";
        cin >> input;
    }

    unsigned int colorValue;
    if (sscanf(input, "%x", &colorValue) != 1) {
        printf("Valor hexadecimal no válido.\n");
    }
    return colorValue;
}

int main() {
    // Inicializando leds
    PwmOut ledR(LED1);
    PwmOut ledG(LED2);
    PwmOut ledB(LED3);

    // Determinar periodo
    ledR.period(0.10);
    ledG.period(0.10);
    ledB.period(0.10);

    // Tiempo del pwm
    float pwm = 0.00;
    // Para subir o bajar la intensidad de manera triangular
    int cambio = 1;

    while (true) {
            // Punto 1
        ledR.write(pwm);
        ThisThread::sleep_for(BLINKING_RATE);
        pwm += 10 * cambio;
        if (pwm == 1.00 || pwm == 0.00) cambio *= -1;
    }

    /*
        // Punto 2
    // Color del led
    string color = obtenerColor();

    // Extraer los componentes R, G y B del valor hexadecimal
    unsigned char red = (color >> 16) & 0xFF;
    unsigned char green = (color >> 8) & 0xFF;
    unsigned char blue = color & 0xFF;

    // Configurar los valores PWM para los pines R, G y B
    ledR.write(float(red) / 255.0);
    ledG.write(float(green) / 255.0);
    ledB.write(float(blue) / 255.0);
    */
}
