# Exploring-SystemC

This repository documents the journey of learning systemC

## Table of Contents

- [Tool Chain](#Tool-Chain)
  * [SystemC](#SystemC)
  * [gtkwave](#gtkwave)
- [Running the Program](#Running-the-Program)

## Tool Chain

### SystemC
Make sure gcc compiler is installed, else run below command to install  
```
sudo apt install build-essential
```
Run below command to get version of gcc compiler  
```
gcc --version
```
Download SystemC 2.3.3 version from below link 
```
https://www.accellera.org/downloads/standards/systemc
```
Navigate to downloads folder and check the downloaded file  
```
cd Downloads/
```
Extract the File  
```
tar -xvf systemc-2.3.3.tar.gz
```
Navigate to the extracted directory and create a object directory
```
cd systemc-2.3.3/
mkdir objdir
cd objdir/
```
Enter below commands
```
sudo ../configure --prefix=/usr/local/systemc-2.3.3/
sudo make
sudo make install
```
Add the installation path to environment variables
```
vim ~/.bashrc
```
Add below lines at the end in insert mode and save the file
```
# System C Installation Path
export SYSTEMC_HOME=/usr/local/systemc-2.3.3/
export LD_LIBRARY_PATH=/usr/local/systemc-2.3.3/lib-linux64/
```

### gtkwave
The simulator generates value change dump (.vcd) file this can be viewed as wave using gtkwave waveform viewer.  
Use following command to install gtkwave on Ubuntu machine.
```
sudo apt install gtkwave
```

## Running the Program
```
g++ -I. -I$SYSTEMC_HOME/include -L. -L$SYSTEMC_HOME/lib-linux64 -o out main.cpp driver.h monitor.h andgate.h -lsystemc -lm
```
```
./out
```
```
gtkwave traces.vcd
```
