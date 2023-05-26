COMPILER = g++
FLAGS = -w -Wall
OUTPUTFOLDER = ./Out
INPUTFOLDER = ./Model

clean:
	rm -rf $(OUTPUTFOLDER)/*.o

musicapp: player.o commander.o
	$(COMPILER) $(FLAGS) $(INPUTFOLDER)/Program.cpp $(OUTPUTFOLDER)/*.o -o $(OUTPUTFOLDER)/musicapp

commander.o: player.o playlist.o track.o 
	$(COMPILER) $(FLAGS) -c $(INPUTFOLDER)/Commander.cpp $(INPUTFOLDER)/ICommand.h $(OUTPUTFOLDER)/*.o -o $(OUTPUTFOLDER)/commander.o

player.o: playlist.o track.o
	$(COMPILER) $(FLAGS) -c $(INPUTFOLDER)/Player.cpp $(OUTPUTFOLDER)/*.o -o $(OUTPUTFOLDER)/player.o

playlist.o: track.o
	$(COMPILER) $(FLAGS) -c $(INPUTFOLDER)/Playlist.cpp $(OUTPUTFOLDER)/track.o -o $(OUTPUTFOLDER)/playlist.o

track.o:
	$(COMPILER) $(FLAGS) -c $(INPUTFOLDER)/track.cpp -o $(OUTPUTFOLDER)/track.o

