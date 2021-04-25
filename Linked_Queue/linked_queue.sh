gcc -o ./lib/node.o -c node.c

gcc -o ./lib/linked_queue.o -c linked_queue.c

gcc -o ./lib/linked_queue ./lib/node.o ./lib/linked_queue.o -lm