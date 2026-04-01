CXX = clang++
CXXFLAGS = -std=c++17 -Wall -Wextra

TARGET = app

SRCS = main.cpp array.cpp database.cpp magazines.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

$.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o %@

clean:
	rm -f $(OBJS) $(TARGET)