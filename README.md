# UnityDumper

UnityDumper is a (WIP) tool for analyzing and hacking various Unity games. It works for games built with both Mono & IL2CPP.

# Getting started
UnityDumper works completely out of the box, just download the latest release from the releases page, run the UnityDumper.exe file and follow the instructions.

# Understanding Unity

## Unity Backends
Almost all games built with Unity use one of two backends, Mono and IL2CPP

## Mono
Mono games are the most common and most basic, the game code is compiled into a managed DLL file (usually named "Assembly-CSharp.dll") that is loaded and executed by Mono. Mono is a free and open-source software framework that aims to run software made for the .NET Framework on Linux and other OSes. Essentially, it translates the intermediate representation (IL) of your game code into low level instructions that can be executed by the operating system.

![monobuildsteps](https://github.com/user-attachments/assets/732e0f2f-ad64-43e2-bfa6-2e09fa6a0294)

## IL2CPP
IL2CPP (Intermediate Language To C++) adds an extra step to the compilation process, instead of storing the intermediate representation of your C# code which needs to be translated by Mono, IL2CPP converts the intermediate language directly into C++ (You can think of this as converting C# into C++). Due to C++ being a compiled language, the code is converted directly into machine code, meaning it does not need to be translated at runtime. The result is a (usually) faster program, at the cost of longer build times. This usually also makes it easier to hack, as we do not need to worry about any IL or runtime translation, everything is done ahead of time.

![il2cppbuildsteps](https://github.com/user-attachments/assets/f332c19f-8ce7-4fca-bd35-f48c1daa13da)
