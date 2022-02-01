# build the autograder/user solution combo

# gcc compiler
GCC = g++

# compiler flags
# -Wall       compiler warnings cause no compile
# -Werror     compiler errors cause no compile
# -O1         O1 optimization
# -pedantic   enforces standard C conventions
# --std=c++11 uses c++11 compiler
CFLAGS = -Wall -Werror -O1 -pedantic --std=c++17

# build target
TARGET = autograder

# build dependencies
INCLUDES = driver_22.cpp contest_22.cpp contest_22.h

autograder: $(INCLUDES)
	$(GCC) $(CFLAGS) -o $(TARGET) $(INCLUDES)

clean:
	$(RM) $(TARGET)
