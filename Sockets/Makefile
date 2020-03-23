.PHONY   = clean

CXX      = g++
CXXFLAGS = -g -Wall -Wextra -pedantic


client: client.cpp PaqueteDatagrama.o SocketDatagrama.o
	$(CXX) $(CXXFLAGS) -o $@ $^
	@rm *.o


clean:
	@rm client
