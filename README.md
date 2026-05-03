# InfraHome — IR-Based Smart Home Controller

A lightweight Arduino project that lets you control home appliances wirelessly using any standard IR remote. Toggle individual lights, control a fan, and cut power to all devices with a single button press — all with real-time feedback on a 16×2 LCD display.

---

## System Diagram

![System Diagram](diagram.png)

---

## Features

- **Wireless control** via IR remote — no Wi-Fi or Bluetooth needed
- **Toggle 3 devices independently** (Light 1, Light 2, Fan)
- **Master power-off** button turns off all devices at once
- **16×2 I2C LCD** shows the current state of each device in real time
- **Serial monitor output** for debugging raw IR codes

---

## Hardware Requirements

| Component | Quantity |
|---|---|
| Arduino Uno (or compatible) | 1 |
| IR Receiver Module (e.g. VS1838B) | 1 |
| 16×2 I2C LCD Display | 1 |
| LEDs (representing appliances) | 3 |
| 220Ω Resistors | 3 |
| IR Remote Control | 1 |
| Jumper Wires & Breadboard | — |

---

## Pin Configuration

| Component | Arduino Pin |
|---|---|
| IR Receiver | D2 |
| LED 1 (Light 1) | D7 |
| LED 2 (Light 2) | D8 |
| LED 3 (Fan) | D9 |
| LCD SDA | A4 |
| LCD SCL | A5 |

> The LCD uses the I2C interface at address `0x27`. If your display doesn't turn on, try `0x3F`.

---

## Libraries Used

Install these via the Arduino Library Manager before uploading:

- [IRremote](https://github.com/Arduino-IRremote/Arduino-IRremote) — IR signal decoding
- [LiquidCrystal_I2C](https://github.com/johnrickman/LiquidCrystal_I2C) — I2C LCD control

---

## How It Works

1. The IR receiver listens for signals on pin D2.
2. When a button is pressed on the remote, the decoded hex code is matched against predefined constants.
3. The corresponding device state is toggled and the LED is updated.
4. The LCD clears and displays the device name along with its new state (`ON` / `OFF`).
5. Pressing the **Power** button sets all devices to `OFF` simultaneously.

### Remote Button Mapping

| Button | Action | IR Code |
|---|---|---|
| `1` | Toggle Light 1 | `0xF50A7F80` |
| `2` | Toggle Light 2 | `0xE41B7F80` |
| `3` | Toggle Fan | `0xE01F7F80` |
| `POWER` | Turn off all devices | `0xED127F80` |

---

## Customising for Your Remote

Every IR remote sends different hex codes. To find yours:

1. Upload the sketch and open the **Serial Monitor** at `9600` baud.
2. Point your remote at the receiver and press a button.
3. Note the hex value printed in the monitor.
4. Replace the `#define BUTTON_x` constants in the sketch with your values.

---

## Getting Started

1. Wire up the components following the pin configuration table above.
2. Install the required libraries.
3. Open `InfraHome.ino` in the Arduino IDE.
4. Select your board and COM port, then click **Upload**.
5. The LCD will display **"Smart Home — System Ready"** for 2 seconds, then go blank and wait for input.

---

## Project Structure

```
InfraHome/
├── InfraHome.ino   # Main Arduino sketch
├── diagram.png     # Circuit/system diagram
└── README.md       # Project documentation
```

---

## License

This project is open source and free to use for personal and educational purposes.
