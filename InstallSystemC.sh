#!/bin/sh
echo Ya que éste script instala programas, necesita sudo
echo Descargando Systemc 2.3.3
wget https://accellera.org/images/downloads/standards/systemc/systemc-2.3.3.tar.gz
echo Listo!, Descomprimiendo...
tar -xvf systemc-2.3.3.tar.gz
cd systemc-2.3.3
echo creando systemc-2.3.3/objdir
mkdir objdir
cd objdir
echo creando carpeta en /usr/local
sudo mkdir /usr/local/systemc-2.3.3
echo configurando...
sudo ../configure --prefix=/usr/local/systemc-2.3.3/
echo instalando
sudo make
sudo make install

echo exportando variable de entorno
export SYSTEMC_HOME=/usr/local/systemc-2.3.3/
 echo "export LD_LIBRARY_PATH=/usr/local/systemc-2.3.3/lib-linux64" >> ~/.bashrc
