CC = g++

CFLAGS = -fPIC -Wall

LDFLAGS = -shared

RM = rm -f

TARGET_LIB = libstr.so

all: create

create:
        $(CC) clStr.cpp $(CFLAGS) $(LDFLAGS) -o libstr.so

        echo -e  " >>>>>>>>>>>>>>>>>.so file created "

install: lib h config

lib:
        sudo cp libstr.so /usr/lib

h:
        sudo cp clStr.h /usr/include

config:
        sudo ldconfig

export:
        
run:
        ./main3

clean:
        -${RM} ${TARGET_LIB} 
~                            
