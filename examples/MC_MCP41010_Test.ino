/*
 Name:		MC_MCP41010_Test.ino
 Created:	6/1/2016 7:20:54 PM
 Author:	Mario
*/

#include <SPI.h>  // include the SPI library
#include <MC_MCP41010.h>


#define USE_SPI 1



#define MCP41010_CS_PIN 4

#if USE_SPI
  MC_MCP41010 MCP41010 ( MCP41010_CS_PIN );
#else
  MC_MCP41010 MCP41010(MCP41010_CS_PIN, 13,11);
#endif

void setup() 
{
  Serial.begin(115200);
  Serial.println("Start MCP 41010");
  //SPI.begin();
  //SPI.end();
  MCP41010.Begin();
}

void loop() 
{
  Serial.println("Loop");
  for (int level = 0; level <= MAX_LEVEL; level++)
  {
    MCP41010.Write((uint8_t)level);
    delay(1);
  }
  for (int level = 0; level <= MAX_LEVEL; level++)
  {
    MCP41010.Write((uint8_t)(MAX_LEVEL-level));
    delay(1);
  }

}
 
