
////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Audio.hpp>
#include <iostream>


////////////////////////////////////////////////////////////
/// Entry point of application
///
/// \return Application exit code
///
////////////////////////////////////////////////////////////
int main()
{
    // Check that the device can capture audio
    if (sf::SoundRecorder::isAvailable() == false)
    {
        std::cout << "Sorry, audio capture is not supported by your system" << std::endl;
        return EXIT_SUCCESS;
    }

    // Choose the sample rate
    unsigned int sampleRate = 44100;

    // Wait for user input...

    // Here we'll use an integrated custom recorder, which saves the captured data into a SoundBuffer
    sf::SoundBufferRecorder recorder;
    //main loop
    while (true){
    // Audio capture is done in a separate thread, so we can block the main thread while it is capturing
    recorder.start(sampleRate);
//    std::cout << "Recording... press enter to stop";
//    std::cin.ignore(10000, '\n');
    char k = system("choice /n /t 10 /d y /m recording...");
    if (k=='N') {return 0;};
    recorder.stop();

    // Get the buffer containing the captured data
    const sf::SoundBuffer& buffer = recorder.getBuffer();

    // Choose what to do with the recorded sound data
    // Create a sound instance and play it
    sf::Sound sound(buffer);
    sound.play();
    // Wait until finished
    while (sound.getStatus() == sf::Sound::Playing)
        {
            // Display the playing position
            std::cout << "\rPlaying... " << sound.getPlayingOffset().asSeconds() << " sec        ";
            std::cout << std::flush;

            // Leave some CPU time for other threads
            sf::sleep(sf::milliseconds(100));
        }

    }
    return EXIT_SUCCESS;
}
