

![Austral Ingenieria](https://encrypted-tbn0.gstatic.com/images?q=tbn%3AANd9GcQooGo7vQn4t9-6Bt46qZF-UY4_QFpYOeh7kVWzwpr_lbLr5wka)


# Proyecto 30-1st-web 

## Secciones

- [Objetivo](#objetivo)
- [Programa](#programa)
- [platformio.ini](#platformio.ini)
- [Constantes](#constantes)


## Objetivo

>   El objetivo es construir una página muy simple de Web que reside en el SoC (ESP32)
>   El único objeto de esta página es poner un texto de saludo acorde al SoC donde corra.
>   Usar con cualquier placa que incluya a los procesadores indicados
>
>   Puede ver [Create A Web Server with ESP32](https://electropeak.com/learn/create-a-web-server-w-esp32/)

### Programa

> Para poder crear una página de Web, aparte de la biblioteca residente que permite trabajar con WiFi, se debe tener también una biblioteca que permita crear un servidor de Web.

> De la misma manera que en el caso de la biblioteca de WiFi, el archivo de encabezamiento (_header file_) que debe usarse es _WebServer.h_


~~~ C++

#include <WiFi.h>
#include <WebServer.h>

~~~

> En la línea 16 se crea un objeto _server_ de tipo _Webserver_  que reportará sobre el _port_ 80 de TCP

> Entre las líneas 16 y 42 están las funciones de la página Web

~~~ C++

#include <WiFi.h>
#include <WebServer.h>

#define ServerObject    WebServer
#define HelloMsg        "Hello from ESP32 !"

~~~

> El resto del programa está constituído por las tradicionales funciones _setup_ y _loop_.

> En _setup_ (líneas 44 a 63) se inicializa la interfase serie, se conecta con WiFi y se regiostran dos funciones del servidor, a saber _handleRoot_, que es la función que maneja el pedido del cliente y la función _handleNotFound_ que maneja el error producido por solicitar una página que no sea la página raíz.
> A continuación, se comienza la actividad del servidor y se imprime que el servidor ya espera pedidos.

> A su vez, en _loop_ (líneas 65 a 69), simplemente, se llama al método _handleClient_ del objeto _server_ de manera que, frente a un requerimiento, lo despache con las dos unciones previamente registradas

> Para acceso a WiFi simplificado usado en este proyecto, ver archivo _esp32wifi.md_ en este mismo directorio.

### platformio.ini

#### Constantes

> Como se habrá observado, hay solo una constante _SERIAL\_BAUD_ que se define en el archivo _platformio.ini_ para mayor comodidad de mantenimiento; de esa manera, no es necesario entrar en los archivos de código para dicho mantenimiento.


