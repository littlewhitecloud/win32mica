echo off
cls
echo build.bat - Build the dll file
cd win32mica

echo Use Visual Studio 2022 Developer Powershell to execute this file
cl /Ox /Ot /favor:blend /EHsc /GA /nologo /LD /DEF: win32mica.def win32mica.cpp /w /errorReport:none /std:c++17 /D "_WINDOWS"
pause
