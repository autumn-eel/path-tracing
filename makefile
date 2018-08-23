main: main.cpp
	g++ -O2 main.cpp -o main -fopenmp
clean:
	rm main
