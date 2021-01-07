run: jogo
	./jogo

jogo: jogo.cpp
	$(CXX) -o jogo jogo.cpp

.PHONY: run