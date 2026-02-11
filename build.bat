@echo off
set PIO_EXE=%USERPROFILE%\.platformio\penv\Scripts\platformio.exe
set ENV_NAME=unknown

IF /I "%1"=="ESP32" set ENV_NAME=ESP32
IF /I "%1"=="mega" set ENV_NAME=mega2560
IF /I "%1"=="PRIVATE" set ENV_NAME=Nucleo-F446ZE

IF "%ENV_NAME%"=="unknown" (
    echo ==========================================
    echo ERROR: ENV nicht gefunden
    echo ==========================================
    echo ESP32   ESP32
    echo MEGA    mega2560
    echo NULEO   Nucleo-F446ZE
    echo ==========================================
    exit /b 1
)

echo ==========================================
echo STARTE BUILD PROZESS FUER: %ENV_NAME%
echo ==========================================

:: 1. CLEAN
echo [1/3] Bereinige Build-Ordner (Clean)...
"%PIO_EXE%" run -e %ENV_NAME% --target clean
if %errorlevel% neq 0 goto error

:: 2. BUILD FILESYSTEM (SPIFFS/LittleFS)
::echo [2/3] Baue Dateisystem (BuildFS)...
::"%PIO_EXE%" run -e %ENV_NAME% --target buildfs
::if %errorlevel% neq 0 goto error

:: 3. BUILD FIRMWARE
echo [3/3] Kompiliere Firmware (Build)...
"%PIO_EXE%" run -e %ENV_NAME%
if %errorlevel% neq 0 goto error

echo ==========================================
echo BUILD ERFOLGREICH ABGESCHLOSSEN!
echo ==========================================
:: pause
exit /b 0

:error
echo.
echo !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
echo FEHLER BEIM BUILD PROZESS!
echo !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
:: pause
exit /b 1