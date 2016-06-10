#include "MC_MCP41010.h"


void _writePin(uint8_t pin, uint8_t value)
{
  if (pin>=0 && pin<=A7 )
  {
    pinMode       ( pin,  OUTPUT);
    digitalWrite  ( pin,  value);
  }
}


void MC_MCP41010::_writeBytes (uint8_t *data, uint8_t dataSize)
{
  _writePin  ( this->_cs,  LOW);
  if (this->_use_spi)
    SPI.transfer  ( data, dataSize);
  else
  {
    for (uint8_t i=0; i<dataSize; i++) 
    {
      for (byte b=1; b<=8; b++) 
      {
        digitalWrite(this->_mosi, (data[i] >> (8-b)) & 1 ? HIGH : LOW);
        digitalWrite(this->_clk, HIGH);
        digitalWrite(this->_clk, LOW);
      }
    }
  }
  _writePin  ( this->_cs,  HIGH); 
}


MC_MCP41010::MC_MCP41010(uint8_t cs )
{
  this->_use_spi  = true;
  this->_cs       = cs;
  this->_clk      = SCK;
  this->_mosi     = MOSI;
}

MC_MCP41010::MC_MCP41010(uint8_t cs, uint8_t clk , uint8_t mosi  )
{
  this->_use_spi  = false;
  this->_cs       = cs;
  this->_clk      = clk;
  this->_mosi     = mosi;
}

void  MC_MCP41010::Begin()
{
  _writePin(this->_cs,HIGH);
  if (this->_use_spi)
    SPI.begin();  
  else
  {
    _writePin(this->_clk,   LOW);
    _writePin(this->_mosi,  LOW);
  }
  this->Reset();
}

// 0 - 255
void MC_MCP41010::Write(uint8_t Value)
{
  uint8_t Data[2] = {MC_MCP41010_WRITE0, Value};
  this->_writeBytes(Data, 2);
}

// 0 - 10Khom
void MC_MCP41010::SetResistor(uint16_t Value)
{
  if (Value>10000) Value = MAX_RESISTOR_LEVEL;
  uint8_t newValue = map (Value, 0,10000, 0,255);
  this->Write(newValue );
}

void MC_MCP41010::Reset(void)
{
  uint8_t Data[1] = {MC_MCP41010_SHUTDOWN};
  this->_writeBytes ( Data, 1);
}

void MC_MCP41010::End()
{
  if (this->_use_spi)
    SPI.end();
}
