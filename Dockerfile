FROM rockylinux:9

ADD ./asterisk-20.5.0.tar.gz /home/a

# Comando para manter o contêiner em execução
CMD tail -f /dev/null