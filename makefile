all : COMP EXEC

COMP:
	gcc tp1.c graph.c 

EXEC:
	./a.out