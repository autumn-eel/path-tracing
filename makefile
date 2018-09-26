main: main.cpp define.h load.h object.h pathtrace.h ppm.h scene.h xorshift.h
	g++ -O2 main.cpp -o main -fopenmp
clean:
	rm main
