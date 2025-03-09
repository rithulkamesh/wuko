#include "midi.h"
class Potentiometer {
  public:
    Potentiometer(int pin);
    void init();
    int readValue();

    void sendControlChange(Midi &midi);

  private:
    int pin;
};