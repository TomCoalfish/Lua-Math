pushd .
cd ~

travis_retry wget https://cmake.org/files/v3.9/cmake-3.9.4.tar.gz

tar -xzf cmake-3.9.4.tar.gz 
cd cmake-3.9.4/ 

./bootstrap

make -j2 > trash.txt
sudo make install

CMAKE_VER="3.9.4"

popd

