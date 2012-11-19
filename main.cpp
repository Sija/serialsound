#include <iostream>
#include <Windows.h>
#include "Serial.h"

using namespace std;

int main(int argc, char* argv[])
{
    if (argc < 2) {
        cerr << "You must provide COM port as an argument!" << endl;
        return 1;
    }
    string sound_file = "snapshot.wav";
    if (argc > 2) {
        sound_file = argv[2];
    }
    Serial serial(argv[1]);
    if (!serial.isConnected()) {
        cerr << "Cannot connect!" << endl;
        return 1;
    }
    char c;
    while (true) {
        if (-1 == serial.readData(&c, 1)) {
            continue;
        }
        PlaySound(sound_file.c_str(), NULL, SND_FILENAME);
    }
    return 0;
}
