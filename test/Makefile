
CXX = g++
CXXFLAGS += -g -std=c++14 -Wall -Wextra -pedantic -I../external -I../include
LDFAGS +=

TARGET = main
SRC = main.cpp static_wikipedia.cpp lmds.cpp bm25.cpp
OBJ = $(SRC:.cpp=.o)
DEP = $(SRC:.cpp=.d)

.PHONY: all
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFAGS)

%.o: %.cpp Makefile
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

.PHONY: clean
clean:
	$(RM) $(TARGET) $(OBJ) $(DEP)

-include $(DEP)
