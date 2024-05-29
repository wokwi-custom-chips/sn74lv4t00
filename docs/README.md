# Wokwi sn74lv4t00 Chip

This is a custom chip for [Wokwi](https://wokwi.com/). It implements the sn74lv4t00 IC.

## Description

The sn74lv4t00 contain Quadruple 2-input NAND gate. Each gate performs the Boolean function
of Y = NOT(A . B) in positive logic.

## Truth Table

| INPUT A | INPUT B |  OUTPUT |
|---------|---------|---------|
|    L    |    L    |    H    |
|    H    |    L    |    H    |
|    L    |    H    |    H    |
|    H    |    H    |    L    |

## Pin names

| Name  | Description             |
| ----- | ----------------------- |
|  1A   | Gate 1 Input signal  A  |
|  1B   | Gate 1 Input signal  B  |
|  1Y   | Gate 1 Output signal    |
|  2A   | Gate 2 Input signal  A  |
|  2B   | Gate 2 Input signal  B  |
|  2Y   | Gate 2 Output signal    |
|  3A   | Gate 3 Input signal  A  |
|  3B   | Gate 3 Input signal  B  |
|  3Y   | Gate 3 Output signal    |
|  4A   | Gate 4 Input signal  A  |
|  4B   | Gate 4 Input signal  B  |
|  4Y   | Gate 4 Output signal    |
|  GND  | Ground                  |
|  VCC  | Supply voltage          |


## Usage

To use this chip in your project, include it as a dependency in your `diagram.json` file:

```json
  "dependencies": {
    "chip-sn74lv4t00": "github:wokwi-custom-chips/sn74lv4t00@0.1.0"
  }
```

Then, add the chip to your circuit by adding a `chip-sn74lv4t00` item to the `parts` section of diagram.json:

```json
  "parts": {
    ...,
    { "type": "chip-sn74lv4t00", "id": "chip1" }
  },
```

For a complete example, see [The sn74lv4t00 chip test project](https://wokwi.com/projects/398980510024578049).
