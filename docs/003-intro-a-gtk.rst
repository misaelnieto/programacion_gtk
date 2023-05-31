Introducción
------------

A continuación comenzaremos a estudiar la parte gráfica, de interacción con el usuario. Discutiremos el concepto genérico de widget y como utilizarlos para construir gran cantidad de objetos.

El concepto de widget
=====================

La palabra widget proviene de una contracción de la lengua inglesa: “Window Gadget6”, que se utiliza
para referir a los diferentes elementos de una interfaz gráfica de usuario. Un widget de GTK+ es un
componente de interfaz gráfica de usuario, es un objeto en toda la extensión de la palabra. Ejemplos de
widgets son las ventanas, casillas de verificación, botones y campos editables. Los widgets (no
importando de que tipo sean), siempre se definen como punteros a una estructura GtkWidget. Esta
estructura es un tipo de dato genérico utilizado por todos los widgets y ventanas en GTK+.

(Figura 3.1.1: Diagrama UML de herencia de GObject)
La librería GTK+ sigue un modelo de programación orientada a objetos(POO). La jerarquía de
objetos comienza en GObject de la librería Glib del que hereda GtkObject. Todos los widgets
heredan de la clase de objetos GtkWidget, que a su vez hereda directamente de GtkObject. Un
diagrama UML que muestra tales relaciones se muestra en la figura 3.1.1.


La clase GtkWidget contiene las propiedades comunes a todos los widgets; cada widget
particular le añade sus propias propiedades. En GTK+ los widgets presentan una relación padre/hijo
entre sí, las aplicaciones suelen tener un widget "ventana" de nivel superior que no tiene padre, pero
aparte de él, todos los widgets que se usen en una aplicación deberán tener un widget padre. Al widget
padre se le denomina contenedor (Consulte la figura 3.1.2).


Nomenclatura GTK
================

Cualquier proyecto de software, por pequeño que sea, requiere una gran inversión en tiempo y trabajo.
Considerando que el software Libre como GTK+ o GNOME son proyectos enormes que no pueden ser
manejados por un grupo reducido de personas, ofrecer una nomenclatura consistente es de vital
importancia para poder coordinar los esfuerzos de miles de programadores alrededor del mundo.
Antes de continuar precisa discutir adecuadamente la nomenclatura de objetos, métodos y, en
general, el estilo de programación de GTK+, Glib, Gdk, GdkPixBuf, Gobject, etc.. Cubriendo
estos lineamientos tendremos el beneficio de mejorar nuestros hábitos de programación, escribiendo
código que puede ser entendido por cualquier otra persona.
Seremos capaces de acostumbrarnos rápidamente a gran cantidad de librerías que utilizan este
estilo de programación como el entorno de programación de GNOME.
Como extracto del documento “GNOME Programming Guidelines”[7] resumimos la
nomenclatura de GTK+. 

* Siempre que sea posible, en GTK+ siempre se debe evitar el uso de variables globales. Esto es
importante aún más para librerías, ya que las variables globales dentro de sendos módulos se
exportan junto a las funciones (métodos si consideramos a una librería como un objeto). Todos
estos símbolos se integran al espacio global de nombres de la aplicación que llama a la
librería(Global Namespace). Un variable global de una librería cuyo nombre haya sido asignado
de manera descuidada puede causar conflictos con otra variable con el mismo nombre que se
esté usando en una parte del código que utiliza la librería.

* Los nombres de las funciones deberán tener la forma modulo_submodulo_operacion().
Por ejemplo: gtk_window_new(), g_string_truncate() ó g_tree_destroy().
Esta simple nomenclatura evita el choque de símbolos o nombres entre diferentes módulos de
las librerías.

* Los símbolos (funciones y variables), deberán tener nombres descriptivos: en lugar de usar
cntusr() deberemos usar contar_usuarios_activos(). Esto hace que el código
fuente sea fácil de usar y casi auto-documentado.
* Los nombres de funciones deben estar en minúsculas y deberán usar guión bajo para separar
palabras, por ejemplo: g_string_destroy(), gtk_window_new(),
abrir_puerto().

