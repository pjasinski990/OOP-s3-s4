CXX = g++
EXEC = main.exe
CXXFLAGS = -Wall -g -MMD
LDFLAGS = 

SRC=$(wildcard *.cpp)
OBJS=$(SRC:.cpp=.o)
DEPS=$(SRC:.cpp=.d)

$(EXEC): $(OBJS)
	$(CXX) -o $(EXEC) $(OBJS) $(CXXFLAGS) $(LDFLAGS)

*.o: *.cpp
	$(CXX) -c $(CXXFLAGS) $<

.PHONY: clean run all 

clean: 
	rm -f $(OBJS)
	rm -f $(DEPS)
	rm -f $(EXEC) 
	rm -rf latex html
	rm -f Doxyfile

run: $(EXEC)
	@echo 
	@echo ~~~ NOW RUNNING THE EXECUTABLE: ~~~
	./$(EXEC)

all:
	make clean
	make run

-include $(DEPS)
