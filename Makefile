all: program

program: $(TheUnmagicalWand)
	g++ $(TheUnmagicalWand)-std=c++11 *.cpp -o TheUnmagicalWand -I/home/jscheil/.sfml/include -L/home/jscheil/.sfml/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network
	./TheUnmagicalWand

headers:
	g++ *.hpp

clean:
	rm *.hpp.gch
