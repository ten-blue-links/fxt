
CXX = g++
CXXFLAGS += -O0 -g -std=c++17 -Wall -Wextra -pedantic \
			-I../external \
			-I../include \
			-I../external/cereal/include
LDFAGS = -lFastPFor -L../build/external/FastPFor

TARGET = main
SRC = main.cpp static_wikipedia.cpp lmds.cpp bm25.cpp forward_index.cpp \
	  ../src/compression.cpp forward_index_interactor.cpp \
	  lexicon.cpp sdm.cpp
OBJ = $(SRC:.cpp=.o)
DEP = $(SRC:.cpp=.d)

.PHONY: all
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

.PHONY: clean
clean:
	$(RM) $(TARGET) $(OBJ) $(DEP)

-include $(DEP)
