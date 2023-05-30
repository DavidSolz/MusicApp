#include "AudioEffectPipeline.h"
#include "SoundStream.h"

int main(int argc, char** argv){

    AudioEffectPipeline* pipeline = new AudioEffectPipeline();
    SoundStream* soundStream = new SoundStream(argv[0], pipeline);

    std::string userInput;


    while (true) {
        std::cout << "\n> ";
        std::cin >> userInput;
        if (userInput == "play"){
            soundStream->play();
        } else if (userInput == "pause"){
            soundStream->pause();
        } else if (userInput == "stop"){
            soundStream->stop();
        } else if (userInput == "exit"){
            soundStream->stop();
            break;
        } else if (userInput == "time"){
            std::cout << soundStream->timeElapsed() << std::endl;
        } else if (userInput == "duration"){
            std::cout << soundStream->fileLength() << std::endl;
        } else if (userInput == "info"){
            soundStream->printCurrentlyPlayingInfo();
        } else if (userInput == "init"){
            std::cin >> userInput;
            soundStream->init(userInput);
        } else if (userInput == "volume") {
            std::cin >> userInput;
            float volume = std::stof(userInput);
            pipeline->setEffect("volume", &volume);
        } else if (userInput == "balance") {
            std::cin >> userInput;
            float balance = std::stof(userInput);
            pipeline->setEffect("balance", &balance);
        } else if (userInput == "skip") {
            std::cin >> userInput;
            int toSkip = std::stof(userInput);
            std::cout << soundStream->timeElapsed() << std::endl;
            soundStream->skipSeconds(toSkip);
            std::cout << soundStream->timeElapsed() << std::endl;
        } else if (userInput == "jump") {
            std::cin >> userInput;
            int min = std::stof(userInput);
            std::cin >> userInput;
            int sec = std::stof(userInput);
            std::cout << soundStream->timeElapsed() << std::endl;
            soundStream->jumpTo(min, sec);
            std::cout << soundStream->timeElapsed() << std::endl;
        }
    }

    delete soundStream;
    delete pipeline;
    return 0;
}