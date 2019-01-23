
CC=g++

CFLAGs = -c -Wall

OUT= -o

MF = mv

CP = cp

MD = mkdir -p

SRC = SRC

BIN = BIN

all: move

move: compile movenow

compile: servp2.o clip2.o

servp2.o:
	$(CC) $(CFLAGs) server.cpp

clip2.o:
	$(CC) $(CFLAGs) client.cpp

movenow: file.cpp file.o

file.cpp: makecppdir
	$(CP) *.cpp $(SRC)\
	
makecppdir:
	$(MD) $(SRC)

file.o: makeodir 
	$(CP) *.o $(BIN)\

makeodir:
	$(MD) $(BIN)

clean:
	rm *.o *.h *.cpp

