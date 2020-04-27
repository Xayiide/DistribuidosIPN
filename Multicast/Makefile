.PHONY = clean all

CXX      = g++

all: receptor emisor
	@rm *.o

receptor: SocketDatagrama.o PaqueteDatagrama.o Respuesta.o Solicitud.o SocketMulticast.o receptor.cpp
	$(CXX) -o $@ $^

emisor: SocketDatagrama.o PaqueteDatagrama.o Respuesta.o Solicitud.o SocketMulticast.o emisor.cpp
	$(CXX) -o $@ $^


clean:
	@rm receptor emisor
