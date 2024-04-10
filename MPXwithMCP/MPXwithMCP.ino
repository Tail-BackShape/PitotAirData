#include <Wire.h>
#define MCP3425_addr 0x68

const byte MCP3425_config = 0B10011000;

double MCP3425_out(byte);
double airSpeed(double);

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
  double Vout2 = MCP3425_out(MCP3425_config);
  double Vout1 = originV(Vout2);
  double As = airspeed(Vout1);

  Serial.print("Vout1: ");
  Serial.println(String(Vout1, 6));
  Serial.print("Vout2: ");
  Serial.println(String(Vout2, 6));
  Serial.print("Airspeed: ");
  Serial.println(String(As, 6));

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

double originV(double Vout2)
{
  double Vout1 = Vout2 * 50.0 / 33.0;

  return Vout1;
}

double airspeed(double Vout1)
{
  double dP, airspeed;
  dP = Vout1 - 2.5;
  airspeed = sqrt((2 * dP) / 1.293);

  return airspeed;
}
