all: main.o
	gcc -Wall -Wextra -o ./bin/main ./build/main.o
	cp ./bin/main ~/.local/bin/trac

main.o:
	gcc -Wall -Wextra -c -o ./build/main.o ./src/main.c

clean:
	rm -rf ./build/*.o ./bin/main
