echo "" &&
ps aux | grep rmiregistry &&
echo "--------------------------------------------------------------------------------" &&

echo "" &&
echo "Enter ID of rmiregistry to kill (enter blank if no RMI running):" &&
read ID &&
echo "--------------------------------------------------------------------------------" &&

echo "" &&
echo "Killing $ID" &&
kill -9 $ID &&
echo "--------------------------------------------------------------------------------" &&

echo "" &&
echo "Removing old classing and compiling new ones" &&
rm -rf *.class &&
javac *.java &&
echo "--------------------------------------------------------------------------------" &&


echo "" &&
echo "Running rmiregistry at port 5000"
rmiregistry 5000 & echo "--------------------------------------------------------------------------------" &&

echo "" &&
echo "Running Server" &&
java RemoteStoreFrontController