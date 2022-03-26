echo "" &&
echo "Removing old classes and compiling new ones" &&
rm -rf *.class &&
javac *.java && 
echo "--------------------------------------------------------------------------------" &&

echo "" &&
echo "Running Client" &&
echo "--------------------------------------------------------------------------------" &&
java ClientStoreFrontController