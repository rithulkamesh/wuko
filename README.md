# Wuko

Wuko is a DIY MIDI macro controller built with ESP32, designed for musicians and producers who need customizable MIDI control capabilities in a compact package.

## Features

- **Customizable MIDI Controls**: Configure buttons for various MIDI commands
- **Potentiometer Input**: B10K potentiometer for continuous controller data (CC), specifically mapped to modulation wheel
- **Display Feedback**: SH110X OLED display for visual feedback and configuration
- **Wired Connection**: Reliable USB MIDI connection to your computer or other MIDI devices
- **Open Source**: Fully customizable hardware and software

## Hardware Requirements

- ESP32 microcontroller
- SH110X OLED display
- Push buttons (for MIDI macros)
- B10K potentiometer
- PCB (design files included in wuko-pcb)
- USB cable for power and data

## Getting Started

### Development Environment Setup

This project uses Nix for dependency management. To set up the development environment:

1. Install Nix if you don't have it already
2. Clone this repository
3. Enter the development environment:
   ```sh
   cd wuko
   nix-shell
   ```
   The shell.nix file will automatically set up all required dependencies.

### Building and Flashing

This project uses PlatformIO for building and uploading

```sh
# Install Requirements
pio pkg install

# Build the project
pio run

# Upload to connected device
pio run -t upload

# Monitor serial output
pio device monitor
```

## Usage

After flashing your Wuko device:

1. Connect it to your computer or MIDI device via USB
2. The device will appear as a USB MIDI device
3. The potentiometer controls the modulation wheel (CC #1) on MIDI channel 1
4. Buttons can be programmed to send various MIDI commands
5. The OLED display shows the current status and configuration

## License

This project is licensed under the GNU General Public License v3.0 - see the LICENSE.md file for details.

## Contributing

Contributions are welcome! Feel free to submit issues or pull requests.

## Author

&copy; 2025-Present Rithul Kamesh
