FROM		debian:oldstable

RUN			apt-get update -y && apt-get upgrade -y

RUN			apt-get install -y wget mariadb-client php7.4 php-fpm php-mysql wordpress && rm -rf /var/lib/apt/lists/*

RUN			wget -O /usr/local/bin/wp https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
RUN			chmod +x /usr/local/bin/wp
RUN			wp core download --allow-root --path=/var/www/html

RUN			mkdir /run/php

COPY		conf/www.conf /etc/php/7.4/fpm/pool.d/www.conf
COPY		conf/wp-config.php /var/www/html/wp-config.php
COPY		./tools/wordpressinit.sh /usr/local/bin/wordpressinit.sh
RUN			chmod +x /usr/local/bin/wordpressinit.sh

ENTRYPOINT	["wordpressinit.sh"]