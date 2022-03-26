echo "" &&
echo "Removing old classes and compiling new ones" &&
rm -rf *.class &&
javac *.java && 
echo "--------------------------------------------------------------------------------" &&

echo "" &&
echo "Creating stub class" &&
rmic Store_Controller &&
echo "--------------------------------------------------------------------------------" &&

echo "" &&
echo "Running Client" &&
echo "--------------------------------------------------------------------------------" &&
java Client_Store_Controller