all: program

program: $(TheUnmagicalWand)
	g++ $(TheUnmagicalWand) *.h *.hpp *.cpp -o TheUnmagicalWand -I/home/jscheil/.sfml/include -L/home/jscheil/.sfml/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network
	./TheUnmagicalWand
