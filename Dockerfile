FROM ubuntu:14.04

RUN apt-get update && apt-get install -y \
   build-essential \
   check \
   git \
   wget \
   gconf2 \
   gconf-service \
   libgtk2.0-0 \
   libnotify4 \
   libxtst6 \
   libnss3 \
   python \
   gvfs-bin \
   xdg-utils \
   pkg-config

RUN wget --no-verbose https://github.com/atom/atom/releases/download/v1.8.0/atom-amd64.deb -O /tmp/atom-amd64.deb

RUN dpkg -i /tmp/atom-amd64.deb

CMD ["/bin/bash"]
