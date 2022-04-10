#! /bin/bash
echo 0 | tee /proc/sys/kernel/randomize_va_space
echo "kernel.randomize_va_space = 0" > /etc/sysctl.d/01-disable-aslr.conf
adduser player
echo "player ALL=(root) /usr/bin/vi /opt/*, /usr/bin/cat /opt/*, /usr/bin/find" > /etc/sudoers.d/player