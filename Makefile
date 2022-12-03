all:	main.o Saver.o Task.o TaskList.o
	g++ main.o Saver.o Task.o TaskList.o -o ToDo
	
main.o: main.cpp
	g++ -c main.cpp

Saver.o: Saver.cpp
	g++ -c Saver.cpp

Task.o: Task.cpp
	g++ -c Task.cpp

TaskList.o: TaskList.cpp
	g++ -c TaskList.cpp

clean:
	rm -rf *.o