* Las macros y enumeraciones deben escribirse en letras mayúsculas, utilizando guiones bajos
para separar palabras, por ejemplo: TRUE o G_DIR_SEPARATOR .
* Tipos de datos, objetos y nombres de estructuras son una mezcla entre mayúsculas y
minúsculas, por ejemplo: Gslist, GtkWidget.

* El uso de guión bajo para separar palabras hace que el código fuente luzca menos apretado y
fácil de editar ya que se pueden utilizar de mejor manera los comandos de navegación por
palabras de los editores de texto de forma que naveguemos más rápidamente.

* A la hora de escribir una librería se hace común compartir símbolos (nombres de variables o
funciones), entre los diversos componentes de la librería pero no se desea que estos símbolos
estén disponibles para los usuarios de la librería. En tal caso, se puede anteponer un guión bajo
al nombre de la función o variable mientras éste sigue la nomenclatura modulo/submódulo
descrita arriba. Por ejemplo: _modulo_objeto_algunmetodo().


Proceso de creación de un widget
================================

El proceso de creación de un *widget* consta de cuatro pasos:
(1) Creación de la instancia de clase del widget que deseamos utilizar.
(2) Configuración de esta instancia (tamaño, clase, relación con widgets padres, etc..)
(3) Conexión de señales y eventos.
(4) Visualización de la instancia.
De acuerdo a la nomenclatura de la sección anterior, si la la clase de un *widget* es GtkClase, su
constructor de clase y todos los métodos asociados a esta tendrán la siguiente nomenclatura:
gtk_clase_metodo:
* "clase" debe sustituirse por el nombre del widget que se desea crear.
* "metodo" describe la acción que ejecutará la instancia de la clase.
Por ejemplo, el constructor de clase GtkWindow tiene la siguiente nomenclatura:
gtk_window_new().

La función de creación de un *widget* gtk_clase_new() siempre debe devolver un puntero (en
lenguaje C) a una instancia de tipo GtkWidget y no un puntero a una instancia del tipo creado. Por
ejemplo, la función gtk_window_new() devuelve un puntero a un objeto de GtkWidget y no una
instancia de tipo GtkWindow.
Es importante remarcar esta característica primordial de GTK+, ya que si recordamos que el
lenguaje C no es un lenguaje orientado a objetos, nosotros deberemos hacernos cargo del correcto
moldeo de tipos de clase.
La preferencia de los constructores de clase de regresar la referencia a un tipo de dato de la clase
base (GtkWidget) en lugar de regresar como un puntero a la clase heredada (GtkWindow) se
justifica gracias a que muchos métodos de la clase base aún aplican a la clase heredada. El mejor
ejemplo lo encontramos a la hora de hacer visible la instancia del objeto de tipo GtkWindow, para ello
se utiliza el método gtk_widget_show(). Si en algún momento se necesitase un puntero del tipo
de la clase heredada podemos hacer uso de las macros que define cada objeto de GTK+ y que nos
ayudan a moldear nuestro puntero a la clase de conveniencia.
Con nuestro ejemplo, si necesitásemos un puntero del tipo GtkWindow utilizando como base al
puntero de tipo GtkWidget, recurriríamos a la macro GTK_WINDOW. Ahora un mismo objeto se
puede comportar de dos formas distintas. Esto es conocido en cualquier lenguaje que soporte
programación orientada a objetos como *polimorfismo*.
Un ejemplo no compilable, pero ilustrativo, se redacta a continuación.
(Listado de programa 3.3.1)

(Figura 3.3.1: Ciclo de vida)

