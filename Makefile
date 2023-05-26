COMPILER = g++
FLAGS = -w -Wall -lpulse-simple -lpulse -std=c++17
OUTPUTFOLDER = ./Out
INPUTFOLDER = ./Model

musicapp:
	$(COMPILER) $(FLAGS) $(INPUTFOLDER)/*.cpp -o $(OUTPUTFOLDER)/musicapp

clean:
	rm -rf $(OUTPUTFOLDER)/*

