Introducción
============

Tipos de datos
--------------

Dentro de ``Glib`` hallaremos tipos de datos útiles que nos harán más fácil la
tarea de construir programas en ``GTK+``. ``Glib`` crea sus propios tipos de datos con
el objetivo de hacer más sencillo transportar programas entre diferentes tipos
de sistemas operativos donde los tipos estándar de C pudieran diferir en
tamaño o alineación de bytes; ``Glib`` se encargará de esas diferencias.

Los tipos que se usan en ``Glib`` no son muy diferentes de los que usamos en el
estándar de C. Así que realmente no resultará nada complicado habituarse a
ellos. La Tabla 1 muestra una comparación entre los tipos de datos de ``Glib`` y
su equivalencia en ANSI C[5].

+-----------------------+----------------------------------------+
| Definidos en ``Glib`` | Equivalencia en el estándar ANSI de C  |
+=======================+========================================+
| gchar                 | typedef char gchar;                    |
+-----------------------+----------------------------------------+
| gshort                | typedef short gshort;                  |
+-----------------------+----------------------------------------+
| glong                 | typedef long glong;                    |
+-----------------------+----------------------------------------+
| gint                  | typedef int gint;                      |
+-----------------------+----------------------------------------+
| gchar                 | typedef char gchar;                    |
+-----------------------+----------------------------------------+
| gboolean              | typedef int gboolean;                  |
+-----------------------+----------------------------------------+
| gpointer              | typedef void* gpointer;                |
+-----------------------+----------------------------------------+


Algunos tipos no tan conocidos como ``void *``, son realmente útiles para pasar
diferentes estructuras de datos a funciones. Otros tipos definidos en ``Glib`` se
muestran en la siguiente tabla.

+---------------------------+----------------------------------------+
| Tipo definido en ``Glib`` | Equivalencia en ANSI C                 |
+===========================+========================================+
| gint8                     | typedef signed char gint8;             |
+---------------------------+----------------------------------------+
| gint16                    | typedef signed short gint16;           |
+---------------------------+----------------------------------------+
| gint32                    | typedef signed int gint32;             |
+---------------------------+----------------------------------------+
| gint64                    | typedef signed long long gint64;       |
+---------------------------+----------------------------------------+
| guint8                    | typedef unsigned char guint8;          |
+---------------------------+----------------------------------------+
| guint16                   | typedef unsigned short guint16;        |
+---------------------------+----------------------------------------+
| guint32                   | typedef unsigned int guint32;          |
+---------------------------+----------------------------------------+
| guint64                   | typedef unsigned int guint64;          |
+---------------------------+----------------------------------------+
| guchar                    | typedef unsigned char guchar;          |
+---------------------------+----------------------------------------+
| gushort                   | typedef unsigned short gushort;        |
+---------------------------+----------------------------------------+
| gulong                    | typedef unsigned long gulong;          |
+---------------------------+----------------------------------------+
| gsize                     | typedef unsigned int gsize;            |
+---------------------------+----------------------------------------+
| gssize                    | typedef signed int gssize;             |
+---------------------------+----------------------------------------+
| gconstcopointer           | typedef const void *gconstpointer;     |
+---------------------------+----------------------------------------+

Tabla 2: Otros tipos de datos definidos en ``Glib``.

 En lugar de incrementar la complejidad a las aplicaciones, los tipos de datos
de ``Glib`` compactan complicadas definiciones de tipos en identificadores de
tipos de datos que se reconocen más fácilmente, pues son auto descriptivos.
Esto elimina gran cantidad de trabajo a la hora de mantener programas muy
grandes y el código se hace más legible.

Límites de tipos de datos
-------------------------

Por cada tipo de dato definido en la tablas 1 y 2 ``Glib`` ha definido valores
indicando los valores mínimos y máximos que pueden contener, exceptuando los
tipos de datos ``gpointer``, ``gconstpointer``, ``gssize`` y ``gboolean``.

En lugar de memorizar nombres complicados podemos adivinar los límites de un
tipo de datos mediante su nombre. Por ejemplo, ``gint`` está definido entre los
límites ``G_MAXINT`` y ``G_MININT`` mientras que un ``gdouble`` se encuentra acotado
entre ``G_MAXDOUBLE y ``G_MINDOUBLE``. Por conveniencia la tabla 3 agrupa los tipos
de datos y sus límites definidos.

Tabla 3: Límites de tipos de datos

+-----------------------+----------------------------------------+
| Tipo de dato          | Límites                                |
+=======================+========================================+
| ``gint``              | ``G_MININT`` a ``G_MAXINT``            |  
+-----------------------+----------------------------------------+
| ``gshort``            | ``G_MINSHORT`` a ``G_MAXSHORT``        |   
+-----------------------+----------------------------------------+
| ``glong``             | ``G_MINLONG`` a ``G_MAXLONG``          |
+-----------------------+----------------------------------------+
| ``guint``             | ``0`` a ``G_MAXUINT``                  |
+-----------------------+----------------------------------------+
| ``gushort``           | ``0`` a ``G_MAXUSHORT``                |
+-----------------------+----------------------------------------+
| ``gulong``            | ``0`` a ``G_MAXULONG``                 |
+-----------------------+----------------------------------------+
| ``gint8``             | ``G_MININT8`` a ``G_MAXINT8``          |
+-----------------------+----------------------------------------+
| ``gint16``            | ``G_MININT16`` a ``G_MAXINT16``        |
+-----------------------+----------------------------------------+
| ``gint32``            | ``G_MININT32`` a ``G_MAXINT32``        |
+-----------------------+----------------------------------------+
| ``gint64``            | ``G_MININT64`` a ``G_MAXINT64``        |
+-----------------------+----------------------------------------+
| ``guint8``            | ``0`` a ``G_MAXUINT8``                 |
+-----------------------+----------------------------------------+
| ``guint16``           | ``0`` a ``G_MAXUINT16``                |
+-----------------------+----------------------------------------+
| ``guint32``           | ``0`` a ``G_MAXUINT32``                |
+-----------------------+----------------------------------------+
| ``guint64``           | ``0`` a ``G_MAXUINT64``                |
+-----------------------+----------------------------------------+
| ``gfloat``            | ``G_MINFLOAT`` a ``G_MAXFLOAT``        |
+-----------------------+----------------------------------------+
| ``gdouble``           | ``0`` a ``G_MAXUSHORT``                |
+-----------------------+----------------------------------------+
| ``gsize``             | ``0`` a ``G_MAXSIZE``                  |
+-----------------------+----------------------------------------+

 

Macros y definiciones útiles
----------------------------

``Glib`` viene empacada con una gran cantidad de Macros que nos evitan gran
cantidad de trabajo. A continuación revisaremos un conjunto de Macros y
definiciones útiles y de uso común.


Macros básicas
~~~~~~~~~~~~~~

Las dos macros más sencillas, sin embargo útiles son ``TRUE`` y ``FALSE``.
Solamente definen un cero para un valor de tipo ``gboolean`` falso y diferente de
cero para un valor positivo. Sin embargo es mucho mas intuitivo y explicativo
trabajar con ``TRUE`` y ``FALSE``. Veamos una comparación.


Macros referentes al Sistema Operativo
--------------------------------------

Este conjunto de macros son útiles al escribir programas que funcionarán en
diferentes Sistemas Operativos. ``G_OS_WIN32``, ``G_OS_BEOS``, ``G_OS_UNIX``
solo están definidas en su respectiva plataforma y deben utilizase entre
bloques de directivas del compilador "``#ifdef ... #elif ...#endif``", lo que
causará que el compilador construya secciones de código diferentes para cada
plataforma. Veamos el siguiente ejemplo.


.. code-block:: c

    #include <glib.h>
    /* ... */
    #ifdef G_OS_WIN32
        const gchar *dispositivo = “COM1”;
    #elif G_OS_BE_OS
        const gchar *dispositivo = “/dev/usb0”;
    #else // G_OS_UNIX
        const gchar *dispositivo = “/dev/ttyS0”;
    #endif
    /* ... */

