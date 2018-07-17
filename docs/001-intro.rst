Introducción
============

¿Qué es Gtk+?
-------------

GTK+ es una librería para la creación de interfaces gráficas de usuario. Su
licencia permite desarrollar programas libres así como aplicaciones
comerciales. Todo esto sin tener que pagar licencias o regalías para su uso.

GTK es el acrónimo de *GIMP Toolkit* debido a que originalmente fue escrito
para desarrollar el *Programa de manipulación de imágenes de GNU* (GNU Image
Manipulation Program, GIMP)

GTK+ se usa en gran cantidad de proyectos. Algunos de los más famosos son:
`GIMP <http://gimp.org>`_, Inkscape, Pitivi, Pidgin, XChat, LibreOffice, VLC y Elementary OS.

GTK+ se ha construido en base a tres librerías: GDK (*GIMP Drawing Kit*) para
interactuar con el sistema gráfico, gdk-pixbuf para manipular imágenes y Glib
para integración con el Sistema Operativo(SO).

Desde el punto de vista de GTK+ una aplicación gráfica se construye mediante
una conjunto de objetos que se comunican mediante eventos y retro llamadas. Su
diseño, en constante mejora, le permite lograr una gran velocidad de
ejecución, interactuar con diferentes lenguajes de programación como C, C++,
Python, C#, Perl o Ada, y ser un ambiente de desarrollo multi-plataforma
(UNIX, Linux, Windows TM , MacOS X TM ).



Componentes de GTK+
-------------------

GTK es la parte gráfica que interactúa con el usuario. GTK nos ofrece todo lo
necesario para el desarrollo de interfaces gráficas de usuario como botones,
cajas de texto, menús, ventanas, etc.. Otras formas o widgets mucho más
complejos pueden ser creados para satisfacer nuestras necesidades.

Los componentes de GTK+ se interrelacionan de la siguiente manera:

* GLIB es la base del proyecto GTK+ y GNOME. GLIB provee las estructuras de
  datos en el lenguaje C. Contiene la infraestructura necesaria para construir
  envoltorios e interfaces para tales funciones como un bucle de ejecución de
  eventos, hilos, carga dinámica de módulos y un sistema de objetos.

* GObject es la parte de Glib que implementa las características de lenguajes
  orientados a objetos que no están disponibles intrínsecamente en el lenguaje
  C. De esta manera GTK+ puede ser una caja de herramientas orientada a objetos
  sin tener que implementarse en C++ u otro lenguaje.

* GDK interactúa con las primitivas gráficas de cada SO y las prepara para su
  uso con GTK+. En los sistemas UNIX soportados como Linux y Solaris, GDK
  interactúa con el sistema X-Win­ dow[1], mientras que en sistemas Windows TM
  lo hará con GDI[2] y en MacOS X TM con Quartz TM [3]. El programador de
  aplicaciones no notará esto y, salvo raras excepciones, un programa escrito
  para GTK+ en Linux, por ejemplo, puede compilarse en Windows sin mayor
  modificación.

* GdkPixbuf contiene convenientes rutinas para el manejo de imágenes(png, gif,
  jpeg, etc), tales como abrir y guardar, trabajar con mapas de imágenes en
  memoria, escalado y animaciones entre otras características.

* Pango es un entorno de trabajo para el procesamiento y despliegue de texto
  internacional utilizando UTF8 como código base[4]; está integrado por completo
  en GTK+ y permite desplegar caracteres en distintos alfabetos y estilos de
  escritura (occidental, cirílico, árabe, chino, etc), texto bidireccional y con
  atributos como color, tamaño y estilo o rotación.

* ATK proporciona un conjunto de interfaces de accesibilidad. Si uno soporta
  interfaces ATK en un programa, tendremos la posibilidad de utilizar diferentes
  herramientas como magnificadores de pantalla, texto a diálogo o diferentes
  métodos de entrada para personas con capacidades diferentes.

Glib
----

Glib es una librería de utilidades de propósito general, la cual provee tipos
de datos útiles, así como macros, conversiones de tipo, utilidades de cadenas
y muchas más. Glib se encarga de interactuar con el SO anfitrión sin distraer
al programador de las diferencias más significativas entre las distintas
variedades de estos.

La siguiente lista reúne las principales características de Glib:

* Tipos de datos: Los tipos de datos (char, int, float, double), pueden diferir
  entre los diferentes SO ó arquitecturas de hardware. Glib libera al
  programador de prestar atención a estos detalles y en su lugar ofrece un
  conjunto de tipos propios (gchar, gint, gint32, guint, guint32, guchar, etc).

* Gestión de memoria: La gestión de memoria es una tarea especialmente
  delicada, por lo que Glib la administra automáticamente. Si el programador
  necesita mayor control de la memoria entonces tendrá a su disposición gran
  cantidad de métodos que le permitirán un control más exhaustivo de ésta.

* Estructuras de datos: Las estructuras de datos más comunes como listas
  enlazadas, arreglos dinámicos, tablas de tablas de claves, pilas y colas, ya
  están disponibles en Glib.

* Sistema de objetos: El sistema de Objetos de Glib se ha diseñado con miras a
  flexibilidad y capacidad de adaptarse a las necesidades del usuario. Se ha
  creado con la intención de integrarse fácilmente con otros lenguajes de
  programación diferentes de C. Todos los objetos de GTK+ se derivan de la clase
  fundamental de Glib: Gobject.

* Bucle de ejecución: En lugar de crear un bucle de eventos nosotros mismos,
  podemos dejarle la tarea a Glib para centrarnos en el diseño y desarrollo de
  nuestras aplicaciones asíncronas. Glib se encarga de la distribución de
  señales y mensajes a las diferentes partes de nuestro programa. También se
  encarga de administrar alarmas (temporizadores para aplicaciones síncronas),
  momentos de inactividad de la aplicación, eventos de entrada y salida en
  tuberías, sockets, o descriptores de archivos, así como hilos.


Vala
----

Extracto de la `Traducción al castellano del tutorial de Vala <https://wiki.gnome.org/Projects/Vala/Tutorial/es>`_

  Vala es un nuevo lenguaje de programación que permite utilizar modernas
  técnicas de programación para escribir aplicaciones que funcionan con las
  bibliotecas de tiempo de ejecución de GNOME, particularmente GLib y GObject.
  Esta plataforma ha proporcionado durante mucho tiempo un entorno de
  programación muy completo, con características como un sistema de tipado
  dinámico y gestión asistida de memoria. Antes de crear Vala, la única manera
  de programar para la plataforma era con la API nativa de C, que expone muchos
  detalles no deseados, con un lenguaje de alto nivel que tiene una máquina
  virtual auxiliar, como Python o el lenguaje C# de Mono o, alternativamente,
  con C++ a través de una biblioteca contenedora (wrapper)

  Vala es diferente a todas estas otras técnicas, ya que genera código C que se
  puede compilar para ejecutarse sin necesidad de bibliotecas externas aparte de
  la plataforma GNOME
