#!/bin/bash

if [ $UID != 0 ]; then
	echo "Usage: sudo ./install.sh";
fi

sudo -u rmullins echo "I am ${USER}"
