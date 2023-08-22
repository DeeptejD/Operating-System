echo -n "Number of files in the directory: "
find -type f | wc -l
echo ""
echo "Directory: "
pwd
echo ""
echo "The files are"
ls -l
