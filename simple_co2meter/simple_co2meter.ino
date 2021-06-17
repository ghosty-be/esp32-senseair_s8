/*  simple sketch to test the basic functionality of 
 *  Senseair s8 sensor attached to ESP32
 *  based on https://github.com/liutyi/esp32-oled-senseair/
*/

//Senseair Sensor UART pins
#define RXD2 13
#define TXD2 12

byte CO2req[] = {0xFE, 0X44, 0X00, 0X08, 0X02, 0X9F, 0X25};
byte CO2out[] = {0, 0, 0, 0, 0, 0, 0};

void RequestCO2 ()
{
  while (!Serial1.available())
  {
    Serial1.write(CO2req, 7);
    delay(50);
  }

  int timeout = 0;
  while (Serial1.available() < 7 )
  {
    timeout++;
    if (timeout > 10)
    {
      while (Serial1.available())
        Serial1.read();
      break;
    }
    delay(50);
  }

  for (int i = 0; i < 7; i++)
  {
    CO2out[i] = Serial1.read();
  }
}

unsigned long CO2count()
{
  int high = CO2out[3];
  int low = CO2out[4];
  unsigned long val = high * 256 + low;
  return val * 1; // S8 = 1. K-30 3% = 3, K-33 ICB = 10
}


void setup() {
  // PC COM Port
  Serial.begin(115200);
  // UART to Sensair CO2 Sensor
  Serial1.begin(9600, SERIAL_8N1, RXD2, TXD2);
}

void loop() {
  // Get Data from the Sensor
  RequestCO2();
  unsigned long CO2 = CO2count();
  delay(2000);
  String CO2s = "CO2: " + String(CO2);
  // Debug to PC COM Port
  Serial.println(CO2s);
}
