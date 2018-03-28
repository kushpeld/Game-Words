cls

@echo off

cl /EHsc /W4 run.cpp
echo.
echo Output of program
echo ******************************************************
echo.
IF %ERRORLEVEL% EQU 0 run.exe
echo.
echo ******************************************************
