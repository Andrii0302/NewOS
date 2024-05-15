FILES=./build/start.o ./build/newos.o
INCLUDES=

all: ${FILES}
	i686-elf-ld -m elf_i386 -relocatable ${FILES} -o ./stdlib.elf

./build/start.o: ./src/start.asm
	nasm -f elf ./src/start.asm -o ./build/start.o

./build/newos.o: ./src/newos.asm
	nasm -f elf ./src/newos.asm -o ./build/newos.o


clean:
	rm -rf ${FILES}
	rm ./stdlib.elf