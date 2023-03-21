#!/bin/bash

if command -v cmake > /dev/null 2>&1; then
  echo "-- Initiating MySecurity build"
else
  echo "error: cmake is not installed!"
  echo "please install cmake on your machine or try installing with Makefile."
  exit 127
fi

create_desktop_app() {
  echo "[+] Creating MySecurity executable"
  echo "[Desktop Entry]" > MySecurity.desktop
  echo "Name=MySecurity" >> MySecurity.desktop
  echo "GenericName=Computer controller" >> MySecurity.desktop
  echo "Comment=Control your computer remotelly" >> MySecurity.desktop
  echo "Exec=sudo ~/.local/bin/MySecurity" >> MySecurity.desktop
  echo "Terminal=false" >> MySecurity.desktop
  echo "Type=Application" >> MySecurity.desktop
  echo "X-GNOME-Autostart-enabled=true" >> MySecurity.desktop
  chmod 755 MySecurity.desktop
}

build() {
  echo "[+] Building MySecurity"
  cmake -B cmake/
  cd cmake/
  make
}

install() {
  cp ./MySecurity ~/.local/bin
  mkdir -p ~/.config/autostart
  cp ./MySecurity.desktop ~/.config/autostart
  echo "[+] MySecurity installed successfully!"
}

build
create_desktop_app
install
