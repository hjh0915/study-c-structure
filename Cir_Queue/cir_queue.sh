gcc -o ./lib/node.o -c node.c

gcc -o ./lib/cir_queue.o -c cir_queue.c

gcc -o ./lib/cir_queue ./lib/node.o ./lib/cir_queue.o -lm