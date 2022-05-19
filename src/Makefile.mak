PROJECT_NAME=RawTest
TARGET=../build/$(PROJECT_NAME).exe

FILES =$(wildcard ../vendor/GLAD/src/*.c) $(wildcard *.cpp)
OBJS  =$(wildcard *.o)

MINGW=$(MINGW_PATH)
MINGW_LIB=-L"$(MINGW)\\lib"
MINGW_INC=-I"$(MINGW)\\include"
GLAD_INC=-I"..\\vendor\\GLAD\\include"
LINMATH_INC=-I"..\\vendor\\linmath\\include"
SDL2_LIB=-L"..\\vendor\\SDL2\\lib"
SDL2_INC=-I"..\\vendor\\SDL2\\include"
STB_INC=-I"..\\vendor\\stb\\include"
JSON_INC=-I"..\\vendor\\json\\include"

LIB_FLAGS=-mwindows -lkernel32 -luser32 -lgdi32 -lglfw3 -lopengl32 -lz -lstdc++
INC_FLAGS=-g -Wall -Wextra -w

LIBS=$(MINGW_LIB) $(SDL2_LIB) $(LIB_FLAGS)
CFLAGS=$(MINGW_INC) $(GLAD_INC) $(LINMATH_INC) $(SDL2_INC) $(STB_INC) $(JSON_INC) $(INC_FLAGS)
CPP=g++.exe

all: clean-before build clean-after run

clean-before:
	@for %%i in ($(OBJS)) do if exist %%i del /f %%i

clean-after:
	@for %%i in ($(OBJS)) do if exist %%i del /f %%i

build: compile
	@$(CPP) -Wall -s -O2 -o $(TARGET) $(OBJS) $(LIBS)
	@echo building $(OBJS)..

compile: $(FILES)
	@$(CPP) -Wall -s -O2 -c $(FILES) $(CFLAGS)
	@echo compile $(FILES)..

run:
	@echo running project..
	./$(TARGET)