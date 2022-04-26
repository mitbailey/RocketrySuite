# RocketrySuite
## Description
Program to calculate the trajectory of a model rocket. 

## Prerequisites
__For Windows, Mingw-w64 is required to compile and / or run the program.__

To install Mingw-w64, follow steps 3 and 4 under the 'Prerequisites' section of the following document, which are also listed below:  
https://code.visualstudio.com/docs/cpp/config-mingw  

1. Proceed to https://www.msys2.org/.
2. Follow the instructions under the red "Installation" header beginning with downloading the MSYS2 installer. For clarity, some of those instructions have been mirrored below.
3. Once the MSYS2 terminal has opened automatically, run the following command:  
   `pacman -Syu`  
   _Note that this may take a minute..._

4. Once the MSYS2 terminal closes, use the Windows Start menu to search for and open "MSYS2 MSYS".
5. Once the MSYS2 terminal has opened, run the following command:  
   `pacman -Su`  
    _Note that this may take a minute..._   
6. To install mingw-w64, run the following command:  
   `pacman -S --needed base-devel mingw-w64-x86_64-toolchain`  
   _Note that this may take a minute..._   
7. Now that Mingw-w64 is installed, it must be added to the windows `PATH` environment variable. To do so, begin by making note of the path to Mingw-w64's `bin` folder. By default it is `C:\msys64\mingw64\bin`.
8. Search "Edit the system environment variables" in the Windows Start menu and select the entry of the same name.
9. Click the "Environment Variables..." option.
10. Find the variable labeled "Path", click the entry, and then click the "Edit..." button.
11. Click the "New" button and paste in the Mingw-w64 path found in step 7.
12. Select OK to confirm. Close and reopen any active console windows.

## Compilation
### Windows
Double-click on `make.bat`  
or open Command Prompt in the RocketrySuite/ directory and execute  
`make.bat`  
(`./make.bat` for PowerShell)  

### Linux
Open Terminal in the RocketrySuite/ directory and execute  
`make`  

## Use Instructions
### Windows
After compilation, either double-click `RocketrySuite.exe` or run `RocketrySuite.exe` in a CMD window opened within the repository directory. Then, follow the on-screen prompts.  

### Linux
After compilation, run `./sim.out` in a Terminal from within the repository directory. Then, follow the on-screen prompts.