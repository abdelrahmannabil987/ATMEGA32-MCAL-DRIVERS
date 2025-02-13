# TWI (I2C) Driver for ATMEGA32

## Overview
This repository contains a Two-Wire Interface (TWI/I2C) driver for the ATMEGA32 microcontroller. The driver supports Master and Slave operations and includes functions for data transmission and reception.

## Features
- Supports Master and Slave initialization.
- Implements start, repeated start, stop conditions.
- Handles sending and receiving data over I2C.
- Uses polling mechanism for data transmission.

## Files
- `TWI_config.h`: Configuration file for TWI settings.
- `TWI_interface.h`: Interface file containing function prototypes.
- `TWI_private.h`: Private file for internal macros and definitions.
- `TWI_register.h`: Register definitions for TWI.
- `TWI_program.c`: Implementation of TWI functions.

## Functions

### `void TWI_voidMasterINIT(u8 Copy_u8SlaveAddress)`
Initializes the TWI module in Master mode with a clock frequency of 400 kbps. Pass `0` as `Copy_u8SlaveAddress` if the master will not be addressed.

### `void TWI_voidSlaveINIT(u8 Copy_u8SlaveAddress)`
Initializes the TWI module in Slave mode with a specific address.

### `TWI_ErrorStatus TWI_SendStartCondition(void)`
Sends a start condition on the I2C bus and returns an error status.

### `TWI_ErrorStatus TWI_SendRepeatedStart(void)`
Sends a repeated start condition on the I2C bus and returns an error status.

### `TWI_ErrorStatus TWI_SendSlaveAddressWithWrite(u8 Copt_u8SlaveAddress)`
Sends a slave address with a write request and returns an error status.

### `TWI_ErrorStatus TWI_SendSlaveAddressWithRead(u8 Copt_u8SlaveAddress)`
Sends a slave address with a read request and returns an error status.

### `TWI_ErrorStatus TWI_MasterWriteDataByte(u8 Copy_u8DataByte)`
Writes a data byte to the slave and returns an error status.

### `TWI_ErrorStatus TWI_MasterReadDataByte(u8* Copy_pu8DataByte)`
Reads a data byte from the slave and returns an error status.

### `void TWI_SendStopCondition(void)`
Sends a stop condition on the I2C bus.

## Usage
1. Call `TWI_voidMasterINIT(0)` to initialize the TWI in Master mode.
2. Call `TWI_voidSlaveINIT(slave_address)` to initialize the TWI in Slave mode.
3. Use `TWI_SendStartCondition()` to start communication.
4. Use `TWI_SendSlaveAddressWithWrite()` or `TWI_SendSlaveAddressWithRead()` to address a slave.
5. Use `TWI_MasterWriteDataByte()` to send data or `TWI_MasterReadDataByte()` to receive data.
6. Call `TWI_SendStopCondition()` to end the communication.

## License
This project is licensed under the MIT License.

