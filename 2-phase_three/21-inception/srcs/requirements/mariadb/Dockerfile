FROM		debian:oldstable

ARG			SQL_DATABASE
ARG			SQL_USER
ARG			SQL_PASSWORD

RUN			apt-get update -y && apt-get upgrade -y

RUN			apt-get install -y mariadb-server && rm -rf /var/lib/apt/lists/*

COPY		conf/custom-mariadb.cnf /etc/mysql/my.cnf

COPY		./tools/mariadbinit.sh /usr/local/bin/mariadbinit.sh
RUN			chmod +x /usr/local/bin/mariadbinit.sh

CMD			["mysqld_safe"]
ENTRYPOINT	["mariadbinit.sh"]