:loop
data.py > data.in
py.py < data.in > py.out
g++ Try.cpp -o Try.exe
Try.exe < data.in > cpp.out
fc py.out cpp.out
if errorlevel 1 pause
goto loop