# MC_MCP41010
MCP41010 digital SPI 10KOhm potentiometer  - Arduino Library

Download and try the class MC_MCP41010 to manage MCP41010 digital SPI 10KOhm potentiometer...
#   Constructors
        MC_MCP41010 (uint8_t cs)
        MC_MCP41010 (uint8_t cs, uint8_t clk, uint8_t mosi)



#   Methods
        Begin       ( void )            Use it when you want start SPI communication
        Write       ( uint8_t Value)    Set value from 0 up to 255   (variation between 0-10KoHm)
        SetResistor ( uint16_t Value)   Set value from 0 up to 10000 (10Khom)
        Reset       ( void )
        End         ( void )
