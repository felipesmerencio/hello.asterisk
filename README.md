# Hello Word Asterisk using Docker

docker build -t helloasterisk:1 .

docker create --name helloasterisk -p 5060:5060/tcp -p 5060:5060/udp -p 10000-10099:10000-10099/udp helloasterisk:1

docker container start helloasterisk

docker exec -ti helloasterisk /bin/bash

# Install dependencies

dnf install gcc gcc-c++ bzip2 patch libedit-devel libuuid-devel libjansson-devel wget autoconf automake autoconf libtool libxml2-devel sqlite-devel -y

## Install Jansson

cd /home/

wget https://github.com/akheron/jansson/archive/refs/tags/v2.13.1.tar.gz

tar -zxvf v2.13.1.tar.gz

cd jansson-2.13.1

autoreconf -i

./configure

make

make install

## Install Asterisk

cd /home/asterisk-20.5.0/

./configure --disable-asteriskssl --libdir=/usr/lib64

scp ../menuselect.makeopts ./

make menuselect.makeopts
cd .

# Stop and delete Container

```
docker container stop helloasterisk && docker container rm helloasterisk
```

# Complete command to upload Linux

```
docker build -t helloasterisk:1 . && docker create --name helloasterisk -p 5060:5060/tcp -p 5060:5060/udp -p 10000-10099:10000-10099/udp helloasterisk:1 && docker container start helloasterisk && docker exec -ti helloasterisk /bin/bash
```
