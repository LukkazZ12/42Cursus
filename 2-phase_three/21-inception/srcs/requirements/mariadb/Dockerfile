FROM debian:oldstable

ARG SQL_DATABASE
ARG SQL_USER
ARG SQL_PASSWORD

RUN apt update -y && apt upgrade -y

RUN apt install -y mariadb-server \
	&& rm -rf /var/lib/apt/lists/*

COPY conf/custom-mariadb.cnf /etc/mysql/my.cnf

COPY ./tools/mariadbinit.sh mariadbinit.sh
RUN chmod +x mariadbinit.sh

RUN ./mariadbinit.sh

CMD ["mysqld_safe"]