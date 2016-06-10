/************************************************************************************************************************
  File type   : Arduino Library
  Developed By: Mario Calfizzi

  Description : This is the core MCP41010 library to managge the MCP41010 digital SPI 10KOhm potentiometer.
                
                Constructors:
                  MC_MCP41010 (uint8_t cs)
                  MC_MCP41010 (uint8_t cs, uint8_t clk, uint8_t mosi)

                Methods:
                  Begin       ( void )            Use it when you want start SPI communication
                  Write       ( uint8_t Value)    Set value from 0 up to 255   (variation between 0-10KoHm)
                  SetResistor ( uint16_t Value)   Set value from 0 up to 10000 (10Khom)
                  Reset       ( void )
                  End         ( void )

*************************************************************************************************************************/

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
private:
  uint8_t _cs;
  uint8_t _clk;
  uint8_t _mosi;
  bool    _use_spi;
  void    _writeBytes   ( uint8_t *data, uint8_t dataSize);
public:
          MC_MCP41010   ( uint8_t cs);
          MC_MCP41010   ( uint8_t cs, uint8_t clk, uint8_t mosi);
  void    Begin         ( void );
  // 0 - 255
  void    Write         ( uint8_t Value);
  // 0 - 10Khom
  void    SetResistor   ( uint16_t Value);
  void    Reset         ( void );
  void    End           ( void );
};

#endif