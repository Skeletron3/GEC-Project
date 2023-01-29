# Contributing to the Ember programming language

## General

Please add comments as to how the code works so it is easier for other people to contribute

## Making own package dist

These dists shall not be maintained by the owner of this and will be community built with the exception of `.deb`

### Creating Makefile

To create a Makefile please add a file named `pkg . <file extension>` in folder `Make`.
If the package has no file extension please use the package manager it was designed as the extension.

### Targets within Makefile

To make your own package target have the same target as the main file but all other targets should end with `_PKG_ + <file extension>`

### Exceptions

If the package has no file extension please use the package manager it was designed for install of extension. For example if Debain packages didn't have a file extension and it was designed for apt then it should be `pkg.apt`

### Important

Do not have an install/uninstall target so any package that has been built should not be able to be installed with Makefile.
Follow `Make/pkg.deb` for a guide

### Examples

For Debian packages:

* File: `Make/pkg.deb`
* Main target: `pkg.deb` (in the file above)
* Prereq/target without extension: `build/_PKG_DEB`
* Prereq/target with extension `.deb`:  `build/_PKG_DEB.deb`

No extension packages:

Assume that the package manager is called `MyPkgMnger`

* File: `make/pkg.MyPkgMnger`
* Main target: `pkg.MyPkgMnger` (in the file above)
* Prereq/target without extension: `build/_PKG_MYPKGMNGER`
* Prereq/target with extension `.deb`:  `build/_PKG_MYPKGMNGER.MyPkgMnger`

See `Make/pkg.deb` for an example

### After

Please add `include Make/<FILE>` to `Makefile` so it can be used within make

## Changing code

Never edit master branch directly create a new branch and then do changes there. Then create a pull request
