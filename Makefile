ogl : ogl.o
	g++ ogl.o -lglfw3 -I/usr/local/include -Wl,-rpath=/usr/lib/nvidia-384 -L/usr/lib/nvidia-384 -lGL -lX11 -lpthread -lm -ldl -o ogl

ogl.o : ogl.cpp
	g++ -c -g -ggdb -O0 ogl.cpp

.PHONY : clean

clean:
	rm -f *.o ogl
