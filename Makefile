
# A simple Makefile for compiling small SDL projects

# set the compiler
CC := g++ 

# set the compiler flags
CFLAGS := `sdl2-config --libs --cflags` -ggdb3 -O0 --std=c99 -Wall -lSDL2_ttf -lm 

# add header files here
HDRS := src/SDL_Dictionary.h src/Essential.h src/Dictionary/Definition.h src/Dictionary/Dictionary.h src/Dictionary/Origin.h src/Dictionary/Member.h src/Dictionary/Word.h

# add source files here
SRCS := src/main.cpp src/SDL_Dictionary.cpp src/Essential.cpp src/Dictionary/Definition.cpp src/Dictionary/Dictionary.cpp src/Dictionary/Origin.cpp src/Dictionary/Member.cpp src/Dictionary/Word.cpp

# generate names of object files
OBJS := $(SRCS:.cpp=.o)

# name of executable
EXEC := quick-dict

# default recipe
all: $(EXEC)

showfont: showfont.c Makefile
	$(CC) -o $@ $@.c $(CFLAGS) $(LIBS)

glfont: glfont.c Makefile
	$(CC) -o $@ $@.c $(CFLAGS) $(LIBS)

# recipe for building the final executable
$(EXEC): $(OBJS) $(HDRS) Makefile
	$(CC) -o $@ $(OBJS) $(CFLAGS)

# recipe for building object files
#$(OBJS): $(@:.o=.c) $(HDRS) Makefile
#    $(CC) -o $@ $(@:.o=.c) -c $(CFLAGS)

# recipe to clean the workspace
clean:
	rm -f $(EXEC) $(OBJS)

.PHONY: all clean
