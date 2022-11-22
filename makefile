all: sprint

sprint: sprint_def.o sprint_cl.o
	gcc sprint.h sprint_def.c sprint_cl.c -o sprint

sprint_def.o: sprint_def.c
	gcc -c sprint.h sprint_def.c
           
sprint_cl.o: sprint_cl.c
	gcc -c sprint.h sprint_cl.c