El ejemplo anterior definirá una compilación condicional en la cual,
dependiendo de la plataforma donde se compile el programa, la cadena
``dispositivo`` tendrá diferente valor en cada Sistema Operativo.

Las macros ``G_DIR_SEPARATOR`` y ``G_DIR_SEPARATOR_S`` contienen el carácter
separador de directorios. Su valor es ``'/'`` en sistemas tipo UNIX y ``'\'``
en sistemas Windows. La segunda macro contiene la misma información que la
primera pero en formato de cadena: ``'/'`` y ``'\'``.
``G_IS_DIR_SEPARATOR(c)`` acepta un carácter ``c`` y determina si es el
carácter separador de directorios. Esta macro devuelve ``TRUE`` si el carácter
es ``'/'`` en sistemas UNIX o ``'\'`` en Sistemas Windows.

``G_SEARCHPATH_SEPARATOR`` y ``G_SEARCHPATH_SEPARATOR_S`` devuelven el carácter
separador de rutas en forma de carácter o cadena respectivamente. Este
carácter es ``':'`` para sistemas UNIX y ``';'`` para Windows.

Macros y constantes matemáticas
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Existen ciertas operaciones matemáticas comunes que no se encuentran
disponibles en la biblioteca estándar de C.

``MIN(a, b) y MAX(a, b) calculan el valor mínimo y máximo de entre dos números
``a y b, mientras que ABS(n) calcula el valor absoluto de un número n.

``CLAMP(x, a, b)`` se asegura de que el número ``x`` se encuentre dentro de
los límites ``a`` y ``b``. Si ``x`` se encuentra dentro de estos límites,
``CLAMP()`` devolverá el número ``x``, si esto no se cumple y ``x`` es mayor
que el límite superior ``b``, ``CLAMP()`` regresará este valor, de lo
contrario ``x`` es menor que el límite inferior ``a``, ``CLAMP()`` regresará
el valor de límite inferior a. Esta macro resulta confusa, pero es útil al
posicionar objetos gráficos en la pantalla y simular cierta resistencia al
movimiento.

La siguiente tabla muestra constantes matemáticas predefinidas en ``Glib``. En
la documentación de ``Glib`` existen uniones para acceder al signo, la mantisa
y el exponente de números de tipo coma flotante que cumplan con el estándar
IEEE 754.


+------------------------+-------------------------+-------------------------------------------------+
| Símbolo matemático     | Definición en ``Glib``  | Valor                                           |
+========================+=========================+=================================================+
| :math:`\pi`            | ``G_PI``                | ``3.1415926535897932384626433832795028841971``  |
+------------------------+-------------------------+-------------------------------------------------+
| :math:`\frac{\pi}{2}`  | ``G_PI2``               | ``1.5707963267948966192313216916397514420985``  |
+------------------------+-------------------------+-------------------------------------------------+
| :math:`\frac{\pi}{4}`  | ``G_PI4``               | ``0.7853981633974483096156608458198757210492``  |
+------------------------+-------------------------+-------------------------------------------------+
| :math:`\sqrt`          | ``G_SQRT2``             | ``1.4142135623730950488016887242096980785696``  |
+------------------------+-------------------------+-------------------------------------------------+
| :math:`e`              | ``G_E``                 | ``2.7182818284590452353602874713526624977572``  |
+------------------------+-------------------------+-------------------------------------------------+
| :math:`\ln(2)`         | ``G_LN2``               | ``0.6931471805599453094172321214581765680755``  |
+------------------------+-------------------------+-------------------------------------------------+
| :math:`\ln(10)`        | ``G_LN10``              | ``2.3025850929940456840179914546843642076011``  |
+------------------------+-------------------------+-------------------------------------------------+
| :math:`\log_{10}(2)`   | ``G_LOG2_BASE10``       | ``2.3025850929940456840179914546843642076011``  |
+------------------------+-------------------------+-------------------------------------------------+


Tabla 4: Constantes matemáticas predefinidas en ``Glib``.

Macros para verificación de errores, excepciones y depurado
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Un buen diseño de software no viene de la noche a la mañana. Parte importante
del tiempo de desarrollo de un programa se consume en la depuración de
errores. También es cierto que parte importante del total del código fuente
escrito de un programa robusto se dedica a la validación y corrección de
posibles errores, es decir, que las cosas que deban estar en orden realmente
lo estén.

Los desarrolladores de ``Glib`` nos ofrecen diferentes herramientas: 7 macros
para ayudarnos a mejorar nuestros programas.

La macro `g_assert() <https://developer.gnome.org/glib/stable/glib-Testing.html#g-assert>`_ 
recibe como parámetro una expresión, tal y como se usa en el condicional 
``if... then ... else ...`` Si la condición especificada falla o es ``FALSE``, el
programa termina especificando un mensaje de error.

Un buen ejemplo de aplicación de estas macro se daría en un función que
transforma cadenas provenientes, por ejemplo, de una comunicación serial.

.. code-block:: c

    #include <glib.h>
    /* ... */
    g_assert (cadena == NULL);
    /* ... */


En el ejemplo anterior, el programa terminara con un mensaje de error si la
cadena es null.

Estas macros puede desactivarse en compilaciones finales mediante la
definición de G_DISABLE_ASSERT al momento de compilar la aplicación.

``g_return_if_fail()`` toma una expresión y regresa de la función si tal
expresión no resulta verdadera o TRUE.De lo contrario registra un mensaje de
aviso y regresa de la función.

``g_return_if_fail()`` sólo se puede utilizar en funciones que no regresan
ningún valor. Para aquellas funciones que debe regresar un valor, esta
``g_return_val_if_fail(expr, val)``, que regresa el valor ``val`` en función
del la expresión ``expr`` al igual que ``g_return_if_fail()``.

Parecido al par anterior, ``g_return_if_reached()`` y
``g_return_val_if_reched()`` regresan de la función si alguna vez son
ejecutadas. La primera macro no toma ninguna expresión mientras que la segunda
espera como parámetro el valor que ha de regresar la función.

Por último ``G_BREAKPOINT`` inserta una instrucción de punto de rompimiento
con el objeto de depurar el programa. Esta macro solo está disponible en la
arquitectura x86.

Macros para manejo de memoria
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Como hemos discutido previamente, ``Glib`` maneja la memoria de de los objetos
que nosotros creamos, pero también nos ofrece la posibilidad de tomar el
control de la memoria en nuestras manos. Esto es conveniente si trabajamos con
vectores o matrices que cambian de tamaño o estamos implementando un nuevo
objeto. Gran parte de las funciones de ``Glib`` se basan en la implementación
disponibles en la librería estándar de C de UNIX. Una región de memoria tiene
un ciclo de vida simple, como el mostrado en la Figura .

Figura aca

Comencemos con la macro que define un puntero nulo: ``NULL``. Está definida en
prácticamente cualquier implementación de C. Esta macro es útil para
inicializar punteros a memoria o estructuras vacías, por ende, un objeto que
no está inicializado contiene un puntero nulo.

Kernighan y Ritchie establecieron tres funciones para manejar memoria de
manera dinámica: ``malloc()``, ``calloc()`` y ``free()``. Estas pueden cubrir
por completo el proceso mostrado en la figura .

El primer paso del ciclo de vida de un bloque de memoria es la función
estándar de C ``malloc()``:

.. code-block:: c

    void *malloc(size_t n);


La función ``malloc()`` toma como único parámetro el número de bytes de
memoria a reservar. Si tal petición no pudo completarse regresará entonces el
puntero ``NULL``.

Por otro lado se encuentra ``calloc()``, cuyo prototipo es:

.. code-block:: c

    void *calloc(size_t n, size_t size);

La funcion ``calloc()`` reservará memoria para un arreglo de ``n`` estructuras
de tamaño ``size``. Como ``malloc()`` y ``calloc()`` regresan punteros de tipo
``void``, se hace necesario hacer un *casting* o moldeado al tipo deseado.
Ve el siguiente ejemplo.

.. code-block:: c

    int *ip;
    ip = (int *) calloc(n, sizeof(int));

