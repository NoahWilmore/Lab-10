@echo off

cls

set DRIVE_LETTER=%1:
set PATH=%DRIVE_LETTER%\MinGW\bin;%DRIVE_LETTER%\MinGW\msys\1.0\bin;c:\Windows;c:\Windows\system32

g++ -I.\CSC2110 -c HybridDriver.cpp
g++ -L.\CSC2110 -o lab10.exe HybridDriver.o -lCSC2110
lab10.exe







