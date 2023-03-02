<div align="center">

![MySecurity](https://user-images.githubusercontent.com/80127749/219816170-f819f35c-6ae2-4592-b51c-1903dd07fc46.png)

</div>

#
**MySecurity is a simple application that allows you to command your computer from another device** It's pretty much like a remote control in which you can infer commands direcly to the machine.<br>
**MySecurity** works throught Socket connections that will allow you access your computer just by connecting at the `port 8080` using a `socket client`.

    
## Usage/Examples
After running MySecurity from the computer you want to control, run the executable _MySecurity_ file. It will automatically open a port on your computer **(port 8080)** that will be allowed to receive socket connections from any device on the same network.
Once the client connects to MySecurity, it will receive a message with all the available options:
```bash
===== MySecurity =====
[1] Shutdown Computer
[2] Reboot Computer
[3] Log out
[0] Exit
> | 1 | 2 | 3 | 0 |
```
When a option is selected and sent, MySecurity will execute the command on the computer.<br>No matter what operating system you are using, the command will be executed with no problems, just make sure your firewall or system defender does not affect MySecurity.

## Installation

### Precompiled (recommended)

You can easily just install and use MySecurity in your computer.<br>Go to [Releases](https://github.com/FelipeFTN/MySecurity/releases) and download one of the binaries available in the _Assets_ section. It is **plug & play**, just make sure your firewall doesn't block the TCP connection at the port 8080. 

<div align="center" style="border: 1px solid white;">

![Screenshot from 2023-02-17 19-58-06](https://user-images.githubusercontent.com/80127749/219817048-036f5e81-00a7-4ec5-b1e8-a2c41ddb1218.png)

</div>

### Build (compiling from source)
Download MySecurity from **master**.

```bash
  # Git clone (master branch)
  $ git clone https://github.com/FelipeFTN/MySecurity.git
  
  # WGet (latest release)
  $ wget https://github.com/FelipeFTN/MySecurity/archive/refs/tags/{tag version}.tar.gz
  
  # Curl (latest release)
  $ curl -L https://github.com/FelipeFTN/MySecurity/archive/refs/tags/{tag version}.tar.gz > MySecurity.tar.gz
```
If you wanna use Curl, or WGet, please substitute the `{tag version}` for the latest version from the releases, or any tag you prefer, e.g.:<br>
```bash
  $ wget https://github.com/FelipeFTN/MySecurity/archive/refs/tags/v0.x.x.tar.gz

  # OR

  $ wget https://github.com/FelipeFTN/MySecurity/archive/refs/tags/v0.x.x.zip
```
Extract the compressed file (_zip_ or _tar.gz_).

In order to build your own application from source, you will need either **CMake** or **Make** to execute the _Makefile_.
You will also need [GCC](https://gcc.gnu.org/) installed in your system (if you are in Microsoft Windows, we recommend using [MingW](https://www.mingw-w64.org/)).

#### CMake:
If you want something easy, execute the file _install.sh_, it should handle everything for you.<br>
Otherwise, if you are a hard user you can compile by running:
```bash
  # Generate the building files
  $ cmake -B cmake/

  # Go to "cmake" directory
  $ cd cmake/

  # Compile MySecurity
  $ make
```
This process will generate a binary _MySecurity_ **or** _MySecurity.exe_ file, now you just need to run it.

#### Make:
If you want something REALLY easy, then just run the **Makefile**:
```bash
  $ make
```
This will compile all the files for you automatically and will generate a binary _MySecurity_ **or** _MySecurity.exe_ file at the _bin_ directory, now you just need to run it.<br>
For this method to work, you will need **make** command installed into your system, if we are using Microsoft Windows, we highly recommend you to install it with [Chocolatey](https://chocolatey.org/install):<br>
```bash
  $ choco install make
```
In case you are may having trouble with make on Windows, take a look at this [article](https://www.technewstoday.com/install-and-use-make-in-windows/).

#### Compiling to Windows from Unix
To compile a `MySecurity.exe` file from Unix based operating systems, like Linux or Mac.<br>
First, you will need to install [mingw-w64](https://www.mingw-w64.org/downloads/):
```bash
  # Arch Linux & Manjaro
  $ sudo pacman -Sy mingw-w64-gcc

  # MacOS
  $ brew install mingw-w64

  # Debian based
  $ sudo apt install mingw-w64

  # Fedora, CentOS & RedHat based
  $ sudo dnf install mingw-w64
```
Now, just uncomment these two lines from `Makefile`:
```bash
  CC=i686-w64-mingw32-gcc
  CFLAGS+= -lws2_32
```
Finally, simply run `make clean && make` to build the source code.


## Contributing

If you want to contribute to improve MySecurity, please read [CONTRIBUTING.md](https://github.com/FelipeFTN/MySecurity/blob/master/CONTRIBUTING.md).

> And if you like the project, but just don't have time to contribute, that's fine. There are other easy ways to support the project and show your appreciation, which we would also be very happy about:
> - Star the project
> - Tweet about it
> - Refer this project in your project's readme
> - Mention the project at local meetups and tell your friends/colleagues
