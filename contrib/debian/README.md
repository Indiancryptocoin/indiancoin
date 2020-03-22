
Debian
====================
This directory contains files used to package indiancoind/indiancoin-qt
for Debian-based Linux systems. If you compile indiancoind/indiancoin-qt yourself, there are some useful files here.

## indiancoin: URI support ##


indiancoin-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install indiancoin-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your indiancoin-qt binary to `/usr/bin`
and the `../../share/pixmaps/indiancoin128.png` to `/usr/share/pixmaps`

indiancoin-qt.protocol (KDE)

