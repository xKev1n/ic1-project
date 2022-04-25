#! /bin/bash
echo 0 | tee /proc/sys/kernel/randomize_va_space
echo "kernel.randomize_va_space = 0" > /etc/sysctl.d/01-disable-aslr.conf
adduser player
echo "player ALL=(root) /usr/bin/find" > /etc/sudoers.d/player
chmod -R 757 /boot
chmod o+r /etc/shadow
cp /root/ic1-project/gui/gui-test /ic1-project/flags-gui/flags-gui /etc/init.d/ 
cp /root/ic1-project/functions_to_exploit/* /home/player/Desktop


cat > /etc/xdg/autostart/flags-gui.desktop <<EOF
[Desktop Entry]
Type=Application
Encoding=UTF-8
Name=timer
Exec=/etc/init.d/flags-gui
X-GNOME-Autostart-enabled=true
EOF

cat > /etc/xdg/autostart/gui-test.desktop <<EOF
[Desktop Entry]
Type=Application
Encoding=UTF-8
Name=timer
Exec=/etc/init.d/gui-test
X-GNOME-Autostart-enabled=true
EOF

cat > /home/lubuntu/flag.txt <<EOF
THE FLAG IS RIGHT THERE!!!
>>>	https://bit.ly/3vCnNLq

EOF
