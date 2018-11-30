CC = g++
CXXFLAGS = -std=c++17

SRC_TIMER = timer.cpp
SRC_UNTIL = until.cpp
BIN_TIMER = timr
BIN_UNTIL = untl

INSTALL_PATH = /usr/bin/ # NOTE: Change if you want to install it somewhere else


all: untl timr
	
untl:
	$(CC) $(CXXFLAGS) -o $(BIN_UNTIL) $(SRC_UNTIL)
	
timr:
	$(CC) $(CXXFLAGS) -o $(BIN_TIMER) $(SRC_TIMER)

install:
	@install $(BIN_TIMER) $(BIN_UNTIL) $(INSTALL_PATH)

clean:
	@rm -f $(BIN_TIMER) $(BIN_UNTIL)
