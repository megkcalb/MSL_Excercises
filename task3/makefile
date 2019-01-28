CC = g++

CFLAGS = -fPIC -Wall

LDFLAGS = -shared

RM = rm -f

TARGET_LIB = libstr.so

all: create link install run

create:
        $(CC) clStr.cpp $(CFLAGS) $(LDFLAGS) -o libstr.so

        echo -e  " >>>>>>>>>>>>>>>>>.so file created "

link:
        $(CC) main3.cpp -L. -lstr -o main3

        echo  -e " >>>>>>>>>>>>>>>>> linked with the program "

install: lib h config

lib:
        sudo cp libstr.so /usr/lib

h:
        sudo cp clStr.h /usr/include

config:
        sudo ldconfig


run:
        ./main3

clean:
        -${RM} ${TARGET_LIB} 
