# ejecutables
app: main.o functions.o
	gcc main.o functions.o -o ./execute/app

# fuentes
functions.o: functions.c
	gcc -c functions.c
main.o: main.c
	gcc -c main.c

# reglas mudas
.PHONY: clean # make clean, ejecuta y hace clena

clean:
	rm *.o