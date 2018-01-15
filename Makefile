ogl : ogl.o
	gcc ogl.o -lglfw3 -Wl,-rpath=/usr/lib/nvidia-384 -L/usr/lib/nvidia-384 -lGL -lX11 -lpthread -lm -ldl -o ogl

ogl.o : ogl.c
	gcc -c -g -ggdb -O0 ogl.c

.PHONY : clean

clean:
	rm -f *.o ogl