Es importante hacer notar que, en este ejemplo en específico, el objeto ventana es de tipo
GtkWindow, pero a la vez es del tipo GtkWidget. Como el tipo base del puntero ventana es
GtkWidget, es necesario moldearlo al tipo GtkWindow para que pueda comportarse como éste tipo
de objeto. Si no se hace esto, el compilador se quejará y la aplicación terminará con una violación de
segmento.
El interfaz gráfico de una aplicación se construye combinando diferentes *widgets* (ventanas,
cuadros combinados, cuadros de texto, botones, ...) y se establecen diversas retrollamadas (*callbacks*)
eventos asíncronos; de esta forma se obtiene la lógica requerida por el programa a medida que se
producen ciertas señales que a su vez provocan las *retrollamadas*. Las señales se producen por diversos
sucesos como oprimir el botón de un ratón que se encuentra sobre un *widget* botón, pasar el cursor por
encima de un *widget* u oprimir una tecla

Teoría de señales y retrollamadas
=================================

GTK+ es una librería dirigida por eventos. Desde el punto de vista del programador esto significa que
se quedará en el bucle principal de ejecución ( gtk_main() ), hasta que algún evento o señal ocurra
y el control se pase a la función apropiada.
Las señales son el medio por el cual GTK+ informa a las aplicaciones de los acontecimientos
producidos en el interfaz gráfico o dentro de los objetos que componen el programa.
Las señales son importantes dentro de las aplicaciones con interfaz gráfica de usuario ya que el
programa debe responder a las acciones que el usuario ejecute que por naturaleza son asíncronas y no
se pueden predecir o prever.
Si el usuario mueve el ratón, presiona un botón, escribe un texto o cierra una ventana, una función
retrollamada se ejecuta y se realiza el cómputo requerido por el usuario, por ejemplo: guardar un
archivo.
Un procesador de textos puede tener un botón que haga que el bloque seleccionado de texto
adquiera los atributos de letra negrita. La *retrollamada* asignada a ese botón contiene el código que se
encargará de llevar a cabo esa tarea.
De alguna forma, antes de cerrar una aplicación se hace necesario llamar a rutinas de limpieza,
guardar el trabajo del usuario o simplemente desplegar un diálogo que pregunte si realmente desea
cerrar la ventana.

En una aplicación, como veremos más tarde, continuamente se están generando señales y eventos,
sin embargo no todos son atendidos y sólo conectamos *retrollamadas* para aquellos eventos o señales
que son de nuestro interés.
Cuando deseamos atender a la escucha de una señal o *retrollamada*, se asocia un *widget* y una
función en C. Así, también se puede asociar *retrollamadas* a más de un *widget* ahorrando código que
deba escribirse.


*Rutinas de tratamiento de señales y eventos*
=============================================

En GTK+ señales y eventos se administran casi de la misma manera, la distinción entre estos dos
grupos se debe a que las señales son provocadas por el sistema de objetos de Glib / GTK+ y los
eventos son una corriente de mensajes que llegan desde el subsistema gráfico. Desde una perspectiva
del programador resulta sencillo pensar en los eventos como cualquier señal causada por la interacción
del usuario con el programa
Dos de las señales básicas en GTK+ son delete_event y destroy. El evento
delete_event generalmente se envía a una ventana cuando el usuario trata de cerrarla. Por su parte,
la señal destroy se manda a un objeto cuando su método de destrucción debe ser invocado.
Una ventana de nivel superior siempre debe conectar una función *retrollamada* al evento
delete_event. Si el usuario quiere cerrar la ventana, entonces la aplicación deberá terminar
correctamente.
Una retrollamada es una función en C como cualquier otra. Sin embargo, dependiendo de la señal
o evento a escuchar es como se declarará el tipo dato de regreso y los parámetros. Una vez escrita
adecuadamente, se registra esta rutina ante GTK+ usando la macro g_signal_connect().

#define g_signal_connect(instance, detailed_signal, c_handler, data)

Descripción: Conecta una función retrollamada que atenderá una señal de un objeto en particular.

Parámetros:

* instance : Es la referencia al *widget* u objeto del que queremos escuchar señales y
eventos. Este puntero debe estar moldeado al tipo GObject ya que GtkWidget está
es un derivado de éste. Para esto deberemos usar la macro G_OBJECT().

