FROM rockylinux:9

ADD ./asterisk-21.0.0.tar.gz /home/

# Comando para manter o contêiner em execução
CMD tail -f /dev/null