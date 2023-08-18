# Programa de Control de LED RGB

Este es un proyecto de control de LED RGB desarrollado con la plataforma mbed. El programa permite encender un LED con colores específicos en formato RGB hexadecimal y también realiza una animación de cambio de intensidad triangular en un LED rojo. Además, está diseñado para interactuar con una tableta a través de comunicación serial.

# Integrantes

• David Betancur

• Tomas Lopera

# Contenido

1. Descripción
2. Requisitos

# Descripción

Este programa desarrollado en mbed permite controlar un LED RGB de manera interactiva. Incluye dos modos principales: uno para realizar una animación de cambio de intensidad triangular en un LED rojo y otro para establecer el color del LED RGB utilizando valores hexadecimales.

# Punto 1: Modo Animación Triangular
El Modo Animación Triangular agrega vida al LED rojo a través de una secuencia dinámica. La función **luzTriangular()** orquesta una animación cautivadora al alterar la intensidad luminosa en un ciclo triangular. El LED rojo, identificado como **ledR**, va aumentando y disminuyendo su brillo en una transición fluida. Este efecto se logra mediante una lógica, donde la variable **pwm** controla la intensidad y determina la dirección del cambio.

# Punto 2: Modo Color LED RGB
En el Modo Color LED RGB, puedes personalizar el LED RGB según tus preferencias de color. La función **colorLed()** encabeza esta característica al permitirte ingresar un valor hexadecimal de 6 dígitos (**RRGGBB**) mediante la comunicación serial. Una vez ingresado, el programa interpreta el valor hexadecimal utilizando la función **sscanf()**, luego descompone los componentes rojo, verde y azul a través de operaciones de bits. Estos componentes ajustan las intensidades de los LEDs rojo (**ledR**), verde (**ledG**) y azul (**ledB**) respectivamente, para lograr el color deseado. La función **waitForEnter()** brinda un control cómodo y claro al permitirte reiniciar la entrada de colores cuando lo desees, sin embargo, no se pudo ejecutar y probar debido a que no se tenía la tableta para verificar si el código funcionaba.

# Requisitos

• Placa compatible con mbed

• LED RGB conectado a los pines correspondientes en la placa

• Tableta o dispositivo de comunicación serial para interactuar con el programa
