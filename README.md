# MIDI ESP8266 Controller

This project is a MIDI macro controller built using the ESP8266 microcontroller. It features a couple of buttons, a B10K potentiometer, and an SH110X display. The main functionality includes sending MIDI Control Change (CC) signals, specifically for the mod wheel potentiometer.

## Project Structure

The project is organized as follows:

```
midi-esp8266-controller
├── src
│   ├── main.cpp          # Entry point of the application
│   ├── display.cpp       # Implementation of display functionality
│   ├── display.h         # Header for display class
│   ├── buttons.cpp       # Implementation of button handling
│   ├── buttons.h         # Header for buttons class
│   ├── potentiometer.cpp  # Implementation for potentiometer reading
│   ├── potentiometer.h    # Header for potentiometer class
│   ├── midi.cpp          # Implementation of MIDI communication
│   └── midi.h            # Header for MIDI class
├── include
│   └── config.h          # Configuration settings
├── lib
│   ├── README.md         # Documentation for libraries used
│   └── placeholder.txt    # Placeholder for future library files
├── test
│   └── test_main.cpp     # Unit tests for main functionality
├── platformio.ini        # PlatformIO configuration file
├── shell.nix             # Development environment definition
└── README.md             # Project documentation
```

## Features

- **MIDI Control Change**: Sends CC signals on channel 1 for the mod wheel potentiometer.
- **User Interface**: Utilizes buttons for user interaction and an SH110X display for visual feedback.
- **Modular Design**: Each component (display, buttons, potentiometer, MIDI) is encapsulated in its own class for better maintainability.

## Setup Instructions

1. **Clone the Repository**: 
   ```
   git clone <repository-url>
   cd midi-esp8266-controller
   ```

2. **Install Dependencies**: 
   Use Nix to set up the development environment:
   ```
   nix-shell
   ```

3. **Build the Project**: 
   Use PlatformIO to build the project:
   ```
   pio run
   ```

4. **Upload to ESP8266**: 
   Connect your ESP8266 and upload the firmware:
   ```
   pio run --target upload
   ```

## Usage

Once uploaded, the device will initialize the display and buttons. The potentiometer can be adjusted to send MIDI Control Change messages, which can be received by any compatible MIDI device or software.

## Contributing

Contributions are welcome! Please submit a pull request or open an issue for any enhancements or bug fixes.

## License

This project is licensed under the MIT License. See the LICENSE file for details.