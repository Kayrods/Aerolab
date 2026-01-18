# Aerolab New

Bienvenido al proyecto **Aerolab New**. Este proyecto consiste en el diseño y construcción de un vehículo  nautico controlado mediante Arduino, con componentes mecánicos impresos en 3D.

## Estructura del Proyecto

El proyecto está organizado en las siguientes carpetas principales:

- **Software**: Contiene el código fuente para el control del vehículo.
  - `AerolabOficialCode/`: Carpeta del sketch de Arduino.
- **Partes Impresas (3D)**: Modelos 3D listos para impresión (formato `.3mf`).
  - `Proa`: Componentes de la parte delantera.
  - `Popa`: Componentes de la parte trasera.
  - `Centro`: Estructura central.
  - `Soportes`: Elementos de sujeción.
  - `Tapaderas`: Cubiertas para la electrónica.
  - `Accesorios`: Piezas adicionales.
- **Documentación y Otros**:  - `Articulos externos`: Documentación o referencias de componentes comprados.

## Hardware Necesario

Para ensamblar este proyecto necesitarás los siguientes componentes electrónicos y mecánicos:

### Electrónica
- **Microcontrolador**: Arduino (Uno, Nano, o similar).
- **Driver de Motores**: Puente H (L298N o compatible).
- **Motores**: 2 o 4 Motores DC (controlados en pares).
- **Entrada de Control**: Receptor de Radio Control (RC) o un potenciómetro para pruebas (conectado al Pin A0).
- **Fuente de Alimentación**: Batería adecuada para los motores y el Arduino.

### Pines de Conexión (Según el código)
| Componente | Pin Arduino | Descripción |
|------------|-------------|-------------|
| Motor A (IN1/IN2) | 2, 3 | Control de dirección Motor 1 |
| Motor B (IN3/IN4) | 4, 5 | Control de dirección Motor 2 |
| Enable (PWM) | 9 | Control de velocidad (PWM) |
| Señal de Control | A0 | Entrada analógica (0-1023) |

## Software

El código principal se encuentra en `Software/AerolabOficialCode/AerolabOficialCode.ino`.

### Funcionalidad
El script controla la dirección y velocidad de los motores basándose en una señal analógica de entrada:

- **Zona Muerta (Stop)**: Si la señal está entre 505 y 520, los motores se detienen.
- **Avance**: Señal > 520. La velocidad aumenta proporcionalmente hasta el máximo (1023).
- **Reversa**: Señal < 505. La velocidad aumenta inversamente proporcional hasta el mínimo (0).

### Instalación
1. Instala el [Arduino IDE](https://www.arduino.cc/en/software).
2. Abre el archivo `AerolabOficialCode.ino`.
3. Conecta tu placa Arduino al PC.
4. Selecciona el puerto y la placa correcta en el IDE.
5. Carga el código (`Upload`).

## Fabricación (Impresión 3D)

Las carpetas `Proa`, `Popa`, `Centro`, etc., contienen archivos `.3mf`. Estos archivos son proyectos de fabricación 3D que pueden abrirse en "Slicers" como Cura o PrusaSlicer.

- **Material Recomendado**: PLA o PETG para mayor resistencia.
- **Relleno**: Se recomienda al menos 20% para partes estructurales.

## Puesta en Marcha

1. Imprime todas las piezas necesarias de las carpetas de diseño.
2. Ensambla la estructura utilizando los soportes y tornillería adecuada.
3. Realiza el cableado electrónico siguiendo el esquema de pines detallado arriba.
4. Carga el código en el Arduino.
5. Alimenta el sistema y prueba el control de movimiento variando la entrada en A0.

---
*Documentación generada automáticamente para Aerolab New.*
