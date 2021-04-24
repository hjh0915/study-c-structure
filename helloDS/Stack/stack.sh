gcc -o node.o -c node.c
gcc -o seq_stack.o -c seq_stack.c
gcc -o seq_stack node.o seq_stack.o -lm