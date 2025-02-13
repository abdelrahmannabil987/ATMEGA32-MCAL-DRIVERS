# SPI Driver

## Overview
This repository contains an SPI (Serial Peripheral Interface) driver written in C. The driver supports both Master and Slave modes and includes a function for data transceiving.

## Features
- Supports SPI Master and Slave initialization.
- Uses polling mechanism for data transmission.
- Configurable clock prescaler.

## Files
- `SPI_config.h`: Configuration file for SPI settings.
- `SPI_interface.h`: Interface file containing function prototypes.
- `SPI_private.h`: Private file for internal macros and definitions.
- `SPI_register.h`: Register definitions for SPI.
- `SPI_program.c`: Implementation of SPI functions.

## Functions

### `void SPI_voidInitMaster(void)`
Initializes the SPI module in Master mode with a clock prescaler of 16.

```c
void SPI_voidInitMaster(void)
{
    /*Master Initialization*/
    SET_BIT(SPCR,SPCR_MSTR);

    /*Clock Prescaler divide by 16*/
    SET_BIT(SPCR,SPCR_SPR0);
    CLR_BIT(SPCR,SPCR_SPR1);
    CLR_BIT(SPSR,SPSR_SPI2X);

    /*SPI Enable*/
    SET_BIT(SPCR,SPCR_SPE);
}
```

### `void SPI_voidInitSlave(void)`
Initializes the SPI module in Slave mode.

```c
void SPI_voidInitSlave(void)
{
    /*Slave Initialization*/
    CLR_BIT(SPCR,SPCR_MSTR);

    /*SPI Enable*/
    SET_BIT(SPCR,SPCR_SPE);
}
```

### `u8 SPI_u8Transceive(u8 Copy_u8Data)`
Transmits and receives a byte of data over SPI.

```c
u8 SPI_u8Transceive(u8 Copy_u8Data)
{
    /*Send the data*/
    SPDR = Copy_u8Data;

    /*Busy Waiting until Transfer Complete*/
    while (GET_BIT(SPSR,SPSR_SPIF) == 0);

    /*Get the exchanged data*/
    return SPDR;
}
```

## Usage
1. Call `SPI_voidInitMaster()` to initialize the SPI in Master mode.
2. Call `SPI_voidInitSlave()` to initialize the SPI in Slave mode.
3. Use `SPI_u8Transceive(data)` to send and receive data over SPI.

## License
This project is licensed under the MIT License.

