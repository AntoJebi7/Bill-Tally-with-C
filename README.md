# Billing System

## Overview

The **Billing System** is a comprehensive solution developed in C for managing transactions and generating invoices. This system allows users to efficiently create, store, and retrieve invoices, handle various billing calculations, and track transactions. It offers a clear and professional way to manage billing with an emphasis on accuracy and user-friendly functionality.

## Status

**Under Development:** This project is currently under development. As a result, some features may be limited, and the system may undergo significant changes. Contributions and feedback are welcome to help improve and expand the functionality of the project.

## Features

- **Generate Invoices:** Create detailed invoices for transactions, including itemized lists, quantities, and prices.
- **Discount and Tax Calculations:** Automatically apply discounts and calculate GST (CGST and SGST) on the total amount.
- **Invoice Storage:** Save and retrieve billing history from a file system, allowing for future reference and record-keeping.
- **Search and Retrieve Invoices:** Search for and display invoices based on customer name.
- **User Interface:** Simple text-based interface for easy interaction and data entry.

## Technologies Used

- **Programming Language:** C
- **File Handling:** Used for storing and retrieving invoice data
- **Standard Libraries:** `stdio.h`, `stdlib.h`, `string.h`, `time.h`

## Project Structure

- **`billing_system.h`**: Header file containing structure definitions and function declarations.
- **`billing_system.c`**: Source file with implementations of billing-related functions.
- **`main.c`**: Main source file that drives the application and handles user interactions.

## Getting Started

### Prerequisites

- A C compiler (e.g., GCC)

### Compilation

To compile the project, use the following command:

```bash

gcc tally_manager.c -o tally_manager
