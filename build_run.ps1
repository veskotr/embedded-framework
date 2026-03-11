# build_run.ps1
# Auto configure, build, and run the framework

param(
    [string]$BuildDir = "build_debug",
    [string]$Config = "Debug"
)

# Exit on errors
$ErrorActionPreference = "Stop"

Write-Host "==== Building EmbeddedFramework ===="

# Step 1: Configure CMake (no need to specify CMAKE_BUILD_TYPE for Visual Studio)
Write-Host "Configuring project..."
cmake -S . -B $BuildDir

# Step 2: Build the project
Write-Host "Building project..."
cmake --build $BuildDir --config $Config

Write-Output $BuildDir

# Step 3: Determine executable path
$ExePath = Join-Path $BuildDir "/app/Debug/app.exe"
if (-Not (Test-Path $ExePath)) {
    # Some setups place it in Debug folder for MSVC
    $ExePath = Join-Path $BuildDir $Config "app.exe"
}

if (-Not (Test-Path $ExePath)) {
    Write-Error "Executable not found. Check your targets and CMakeLists.txt"
    exit 1
}

# Step 4: Run the executable
Write-Host "Running $ExePath ..."
& $ExePath

Write-Host "==== Done ===="