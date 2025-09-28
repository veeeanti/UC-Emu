#!/bin/bash

echo "Building Steam API Emulator for both x86 and x64 architectures..."

# Clean existing build directories
echo "Cleaning existing build directories..."
if [ -d "build-x86" ]; then
    rm -rf build-x86
fi

if [ -d "build-x64" ]; then
    rm -rf build-x64
fi

# Create build directories
echo "Creating build directories..."
mkdir -p build-x86
mkdir -p build-x64

# Build x86 version
echo "Building x86 version..."
cd build-x86
cmake .. -A Win32
if [ $? -ne 0 ]; then
    echo "Error generating x86 build files"
    cd ..
    exit 1
fi

cmake --build . --config Debug
if [ $? -ne 0 ]; then
    echo "Error building x86 version"
    cd ..
    exit 1
fi
cd ..

# Build x64 version
echo "Building x64 version..."
cd build-x64
cmake .. -A x64
if [ $? -ne 0 ]; then
    echo "Error generating x64 build files"
    cd ..
    exit 1
fi

cmake --build . --config Debug
if [ $? -ne 0 ]; then
    echo "Error building x64 version"
    cd ..
    exit 1
fi
cd ..

# Test both versions
echo "Testing x86 version..."
build-x86/Debug/test_steam.exe
if [ $? -ne 0 ]; then
    echo "Error testing x86 version"
    exit 1
fi

echo "Testing x64 version..."
build-x64/Debug/test_steam.exe
if [ $? -ne 0 ]; then
    echo "Error testing x64 version"
    exit 1
fi

echo ""
echo "Build and testing completed successfully!"
echo ""
echo "Output files:"
echo "  x86 DLL: build-x86/Debug/steam_api.dll"
echo "  x64 DLL: build-x64/Debug/steam_api.dll"
echo "  x86 Test: build-x86/Debug/test_steam.exe"
echo "  x64 Test: build-x64/Debug/test_steam.exe"

exit 0