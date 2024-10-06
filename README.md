# rk-61-qmk
qmk firmware for the royal kludge rk61 qmk with firmware level SOCD/snap tap and via support

## NOTE
This is not official firmware, but custom qmk firmware. I do NOT currently have RGB/backlight support, waiting for rk to get back to me on which pins are for lighting.

MAKE SURE THAT IS IS THE RK61 QMK EDITION -> PID 6461

This is my improved firmware -> that is, fn + arrow keys for arrow key behaviour, fn + <> for volume, etc.

FN + Q TO TOGGLE SOCD

## USAGE

### Compile from source

Follow the instructions here to setup your qmk environment: https://docs.qmk.fm/newbs_getting_started
 
Copy the royal_kludge folder into the keyboards folder in your qmk_firmware directory

Compile with `qmk compile -kb royal_kludge/rk61 -km ssyo`

Flash to your keyboard with QMK toolbox

### Precompiled
Go to the releases page here: [https://github.com/yutaoz/rk-61-qmk/releases](https://github.com/yutaoz/better-rk61-qmk/releases)

Unzip the files

Flash with qmk toolbox

## HELP

Enter bootloader mode by pressing the button under the spacebar after you remove it
