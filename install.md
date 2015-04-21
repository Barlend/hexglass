

# Install binaries #

## MS Windows ##

You can get ready-to-run binary for MS Windows on
[download page](http://code.google.com/p/hexglass/downloads/list).

## Ubuntu Linux ##

You can install hexglass from `ppa:mezomish/qtapps`:

```
$ sudo add-apt-repository ppa:mezomish/qtapps
$ sudo apt-get update
$ sudo apt-get install hexglass
```

Thanks to **[Mikhail Murzin <mezomish@gmail.com>](http://murzin.ca/)**

## SuSE Linux ##

You can search hexglass at [openSUSE Build Service search engine](http://software.opensuse.org/search?q=hexglass) for one-click-install. Thanks to **Lazy\_Kent**.

## Arch Linux ##

You can install hexglass fom AUR:

```
$ yaourt hexglass
```

(You need to
[install yaourt](https://wiki.archlinux.org/index.php/Yaourt)
if you do not have it yet.)

# Build from sources #

## Quick guide ##

Before building, you will need to have the Qt4 library and developers
tools installed on your system.

Get source codes from
[download page](http://code.google.com/p/hexglass/downloads/list).
Unpack them, and enter to directory with sources.

Build:

```
$ qmake # or qmake-qt4
$ make  # or mingw32-make or nmake or other
```

Test it:

```
$ ./hexglass # or hexglass.exe ,-)
```

Install:

```
$ sudo make install
```

Uninstall:

```
$ sudo make uninstall
```

# Build-time settings #

If you prepare the binary for wide distribution,
or just want to customise binary for yourself,
you can do it at build-time.

## Installation path ##

You can specify alternative installation root
(usefull to prepare packages):

```
$ make INSTALL_ROOT=/tmp/pkg_root
```

## Default settings ##

You can specify default size and skin:

```
$ qmake 'DEFINES += DEFAULT_SIZE=0 DEFAULT_SKIN=0'
```

Valid values are 0, 1, 2, 3, 4.

# Build static binary for MS Windows using MinGW #

## Build Qt library ##

First, [get and install MinGW](http://www.mingw.org/wiki/InstallationHOWTOforMinGW).

Get sources of Qt library
(download
[ftp://ftp.trolltech.com/qt/source/qt-everywhere-opensource-src-4.7.1.tar.gz](ftp://ftp.trolltech.com/qt/source/qt-everywhere-opensource-src-4.7.1.tar.gz)
or samthing like).

Unpack, say, into `C:\qt\qt-everywhere-opensource-src-4.7.1` and
goto this directory.

Edit the file `mkspecs/win32-g++/qmake.conf`. Add flag
`QMAKE_LFLAGS += -static`

Now, create and execute .bat-file:

```
SET QTDIR=c:\qt\qt-everywhere-opensource-src-4.7.1
SET PATH=c:\mingw\bin;%QTDIR%\bin;%PATH%

configure -opensource -release ^
 -nomake examples -nomake demos -nomake tools ^
 -nomake translations -nomake docs ^
 -no-exceptions -no-stl -no-rtti ^
 -no-qt3support -no-scripttools -no-openssl -no-opengl ^
 -no-dsp -no-webkit -no-phonon ^
 -no-style-motif -no-style-cde -no-style-cleanlooks ^
 -no-style-plastique ^
 -no-sql-sqlite -no-script -no-scripttools -no-declarative ^
 -static -platform win32-g++

mingw32-make
```

Wait for complete build process, and now you have Qt library.

## Build HexGlass ##

Get source codes from
[download page](http://code.google.com/p/hexglass/downloads/list),
unpack them, enter to directory with sources and execute .bat-file:

```
SET QTDIR=c:\qt\qt-everywhere-opensource-src-4.7.1
SET PATH=c:\mingw\bin;%QTDIR%\bin;%PATH%

qmake
mingw32-make
```

Look into `release` directory; `hexglass.exe` here.