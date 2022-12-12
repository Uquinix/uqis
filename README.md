UQIS
====

UQIS is a dependency-based init system that hooks onto the
system-provided init program on Enso, `/sbin/init`. UQIS is a fork of
OpenRC, our changes made include performance enhancements, security updates,
and other under-the-hood fixes.

For any enquires, please contact us at support@uquinix.com

Source Tree
-----------

| Directory | Description |
| --------- | ----------- |
| conf.d | System services. |
| etc | UQIS config files. |
| init.d | UQIS/System init files. |
| local.d | Custom Programs to be run for when a service Starts/Stops. |
| man | Man files. |
| meta | Documentation and markdown files. |
| pkgconfig | System include files. |
| sh | Shell scripts. |
| src | UQIS Source Code. |
| sysctl.d | Kernel system variables configuration files. |
| test | Directory for testing the functionality of UQIS. |
| tools | UQIS tools for CI and build options. |

Licensing
---------

Features that can be ported back across to OpenRC will be licensed under BSD.
Enso specific features & optimisations will be licensed under UPSL.

Reporting Bugs
--------------

Please report bugs on our [bug tracker](http://github.com/Uquinix/uqis/issues).

If you can contribute code , please feel free to do so by opening
[pull requests](https://github.com/Uquinix/uqis/pulls).
