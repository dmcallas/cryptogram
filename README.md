To compile the program, you will need to have the Qt development
libraries installed.


COMPILING FOR LINUX
==================================================
To compile on Linux, run qmake-qt5 followed by make.

COMPILING FOR WINDOWS
==================================================
From a Linux system, you can use Mingw32 to cross-compile. I have done
this succesfully on Fedora 14. Your mileage may vary.

If you are on a Windows system, you should look at the Qt
documentation for Windows compilation. You will need to run qmake,
followed by your system's equivalent of make, which may be either make
or nmake. You should be able to use Mingw32 or VC++ to compile.

Note that you will need to have Qt libraries installed on the Windows
system.

COMILING FOR MAC
==================================================
I have no experience with Apple products, but if you try compiling for
Mac and get any errors, send me the error log and I will try to
correct them. The process should be similar to the other versions. You
should be able to run qmake and your system's version of make and get
an executable.