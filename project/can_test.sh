#! /bin/bash

ifconfig can0 down
ip link set can0 type can bitrate 1000000
ifconfig can0 up
./threadtest