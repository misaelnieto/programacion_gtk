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
● Tipos de datos, objetos y nombres de estructuras son una mezcla entre mayúsculas y
minúsculas, por ejemplo: Gslist, GtkWidget.
58
● El uso de guión bajo para separar palabras hace que el código fuente luzca menos apretado y
fácil de editar ya que se pueden utilizar de mejor manera los comandos de navegación por
palabras de los editores de texto de forma que naveguemos más rápidamente.
● A la hora de escribir una librería se hace común compartir símbolos (nombres de variables o
funciones), entre los diversos componentes de la librería pero no se desea que estos símbolos
estén disponibles para los usuarios de la librería. En tal caso, se puede anteponer un guión bajo
al nombre de la función o variable mientras éste sigue la nomenclatura modulo/submódulo
descrita arriba. Por ejemplo: _modulo_objeto_algunmetodo().
