# Arduino CAN Bus Monitor

This is a fork of [arduino-canbus-monitor](https://github.com/latonita/arduino-canbus-monitor) meant to work with the Longan Labs / SSI [CANBed v1](https://www.seeedstudio.com/CANBed-Arduino-CAN-BUS-Development-Kit-Atmega32U4-with-MCP2515-and-MCP2551-p-4365.html).

The CANBed v1 is an Atmega32U4 based board with MCP2515 and MCP2551 CAN chips.

This Arduino sketch turns the CANBed v1 into a USB-to-CAN tranceiver using the slcan (CAN over serial) protocol.

See the upstream repo for full protocol details.

## Using with Linux
### Install `can-utils`
On Ubuntu and other Debian-based distros `can-utils` package is included into standard repositories:
```
sudo apt install can-utils
```
For other distros please follow respective instructions, start from here https://github.com/linux-can/can-utils

### Create CAN Device
```
sudo slcand -o -c -s6 -S 115200 /dev/ttyAMC0
sudo ip link slcan0 up
```
Replace `/dev/ttyAMC0` with the serial device of the CANBed.
The `115200` is the default serial baudrate. Update this command if you've changed it in the sketch.

### Run Your Scanner
You can use one of the tools included with `can-utils`:
```
candump slcan0
```
Or run your own which is compatible with Linux SocketCAN.

### Disconnect CAN Device
```
sudo killall slcand
```
