# MySecurity v2
MySecurity is a simple program that allows you to access your computer from another device. It uses Socket to connect you with your computer, which were separated into client and server.<br>
There was an old version of MySecurity, which you can [check here](https://github.com/FelipeFTN/MySecurity/tree/v1), but it was discontinued due to hard complexity and maintenance of the code.<br>
We're working on MySecurity v2, which is a lighter version, easy to run, faster and compiled.<br>
MySecurity v2 is cross-platform, so you can run it from any operational system.

## How it works?
All the magic is handled by simple TCP connections between two applications(client & server).<br>
We are going to add new authentication features and security logics very soon, and a possibility to control multiple machines throught MySecurity.

## Compiling
You can compile your mySecurity source code using **make**. MySecurity compiling settings is all set up into _Makefile_, which is responsible by checking any change in source files and compiling it into a executable file that will be saved in */bin*.<br>
If you want to build your MySecurity source code, just run: ```make``` into your terminal at MySecurity's root folder and the magic will be done.
