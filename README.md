# ArqCompMicroprocesador
Repositorio para el producto de Arquitectura del Computador, una simulación de microprocesador

# Dependencias

* SystemC

# Para Compilar y ejecutar

Por defecto, el makefile está configurado para sistemas de 64 bits
```sh
$ make
$ ./test
```

## Instalación de SystemC

### Pasos:

 _A) Ejecuta el archivo `installSystemC.sh`_
 _**ó**
 **B) sigue los sigientes pasos:**_

1.- Instala el paquete **build-essential**, necesario para compilar paquetes de Debian, y que contiene los compiladores gcc/g++. El comando es:

```sh
$ sudo apt-get install build-essential
```

2.- Corre lo siguiente:

```sh
$ wget https://accellera.org/images/downloads/standards/systemc/systemc-2.3.3.tar.gz
```
Y luego para descomprimir:
```sh
$ tar -xvf systemc-2.3.3.tar.gz
```

3.- Accede al directorio `systemc-2.3.3/` y crea un directorio llamado `objdir/`.

4.- Accede a `objdir/` y crea una carpeta en el directorio `/usr/local/`:

```sh
$ sudo mkdir /usr/local/systemc-2.3.3
```

5.- Desde `objdir/` de nuevo, corre el script que defina la ruta de instalación en el sistema:

```sh
$ sudo ../configure --prefix=/usr/local/systemc-2.3.3/
```

6.- Ejecuta ahora los siguientes comandos de compilación:

```sh
$ sudo make
```
 Y luego
```sh
$ sudo make install

```

7.- Si no has tenido errores, entonces SystemC debió instalarse de manera correcta en tu sistema. Para probar que esto es cierto, posicionate en `arq_comp/` y crea una carpeta llamada ejemplos. Dentro de dicha carpeta, crea un archivo llamado hello.cpp en el cual agregarás el siguiente código:

```c++
#include <systemc.h>

SC_MODULE (hello_world) {
  SC_CTOR (hello_world) {
  }

  void say_hello() {
    cout << "Hello World SystemC-2.3.3.\n";
  }
};

int sc_main(int argc, char* argv[]) {
  hello_world hello("HELLO");
  hello.say_hello();
  return(0);
}
```

8.- Exporta la variable de entorno que contendrá la dirección de instalación de SystemC:

```sh
export SYSTEMC_HOME=/usr/local/systemc-2.3.3/
```

9.- Compila el código utilizando g++, para ello, utiliza este comando si tu distro es de 64 bits.

```
g++ -I. -I$SYSTEMC_HOME/include -L. -L$SYSTEMC_HOME/lib-linux64 -Wl,-rpath=$SYSTEMC_HOME/lib-linux64 -o hello hello.cpp -lsystemc -lm
```

Si es de 32 bits:

```
g++ -I. -I$SYSTEMC_HOME/include -L. -L$SYSTEMC_HOME/lib-linux -Wl,-rpath=$SYSTEMC_HOME/lib-linux -o hello hello.cpp -lsystemc -lm
```

10.- Corre el programa. Si no hubo error de ningún tipo, entonces la instalación fue correcta.
