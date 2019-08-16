@echo off
CLS

ECHO Scanner Pro MK3 Uploader
ECHO.

set /p port=Enter COM Port:

ECHO.
ECHO 1. Distribution
ECHO 2. PXI ID + Barcode (2390D)
ECHO 3. PXI ID + Barcode (2390N) 
ECHO 4. PXI ID + FCPSON
ECHO 5. Rack Scanning Location
ECHO 6. Rack Scanning Location + FCPSON
ECHO 7. Rack Scanning Location + LOANER
ECHO.

CHOICE /C 1234567 /M "Enter your choice: "

IF ERRORLEVEL 7 GOTO racklocationLOANER
IF ERRORLEVEL 6 GOTO racklocationFCPSON
IF ERRORLEVEL 5 GOTO rackLocation
IF ERRORLEVEL 4 GOTO pxiID_FCPSON
IF ERRORLEVEL 3 GOTO pxiID_2390N
IF ERRORLEVEL 2 GOTO pxiID_2390D
IF ERRORLEVEL 1 GOTO distribution

:distribution
ECHO.
ECHO 1. Distribution
cd .\avrdude
.\uploader.exe %port% ..\scripts\distribution.hex
GOTO End

:pxiID_2390D
ECHO.
ECHO 2. PXI ID + Barcode (2390D)
cd .\avrdude
.\uploader.exe %port% ..\scripts\pxiID_2390D.hex
GOTO End

:pxiID_2390N
ECHO.
ECHO 3. PXI ID + Barcode (2390N)
cd .\avrdude
.\uploader.exe %port% ..\scripts\pxiID_2390N.hex
GOTO End

:pxiID_FCPSON
ECHO.
ECHO 4. PXI ID + FCPSON
cd .\avrdude
.\uploader.exe %port% ..\scripts\pxi_FCPSON.hex
GOTO End

:rackLocation
ECHO.
ECHO 5. Rack Scanning Location
cd .\avrdude
.\uploader.exe %port% ..\scripts\rackLocation.hex
GOTO End

:racklocationFCPSON
ECHO.
ECHO 6. Rack Scanning Location + FCPSON
cd .\avrdude
.\uploader.exe %port% ..\scripts\racklocationFCPSON.hex
GOTO End

:racklocationLOANER
ECHO.
ECHO 7. Rack Scanning Location + LOANER
cd .\avrdude
.\uploader.exe %port% ..\scripts\racklocationLOANER.hex
GOTO End

:End
pause