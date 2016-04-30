all: program

program: $(TheUnmagicalWand)
	g++ $(TheUnmagicalWand) -O0 -std=c++11 *.cpp -o TheUnmagicalWand -I/home/jscheil/.sfml/include -L/home/jscheil/.sfml/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network

headers:
	rm *.hpp.gch
	g++ *.hpp

debug:
		g++ -g -O0 -std=c++11 *.cpp -o TheBrokenWand -I/home/jscheil/.sfml/include -L/home/jscheil/.sfml/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network
