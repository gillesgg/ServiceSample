# ServiceSample
ATL Server / Client Sample
How to Build
md vcpkg
git clone https://github.com/microsoft/vcpkg
.\vcpkg\bootstrap-vcpkg.bat
.\vcpkg\vcpkg install boost:x64-windows
.\vcpkg.exe export boost:x64-windows  --nuget --nuget-id=boost_x64_1_75 --nuget-version=1.75.0
Install-Package boost_x64_1_75 -Source "VCPKG folder"
