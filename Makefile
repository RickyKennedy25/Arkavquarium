OBJS = models/*.cpp controllers/*.cpp views/*.cpp main.cpp
TEST_OBJS = models/*.cpp controllers/*.cpp views/*.cpp tests/*.cpp test.cpp

CC = g++
COMPILER_FLAGS = -std=c++11 -w -O2
LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf
OBJ_NAME = bin/arkavquarium
TEST_OBJ_NAME = bin/tests

all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

test : $(OBJS)
	$(CC) $(TEST_OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(TEST_OBJ_NAME)
	$(TEST_OBJ_NAME)
