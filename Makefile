ogl : ogl.o
	gcc ogl.o -L/usr/local/lib -lglfw3 -ldrm -ldl -lm -lX11 -lGL -lpthread -lm -o ogl

ogl.o : ogl.c
	gcc -c -g -ggdb -O0 ogl.c

.PHONY : clean

clean:
	rm -f *.o ogl
