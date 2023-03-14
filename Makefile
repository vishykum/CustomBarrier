all:
	g++ main.cpp CustomBarrier.cpp -lpthread -O3 -o main

clean:
	rm main