* detailed_signal : Es una cadena que especifica la señal o evento a escuchar.

* c_handler : El puntero de la función *retrollamada*. Este puntero debe estar
moldeado mediante la macro G_CALLBACK() al tipo de puntero GCallback. El
prototipo de cada función *retrollamada* se determina por el contexto en el que será
usada; visto de otra manera: el prototipo de cada función se determina por el tipo de
señal a la que será conectada.

* data : Este último argumento permite adjuntar algún dato extra a la *retrollamada*, de
tal manera que se evite el uso de variables globales y en su lugar se pasen estructuras o
valores directamente a la función *retrollamada* cuando ésta sea invocada.

La función retrollamada cambia dependiendo de la señal que se desea escuchar, pero hay una
función retrollamada prototipo que se usa como base para todas las demás:

void (*Gcallback) (void);

Lo anterior no significa que todas las funciones retrollamadas no deban tomar parámetros y
regresar void.

Una función *retrollamada* muy común en GTK+ y puede tener el siguiente prototipo:

void funcion_retrollamada ( Gtkwidget *widget,
gpointer datos);

El primer argumento es un puntero al widget que recibe el evento o genera la señal.
El segundo argumento es un puntero a los datos extras que se mandaron cuando se conectó la
señal a la retro llamada. De nuevo hay que hacer notar que el perfil de retro llamada descrito arriba es
sólo una forma general. Hay algunas retrollamadas generadas por widgets especiales que requieren
diferentes parámetros.


*Eventos*
=========


En complemento al mecanismo de señales descrito arriba, hay un conjunto de eventos que reflejan el
mecanismo de eventos del subsistema gráfico del sistema operativo (En UNIX será X-window). Las
funciones retrollamada también se pueden conectar a estos. Son

* event
* button_press_event
* button_release_event
* scroll_event
* motion_notify_event
* delete_event
* destroy_event
* expose_event
* key_press_event
* key_release_event
* enter_notify_event
* leave_notify_event
* configure_event
* focus_in_event
* focus_out_event
* map_event
* unmap_event
* property_notify_event
* selection_clear_event
* selection_request_event
* selection_notify_event
* proximity_in_event
* proximity_ouLevent
* visibility_notify_event
* client_event
* no_expose_event
* window_state_event

Para poder conectar una función retro llamada a alguno de estos eventos, se usará la función
g_signal_connect() , tal y como se ha descrito arriba usando alguno de los nombres que se dan
como el parámetro señal. La función retro llamada para eventos es un poco diferente a la que se usa
para las señales:

gint funcion_retrollamada( GtkWidget *widget,
GdkEvent *event,
gpointer datos_extra );

En C, GdkEvent es una unión, de la cual su tipo dependerá de cual de los eventos mostrados
arriba se han producido y esta construido mediante diferentes máscaras de eventos.. Para poder
decirnos que tipo de evento ha ocurrido, cada una de las posibles alternativas tiene un miembro type que muestra que evento ocurrió. Los otros elementos de la estructura dependerán de que tipo de evento
se generó. Las máscaras de los tipos posibles de eventos son:

GDK_NOTHING
GDK_DELETE
GDK_DESTROY
GDK_EXPOSE
GDK_MOTION_NOTIFY
GDK_BUTTON_PRESS
GDK_2BUTTON_PRESS
GDK_3BUTTON_PRESS
GDK_BUTTON_RELEASE
GDK_KEY_PRESS
GDK_KEY_RELEASE
GDK_ENTER_NOTIFY
GDK_LEAVE_NOTIFY
GDK_FOCUS_CHANGE
GDK_CONFIGURE
GDK_MAP
GDK_UNMAP
GDK_PROPERTY_NOTIFY
GDK_SELECION_REQUEST
GDK_SELECTION_NOTIFY
GDK_PROXIMITY_IN
GDK_PROXIMITY_OUT
GDK_DRAG_ENTER
GDK_DRAG_LEAVE
GDK_DRAG_MOTION
GDK_DRAG_STATUS
GDK_DROP_START
GDK_DROP_FINISHED
GDK_CLIENTE_EVENT
GDK_VISIBILITY_NOTIFY
GDK_NO_EXPOSE
GDK_SCROLL
GDK_WINDOW_STATE
GDK_SETTING

