
# trans.c

trans is a basic program written in C that utilizes pipes, shared memory, and forked processes to efficiently transmit data between source and destination files in a synchronized manner.
## Installation

Clone this repository and make the executable:

```bash
git clone https://github.com/jacksonmcafee/file-transmission.git
make
```

Run `trans` or run a comparison against `cp`!

`./trans example_files/mobydick.txt myfile.txt`

`./command_comparison example_files/mobydick.txt myfile.txt` 
## Documentation

This program implements an efficient method of data transmission between source and destination files using pipes and shared memory. The program's main functionality and structure are as follows:

- **Process Creation:** The program begins by opening the source file and checking for its existence, while also handling the case of an existing destination file.

- **Pipe Establishment:** The `parent_to_child` and `child_to_parent` pipes are created using the `pipe` system call, setting up channels for communication between parent and child processes.

- **Forking:** The `fork` system call is used to create a child process. The parent process (referred to as the `parent` process) is responsible for transmitting data to the child process.

- **Parent Process (Transmitter):** In the parent process, data is read from the source file in fixed-size blocks. These blocks are then transmitted to the child process via pipes and shared memory. Block numbers and lengths are communicated to ensure synchronization.

- **Child Process (Receiver):** The child process receives data from the parent process and writes it to a destination file. It sends acknowledgments to confirm receipt and synchronization. Once transmission is complete, the child process properly releases allocated resources.

- **Shared Memory Usage:** Shared memory is used as a buffer to temporarily store data during transmission between the parent and child processes. This shared memory region is mapped using the `mmap` system call and is managed to prevent memory leaks.

- **Synchronization and Acknowledgment:** The program maintains synchronization through the exchange of block numbers and lengths between parent and child processes. Acknowledgments are utilized to confirm successful data transmission.

### Main Function

- **Argument Validation:** Validates the correct number of command-line arguments.
- **Source File Handling:** Opens the source file and manages the presence of the destination file.
- **Parent Process Execution:**
   a. Reads data from the source file and transmits it to the child.
   b. Manages block numbers and lengths for synchronization.
- **Child Process Execution:**
   a. Receives data from the parent and writes it to the destination file.
   b. Sends acknowledgments and ensures synchronization.
   c. Cleans up shared memory and resources.

By employing parallel processing, synchronization mechanisms, and efficient shared memory management, the "trans" program provides a potentially optimized method of transmitting data between source and destination files. It is a simple alternative implementation to conventional file copying methods.
## Authors

- [@jacksonmcafee](https://www.github.com/jacksonmcafee)

