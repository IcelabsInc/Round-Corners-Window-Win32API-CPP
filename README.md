# 🪟 Round Corner Window Application

This is a simple Windows desktop application developed by **Icelabs Inc.** that creates a window with rounded corners. The window's background is black, and it has a white, rounded rectangle filling the content area. The window uses the Windows API to handle its graphical user interface and is designed with GDI (Graphics Device Interface) functions.

## ✨ Features

- 🟦 **Round-Corner Window:** The main feature is the round-cornered window created using `CreateRoundRectRgn` and `SetWindowRgn`.
- 🎨 **Custom Background:** The window has a solid black background with a white fill for the content area.
- 🖥️ **No Title Bar or Borders:** The window is displayed without the standard title bar or borders, giving it a clean, custom appearance.

## 🛠️ Prerequisites

- 💻 **Windows**: This application is designed to run on Windows operating systems.
- 🛠️ **Visual Studio**: To compile and run the program, you will need a development environment like Visual Studio.
- 📚 **gdi32.lib and user32.lib**: Make sure the GDI and User libraries are linked.

## 🚀 Build Instructions

### Using **g++**

To compile this application using **g++**:

1. Make sure you have **MinGW** installed with the **g++** compiler and proper linking to Windows libraries.
2. Use the following command to compile the program:

   ```bash
   g++ -o round_corner_window round_corner_window.cpp -lgdi32 -luser32
   ```
    This command links the required gdi32 and user32 libraries needed for the application.
3. Run the compiled program:

    ```
    ./round_corner_window
    ```

### Using Visual Studio C++ Compiler

To compile this application using the **Visual Studio C++ compiler**:

1. Open the **Developer Command Prompt for Visual Studio**.
2. Use the following command to compile the program:
    ```
    cl /Fe:round_corner_window.exe round_corner_window.cpp gdi32.lib user32.lib
    ```
    This command compiles the C++ file and links the necessary libraries (**gdi32.lib** and **user32.lib**).
3. Run the compiled program by executing `round_corner_window.exe`.

## 🖱️ Usage

Once compiled, running the application will open a 500x500 window with rounded corners and a black background.

## 📄 License

This project is licensed under the MIT License. See the [LICENSE](./LICENSE) file for details.

---

Developed by **Icelabs Inc.**
