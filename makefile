all: parent.o child.o
	gcc -o parent parent.o
	gcc -o child child.o

parent.o: parent.c
	gcc -c parent.c
	
child.o: child.c
	gcc -c child.c

run:
	./parent
	./child
