all: parent.o child.o
	gcc -o ninteen parent.o child.o

parent.o: parent.c
	gcc -c parent.c
	
child.o: child.c
	gcc -c child.c

run:
	./ninteen
