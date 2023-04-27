# debug
Pequeña librería de ayuda para depurar código

# Uso

Importar la librería:

    #include "debug.h"
    
Utilizar la función `print_debug` en lugar de `printf`.

Utilizar la función `debug_leaks` para la detección de *leaks* al cierre del programa. En la función `ft_exit` se debe sustituir `main` por el nombre del ejecutable.

Finalmente, con la macro `DEBUG` (en `debug.h`) se activará o no la depuración. Si el valor es 0, el programa funcionará normalmente. Si el valor es 1, se mostrarán por pantalla todos los mensajes ejecutados con `print_debug` y se lanzará el comando `leaks` al final del programa.
