SRC=$(wildcard *.c)
TARGET=$(patsubst %.c,%,${SRC})

all: ${TARGET}

clean:
	rm -f ${TARGET}

%: %.c
	gcc -o $@ $< -g -fsanitize=undefined -fsanitize=address

# ./heapsort: ./heapsort.c ./heapsort.h
# 	gcc -o heapsort heapsort.c
