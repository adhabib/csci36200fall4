hashTable:	main.o
	g++ main.o -o hashTable
main.o:	main.cpp
	g++ -c main.cpp
clean:
	rm -f *.o
	rm hashTable
run:	hashTable
	./hashTable
