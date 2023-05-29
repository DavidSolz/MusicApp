COMPILER = g++
FLAGS = -w -Wall -lpulse-simple -lpulse -std=c++17 -g
TARGET = musicapp
OUTPUTFOLDER = ./Out
INPUTFOLDER = ./Model

musicapp: clean
	$(COMPILER) $(FLAGS) $(INPUTFOLDER)/*.cpp -o $(OUTPUTFOLDER)/$(TARGET)

clean:
	rm -rf $(OUTPUTFOLDER)/$(TARGET) 

