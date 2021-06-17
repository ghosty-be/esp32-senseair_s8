# ESP32 + Senseair S8

- Sensor pinout info: https://esphome.io/components/sensor/senseair.html

## Sensor info
- G+: connected to 5V power pin (supported voltage is 4.5 V to 5.25 V)
- G0: connected to GND pin
- UART_RxD: connected to pin 13 on ESP32
- UART_TxD: connected to pin 12 on ESP32

## Some additional information and notes
- When attached to USB hub on breadboard I had the impression that the the readings were erratic... I stabilised the 5V line by adding an capacitor between VCC and GND close to the sensor.
