# Building from source

To build from source first run `./configure [--OPTIONS]` this will create a directory called 'build' then run `make` to build

To install use `make install` (May require sudo)

To build a package use `make pkg.<file extension>`

The build roughly takes 4 seconds for me so to spped it up using `make -j$(nproc)`

## Options for confifure

| Option name | Description |
| --- | ----------- |
| `--target` | Set target |
| `--prefix=<prefix>` | Install directory, defaults to `/usr/local` |
| `--compiler` | Specify compiler, default to /usr/bin/c++ but will try to find others if not found |
| `--bash` | Bash coloured output to Ember |
