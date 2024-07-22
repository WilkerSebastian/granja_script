CXX		  := clang
CXX_FLAGS := -Wall -Wextra -std=c17

BIN		:= bin
SRC		:= src

LIBRARIES	:=
EXECUTABLE	:= granja_script.exe


all: $(BIN)/$(EXECUTABLE)

run: clean all
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*.c
	$(CXX) $(CXX_FLAGS) $^ -o $@ $(LIBRARIES)

clean:
	-rm $(BIN)/*