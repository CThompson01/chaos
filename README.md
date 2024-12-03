# Chaos

## Description

Chaos utilizes Raylib for C. It is my first attempt at creating an in-depth project with it, I am unsure of what will come of it.

## Building

Building is a little different depending on your OS. Find your OS below, and follow the instructions.

### Linux

Currently, automated setup will only work on Ubuntu. 

Open terminal and run the following command.

```
./setup
```

This should automatically install all of the required dependencies.

After the setup is finished running, you should be able to build the project using make. If you've never used make, simply navigate to your terminal and run the following command.

```
make
```

The finished build can be found within the build/ directory. To run the program, you can execute the application from the command line with ./chaos when in the build directory. You may need to mess with permissions in order to allow it to be executed using chmod. The following command should work.

```
chmod +x chaos
```

### Windows

TODO: Add Windows build instructions.

## TODO

- [ ] Reword the README to be more professional.
- [ ] Fix includes folders.
- [ ] Have makefile move necessary files for Windows builds into the build directory and split them based on OS.
- [ ] Automated build setup for other operating systems.
- [ ] Create level builder to make level design easier.
- [x] Break screens up into separate files.
- [x] Start progress on the project.