Con el objetivo de no recibir quejas del compilador de C, debemos moldear
correctamente el puntero a la memoria reservada que nos entrega ``calloc()``.

Cerrando el ciclo de vida de una región de memoria creada dinámicamente, se
encuentra ``free()``, el cual libera la memoria asignada a un puntero en
especial.

``Glib`` ofrece ``g_malloc()`` y ``g_free();`` ambas funciones operan de igual
manera que sus homólogas en la librería estándar de C, sólo que trabajan con
el tipo ``gpointer``. Además de las dos funciones anteriores, existe un
abanico de posibilidades que ahorran gran cantidad de trabajo al crear una
región de memoria.

Para reservar memoria para una colección de estructuras, ``GLib`` tienen las
macros ``g_new()`` y `g_new0()``. Estas macros  reservan memoria para un
numero de estructuras determinado por ``n_structs``. El tipo de esas
estructuras esta determinado por el parametro: ``struct_type``.

La diferencia entre las dos macros es que ``g_new0()`` inicializará a cero la
región de memoria.

Ambas macros regresan un puntero a la memoria reservada, este puntero ya
estará moldeado a ``struct_type``. Si ocurriera un error al reservar reservar
el número indicado de estructuras en memoria el programa se abortara con un
mensaje de error.

La versión más segura de las macros anteriores se encuentran en
``g_try_new()`` y ``g_try_new0()`` las cuales regresarán un puntero ``NULL``
moldeado a ``struct_type``, en lugar de abortar el programa.


El ciclo de memoria dinámica incluye cambiar el tamaño de ésta, para ello
tendremos dos macros:

.. code-block: c

    #define g_renew(struct_type, mem, n_structs)
    #define g_try_renew(struct_type, mem, n_structs)

Ambas cambian el tamaño de una región de memoria a la que apunta ``mem``. La nueva región de
memoria contendrá ``n_structs`` de tipo ``struct_type``.

La función ``g_try_renew()`` regresa un puntero ``NULL`` moldeado a
``struct_type`` en caso de error, mientras que ``g_renew()`` abortaría el
programa. En ambos casos, cuando la memoria ha podido ser reservada, se
regresa un puntero a la nueva región de memoria.

Existen otras macros como ``g_memove()`` o ``g_newa()``.


Macros de conversión de tipos
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Las aplicaciones escritas en ``GTK+`` usualmente necesitan pasar datos entre
las diferentes partes del programa.

Conforme avancemos
veremos que será muy común convertir un tipo de dato en otro; es por eso que ``Glib`` define seis macros básicas de conversión de tipos casi cualquier objeto o
widget que usemos; son simples casting o moldeado en C, esta técnica
permite que ``GTK+`` se comporte como una librería orientada a Objetos.

La manera de pasar datos de una parte de la aplicación a otra generalmente se
hace utilizando ``gpointer``, el cual es lo equivalente a un puntero ``void``.

Pero existe una limitante al querer pasar números en lugar de estructuras de
datos. Si, por ejemplo, deseáramos pasar un número entero en lugar de una
estructura de datos deberíamos de hacer algo lo siguiente:

.. code-block:: c

    gint *ip = g_new (int, 1);
    *ip = 42;

Los punteros tienen un tamaño de al menos 32 bits en las plataformas que
``Glib`` está disponible. Si vemos con detalle, el puntero``ip`` es puntero a
una constante de tipo ``gint``. Es decir, hay un puntero que apunta a una
región de memoria de 32 bits, al menos. Nosotros tendremos que hacernos cargo
de liberar la memoria del número entero, en base a esto podríamos tratar de
asignar el valor que queremos pasar a un puntero:

.. code-block:: c

    gpointer p;
    int i;
    p = (void*) (long) 42;
    i = (int) (long) p;

Pero esto es incorrecto en ciertas plataformas y en tal caso habría que hacer
lo que sigue:

..code-block:: c

    gpointer p;
    int i;
    p = (void*) (long) 42;
    i = (int) (long) p;

Esto se vuelve demasiado complicado como para llevarlo a la práctica, por eso
los desarrolladores de ``Glib`` han creado las macros ``GINT_TO_POINTER()``,
``GUINT_TO_POINTER()`` y ``GSIZE_TO_POINTER()`` para empacar un ``gint``,
``guint`` o ``gsize`` en un puntero de 32 bits.

Análogamente ``GPOINTER_TO_GINT()``, ``G_POINTER_TO_GUINT()`` y
``GPOINTER_TO_GSIZE()`` sirven para obtener el número que se ha empacado en el
puntero de 32 bits. El ejemplo anterior se cambia a:

.. code-block:: c

    #include <glib.h>
    gpointer p;
    17gint i;
    p = GINT_TO_GPOINTER(42);
    i = GPOINTER_TO_GINT(p);

No es buena idea tratar de empacar en un puntero otro tipo de dato que no sea
``gint`` o ``guint``; la razón de esto es que estas macros solo preservan los
32 bits del entero, cualquier valor fuera de estos límites será truncado.

De igual manera es incorrecto guardar punteros en un entero, por las mismas
razones expuestas arriba, el puntero será truncado y conducirá a gran cantidad
de fallos en el programa.

Tratamiento de mensajes
~~~~~~~~~~~~~~~~~~~~~~~


``Glib`` contiene funciones para mostrar información tales como mensajes del
programa o mensajes de error. Normalmente podríamos llamar a ``printf()`` y
desplegar toda aquella información que deseemos ``Glib`` tiene un sistema de
tratamiento de mensajes mucho más sofisticado, pero a la vez sencillo de usar.

Para comenzar, debes saber que existen tres niveles de despliegue de mensajes:

  1. Despliegue de información variada . Este tipo de mensajes se considera
    inocuos o de carácter meramente informativo, como por ejemplo el estado de un
    proceso.

  2. Registro de mensajes y advertencias . Mensajes que contienen información
    crucial para el funcionamiento interno del programa; los eventos que generan
    estos mensajes no son fatales y el programa puede continuar su ejecución.

  3. Registro y despliegue de errores . Los mensajes de error se consideran
    fatales y solo deben ser utilizados cuando el evento que se esta reportando ha
    sido de tal impacto que el programa no debe continuar. Como ejemplo tenemos
    problemas de direccionamiento y asignación de 18memoria, fallas en el hardware
    y problemas de seguridad. El resultado de desplegar un mensaje de error es la
    terminación definitiva del programa.


Despliegue de información variada
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Comenzamos con `g_print() <https://developer.gnome.org/glib/unstable/glib-
Warnings-and-Assertions.html#g-print>`_. ``g_print()`` funciona de manera
idéntica a ``printf()`` de C.

Pero a diferencia de ``printf()``, que manda cualquier mensaje directamente a
la salida estándar de C (stdout), ``g_print()`` lo hace a través de un
manejador. Este manejador, que usualmente es ``printf()``, puede ser cambiado
a conveniencia. Este manejador puede, en lugar de sacar mensajes a ``stdout``,
hacerlo a un archivo o a una terminal en un puerto serial. El explicar como
registrar el manejador de ``g_print()`` allanará el camino para el siguiente
capítulo. Un manejador (handler, en el idioma anglosajón), es el puntero a una
función escrita por el programador. El prototipo de la función que servirá
como manejador de ``g_print()`` es el siguiente:

.. code-block:: c

    void mi_manejador (const gchar *string);

El puntero de esta función es simplemente su nombre. Este puntero se provee
como parámetro de otra función que lo registra como manejador de
``g_print()``: `g_set_print_handler() <https://developer.gnome.org/glib/unstable/glib-Warnings-and-Assertions.html#g-print>`_

En el siguiente ejemplo mostraremos la facilidad de uso y versatilidad de
``g_print()`` usando un manejador simple.

Listado de Programa 2.3.1

