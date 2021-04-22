模块分离
=======

gcc -o node.o -c node.c
gcc -o test.o -c test.c

gcc -o test node.o test.o -lm