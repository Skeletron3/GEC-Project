# Ember compiler 1.0-1 (simple programming language) Ⓒ

## Licence: GNU GPLv3

## Contact

* Discord:  TheDuck#3454
* Github:  Skeletron3
* Github alt: TheDuck3

## Contributing

See `CONTRIBUTING.md`

## Info

For this project I have used GCC, clang or other c++ compilers will not be shown here.

This project has been tested with:

* Ubuntu version: 22.04LTS x86_64
* Bash version: 5.1.16(1)-release (x86_64-pc-linux-gnu)
* Make version: 4.3 x86_64-pc-linux-gnu
* g++ version: (Ubuntu 12.1.0-2ubuntu1~22.04) 12.1.0

This is an experimental programming language and is designed with Linux in mind. Don't attempt to port Windows featuers into this without first making a method to specify OS. Also note that it is specifically designed for Linux so although most Unix platforms will be able to run this don't cry because it doesnt work on Windows. From my experience I cannot compile it for Windows as c++23 isn't supported so you are kind of on your own.

## Dependancies

See `info/dependancies.md`

## Building from source

See `info/build.md`

## Ember Usage

`/path/to/ember [file] --[options]`

An important thing to note is that a space is required between the option and specification this will be changed in the future

| Option name | Description |
| --- | ----------- |
| `-K` | Will keep generated assembly file |
| `-o` | Will set the arguement after that to the output file name |

## Notes

Keep in mind that Makefile should not be run as root unless it absolutely needs it. You should not build as root or install without building. If you do so the directories created will be owned by user `root` and not you.
