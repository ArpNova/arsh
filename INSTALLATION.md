# Installation Instructions

`arsh` is designed for Unix-like environments. While it natively runs on Linux and macOS, Windows users can use the Windows Subsystem for Linux (WSL) to run the shell.

## Prerequisites

To build `arsh`, you need the following installed on your system:

-   **GCC** (GNU Compiler Collection) or Clang
-   **Make**

## Platform-Specific Installation

### Linux

Most Linux distributions can install the necessary build tools via their package manager.

#### Debian / Ubuntu / Linux Mint

```bash
sudo apt update
sudo apt install build-essential
```

#### Fedora / RHEL / CentOS

```bash
sudo dnf groupinstall "Development Tools"
```

#### Arch Linux

```bash
sudo pacman -S base-devel
```

### macOS

On macOS, you need to install the Xcode Command Line Tools, which include `clang` and `make`.

1.  Open Terminal.
2.  Run the following command:

    ```bash
    xcode-select --install
    ```

3.  Follow the on-screen prompts to complete the installation.

### Windows

Since `arsh` relies on POSIX system calls (like `fork`, `exec`, `pipe`), it does **not** run natively on Windows. However, you can run it seamlessly using the Windows Subsystem for Linux (WSL).

#### 1. Install WSL

Open PowerShell as Administrator and run:

```powershell
wsl --install
```

This will install WSL and Ubuntu by default. You will need to restart your computer.

#### 2. Set Up Environment

After restarting, open the "Ubuntu" application from your Start menu. Follow the on-screen instructions to create a user account.

Once your terminal is ready, install the build tools (same as Ubuntu instructions above):

```bash
sudo apt update
sudo apt install build-essential
```

You can now clone the repository and build the project inside your WSL terminal.

## Building the Shell

1.  Clone the repository (if you haven't already):
    ```bash
    git clone https://github.com/ArpNova/arsh.git
    cd arsh
    ```

2.  Run `make` to compile:
    ```bash
    make
    ```

    This will generate an executable named `arsh` in the current directory.

3.  (Optional) Clean up build artifacts:
    ```bash
    make clean
    ```

## Running the Shell

Start the shell by running:

```bash
./arsh
```
