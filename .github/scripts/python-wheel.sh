#!/usr/bin/env bash


downloads_dir=/home/downloads
work_dir=/home/work

mkdir $downloads_dir
mkdir $work_dir

curl -L https://www.openssl.org/source/openssl-1.1.1h.tar.gz > $downloads_dir/openssl-1.1.1h.tar.gz

cd $work_dir
tar -xzf $downloads_dir/openssl-1.1.1h.tar.gz
cd openssl-1.1.1h
./Config
make -j3
make install

#1  ls
#    2  pwd
#    3  cmake --version
#    4  git --version
#    5  ls /home/
#    6  cd /home/
#    7  git clone https://github.com/cellml/libcellml -b develop --depth 1 libcellml
#   12  git clone https://github.com/OpenCMISS-Dependencies/zlib -b v1.2.3 --depth 1 zlib
#   13  git clone https://github.com/OpenCMISS-Dependencies/libxml2 -b v2.9.6 --depth 1 libxml2
#   8  cmake -S libcellml/ -B build -D COVERAGE=OFF -D BUILD_TYPE=Release
#   17  cmake -S zlib/ -B build-zlib -D CMAKE_BUILD_TYPE=Release -D BUILD_TESTS=OFF
#   23  cmake -S libxml2/ -B build-libxml2 -D CMAKE_BUILD_TYPE=Release -D BUILD_SHARED_LIBS=OFF -D BUILD_TESTS=OFF
#   18  cd build-zlib/
#   19  ccmake .
#   20  make
#   21  make install
#   22  cd ..
#   24  cd build-libxml2/
#   25  ccmake .
#   26  make
#   30  make install
#   75  curl https://www.python.org/ftp/python/3.8.6/Python-3.8.6.tgz > Python-3.8.6.tar.gz
#   https://www.python.org/ftp/python/3.7.9/Python-3.7.9.tgz
#   84  cd /home/
#   85  tar -xzf /root/python-3.8.6.tar.gz
#   87  mkdir build-python
#   89  cd Python-3.8.6/
#   92  ./configure --enable-shared  --enable-optimizations
#   93  make -j4
#   94  make install
#  100  curl -L http://prdownloads.sourceforge.net/swig/swig-4.0.2.tar.gz > swig-4.0.2.tar.gz
#  119  curl https://cfhcable.dl.sourceforge.net/project/swig/swig/swig-4.0.2/swig-4.0.2.tar.gz > swig-4.0.2.tar.gz
#  121  tar -xzf /root/swig-4.0.2.tar.gz
#  123  mkdir build-swig
#  124  cd build-swig/
#  127  ../swig-4.0.2/configure
#  129  make
#  130  make -j4
#  131  make install
#  132  cd ../build
#  133  make
#  134  cmake .
#  135  make -j5
#  136  make test
#  144  curl https://files.pythonhosted.org/packages/a7/00/3df031b3ecd5444d572141321537080b40c1c25e1caa3d86cdd12e5e919c/wheel-0.35.1-py2.py3-none-any.whl > wheel-0.35.1-py2.py3-none-any.whl
#  153  /usr/local/bin/pip3 install wheel-0.35.1-py2.py3-none-any.whl
#  154  /usr/local/bin/python3 setup.py bdist_wheel
#  158  /usr/local/bin/python3 -m venv venv_test
#  159  . venv_test/bin/activate
#  160  pip install /home/build/src/bindings/python/dist/libcellml-0.2.0-cp38-cp38-linux_x86_64.whl
#  161  python -c "import libcellml"

#curl -L https://www.openssl.org/source/openssl-1.1.1h.tar.gz > openssl-1.1.1h.tar.gz
#tar -xzf /root/openssl-1.1.1h.tar.gz
