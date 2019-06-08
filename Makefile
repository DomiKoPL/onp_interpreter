 CC := g++
FLAGS := -std=c++17
TARGET := onp

SRCS := $(wildcard *.cpp)

OBJS := $(patsubst %.cpp,%.o,$(SRCS))
OBJS1 := $(notdir $(OBJS))
OBJS1 := $(addprefix obj/, $(OBJS1))

all: $(TARGET)
$(TARGET): $(OBJS)
	$(CC) $(FLAGS) -o $@ $(OBJS1)
%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $(addprefix obj/, $(notdir $(patsubst %.cpp,%.o,$<)))
clean:
	rm -rf $(TARGET) obj/*.o
	
.PHONY: all clean