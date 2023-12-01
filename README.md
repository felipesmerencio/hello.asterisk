# Hello Word Asterisk using Docker

docker build -t helloasterisk:1 .

docker create --name helloasterisk -p 5060:5060/tcp -p 5060:5060/udp -p 10000-10099:10000-10099/udp helloasterisk:1

docker container start helloasterisk

docker exec -ti helloasterisk /bin/bash

cd /home/

tar -zxf asterisk-20.5.0.tar.gz

cd asterisk-certified-13.8-cert2/
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
