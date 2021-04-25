gcc -o node.o -c node.c
gcc -o linked_stack.o -c linked_stack.c

# 需要在lib目录下运行
gcc -o linked_stack node.o linked_stack.o -lm