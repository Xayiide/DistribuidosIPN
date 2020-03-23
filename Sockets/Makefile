.PHONY   = clean

CXX      = g++
CXXFLAGS = -g -Wall -Wextra -pedantic


client: client.cpp PaqueteDatagrama.o SocketDatagrama.o
	$(CXX) $(CXXFLAGS) -o $@ $^
	@rm *.o

server: server.cpp PaqueteDatagrama.o SocketDatagrama.o
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	@rm client server
