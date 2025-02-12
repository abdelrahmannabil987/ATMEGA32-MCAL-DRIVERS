# USART Driver Documentation

## Overview
This is a USART (Universal Synchronous and Asynchronous Receiver-Transmitter) driver for embedded systems, written in C. It provides synchronous and asynchronous communication features for microcontrollers.

## Features
- Supports different character sizes: `5`, `6`, `7`, `8`, and `9` bits.
- Configurable stop bits (`1` or `2`).
- Configurable parity modes (`None`, `Even`, `Odd`).
- Supports **Asynchronous Normal Mode**, **Asynchronous Double Speed Mode**, and **Synchronous Mode**.
- Interrupt-driven communication.
- Synchronous and Asynchronous transmission and reception.

## Files
- **`USART_config.h`** – Configuration settings.
- **`USART_interface.h`** – Function prototypes.
- **`USART_private.h`** – Private definitions.
- **`USART_register.h`** – Register definitions.
- **`USART_program.c`** – Function implementations.

## Functions

### Initialization
```c
void USART_voidInit(void);
```
Initializes the USART module based on the settings in `USART_config.h`.

### Synchronous Transmission
```c
u8 USART_voidSendCharSynch(u8 Copy_u8Data);
```
- Sends a character synchronously.
- Returns an error state if a timeout occurs.

```c
void USART_u8SendStringSynch(char* USART_pcSendString);
```
- Sends a string synchronously, character by character.

### Asynchronous Transmission
```c
u8 USART_u8SendCharAsynch(u8 Copy_u8Data, void(*Copy_pvNotificationFUNC)(void));
```
- Sends a character asynchronously.
- Calls the provided callback function after completion.

```c
u8 USART_u8SendStringAsynch(char* USART_pcSendString, void(*Copy_pvNotificationFUNC)(void));
```
- Sends a string asynchronously.

### Synchronous Reception
```c
u8 USART_voidReceiveCharSynch(u8 * UDR_Value);
```
- Receives a character synchronously.
- Waits until reception is complete before returning the data.

```c
void USART_u8ReceiveBufferSynch(u8* Buffer_Container, u8 Buffer_Size);
```
- Receives a buffer synchronously.

### Asynchronous Reception
```c
u8 USART_u8ReceiveCharAsynch(u8 *Copy_u8Data, void(*Copy_pvNotificationFUNC)(void));
```
- Receives a character asynchronously.
- Calls the provided callback function after completion.

```c
u8 USART_u8ReceiveBufferAsynch(u8* Buffer_Container, u8 Buffer_Size, void(*Copy_pvNotificationFUNC)(void));
```
- Receives a buffer asynchronously.

## Interrupt Service Routines (ISR)

```c
void __vector_13 (void) __attribute__((signal));
```
- Handles reception complete interrupt.

```c
void __vector_14 (void) __attribute__((signal));
```
- Handles data register empty interrupt.

## Usage
1. Configure USART settings in `USART_config.h`.
2. Call `USART_voidInit();` in the main function.
3. Use synchronous or asynchronous functions for communication.

## License
This project is released under the **MIT License**.

