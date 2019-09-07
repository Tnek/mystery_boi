FROM ubuntu:18.04
MAINTAINER tnek

RUN apt-get update && apt-get install -y socat

RUN useradd -ms /bin/sh mystery_boi
WORKDIR /home/mystery_boi

COPY ./distribute/* ./

RUN chown -R root:mystery_boi /home/mystery_boi && \
     chmod 750 /home/mystery_boi && \
     chmod 550 /home/mystery_boi/mloader && \
     chmod 550 /home/mystery_boi/launcher.py

EXPOSE 8000

CMD ["socat", "-T60", "TCP-LISTEN:8000,reuseaddr,fork,su=mystery_boi","EXEC:/home/mystery_boi/python launcher.py,pty"]
