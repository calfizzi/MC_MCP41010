#ifndef MC_MCP41010_h
#define MC_MCP41010_h
#include <Arduino.h>
#include <SPI.h>


#define MC_MCP41010_NO_PIN 255

#define MC_MCP41010_SHUTDOWN_BIT  B00100000
#define MC_MCP41010_WRITE_BIT     B00010000
#define MC_MCP41010_POT0_BIT      B00000001
#define MC_MCP41010_POT1_BIT      B00000010

#define MC_MCP41010_SHUTDOWN      MC_MCP41010_SHUTDOWN_BIT  | MC_MCP41010_POT0_BIT | MC_MCP41010_POT0_BIT
#define MC_MCP41010_WRITE0        MC_MCP41010_WRITE_BIT     | MC_MCP41010_POT0_BIT 
#define MC_MCP41010_WRITE1        MC_MCP41010_WRITE_BIT     | MC_MCP41010_POT1_BIT 

#define MAX_LEVEL                   255
#define MAX_RESISTOR_LEVEL        10000


class MC_MCP41010
{
public:
  uint8_t _cs;
  uint8_t _clk;
  uint8_t _mosi;
  bool    _use_spi;
  void    _writeBytes (uint8_t *data, uint8_t dataSize);
public:
        MC_MCP41010(uint8_t cs);
        MC_MCP41010(uint8_t cs, uint8_t clk, uint8_t mosi);
  void  Begin();
  // 0 - 255
  void  Write(uint8_t Value);
  // 0 - 10Khom
  void  SetResitor(uint16_t Value);
  void  Reset();
  void  End();
};

#endif