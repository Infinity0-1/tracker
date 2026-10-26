all:
	gcc -o main main.c

# main.o:
# 	gcc -c -o main.o main.c

clean:
	rm -rf *.o main
