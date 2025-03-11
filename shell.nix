{
  pkgs ? import <nixpkgs> { },
}:

pkgs.mkShell {
  buildInputs = with pkgs; [
    # Basic development tools
    gcc
    gcc-arm-embedded
    gnumake
    cmake
    python3
    python3Packages.pip
    python3Packages.setuptools
    python3Packages.wheel

    # PlatformIO for ESP32 development
    platformio

    # Serial communication tools
    screen
    minicom
    picocom

    # USB and MIDI tools
    usbutils
    alsa-utils
    alsa-lib

    # Git and other utilities
    git
    wget
    curl
  ];

  shellHook = ''
    echo "Wuko Development Environment"
    echo "Remember to install these PlatformIO libraries:"
    echo "  - Adafruit SH110X"
    echo "  - MIDI Library"
    echo "  - Adafruit GFX Library"
    echo "  - ESP32 Core"
    echo ""
    echo "Use 'pio lib install <library_name>' to install required libraries"
    echo "Use 'pio run -t upload' to build and upload to your device"
  '';

  # Set environment variables if needed
  NIX_ENFORCE_PURITY = 0;
  PLATFORMIO_CORE_DIR = "~/.platformio";
}
