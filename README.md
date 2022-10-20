# MySecurity
_**A Personal Computer Privacy Safer**_

MySecurity uses 3 layers of control to encrypt your computer data and also command your machine remotelly.

Basically it creates a secure API that can be interacted from your phone in order to execute commands on your computer.

## MySecurity v2
We're working on a next version of MySecurity, which will be a lighter version, easy to run, and compiled.

It's currently working perfectly, but still in development.

You can download it and run on your computer by placing the binary file from _/MySecurity/bin_ on your system's startup folder.

Wanna see it? Take a look at [**v2**](https://github.com/FelipeFTN/MySecurity/tree/v2)!

## How it works?
MySecurity mainly exists within 3 layers:
- frontend(React)
- backend(Go)
- application(Python)

You can install it on your Windows Machine by running _./MySecurity/windows-installer.bat_ This file will configure your local variables on the file settings.yaml.

### Python
_/MySecurity/app_

Handles the application on your desktop. Its like the kernel, which interacts with the **Operational System** in order to execute commands.

### React
_/MySecurity/client_

Handles the application on the local internet. It hosts a simple web-server which can be accessed from another machine or phone through your machine's IP.

### Go
_/MySecurity/server_

Its a REST API that handles the connection between Client(React) and App(Python).
