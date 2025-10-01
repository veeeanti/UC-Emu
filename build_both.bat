@echo off
echo Building Steam API Emulator for both x86 and x64 architectures...

REM Clean existing build directories
echo Cleaning existing build directories...
if exist build-x86 rmdir /s /q build-x86
if exist build-x64 rmdir /s /q build-x64

REM Create build directories
echo Creating build directories...
mkdir build-x86
mkdir build-x64

REM Build x86 version
echo Building x86 version...
cd build-x86
cmake .. -A Win32
if errorlevel 1 (
    echo Error generating x86 build files
    cd ..
    exit /b 1
)
cmake --build . --config Debug
if errorlevel 1 (
    echo Error building x86 version
    cd ..
    exit /b 1
)
cd ..

REM Build x64 version
echo Building x64 version...
cd build-x64
cmake .. -A x64
if errorlevel 1 (
    echo Error generating x64 build files
    cd ..
    exit /b 1
)
cmake --build . --config Debug
if errorlevel 1 (
    echo Error building x64 version
    cd ..
    exit /b 1
)
cd ..

REM Test both versions
echo Testing x86 version...
build-x86\Debug\test_steam.exe
if errorlevel 1 (
    echo Error testing x86 version
    exit /b 1
)

echo Testing x64 version...
build-x64\Debug\test_steam.exe
if errorlevel 1 (
    echo Error testing x64 version
    exit /b 1
)

echo.
echo Build and testing completed successfully!
echo.
echo Output files:
echo   x86 DLL: build-x86\Debug\steam_api.dll
echo   x64 DLL: build-x64\Debug\steam_api.dll
echo   x86 Test: build-x86\Debug\test_steam.exe
echo   x64 Test: build-x64\Debug\test_steam.exe

xcopy /Y ".\build-x86\Debug\steam_api.dll" ".\dlls"
xcopy /Y ".\build-x64\Debug\steam_api.dll" ".\dlls\steam_api64.dll"

exit /b 0