En resumen: para conectar una retro llamada a uno de esos eventos, usaremos algo como lo que se
presenta:

g_signal_connect ( G_OBJECT (button),
"button_press_event",
G_CALLBACK (button_press_callback),
NULL);

Si asumimos que button es un *widget*. Cuando el ratón esté sobre el botón y el botón sea
presionado, se llamará a la función button_press_callback(), la cual puede ser declarada
como sigue:

static gint button_press_callback( GtkWidget *widget,
GdkEventButton *event,
gpointer data );

Es preciso hacer notar que el segundo argumento lo podemos declarar como tipo
GdkEventButton por que ya sabemos cuál es el evento que ocurrirá para que esta función sea
invocada. El valor regresado por esta función indica si el evento se deberá propagar más allá por el
mecanismo de manejo de señales de GTK+. Regresar FALSE indica que el evento ya ha sido tratado
correctamente y ya no se debe propagar.

*Bucle de ejecución y eventos*
==============================

El bucle de eventos de GTK+ es el responsable de que el sistema de señales funcione correctamente, ya
que el primero no es más que un bucle interno de GTK+, en el que se van, una y otra vez, comprobando os estados de cada uno de los elementos de la aplicación, e informando de dichos cambios a los
elementos que se hayan registrado para ser informados. Este bucle de eventos GTK+ se traduce
básicamente en dos funciones, que son gtk_main() y gtk_main_quit().
gtk_main() entrega el control de cualquier programa al bucle de eventos de GTK+. Esto
significa que, una vez que se haya realizado la llamada a gtk_main(), se cede todo el control de la
aplicación a GTK+. Aunque gtk_main() toma el control de la aplicación, es posible ejecutar otras
porciones de código aprovechando el sistema se señales usando algún manejador (instalado ANTES de
llamar a gtk_main())
Dentro de algún manejador o *retrollamada* se puede llamar a gtk_main_quit() que termina
el bucle de eventos de GTK+. El pseudo-código de una típica aplicación GTK+ seria:

int main (int argc, char *argv[])
{
gtk_init (&argc, &argv);
/* creación del interfaz principal */
/* conexión a las distintas señales */
gtk_main ();
return 0;
}
(68)

Como puede comprobarse, el programa inicializa GTK+, crea el interfaz básico, conecta funciones
a las distintas señales en las que esté interesado (llamadas a g_signal_connect()), para
seguidamente entregar el control del programa a GTK+ mediante gtk_main().
Cuando en algún manejador de señal realicemos una llamada a gtk_main_quit(),
gtk_main() retornará, tras lo cual la aplicación termina.

*Ejemplo*
=========

A continuación se mostrará un sencillo ejemplo mostrando el proceso de creación del widget más
sencillo (GtkWindow) y el uso de señales.
Comencemos recordando el capítulo 3.3. El primer *widget* que aprenderemos a usar es
GtkWindow que es ventana común y corriente

(Listado de programa 3.4.1) (69)

El primer paso es inicializar la librería GTK+ con esta instrucción:

gtk_init (&argc, &argv);

De no incluirla, nuestros programas fallarían de manera inmediata.
El siguiente paso es crear una instancia de una ventana y alojar la referencia al objeto en la
variable window:

window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

El constructor de clase de GtkWindow toma un parámetro, es el tipo de ventana que se desea
crear. Las ventanas normales, como la ventana del navegador (Firefox ó Mozilla) o el administrador de
archivos (Nautilus) son ventanas de nivel superior (GTK_WINDOW_TOPLEVEL).
El siguiente paso en nuestra aplicación es establecer el título ...

