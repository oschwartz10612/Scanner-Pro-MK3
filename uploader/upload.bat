@echo off

ECHO Scanner Pro MK3 Uploader

set /p port="Enter COM Port: "

CLS
ECHO 1. Distribution
ECHO 2. PXI ID + Barcode (2390D)
ECHO 3. PXI ID + Barcode (2390N) 
ECHO 4. PXI ID + FCPSON
ECHO 5. Rack Scanning Location
ECHO 6. Rack Scanning Location + FCPSON
ECHO 7. Rack Scanning Location + LOANER
ECHO.

CHOICE /C 1234567 /M "Enter your choice: "

IF ERRORLEVEL 7 GOTO distribution
IF ERRORLEVEL 5 GOTO pxiID_2390D
IF ERRORLEVEL 5 GOTO pxiID_2390N
IF ERRORLEVEL 4 GOTO pxiID_FCPSON
IF ERRORLEVEL 3 GOTO rackLocation
IF ERRORLEVEL 2 GOTO racklocationFCPSON
IF ERRORLEVEL 1 GOTO racklocationLOANER

:distribution
ECHO 1. Distribution
START .\avrdude\uploader.exe %port% distribution.exe
GOTO End

:pxiID_2390D
ECHO 2. PXI ID + Barcode (2390D)
START .\avrdude\uploader.exe %port% pxiID_2390D.exe
GOTO End

:pxiID_2390N
ECHO 3. PXI ID + Barcode (2390N)
START .\avrdude\uploader.exe %port% pxiID_2390N.exe
GOTO End

:pxiID_FCPSON
ECHO 4. PXI ID + FCPSON
START .\avrdude\uploader.exe %port% pxiID_FCPSON.exe
GOTO End

:rackLocation
ECHO 5. Rack Scanning Location
START .\avrdude\uploader.exe %port% rackLocation.exe
GOTO End

:racklocationFCPSON
ECHO 6. Rack Scanning Location + FCPSON
START .\avrdude\uploader.exe %port% racklocationFCPSON.exe
GOTO End

:racklocationLOANER
ECHO 7. Rack Scanning Location + LOANER
START .\avrdude\uploader.exe %port% racklocationLOANER.exe
GOTO End

:End