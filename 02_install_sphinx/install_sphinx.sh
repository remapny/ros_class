echo ""
echo "[Note] Target OS version  >>> Ubuntu 16.04.x (xenial) or Linux Mint 18.x"
echo "[Note] Target Sphinx version >>> 1.8"
echo ""
echo "PRESS [ENTER] TO CONTINUE THE INSTALLATION"
echo "IF YOU WANT TO CANCEL, PRESS [CTRL] + [C]"
read

echo "[get apt-repository on your pc]"
echo "deb http://plf.parrot.com/sphinx/binary `lsb_release -cs`/" | sudo tee /etc/apt/sources.list.d/sphinx.list > /dev/null
sudo apt-key adv --keyserver keyserver.ubuntu.com --recv-keys 508B1AE5

echo "[installation parrot-sphinx]"
sudo apt-get update
sudo apt-get install parrot-sphinx

echo "[copy drones files to home directory]"
cd $HOME/
sudo cp -r /opt/parrot-sphinx/usr/share/sphinx/drones/ $HOME/
sudo chown -R $USER $HOME/drones

cp $PWD/sphinx_bebop2.sh $HOME/
sudo chmod +755 $HOME/sphinx_bebop2.sh

echo "[Complete!!!]"

exit 0