.. code-block:: c

    /***************************************************************************
    *
    Programacion de interfases graficas de usuario con GTK
    *
    * Nombre de archivo: glib-gprint.c
    * Descripcion: Uso del manejador de g_print()
    * Comentarios: Demuestra el funcionamiento de g_print() y g_print_handler()
    *
    *
    ****************************************************************************/
    #include <glib.h>
    /*Para usar g_printf()*/
    #include <glib/gprintf.h>
    
    /* Funcion manejadora de g_print */
    void mi_manejador (const gchar *string){
        g_fprintf(stdout,"mi_manejador:");
        g_fprintf(stdout,string);
    }
    /* Programa principal */
    int main (int argc, char **argv){
    
        GPrintFunc viejo;
        g_print("Usando g_print() sin manejador\n");
        g_print("Estableciendo el nuevo manejador de g_print() ..\n\n");
        viejo = g_set_print_handler(&mi_manejador);
        g_print ("Impresion Normal\n");
        g_print ("Impresion de numeros: %i, %f, 0x%x\n",1,1.01,0xa1);
        g_print("Restableciendo el antiguo manejador de g_print() ..\n\n");
        viejo = g_set_print_handler(viejo);
    }
    g_print("Fin\n");
    return (0);

El programa listado imprime un par de mensajes usando el manejador por defecto
de ``g_print()``, lo cual no presenta demasiada dificultad. La parte más
importante viene a continuación. Usando la variable ``viejo`` guardamos el
puntero al manejador por defecto de ``g_print()`` e inmediatamente
establecemos el nuevo manejador, el cual es nuestra propia función:
``mi_manejador()``. Inmediatamente se pone a prueba nuestro nuevo manejador
imprimiendo algunos mensajes de texto y números. Tomemos en cuenta que el
manejador solo recibe una cadena y no tiene que estar lidiando con parámetros
variables y quien se encarga de esto es ``Glib``. Posteriormente se restablece
el manejador original de ``g_print()`` y todo vuelve a la normalidad. La
comprensión de este sencillo ejemplo es vital para todo el curso, pues no
estamos trabajando con instrucciones comunes y corrientes en el lenguaje C, si
no con punteros a funciones y estructuras complejas de datos. Este tipo de
tópicos por lo general es evitado en los cursos universitarios del lenguaje C.

El siguiente ejemplo es un método interactivo para seleccionar el
comportamiento de ``g_print()``.

Listado de Programa 2.3.2

.. code-block:: c

    /***************************************************************************
    *
    Programacion de interfases graficas de usuario con GTK
    *
    * Nombre de archivo: glib-gprint2.c
    * Descripcion: Uso del manejador de g_print()
    * Comentarios: Ejemplo alternativo para el uso del manejador
    * de g_print()
    *
    ****************************************************************************/
    #include <glib.h>
    /*Para usar g_printf()*/
    #include <glib/gprintf.h>

    /* Funcion manejadora de g_print */
    void mi_manejador (const gchar *string){
        g_fprintf(stdout,"mi_manejador: ");
        g_fprintf(stdout,string);
    }

    void muestra_ayuda( void ) {
        printf("\nError, no ha indicado ningun parametro, o es invalido.\n");
        printf("uso:\n\t--normal g_print normal\n\t--manejador g_print con manejador\n");
    }

    /* Programa principal */
    int main (int argc, char **argv) {
        GPrintFunc viejo;

        if (argc <= 1){
            muestra_ayuda();
            return 0;
        }

        if (g_str_equal(argv[1],"--normal")){
            printf("--== Usando tratamiento normal de mensajes ==--\n");
        } else if (g_str_equal(argv[1],"--manejador")) {
            printf("--== Usando tratamiento con manejador ==--\n");
            viejo = g_set_print_handler(&mi_manejador);
        } else {
            muestra_ayuda();
            return 0;
        }

        /*Imprime algunos mensajes*/
        g_print ("Hola mundo!\n");
        if (g_str_equal(argv[1],"--manejador")) {
            g_set_print_handler(viejo);
        }

        return 0;
    }

El manejador de ``g_print()`` es el mismo que en el listado de programa 2.3.1.
Este ejemplo es un programa pensado para la línea de comandos. Si se ejecuta
este programa sin ningún parámetro se ejecutará la función
``muestra_ayuda()``. Ocurre lo mismo si no se especifican los parámetros
correctos. Solo se aceptan dos parámetros que permiten elegir entre usar o no
el manejador de ``g_print()``.


Registro de mensajes y advertencias
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Es muy buena práctica el clasificar nuestros mensajes debido a su severidad. Para esta tarea ``GTK+``
nos ofrece tres herramientas:

* ``g_message()`` es una macro que registra e imprime un mensaje en la salida
  estándar. Este   mensaje se considera informativo e inocuo.

* ``g_debug()`` es una macro que registra e imprime un mensaje en la salida de
  error estándar. Este   mensaje es útil para propósito de depurado de la
  aplicación.

* ``g_warning()`` se utiliza normalmente para avisar acerca de algún evento
  que ha ocurrido el   cual no es lo suficientemente fatal como para que el
  programa no pueda continuar.

Veamos el siguiente ejemplo:


.. code-block:: c

    /***************************************************************************
    *
    Programacion de interfases graficas de usuario con GTK
    *
    * Nombre de archivo: glib-logging.c
    * Descripcion: Uso de macros de registro de mensajes de ``Glib``
    *
    ****************************************************************************/
    #include <glib.h>
    int main (int argc, char **argv) {
        g_message("Abriendo dispositivo de adquisicion de datos");
        g_debug ("La direccion del dispositivo es 0x378");
        g_warning ("No fue posible abrir el dispositivo de adquisicion de datos");
        return 0;
    }

Si ejecutamos este programa obtendremos la siguiente salida:

** Poner screenshot aca**

Registro y despliegue de errores
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Estas son macros de ``Glib`` para el registro de errores:

* ``g_critical()`` avisa de algún error crítico en la aplicación. Un error
  crítico se define dependiendo de cada aplicación, para algunos un error
  critico es recuperable y para otros no. Este error se dirige a la salida de
  error estándar.

* ``g_error()`` avisa de un error grave en un programa. Sólo se debe utilizar
  g_error() para avisar para comunicar errores que de todas formas harían que la
  aplicación terminara. El uso de esta macro ocasionará que la aplicación
  termine.

.. code-block:: c

    /***************************************************************************
    *
    Programacion de interfases graficas de usuario con GTK
    *
    * Nombre de archivo: glib-error.c
    * Descripcion: Uso de macros de registro de mensajes de ``Glib``
    * Comentarios: Estos mensajes son de indole grave o fatal.
    *
    *
    ****************************************************************************/

    #include <glib.h>

    int main (intargc, char **argv)
    {
        g_critical("La frecuencia de muestreo es demasiado alta.");
        g_error("Se ocasiono un sobreflujo de datos. \nImposible continuar ");
        return 0;
    }



Tratamiento de cadenas
~~~~~~~~~~~~~~~~~~~~~~

Según ``Kernighan & Ritchie 
<http://es.wikipedia.org/wiki/El_lenguaje_de_programaci%C3%B3n_C>`_, una
cadena es arreglo o vector de caracteres terminados con el carácter nulo
``'\0'`` para que los programas puedan encontrar el final de la cadena.

El uso de cadenas comienza a volverse peligroso cuando se subestima su poder.
Una cadena puede ser un vector o un puntero. La diferencia sutil entre estas
dos características puede determinar si el programa gotea memoria o que
reviente.

Por ejemplo, una mala práctica de programación, que es usual entre
programadores no experimentados, es utilizar regiones de memoria estáticas
para almacenar cadenas de texto: si por alguna razón escribimos datos más allá
de los límites de la cadena seguramente estaremos escribiendo en el espacio de
otra variable o incluso en parte del código del programa. Esto conduce a
errores muy difíciles de depurar. Además de lo anterior, las regiones de
memoria estáticas representan un riesgo de seguridad, pues su debilidad
inherente es ampliamente usada para instrumentar ataques informáticos llamados
Buffer Overflow. En este procedimiento el atacante , previo conocimiento de la
vulnerabilidad del sistema, sobreescribe a voluntad otras celdas de memorias
que contienen datos o código del programa, haciendo que éste falle o se
comporte de forma determinada.

Por otro lado, el tratamiento clásico de cadenas goza de gran popularidad. El
tratamiento de cadenas es un tópico importante para cualquier programa.
``Glib`` aborda el problema desde dos perspectivas diferentes:

