output: caso_2.o
	g++ caso_2.o -o output

caso_2.o: Caso_2.cpp
	g++ -c Caso_2.cpp

clean:
	rm *.o output
