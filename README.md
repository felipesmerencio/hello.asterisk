# Hello Word Asterisk using Docker

docker build -t helloasterisk:1 .

docker create --name helloasterisk -p 5060:5060/tcp -p 5060:5060/udp -p 10000-10099:10000-10099/udp helloasterisk:1

docker container start helloasterisk

docker exec -ti helloasterisk /bin/bash

# Install dependencies

dnf install gcc gcc-c++ bzip2 patch libedit-devel libuuid-devel wget autoconf automake autoconf libtool libxml2-devel sqlite-devel jansson vim openssl-devel diffutils -y

## Install Jansson

cd /home/

wget https://github.com/akheron/jansson/archive/refs/tags/v2.13.1.tar.gz

tar -zxvf v2.13.1.tar.gz

cd jansson-2.13.1

autoreconf -i

./configure

make

make install

## Install Asterisk 20

cd /home/asterisk-21.0.0/

chmod 777 -R /home/asterisk-21.0.0/

make clean

./configure --disable-asteriskssl --libdir=/usr/lib64 --with-pjproject-bundled

make menuselect

make && make install

make samples

## Debug 3 - Verbose

vim /etc/asterisk/asterisk.conf

asterisk -gvvvvvvvvvvvvvvvvvvvvvvvv

rasterisk

core set verbose 3

## Criar ramais - /etc/asterisk/pjsip.conf

```
[8000]
type=endpoint
context=test-callface
disallow=all
allow=alaw
transport=transporte-udp-nat
auth=8000
aors=8000
direct_media=no

[8000]
type=auth
auth_type=userpass
password=qwe123
username=8000

[8000]
type=aor
max_contacts=1
;contact=sip:my_extension@127.0.0.1:5060
```

## Regra - /etc/asterisk/extensions.conf

```
[test-callface]
exten => _XXXX,1,Dial(PJSIP/${EXTEN})
exten => _XXXX,n,Hangup()
```

# Stop and delete Container

```
docker container stop helloasterisk && docker container rm helloasterisk
docker container stop helloasterisk && docker container rm helloasterisk && git pull
```

# Complete command to upload Linux

```
docker build -t helloasterisk:1 . && docker create --name helloasterisk -p 5060:5060/tcp -p 5060:5060/udp -p 10000-10099:10000-10099/udp helloasterisk:1 && docker container start helloasterisk && docker exec -ti helloasterisk /bin/bash
```