* Perspectiva procedimental: ``Glib`` ofrecer una vasta colección de rutinas
  de manejo de cadenas similares a las encontradas en la librería string.h de la
  librería estándar de C. Algunas adiciones buscan facilitar las tareas del
  programador.

* Perspectiva orientada a objetos: ``Glib`` pone a disposición de nosotros
  GString, un objeto cuyo funcionamiento esta basado en las cadenas del estándar
  de C, pero tratando de mejorar los problemas que encontremos al manejar
  cadenas de la manera tradicional.


Perspectiva procedimental
~~~~~~~~~~~~~~~~~~~~~~~~~

Existe una gran variedad de funciones de tratamiento de cadenas en ``Glib``.
Resultaría ineficaz el tratar todas en este documento. A continuación haremos
reseña de un pequeño conjunto de funciones útiles en el tratamiento de
cadenas demostrando el uso de
`g_strdup() <https://developer.gnome.org/glib/unstable/glib-String-Utility-Functions.html#g-strdup>`_,
`g_strrstr() <https://developer.gnome.org/glib/unstable/glib-String-Utility-Functions.html#g-strrstr>`_,
`g_strstr_len() <https://developer.gnome.org/glib/unstable/glib-String-Utility-Functions.html#g-strstr-len>`_,
`g_str_has_prefix() <https://developer.gnome.org/glib/unstable/glib-String-Utility-Functions.html#g-str-has-prefix>`_,
`g_str_has_suffix() <https://developer.gnome.org/glib/unstable/glib-String-Utility-Functions.html#g-str-has-suffix>`_,
`g_str_equal() <https://developer.gnome.org/glib/unstable/glib-String-Utility-Functions.html#g-str-equal>`_,


Ejemplo de ``g_strdup``.

.. code-block:: c

    gchar*
    g_strdup
    (const gchar *str);
    Descripción: Duplica una cadena.
    Parámetros:
    ➢
    str: un puntero a la cadena a duplicar.
    Valor de retorno: La cadena duplicada en otra región de memoria. Si NULL se ha
    especificado como parámetro de entrada, el valor de retorno también será NULL. El programador es
    responsable de liberar la memoria de la nueva cadena.

Ejemplo de ``g_strrstr``.

.. code-block:: c

    gchar*
    g_strrstr
    (const gchar *haystack,
    const gchar *needle);
    Descripción: Busca una aguja(needle) dentro de un pajar (haystack). Las cadenas de entrada
    debe estar terminadas con el carácter nulo.
    Parámetros:
    ➢ haystack: La cadena donde se busca (pajar).
    ➢ needle: El texto que se busca (aguja).
    Valor de retorno: Se regresa un puntero a donde se encontró la primera ocurrencia de la
    aguja dentro del pajar. Si no se encontraron coincidencias entonces se regresa NULL.

Ejemplo de ``g_strstr_len``.

.. code-block:: c

    gchar*
    g_strstr_len
    (const gchar *haystack,
    gssize haystack_len,
    28const gchar *needle);
    Descripción: Esta es una versión de la función g_strstr(). Esta versión limitará su búsqueda
    en el pajar a un número de caracteres igual a haystack_len.
    Parámetros:
    ➢ haystack: La cadena donde se busca (pajar).
    ➢ haystack_len: Número máximo de caracteres que se examinarán del pajar.
    ➢ needle: El texto que se busca (aguja).
    Valor de retorno: Se regresa un puntero a donde se encontró la primera ocurrencia de la
    aguja dentro del pajar. Si no se encontraron coincidencias entonces se regresa NULL.


Ejemplo de ``g_str_has_prefix``.

.. code-block:: c

    gboolean
    g_str_has_prefix
    (const gchar *str,
    const gchar *prefix);
    Descripción: Nos dice si la cadena str tiene el prefijo especificado.
    Parámetros:
    ➢ str: La cadena de quien se desea determinar el prefijo.
    ➢ prefix: El prefijo.
    Valor de retorno: Regresa TRUE si la cadena comienza con prefix. FALSE en caso
    contrario.


Ejemplo de ``g_str_has_suffix``.

.. code-block:: c

    gboolean
    g_str_has_suffix
    (const gchar *str,
    const gchar *suffix);
    Descripción: Nos dice si la cadena str tiene el sufijo especificado.
    Parámetros:
    ➢ str: La cadena de quien se desea determinar el sufijo.
    ➢ suffix: El sufijo.
    Valor de retorno: Regresa TRUE si la cadena termina con suffix. FALSE en caso
    contrario.

Ejemplo de ``g_str_equal``.

.. code-block:: c

    gboolean
    g_str_equal
    (gconstpointer v1,
    gconstpointer v2);
    Descripción: Esta función verifica que las dos cadenas sean iguales.
    Parámetros:
    ➢ v1: Una cadena.
    ➢ v2: Otra cadena que se comparará contra v1..
    Valor de retorno: Regresa TRUE si ambas cadenas son idénticas. Esta función esta
    preparada para ser usada en estructuras de datos que necesiten comparación, como listas enlazadas,
    tablas de claves o arboles binarios 5 .


Perspectiva Orientada a Objetos: ``GString``
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

``GString`` es un objeto que se encarga de los detalles de la administración
de memoria, de tal manera que el programador no tenga que ocuparse de liberar
o reservar memoria.

Recordemos que GLib nos provee de lo necesario para hacer programación
orientada objetos, pero en un lenguaje procedural como C. Decimos que
``GString`` es un objeto, pero en realidad esta implementado como una
estructure. Visto desde ese aspecto, ``GString`` define tres miembros públicos
a los que se puede acceder directamente.

.. code-block:: c

    typedef struct {
        gchar *str;
        gsize len;
        gsize allocated_len;
    } GString;

La propiedad ``str`` contendrá el texto de la instancia, mientras que ``len``
contendrá la longitud de la cadena, sin contar los caracteres de terminación
de cadena.

El constructor de clase de ``GString`` es el siguiente:

.. code-block:: c

    GString* g_string_new(const gchar *init);

Opcionalmente toma un parámetro: ``init`` que será la cadena con que se
inicializará el objeto. Si quieres que la cadena este vacía puedes pasar la
macro NULL como parámetro. Veamos un ejemplo:

.. code-block:: c

    #include <glib.h>
    /*....*/
    Gstring *cadena, cadena_vacia;
    cadena = gstring_new(“Hola”);
    cadena_vacia = gstring_new(NULL);


Por conveniencia, ``GLib`` provee otros constructores: 
`g_string_new_len() <https://developer.gnome.org/glib/2.41/glib-Strings.html#g-string-new-len>`_
y
g_string_sized_new() <https://developer.gnome.org/glib/2.41/glib-Strings.html#g-string-sized-new>`_

Todos los constructores regresan el puntero a una nueva instancia de ``GString``.

Una vez que tenemos una instancia del objeto ``GString`` podemos manipular su
contenido mediante algunas de las funciones del API de GString, como por ejemplo 
`g_string_assign() <https://developer.gnome.org/glib/unstable/glib-Strings.html#g-string-assign>` _,
`g_string_append() <https://developer.gnome.org/glib/unstable/glib-Strings.html#g-string-append>`_,
`g_string_append_c() <https://developer.gnome.org/glib/unstable/glib-Strings.html#g-string-append-c>`_,
`g_string_prepend() <https://developer.gnome.org/glib/unstable/glib-Strings.html#g-string-prepend>`_,
`g_string_prepend_c() <https://developer.gnome.org/glib/unstable/glib-Strings.html#g-string-prepend-c>`_,
`g_string_ascii_up() <https://developer.gnome.org/glib/unstable/glib-String-Utility-Functions.html#g-string-ascii-up>`_ o
`g_string_ascii_down() <https://developer.gnome.org/glib/unstable/glib-String-Utility-Functions.html#g-string-ascii-down>`.
Veamos un ejemplo.

