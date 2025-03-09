#ifndef BUTTONS_H
#define BUTTONS_H

class Buttons {
  public:
    Buttons(int buttonPin1, int buttonPin2);
    void init();
    void checkButtons();

  private:
    int buttonPin1;
    int buttonPin2;
};

#endif // BUTTONS_H