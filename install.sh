make -C .

cp clean_dir ~/.clean_dir
cp cleanlist.txt ~/.cleanlist.txt

echo "alias cleandir='~/.clean_dir'" >> ~/.bashrc
echo "alias clean_dir='~/.clean_dir'" >> ~/.bashrc
echo "alias cleandir='~/.clean_dir'" >> ~/.zshrc
echo "alias clean_dir='~/.clean_dir'" >> ~/.zshrc

$SHELL