.. code-block:: c

    # Define un nuevo valor para la cadena,
    g_string_assign(cadena, “Nuevo valor”);

    # Añade caracteres al inicio y al final de la cadena almacenada en Gstring
    g_string_append_c(cadena,'Z');
    g_string_prepend_c(cadena,'A');
    
    #Añade otra cadena al final de GString
    g_string_append (cadena, “Añadiendo valor al final”);
    g_string_prepend(candena,”Añadiendo valor al Principio”);

    # Tambien es posible truncar la longitud de la cadena, 
    # por ejemplo 0 significa que la cadena se limpia...
    g_string_truncate(cadena,0);

    # Convertir la cadena a mayúsculas o minúsculas ...
    g_string_ascii_up(cadena);
    g_string_ascii_down(cadena);


Finalmente, cuando llegue el momento de destruir la instancia de ``GString``
deberemos usar `g_string_free() <https://developer.gnome.org/glib/unstable
/glib-Strings.html#g-string-free>`_.

.. code-block:: c

    g_string_free(cadena, TRUE);



.. note::
    Debemos tener cuidado con el segundo parámetro de ``g_string_free()``. Éste
    parámetro define si junto con el valor de la cadena también se destruye el la
    instancia del objeto. Pasa el parámetro ``FALSE`` si la instancia se está
    usando en algún otro lado del programa. Si ya no planeas utilizar más este
    objeto pasa ``TRUE`` como parámetro.



Finalmente, aca pongo el ejemplo completo de manipulacion de cadenas.

.. code-block:: c

    /***************************************************************************
    * Programacion de interfases graficas de usuario con GTK
    *
    * Nombre de archivo: glib-gstring1.c
    * Descripcion: Ejemplo de tratamiento de cadenas con GLib
    * Comentarios: Revision del ciclo de vida de GString
    *
    ****************************************************************************/
    #include <glib.h>
    
    int main () {
        GString *cadena;

        /* Se crea una instancia de GString con un valor"*/
        cadena = g_string_new("Amor volat undique");
        g_print("( %i Bytes ) %s\n", cadena->len, cadena->str);

        /*Reemplazando el contenido de la cadena*/
        g_string_assign(cadena, "Captus est libidine.");

        /* Inserta algun texto al principio de la cadena*/
        g_string_prepend(cadena,"Siqua sine Socio");
        g_print("( %i Bytes ) %s\n", cadena->len, cadena->str);

        /*El valor de la cadena se trunca*/
        g_string_truncate(cadena,16);
        g_print("( %i Bytes ) %s\n", cadena->len, cadena->str);

        /*Se inserta algun texto al fin de la cadena*/
        g_string_append(cadena,", caret omni gaudio");
        g_print("( %i Bytes ) %s\n", cadena->len, cadena->str);
        
        /*Se insertan caracteres al incio y al fin de la cadena*/
        g_string_append_c(cadena,'!');
        g_string_prepend_c(cadena,'.');
        g_print("( %i Bytes ) %s\n", cadena->len, cadena->str);
        
        /*Se convierte la cadena a Mayusculas */
        g_string_ascii_up(cadena);
        g_print("( %i Bytes ) %s\n", cadena->len, cadena->str);
        
        /*Se convierte la cadena a Mayusculas */
        g_string_ascii_down(cadena);
        g_print("( %i Bytes ) %s\n", cadena->len, cadena->str);
        g_print("\nFin del programa\n");
        g_string_free(cadena,TRUE);

        return 0;
    }

Compila el ejemplo anterior con el siguiente comando:

.. code-block::
    
    ** Ponercomando para compilar

Finalmente, ejecuta el programa

.. code-block:: bash

    ** Poner salida del programa


Estructuras de datos
--------------------

Las estructuras de datos son imprescindibles en el desarrollo de cualquier
programa. Nos permiten abordar de una manera razonada y metódica un problema
en particular.


Listas enlazadas simples
~~~~~~~~~~~~~~~~~~~~~~~~

Las listas enlazadas, al igual que los arreglos y vectores se utilizan para
almacenar colecciones de datos. Un buen artículo de listas enlazadas está
disponible en la librería de educación de la facultad de ciencias de la
computación en la universidad de Stanford[6].

La biblioteca ``Glib`` incluye una implementación de listas enlazadas en
`GSList <>`_.

