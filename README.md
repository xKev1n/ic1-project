# ICT1 Project - Simple exploitation

## Introduction
This project is an introduction to <b>exploiting and privilege escalation</b>. Our inspiration was Escape Room.

The project in form of interactive game, in which you have to find hidden flags for your system to "survive".

There are several vulnerabilities which you have to exploit to get the necessary flags.

Those vulerabilities are represented by 4 pre-compiled C terminal apps. You can find them on the desktop in directories named "level<1-4>".

To make it easier for everyone, we decided to include hints, that will help you with your task.

:warning: <b> WARNING, USE THIS PROJECT ONLY IN VIRTUALIZED ENVIRONMENT AND ONLY FOR EDUCATIONAL PURPOSES !!!! </b> :warning: </font>

There are hidden "easter eggs" and "secret endings" to add more fun and diversity of possible "escapes".

## Description
Clone this repository via HTTPS or SSH. There will be .ova file containing pre-configured Virtual Machine.
After starting the Virtual Machine, you need to log in by `Player` account.
The credentials are as follows:

<h6>Username: player</h3>
<h6>Password: startgame</h3>

<h3> HTTPS </h3>

```shell
$ git clone https://github.com/xKev1n/ic1-project.git
```

<h3> SSH </h3>

```shell
$ git clone git@github.com:xKev1n/ic1-project.git
```
For the project to work to set up your Virtual Machine and <b>disable Linux protection</b> against buffer overflow. That is done by running shell script `turn_off_sec.sh` with <b>root privileges</b>. That is already done in the included Virtual Machine.

```shell
$ sudo bash turn_off_sec.sh
```

After successfully cloning the repository (and running the mentioned script), the app will start itself automatically after rebooting.

There are 4 hidden flags that you have to obtain in a time interval of 10 minutes for the program to end.

If you don't manage to get all flags, the program will <b>wipe out the boot directory</b>:bangbang:

## Requirements
- Linux virtual machine with x86_64 architecture
- Installed gcc
- Installed python
- Installed gtk

## Optional
- Installed GDB is highly suggested
- Installed John The Ripper and Hashcat

## Project build
The app is precompiled is in binary form, thus you don't need to compile anything.
However the Makefiles should be present in all required directories to recompile it at any time.
If you want to recompile the app you need to `cd` into the directory with cloned repository and type:
```shell
$ make
```

## Run the project
To run the precompiled exploitable apps:
```shell
$ cd ~/Desktop/level<1-4>
$ ./exploitable_level<1-4>
```
<h2>:video_game:So let the games begin! HAVE FUN ESCAPING! :video_game:</h2>
