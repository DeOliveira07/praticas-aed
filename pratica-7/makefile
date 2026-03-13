CXX = g++
CXXFLAGS = -Wall -Wextra -Wpedantic -g -std=c++17

SRC_DIR = src
OBJ_DIR = obj
BIN = test_main

SRC = $(wildcard $(SRC_DIR)/*.cpp)
OBJ = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC))

ifeq ($(OS),Windows_NT)
    RM = rmdir /S /Q
    RM_FILE = del /Q
    MKDIR = mkdir
    EXE = .exe
else
    RM = rm -rf
    RM_FILE = rm -f
    MKDIR = mkdir -p
    EXE =
endif


all: $(BIN)

$(BIN): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	-$(RM) $(OBJ_DIR)
	-$(RM_FILE) $(BIN)