2.5.1
Propiedades
La estructura GSList tiene un esquema similar al que se muestra en la Figura 2.5.1, mientras que
su estructura en C es la siguiente:
typedef struct {
gpointer data;
GSList *next;
} GSList;
El puntero *data almacena los datos que se desean coleccionar, mientras que next apunta hacia
al siguiente elemento de la lista enlazada.
Figura 2.5.1: Estructura de datos GSList.
382.5.2
Constructor de clase
Una lista enlazada simple no tiene constructor de clase en si, pues un puntero con el valor NULL se
interpreta como una lista vacía.
El puntero *GSList siempre se debe inicializar con NULL. El fin de una lista enlazada se
encuentra cuando el puntero next contiene el puntero NULL. De ahí que una lista vacía sólo es un
puntero NULL.
2.5.3
Funciones asociadas o Métodos de clase
La estructura de datos de GSList indica que nuestras listas enlazadas simples pueden contener
cualquier dato. Además de cualquier dato, también contienen un puntero a la siguiente estructura.
Los datos contenidos en la estructura de datos pueden ser, por ejemplo, un entero usando
cualquiera de las macros de conversión de tipo que se revisaron en el Capitulo 2.2.6, o un puntero a
otro tipo de datos como un objeto o una cadena.
Una lista enlazada simple sólo permite recorrer la estructura de datos en una sola dirección (no
hay ningún lugar donde diga como regresar a elemento anterior.
Es importante no olvidar estos detalles por que todas los funciones asociadas asumen que el
puntero que se les entrega es el inicio de la lista. Así mismo, las funciones que modifican las listas
enlazadas pueden cambiar la lista de tal manera que una referencia antigua ya no apunte al nuevo inicio
de la lista.
Con las consideraciones anteriores podemos comenzar con nuestra reseña.
El siguiente conjunto de funciones sirven para añadir y eliminar elementos.
GSList*
g_slist_append
(GSList *list,
gpointer data);
39Descripción: Añade un elemento al final de la lista. Note que esta función tiene que recorrer toda
la lista hasta el final para añadir el elemento. Una lista lo suficientemente larga puede crear problemas
de velocidad de ejecución y cuellos de botella, principalmente cuando se añaden varios elementos a la
vez. Para estos casos se puede insertar todos los elementos al inicio para posteriorment invertir el orden
de la lista.
Parámetros:
➢ list: Una lista enlazada simple.
➢ data: Los datos del elemento a insertar.
Valor de retorno: El nuevo inicio de la lista enlazada simple.
GSList*
g_slist_prepend
(GSList *list,
gpointer data);
Descripción: Añade un elemento al inicio de la lista. Note que el puntero al nuevo inicio de la
lista pudo haber cambiado. Asegúrese de guardar el nuevo valor.
Parámetros:
➢ list: Una lista enlazada simple.
➢ data: Los datos del elemento a insertar.
Valor de retorno: El nuevo inicio de la lista enlazada simple.
GSList*
g_slist_insert
(GSList *list,
gpointer data,
gint position);
40Descripción: Inserta un elemento al en la posición especificada. Note que el puntero al nuevo
inicio de la lista pudo haber cambiado. Asegúrese de guardar el nuevo valor.
Parámetros:
➢ list: Una lista enlazada simple.
➢ data: Los datos del elemento a insertar.
➢ position: La posición del elemento a insertar. El elemento se inserta al final si la
posición es negativa o es mayor al número de elementos de la lista.
Valor de retorno: El nuevo inicio de la lista enlazada simple.
GSList*
g_slist_insert_before
(GSList *slist,
GSList *sibling,
gpointer data);
Descripción: Inserta un elemento antes de algún otro elemento. Note que el puntero al nuevo
inicio de la lista pudo haber cambiado. Asegúrese de guardar el nuevo valor.
Parámetros:
➢ list: Una lista enlazada simple.
➢ sibling: El elemento del que deseamos que se inserte datos antes de él.
➢ data: Los datos del elemento a insertar.
Valor de retorno: El nuevo inicio de la lista enlazada simple.
GSList*
g_slist_insert_sorted
(GSList *list,
gpointer data,
GCompareFunc func);
Descripción: Inserta un elemento de manera ordenada. La ordenación se lleva a cabo mediante la
función de comparación especificada.
41Parámetros:
➢ list: Una lista enlazada simple.
➢ data: Los datos del elemento a insertar.
➢ func: La función que será usada para ordenar lo datos de la lista. Esta función deberá
tomar dos parámetros y deberá regresar un valor mayor a cero si el primer parámetro
debe ir después del segundo parámetro.
Valor de retorno: El nuevo inicio de la lista enlazada simple.
GSList*
g_slist_remove
(GSList *list,
gconstpointer data);
Descripción: Remueve un elemento de la lista. Si dos elementos contienen los mismos datos, sólo
se removerá el primero. Si no se encuentra el elemento a eliminar entonces la lista queda sin cambios.
Parámetros:
➢ list: Una lista enlazada simple.
➢ gconstpointer: Los datos del elemento a eliminar de la lista.
Valor de retorno: El nuevo inicio de la lista enlazada simple.
El siguiente conjunto de funciones son para localizar elementos dentro de la lista enlazada simple.
GSList*
g_slist_last
(GSList *list);
Descripción: Entrega el último elemento de la lista.
Parámetros:
➢
list: Una lista enlazada simple.
Valor de retorno: El último elemento de la lista enlazada simple.
#define
g_slist_next(slist)
42Descripción: Una macro que entrega el siguiente elemento de la lista. Equivale a slist-
>next.
Parámetros:
➢
list: Una lista enlazada simple.
Valor de retorno: El siguiente elemento de la lista enlazada simple. NULL si la lista esta vacía o
se ha llegado al último elemento.
GSList*
g_slist_nth
(GSList *list,
guint n);
Descripción: Entrega el n-ésimo elemento de la lista.
Parámetros:
➢
list: Una lista enlazada simple.
Valor de retorno: El n-ésimo elemento de la lista enlazada simple. NULL si la lista esta vacía o se
ha llegado al último elemento.
GSList*
g_slist_nth
(GSList *list,
guint n);
Descripción: Entrega el n-ésimo elemento de la lista.
Parámetros:
➢ list: Una lista enlazada simple.
➢ n: la posición del elemento, iniciando desde 0.
Valor de retorno: El n-ésimo elemento de la lista enlazada simple. NULL si la lista esta vacía o la
posición buscada está fuera de los límites de la lista.
gpointer
g_slist_nth_data
(GSList *list,
guint n);
Descripción: Entrega los datos del n-ésimo elemento de la lista.
Parámetros:
43➢ list: Una lista enlazada simple.
➢ n: la posición del elemento, iniciando desde 0.
Valor de retorno: Los datos del n-ésimo elemento de la lista enlazada simple. NULL si la lista
esta vacía o la posición buscada está fuera de los límites de la lista.
GSList*
g_slist_find
(GSList *list,
gconstpointer data);
Descripción: Encuentra el elemento que contiene los datos especificados.
Parámetros:
➢ list: Una lista enlazada simple.
➢ data: los datos que se buscan
Valor de retorno: El elemento que contiene los datos. NULL si no se encuentra nada.
GSList*
g_slist_find_custom
(GSList *list,
gconstpointer data,
GCompareFunc func);
Descripción: Encuentra un elemento aplicando el criterio de la función especificada. La lista se
recorre y en cada paso se llama a la función especificada la cual debe regresar 0 cuando se halla
encontrado el elemento deseado.
Parámetros:
➢ list: Una lista enlazada simple.
➢ data: los datos que se buscan.
➢ func: la función que se llama por cada elemento. Esta función debe de tomar dos
punteros de tipo gconstpointer, los cuales son los datos del nodo que se esta
iterando y los datos que se buscan, respectivamente
Valor de retorno: El elemento que contiene los datos. NULL si no se encuentra nada.
44Las siguientes funciones servirán para encontrar el índice de un elemento dentro de la lista
gint
g_slist_position
(GSList *list,
GSList *llink);
Descripción: Encuentra la posición de un nodo dentro de una lista enlazada simple.
Parámetros:
➢ list: Una lista enlazada simple.
➢ llink: un elemento/nodo dentro de la lista enlazada simple.
Valor de retorno: El índice del nodo dentro de la lista ó -1 si no se encuentra nada.
gint
g_slist_index
(GSList *list,
gconstpointer data);
Descripción: Encuentra la posición del elemento que contiene los datos especificados.
Parámetros:
➢ list: Una lista enlazada simple.
➢ data: los datos que se buscan
Valor de retorno: El índice del elemento que contiene los datos ó -1 si no se encuentra nada.
Si deseamos recorrer, iterar o caminar a lo largo de la lista debemos usar la siguiente función.
void
g_slist_foreach
(GSList *list,
GFunc func,
gpointer user_data);
Descripción: Recorre toda la lista enlazada simple ejecutando una función para cada nodo de la
lista.
Parámetros:
45➢ list: Una lista enlazada simple.
➢ func: La función que se llamará con cada elemento. Esta función debe tomar dos
punteros de tipo gpointer. El primero corresponde a los datos del elemento iterado, el
segundo a los datos extras proporcionados por el programador.
➢
2.5.4
user_data: datos extras proporcionados por el programador.

Destructor de clase
Cuando se termine el uso de la lista enlazada simple se debe de limpiar la memoria que este usando. El
destructor de GSList libera la memoria de la estructura de la lista, mas no libera la memoria que esta
a la que hace referencia cada elemento de la lista.
Visto de otra forma. Una lista enlazada simple es una estructura que contiene espacio para dos
punteros: uno apunta al siguiente elemento, el otro apunta a cualquier tipo o estructura de datos.
Cuando se libera la memoria de la lista enlazada se libera el espacio que ocupan los dos punteros de
cada elemento de la lista, pero los datos y estructuras a los que hacían referencia cada elemento de la
lista quedan intactos.
Ahora que se ha discutido los detalles del destructor, vemos al reseña.
void
g_slist_free
(GSList *list);
Descripción: Libera toda la memoria ocupada por la estructura de una lista enlazada.
Parámetros:
➢
list: Una lista enlazada simple.
462.5.5
Ciclo de vida de una lista enlazada simple
Comencemos la descripción del ciclo de vida de una lista enlazada simple.
•
El primer paso es declarar la estructura e inicializarla con valor NULL.
#include <glib.h>
GSList *lista=NULL;
/* ... */
•
Ahora podemos manipular la lista a nuestro antojo. Podemos, por ejemplo, añadir una sola
cadena al final...
lista = g_slist_append (lista,”Elemento 1”);
...al principio ...
list = g_slist_prepend(lista,”Elemento 0”);
... o insertar elementos en posiciones arbitrarias ...
list = g_slist_insert (lista, “Elemento insertado”,1);
... y no solamente funciona con cadenas, si no también con otros tipos de objetos...
lista = g_slist_append (lista,G_INT_TO_POINTER(113));
lista = g_slist_append (lista,objeto);
•
Cuando llega el momento de recavar la información guardada en la lista tendremos que recordar
la estructura en C vista arriba. El mismo puntero GSList que representa la lista enlazada, es a
su vez el puntero al primer nodo de la lista. El elemento data del nodo es un puntero a los
datos guardados y el elemento next apunta al siguiente nodo de la lista o es NULL si ya no hay
más elementos. La manera correcta de acceder a los datos que contiene un nodo es mediante la
notación de punteros:
datos= nodo->data;
siguiente = nodo->next;
Una manera útil de recorrer una lista enlazada simple es mediante un ciclo utilizando for...
47for (nodo=lista; nodo; nodo=nodo->next)
g_print("%s\n",(char *)nodo->data);
Otra manera de caminar a lo largo de la lista es utilizar g_slist_for_each() el cual se
apoya de una función definida por el usuario que debe de corresponder con el siguiente
prototipo:
void
GFunc
(gpointer data, gpointer extra_data);
En el próximo ejemplo veremos cono se debe utilizar esta función.
Una vez que se ha terminado de operar con la lista enlazada es necesario liberar la memoria
•
usada, para ello se encuentra g_slist_free().
2.5.6
Ejemplo
Mostraremos dos ejemplos. El primero de ellos mostrará de manera breve el ciclo de vida de GSList.
Listado de Programa 2.5.1
/***************************************************************************
*
Programacion de interfases graficas de usuario con GTK
*
* Nombre de archivo:
glib-gslist1.c
*
Descripcion:
Muestra de ciclo de vida de GSlist
* Comentarios:
Además muestra como caminar a traves de la
*
lista.
*
*
* TESIS PROFESIONAL
INSTITUTO TECNOLOGICO DE PUEBLA
*
INGENIERIA ELECTRONICA
* Autor: Noe Misael Nieto Arroyo
tzicatl@gmail.com
*
****************************************************************************/
#include <glib.h>
void imprimir_lista(gpointer data, gpointer user_data){
gchar *mensaje;
mensaje = (gchar *) data;
g_print("%s\n", mensaje);
}
int main(){
GSList *lista = NULL;
GSList *nodo = NULL;
48gchar *nombre = "Nombre";
/*Inserción de diferentes tipos de elementos */
lista = g_slist_append(lista, nombre);
lista = g_slist_prepend(lista, "Elemento adicionado al principio");
lista = g_slist_insert(lista, "Elemento insertado en posicion 1", 1);
/* Primer metodo de acceso a elementos */
g_print("==-Primer metodo de acceso a los elementos de una lista-==\n");
for (nodo = lista; nodo; nodo = nodo->next)
g_print("%s\n", (char *) nodo->data);
/* segundo metodo */
g_print("==-Segundo metodo de acceso a los elementos de una lista-==\n");
g_slist_foreach(lista, (GFunc) imprimir_lista, NULL);
/*Destructor*/
g_slist_free(lista);
}
return 0;
En el ejemplo anterior se ha mostrado que dos métodos para recorrer toda la lista, elemento por
elemento. El primero es un bucle de ejecución que itera sobre cada elemento hasta que se halle el
elemento final de la lista.
El segundo método deja que ``Glib`` haga la caminata por la lista y llame una función designada
por nosotros por cada elemento que encuentre.
Como se puede ver en la figura siguiente, los efectos de ambos métodos son iguales.
49Figura 2.5.2: Corrida del primer ejemplo de listas enlazadas
El segundo ejemplo es una aplicación práctica de las listas enlazadas simples. El objetivo de este
ejemplo es realizar una lista de los dispositivos de captura de datos que existe en la computadora e
imprimir una relación de estos.
Listado de Programa 2.5.2
/***************************************************************************
*
Programacion de interfases graficas de usuario con GTK
*
* Nombre de archivo:
glib-gslist2.c
*
Descripcion:
Aplicación práctica de GSlist
* Comentarios:
El siguiente ejemplo buscará todos los
*
dispositivos de sonido del sistema y los guardará
*
en una lista enlazada para su posterior
*
procesamiento
*
*
* TESIS PROFESIONAL
INSTITUTO TECNOLOGICO DE PUEBLA
*
INGENIERIA ELECTRONICA
* Autor: Noe Misael Nieto Arroyo
tzicatl@gmail.com
*
****************************************************************************/
#include <glib.h>
#include <glib/gprintf.h>
//void llenar_lista(GSList lista){
GSList *llenar_lista(GSList *lista){
gchar *comando = "/usr/bin/hal-find-by-property --key alsa.type --string
capture";
gchar *mi_stdout;
gchar **disps;
50gint i=0;
/*Ejecuta otro programa sin terminar este */
g_spawn_command_line_sync(comando, &mi_stdout,
NULL,NULL, NULL);
/*La salida del programa se guardó en mi_stdout.
Ahora procederemos a separar cada uno de los
resultados que vienen separados por caracteres
de nueva linea*/
disps = g_strsplit(mi_stdout,"\n",-1);
/*Despues de separados, cada uno se inserta en la lista*/
for (i=0;i< (g_strv_length(disps) -1); i++)
lista = g_slist_insert_sorted(lista,g_strdup(disps[i]),g_str_equal);
/*Liberar la memoria usada por los resultados separados*/
g_free(mi_stdout);
g_strfreev(disps);
}
return lista;
/*Esta función averiguará el dispositivo linux correspondiente a
cada dispositivo de adquisicion de datos*/
void imprimir_lista(gpointer data, gpointer user_data){
GString *comando;
gchar *mi_stdout;
/*Preparar el comando a ejecutar */
comando = g_string_new("");
g_string_printf( comando,
"/usr/bin/hal-get-property --udi %s --key linux.device_file",
(gchar *) data);
/*Ejecuta el comando programa sin terminar este */
g_spawn_command_line_sync(comando->str, &mi_stdout,
NULL,NULL, NULL);
/*Presentar los resultados*/
g_print("====\n");
g_print("HAL UDI
: %s\n", (gchar *) data);
g_print("DISP. LINUX : %s", mi_stdout);
}
/*Limpiar memoria */
g_string_free(comando,TRUE);
g_free(mi_stdout);
void limpiar_lista(gpointer data, gpointer user_data){
g_free(data);
}
int main(){
GSList *lista = NULL;
51g_print ("Buscando dispositivos de captura...\n");
lista = llenar_lista(lista);
g_print ("Se encontraron %i dispostivos\n",g_slist_length(lista));
g_print ("======= LISTA DE DISPOSITIVOS DE ADQUISICION DE DATOS =======\n");
g_slist_foreach(lista,imprimir_lista,NULL);
/*Es hora de liberar toda la memoria*/
g_slist_foreach(lista,limpiar_lista,NULL);
g_slist_free(lista);
g_print ("=============================================================\n");
return 0;
}
La tarea anteriormente expuesta parece difícil, pero los últimos mejoras del sistema operativo
Linux hacen que nuestra tarea no sea titánica. FreeDesktop es un grupo de expertos en computación
que se han reunido para establecer estándares de operación entre las diferentes versiones
(distribuciones) de Linux.
Una de esas especificaciones es HAL (Hardware Abstraction Layer). Una serie de utilerías en
línea de comandos permiten acceder a detalles del hardware de manera sencilla.
La lógica detrás de este ejemplo es la siguiente:
La función llenar_lista() usa HAL para listar a todos los dispositivos de sonido que sean de
captura. Lo anterior implica la ejecución del programa hal-find-by-property, lo cual queda a
cargo de la función g_spawn_command_line_sync() que ejecuta la linea de comandos, descrita
en una cadena, y entrega la salida del comando en otra cadena (mi_stdout). La salida del comando
es una lista de los dispositivos de captura de audio disponibles en el sistema y están separados por
caracteres de nueva línea. Es necesario entonces dividirlos en cadenas independientes.
La función g_strsplit() parte la cadena mi_stdout en un arreglo de cadenas, las cuales
contienen ya,
el identificador de cada dispositivo separado de todos los demás. La función
g_strsplit() regresa una cadena extra vacía que podemos ignorar.
52Después de haber separado nuestros identificadores en cadenas de texto individuales se procede a
llenar la lista enlazada simple con estos valores. Una vez preparada la lista enlazada, se libera la
memoria que ya no sirve y se regresa el puntero de la nueva lista, ya llena.
Llega la hora de presentar resultados. El numero de dispositivos encontrados es ahora reportado
mediante g_slist_lenght().
Ya hemos visto anteriormente como caminar a través de todos los elementos de la lista; hacemos
lo mismo mediante imprimir_lista() que además de imprimir los identificadores de los dispositivos,
utiliza g_spawn_command_line_sync() para investigar el dispositivo Linux correspondiente a
cada dispositivo.
Antes de poder liberar la memoria de la estructura de la lista enlazada simple, se debe recorrer y
liberar la memoria de cada uno de los elementos de la lista en forma individual. Esto se hace fácilmente
con la función limpiar_lista().
El producto de nuestro programa se muestra a continuación.

Figura 2.5.3: La lista de los dispositivos de captura de datos.