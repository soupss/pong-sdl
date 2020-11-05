## Requirements

* SDL 2
* SDL_image 2

## Installation

#### Debian Based Distros

```
$ sudo apt-get install libsdl2 libsdl2-image
```

#### Arch Based Distros

```
$ sudo pacman -S sdl2 sdl2_image
```

For more help see
* The official website: https://wiki.libsdl.org/Installation
* LazyFoo's installation guide: https://lazyfoo.net/tutorials/SDL/01_hello_SDL/index.php

## Usage

1. Build with makefile

Debug

```
$ make
```

Release (You probably want this)

```
$ make release
```

The executable is located at *bin/debug/main* and *bin/release/main* respectively

2. Run

```
$ ./bin/debug/main
```

or

```
$ ./bin/release/main
```
