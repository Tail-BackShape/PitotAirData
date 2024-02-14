#include <Wire.h>
#define MCP3425_addr 0x68

const byte MCP3425_config = 0B10011000;

double MCP3425_out(byte);

void setup()
{
  Wire.begin();
  Serial.begin(115200);
  while (!Serial)
  {
    delay(1);
  }
  Serial.println("Start");
  Wire.beginTransmission(MCP3425_addr);
  Wire.write(MCP3425_config);
  Wire.endTransmission();
}

void loop()
{
  float voltage = MCP3425_out(MCP3425_config);
  Serial.print("Voltage: ");
  Serial.println(voltage);
  delay(1000);
}

double MCP3425_out(byte)
{
  byte data1 = 0;
  byte data2 = 0;
  int result;
  double voltage;
  Wire.requestFrom(MCP3425_addr, 2);
  while (Wire.available())
  {
    data1 = Wire.read();
    data2 = Wire.read();
  }
  result = (data1 << 8) | data2;
  if (result > 32767)
  {
    result = result - 65536;
  }
  voltage = (result * 2.048) / 32768;
  return voltage;
}
