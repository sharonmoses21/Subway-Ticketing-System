# Subway Ticketing System

## Overview

The Subway Ticketing System is a C++ program that simulates a ticketing system for a subway network. It allows users to manage subway stations, track transactions, and generate tickets. The program is designed with classes for subway stations, date, time, nodes, and transactions.

## Features

- **Subway Class:** Represents details of each subway station, including station ID, names, travel distances, fares, and times.

- **Date and Time Classes:** Represent date and time information used in transactions.

- **Node Class:** Represents a node in a doubly linked list, holding a subway station.

- **TransactionNode Class:** Represents a node in a transaction list, storing information about ticket transactions.

- **List Class:** Implements a doubly linked list to manage subway stations.

## Usage

1. Compile the C++ program using a C++ compiler.
2. Run the executable to start the Subway Ticketing System.
3. Use the provided menu to navigate through different features.
4. Manage subway stations, view transactions, and generate tickets.

## Classes

### `subway` Class

- Represents subway station details.
- Stores information about the current, previous, and next stations.
- Provides methods to set and get station information.

### `Date` Class

- Represents date information for transactions.
- Allows printing the date.

### `Time` Class

- Represents time information for transactions.
- Allows printing the time.

### `Node` Class

- Represents a node in a doubly linked list.
- Holds a pointer to a subway station.

### `TransactionNode` Class

- Represents a node in a transaction list.
- Stores information about ticket transactions.
- Provides methods to set and get transaction details.

### `List` Class

- Implements a doubly linked list to manage subway stations.
- Allows inserting subway stations.
- Provides methods to traverse the list.

## System Usage

1. **Insert Subway Station:** Insert new subway stations with relevant details.

2. **View Subway Stations:** View details of all subway stations.

3. **View Transactions:** View details of all ticket transactions.

4. **Generate Ticket:** Generate a new ticket transaction.

5. **Exit:** Exit the program.

## Contributions

Contributions are welcome! If you wish to contribute, please follow the guidelines in the [CONTRIBUTING.md](CONTRIBUTING.md) file.

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details.
