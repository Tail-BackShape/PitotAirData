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
  double voltage = MCP3425_out(MCP3425_config);
  Serial.print("Voltage: ");
  Serial.println(String(voltage, 6));
  delay(1000);
}

double MCP3425_out(byte)
{
  byte data1 = 0;
  byte data2 = 0;
  int MCPout;
  double voltage;
  Wire.requestFrom(MCP3425_addr, 2);
  while (Wire.available())
  {
    data1 = Wire.read();
    data2 = Wire.read();
  }
  MCPout = (data1 << 8) | data2;
  if (MCPout > 32767)
  {
    MCPout -= 65536;
  }
  voltage = (MCPout * 2.048) / 32768;
  return voltage;
}