gtk_window_set_title (GTK_WINDOW (window), "bucle1.c"); (69)

... y el tamaño:
gtk_widget_set_size_request(window,200,100); 

Observe que el método utilizado para cambiar el tamaño de la ventana es un método de
GtkWidget y no de GtkWindow.
Observe también que al establecer el título de la ventana se utilizó una especie de macro con el
puntero window como parámetro. ¿Por qué ocurre esto?
El constructor de GtkWindow regresa la instancia de GtkWindow como un puntero de
GtkWidget y no de GtkWindow. Esto es necesario para que se pueda utilizar el polimorfismo en el lenguaje C. Usando punteros al objeto más general como GtkWidget nos permite moldearlo a
cualquier otro objeto derivado.
El método gtk_window_set_title() requiere que el primer parámetro sea un puntero de
tipo GtkWindow; la macro GTK_WINDOW() moldea el puntero de tipo GtkWidget a puntero
GtkWindow.
El método gtk_widget_set_size_request() requiere que el primer parámetro sea un
puntero de tipo GtkWindow; en el caso citado anteriormente no es necesario moldear el puntero
window pues ya es del tipo deseado.
¿Que ocurriría si decido no usar las macros de moldaje de tipos? El compilador se quejaría de
punteros de tipos incompatibles.
A continuación viene la instrucción más importante del programa:

g_signal_connect (G_OBJECT (window), "destroy",
G_CALLBACK (gtk_main_quit),
NULL);

El prototipo de la macro g_signal_connect() es ya conocida desde el capítulo 3.4.1. El
objeto window conectará la señal "destroy" a la función gtk_main_quit(). La señal
"destroy" se emite cuando la ventana es cerrada.
Cuando el usuario cierre la ventana también ocasionará que el bucle de control de Gtk+ termine y
con ello la aplicación.
¿Qué ocurriría si no conectáramos esta señal? Al cerrar la ventana, esta desaparecería pero el
programa seguiría ejecutándose en memoria.

Por último hacemos visible la ventana y entregamos el control de la aplicación al bucle de GTK+.

(Figura 3.4.1: El ejemplo Más simple de GTK+, una ventana.) (72)

Los frutos de nuestro programa se muestran en la Figura 3.4.1.

*Widgets contenedores*
======================

Uno de los conceptos fundamentales de Gtk+ son los contenedores. Un widget contenedor es aquel
que es capaz de contener a otros widgets. Existen una gran cantidad de contenedores y GTK+ los
utiliza para acomodar los widgets dentro de la interfaz gráfica de usuario..
Cuando se escribe una aplicación, normalmente se necesita colocar mas de un widget dentro de
una ventana. En el ejemplo anterior(listado de programa 3.4.1) no necesitamos de ningún otro widget
más que la ventana.
El ejemplo anterior no ofrece utilidad más allá de la didáctica, pero como no conocemos aún
ningún otro widget lo tomaremos como base para extender nuestra aplicación.
El diagrama de herencia de clase de GtkWindow es el siguiente.

(Figura 3.5.1: La clase GkWindow y alguno de sus parientes)

Como podemos ver en la Figura 3.5.1 GtkWindow también puede contener otros widgets, pues
desciende de la clase GtkContainer. Pero debido a su descendencia directo con la clase GtkBin sólo puede contener un sólo *widget*, eso significa que, a pesar de tener la capacidad de almacenar otros widgets por ser descendiente de GtkContainer, la clase GtkWindow sólo puede contener un sólo widget debido a su parentesco inmediato con GtkBin.
Al igual que GtkWidget, GtkContainer y GtkBin son clases abstractas. Eso quiere decir
que no son instanciables y sólo sirven de plantillas para otros *widgets*.
La clase GtkBin es muy simple y sólo contiene un método que se utiliza de manera errática.
Usaremos, entonces, las siguientes líneas a comentar los métodos más importantes de la clase
GtkContainer.

*Métodos de la clase GtkContainer*
==================================

