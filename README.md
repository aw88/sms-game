# sms-game

## Usage

### Build

To build the ROM using [alexw88/sms-toolchain]:

```sh
docker run --rm -v $(pwd):/app alexw88/sms-toolchain make all
```

To build with debugging symbols:
```sh
docker run --rm -v $(pwd):/app alexw88/sms-toolchain make debug
```

### Debugging

[Visual Studio Code], [Emulicious] and the [Calindro/emulicious-debugger]
extension are recommended for interactive debugging. Debug launch configurations have been included for VS Code.

To debug:

1. Open Emulicious and enable remote debugging. `Tools -> Remote Debugging -> Enable`
1. Open the project in VS Code
1. Go to the "Run" panel (`Ctrl+Shift+D`)
1. Select "Launch in Emulicious"

The "Attach to Emulicious" configuration can be used to attach to a running ROM.

## Acknowledgements

* [DINOBYTE bitmap font](https://mby.itch.io/dinobyte) by [mby](https://mby.itch.io/)
* [Nicer Nightie font](https://unfilledflag.itch.io/nicer-nightie) by [UnfilledFlag](https://unfilledflag.itch.io/)

[alexw88/sms-toolchain]: https://github.com/aw88/sms-toolchain
[Calindro/emulicious-debugger]: https://github.com/Calindro/emulicious-debugger
[Emulicious]: https://emulicious.net/
[Visual Studio Code]:https://code.visualstudio.com/
