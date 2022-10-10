# a) soft link using shell command
touch one.txt
touch two.txt
#ln -s source destination
ln -sf one.txt two.txt
#after this when you put some data in one.txt it will automatically go into two.txt
ls -l two.txt

# b) hard link using shell command
ln -f one.txt two.txt

# c) FIFO
mkfifo myfile
ls -lF *
ls > myfile
# cat < myfile--run this on another terminal to see output