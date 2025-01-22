# ADC Driver for Microcontroller

This repository contains a robust **Analog-to-Digital Converter (ADC)** driver for a microcontroller, supporting synchronous, asynchronous, and chain conversions. The driver is designed to handle real-time data acquisition efficiently with multiple configuration options.

---

## Features

- **Multiple Modes of Operation:**
  - Synchronous (blocking) conversion.
  - Asynchronous (non-blocking) conversion with interrupt handling.
  - Chain conversion for sequentially handling multiple channels.
- **Flexible Configuration:**
  - Adjustable voltage reference (AVCC, external, internal).
  - Configurable data alignment (left or right).
  - Supports auto-triggering and manual single conversions.
- **Error Handling:**
  - Timeouts for synchronous operations.
  - Checks for null pointers and busy states.
- **Interrupt-Driven Design:** Efficient handling of ADC results using callback functions.

---

## Functions Overview

### 1. **Initialization (`ADC_voidInit`)**
Configures the ADC:
- Voltage reference (AVCC, external, internal).
- Data alignment (left or right).
- Prescaler for ADC clock speed.
- Auto-triggering mode (e.g., Free Running).

---

### 2. **Synchronous Conversion (`ADC_u16StartConversionSynch`)**
- Performs a single ADC conversion in a blocking manner.
- Configures the input channel and waits for conversion completion or timeout.
- Returns the result (8-bit or 10-bit) via a user-provided variable.

---

### 3. **Asynchronous Conversion (`ADC_u16StartConversionAsynch`)**
- Starts a non-blocking ADC conversion.
- Configures the input channel, starts the conversion, and enables ADC interrupts.
- A user-defined callback is invoked after the conversion.

---

### 4. **Chain Conversion (`ADC_u8StartChainAsynchronous`)**
- Handles multiple ADC channels sequentially in a non-blocking manner.
- Takes a `Chain_t` structure containing:
  - List of channels.
  - Result array.
  - Callback function invoked after all conversions are complete.
- Operates through interrupt handling for efficiency.

---

### 5. **Interrupt Service Routine (`__vector_16`)**
- Handles ADC conversion completion for:
  - **Single Asynchronous Mode:** Stores the result and invokes the callback.
  - **Chain Asynchronous Mode:** Processes the current channel, continues the chain, or invokes the callback after completion.

---

### 6. **Mapping Function (`Mapping`)**
Maps an input value from one range to another using a linear equation:
```c
s32 Mapping(s32 Input_MIN, s32 Input_MAX, s32 Output_MIN, s32 Output_MAX, s32 Input_Value);
