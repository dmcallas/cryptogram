Cryptogram
==========

This is a small program to help you solve cryptograms.

_Disclaimer: I wrote this several years ago. The only updates I have
made in the past few years have been to make it build. Do not expect
good code. Some of the advanced features may not work either
(Vigenere, for example)._

## Compiling

To compile the program, you will need to have the Qt development
libraries installed.

### Compiling For Linux

To compile on Linux, run `qmake-qt5` followed by `make`.

### Compiling For Windows

From a Linux system, you can use Mingw32 to cross-compile. I have done
this succesfully on Fedora 14. Your mileage may vary.

I have not compiled on Windows itself. If you are on a Windows system,
you should look at the Qt documentation for Windows compilation. You
will need to run `qmake`, followed by your system's equivalent of
`make`, which may be either `make` or `nmake`. You should be able to
use Mingw32 or VC++ to compile.

Note that regardless of the compilation method, you will need to have
Qt libraries installed on the Windows system the program is run on.

## Comiling For Mac

I have no experience with Apple products, but if you try compiling for
Mac and get any errors, send me the error log and I will try to
correct them. The process should be similar to the other versions. You
should be able to run `qmake` and your system's version of `make` and
get an executable.

## License
This program is licensed under the terms of the GNU General Public License, Version 3. See the [LICENSE](LICENSE) file for more details.