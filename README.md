
# TrainingMachine

TrainingMachine is an educational software designed to simulate the operation of the Учебная Машина 3 (УМ-3), a computer system used for teaching the fundamental principles of computer science, programming, and computational theory. This project implements an interpreter for УМ-3, providing an interactive and visual way for students to learn about the basic operations of a computer.

## Features

- **Instruction Set**: A predefined set of instructions that can be executed within the environment.
- **Data Handling**: Managing and manipulating values in a structured table, simulating the handling of memory in the computational environment.
- **Stream Interpretation**: Interpretation of input and output streams during the execution process.
- **User Interface**: A graphical interface for users to input instructions, control memory, and observe the execution of the program.

## Key Components

- **Instruction Handling**: Classes and methods to define and process instructions.
- **Execution Context**: Management of the state and context of the execution process.
- **Stream Processing**: Handling of input and output streams during the execution of instructions.
- **Utilities**: Helper functions and utilities for various tasks within the program.

## Project Structure

The TrainingMachine project follows a modular architecture, consisting of several key components:

```
TrainingMachine/
├── CMakeLists.txt               # CMake build configuration
├── ExecutionContext.h           # Context management for execution (I/O implementation)
├── IStreamInterpreter.h         # Interface for stream interpreters (I/O implementation)
├── Instruction.cpp              # Instructions implementation and refactoring
├── Instruction.h                # Header for instructions
├── InstructionCellHandler.cpp   # Handles instruction cell logic (memory safety)
├── InstructionCellHandler.h     # Header for instruction cell logic (memory safety)
├── InstructionCompleter.cpp     # Instruction table refactor
├── InstructionCompleter.h       # Header for instruction table refactor
├── InstructionInterpreter.cpp   # Handles instruction interpretation (I/O implementation)
├── InstructionInterpreter.h     # Header for instruction interpreter (I/O implementation)
├── InstructionTable.cpp         # Add instruction implementation
├── InstructionTable.h           # Header for instruction table implementation
├── InstructionTableView.cpp     # Handles instruction table view (I/O implementation)
├── InstructionTableView.h       # Header for instruction table view (I/O implementation)
├── LICENSE.txt                  # License added
├── MainWindow.cpp               # Main window logic (UI, I/O implementation)
├── MainWindow.h                 # Header for main window (UI)
├── MainWindow.ui                # Initial UI design (Qt)
├── Memory.cpp                   # Instructions implementation and refactoring
├── Memory.h                     # Header for memory-related operations (I/O implementation)
├── README.md                    # Project documentation and setup instructions
├── StreamInterpreter.cpp        # Stream interpreter implementation (I/O implementation)
├── StreamInterpreter.h          # Header for stream interpreter (I/O implementation)
├── Utils.cpp                    # Utility functions (instruction table refactor)
├── Utils.h                      # Header for utility functions (instruction table refactor)
├── main.cpp                     # Main application entry
├── resources.qrc                # Resource file for icons and other assets
├── Instructions/                # Directory for specific instruction implementations
└── icons/                       # Icons for resources
```

## Algorithms and Methods

TrainingMachine implements the following key algorithms and methods:

- **Syntax Parsing**: Parsing and validating user-provided instructions (via `InstructionCellHandler.cpp`).
- **Data Handling**: Managing and manipulating values in the instruction table (simulating memory access) during instruction execution (via `Memory.h`, `Memory.cpp`).
- **Stream Processing**: Managing input and output streams during instruction execution (via `IStreamInterpreter.h`, `StreamInterpreter.cpp`).
- **Execution Context**: Maintaining the state and context of the execution process (via `ExecutionContext.h`).

## Requirements

- C++11 or higher
- Qt 5 or 6 for the graphical interface
- CMake for building the project

## Installation

To build and run the project, follow these steps:

1. Clone the repository:
   ```bash
   git clone https://github.com/VitalikObject/TrainingMachine.git
   cd TrainingMachine
   ```

2. Create a build directory and configure the project using CMake:
   ```bash
   mkdir build
   cd build
   cmake ..
   ```

3. Build the project:
   ```bash
   cmake --build .
   ```

4. Run the application:
   ```bash
   ./TrainingMachine
   ```

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE.txt) file for details.

## Acknowledgements

- **Qt**: For providing a powerful framework for the graphical interface.
- **C++**: For being the core language of this project.

## Contributing

Feel free to fork this project, open issues, and submit pull requests. Contributions are welcome!

## Contact

For any questions or suggestions, please contact Vitalii Strashnov via [GitHub Issues](https://github.com/VitalikObject/TrainingMachine/issues).
