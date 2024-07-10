#!/bin/bash

service mariadb start

mariadb -u root -e \
	"CREATE DATABASE IF NOT EXISTS ${SQL_DATABASE}; \
	CREATE USER '${SQL_USER}'@'%' IDENTIFIED BY '${SQL_PASSWORD}'; \
	GRANT ALL ON ${SQL_DATABASE}.* TO '${SQL_USER}'@'%' IDENTIFIED BY '${SQL_PASSWORD}'; \
	FLUSH PRIVILEGES;"

# eu tenho o projeto feito na seguinte estruturas de pastas:
# inception
#	 srcs
#	 	requirements
# 			mariadb
# 				conf
# 					arquivo: custom-mariadb.cnf
# 						"[mysqld]
# 						skip-networking=0
# 						skip-bind-address"
# 				tools
# 					arquivo: mariadbinit.sh
# 						"#!/bin/bash
# '
# 						service mariadb start

# 						mariadb -u root -e \
# 							"CREATE DATABASE IF NOT EXISTS ${SQL_DATABASE}; \
# 							CREATE USER '${SQL_USER}'@'%' IDENTIFIED BY '${SQL_PASSWORD}'; \
# 							GRANT ALL ON ${SQL_DATABASE}.* TO '${SQL_USER}'@'%' IDENTIFIED BY '${SQL_PASSWORD}'; \
# 							FLUSH PRIVILEGES;""
# 				arquivo: Dockerfile
# 					FROM debian:oldstable

# 					ARG SQL_DATABASE
# 					ARG SQL_USER
# 					ARG SQL_PASSWORD

# 					RUN apt update -y && apt upgrade -y

# 					RUN apt install -y mariadb-server \
# 						&& rm -rf /var/lib/apt/lists/*

# 					COPY conf/custom-mariadb.cnf /etc/mysql/my.cnf

# 					COPY ./tools/mariadbinit.sh mariadbinit.sh
# 					RUN chmod +x mariadbinit.sh

# 					RUN ./mariadbinit.sh

# 					CMD ["mysqld_safe"]
# 			nginx
# 				conf
# 					arquivo: nginx.conf
# 						"server {
# 							server_name lucade-s.42.fr;

# 							listen 443 ssl default_server;
# 							listen [::]:443 ssl default_server;
# 							ssl_protocols TLSv1.2 TLSv1.3;
# 							ssl_certificate /etc/nginx/ssl/inception.crt;
# 							ssl_certificate_key /etc/nginx/ssl/inception.key;

# 							root /var/www/html;
# 							index index.php index.html;
# 							location ~ \.php$
# 							{
# 								include snippets/fastcgi-php.conf;
# 								fastcgi_pass   wordpress:9000;
# 							}
# 						}"
# 				arquivo: Dockerfile
# 					"FROM debian:oldstable

# 					RUN apt update -y && apt upgrade -y

# 					RUN apt install -y nginx \
# 						openssl \
# 						&& rm -rf /var/lib/apt/lists/*

# 					RUN mkdir /etc/nginx/ssl

# 					COPY ./conf/nginx.conf /etc/nginx/conf.d
# 					RUN openssl req -x509 -nodes -out /etc/nginx/ssl/inception.crt -keyout /etc/nginx/ssl/inception.key -subj "/C=BR/ST=SP/O=42/OU=42SP/CN=lucade-s.42.fr"
# 					RUN chmod 755 /var/www/html
# 					RUN chown -R www-data:www-data /var/www/html

# 					EXPOSE 443

# 					CMD ["nginx", "-g", "daemon off;"]"
# 			wordpress
# 				conf
# 					arquivo: wp-config.php
# 						"<?php
# 						define( 'DB_NAME', getenv('SQL_DATABASE') );
# 						define( 'DB_USER', getenv('SQL_USER') );
# 						define( 'DB_PASSWORD', getenv('SQL_PASSWORD') );
# 						define( 'DB_HOST', 'mariadb' );
# 						define( 'DB_CHARSET', 'utf8' );
# 						define( 'DB_COLLATE', '');

# 						$table_prefix = 'wp_';

# 						define( 'WP_DEBUG', false );

# 						if ( ! defined( 'ABSPATH' ) ) {
# 							define( 'ABSPATH', __DIR__ . '/' );
# 						}

# 						require_once ABSPATH . 'wp-settings.php';"
# 					arquivo: www.conf
# 						"[www]
# 						pm = ondemand
# 						clear_env = no
# 						user = www-data
# 						group = www-data
# 						pm.max_children = 10
# 						listen = 0.0.0.0:9000"
# 				tools
# 					arquivo: wordpressinit.sh
# 						"#!/bin/bash

# 						if [ -f /var/www/html/wp-config-sample.php ]; then
# 							rm -rf /var/www/html/wp-config-sample.php
# 							wp core install --allow-root						    \
# 								--path=/var/www/html						        \
# 								--url=lucade-s.42.fr							    \
# 								--title="Inception"						            \
# 								--admin_user="$WP_ADMIN_USER"					    \
# 								--admin_password="$WP_ADMIN_PASSWORD"			    \
# 								--admin_email="$WP_ADMIN_USER@student.42sp.org.br"

# 							wp user create --allow-root 						    \
# 								--path=/var/www/html						        \
# 								"$WP_USER"									        \
# 								"$WP_USER@student.42sp.org.br" 					    \
# 								--user_pass="$WP_USER_PASSWORD"
# 						fi

# 						exec php-fpm7.4 -F"
# 				arquivo: Dockerfile
# 					"FROM debian:oldstable

# 					RUN apt-get update -y && apt-get upgrade -y

# 					RUN apt-get install -y wget \
# 						mariadb-client \
# 						php7.4 \
# 						php-fpm \
# 						php-mysql \
# 						wordpress \
# 						&& rm -rf /var/lib/apt/lists/*

# 					RUN wget -O /usr/local/bin/wp https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
# 					RUN chmod +x /usr/local/bin/wp
# 					RUN wp core download --allow-root --path=/var/www/html

# 					# Required for php pid
# 					RUN mkdir /run/php

# 					COPY conf/www.conf /etc/php/7.4/fpm/pool.d/www.conf
# 					COPY conf/wp-config.php /var/www/html/wp-config.php
# 					COPY ./tools/wordpressinit.sh wordpressinit.sh

# 					RUN chmod +x wordpressinit.sh

# 					ENTRYPOINT ["./wordpressinit.sh"]"
#		arquivo: .env
#			"SQL_DATABASE=wordpress_db
#			SQL_USER=wuser
#			SQL_PASSWORD=wpass
#			WP_ADMIN_USER=lucade-s
#			WP_ADMIN_PASSWORD=123lucade-s123
#			WP_USER=evaluator
#			WP_USER_PASSWORD=123evaluator123"
#		arquivo: docker-compose.yml
#			"version: '3'

#			networks:
#				inception:
#					name: inception

#			services:
#				nginx:
#					container_name: nginx
#					restart: always
#					image: nginx
#					depends_on:
#						- wordpress
#					build:
#						context: ./requirements/nginx
#					networks:
#						- inception
#					volumes:
#						- wordpress-data:/var/www/html
#					ports:
#						- 443:443

#				mariadb:
#					container_name: mariadb
#					restart: always
#					image: mariadb
#					build:
#						context: ./requirements/mariadb
#						args:
#							- SQL_DATABASE=${SQL_DATABASE}
#							- SQL_USER=${SQL_USER}
#							- SQL_PASSWORD=${SQL_PASSWORD}
#					healthcheck:
#						test: mysqladmin ping -h localhost -u root
#						interval: 1s
#						timeout: 1s
#						retries: 5
#					networks:
#						- inception
#					env_file: .env
#					volumes:
#						- mariadb-data:/var/lib/mysql

#				wordpress:
#					container_name: wordpress
#					restart: always
#					image: wordpress
#					depends_on:
#						mariadb:
#							condition: service_healthy
#					build:
#						context: ./requirements/wordpress
#					environment:
#						- SQL_DATABASE
#						- SQL_USER
#						- SQL_PASSWORD
#						- WP_ADMIN_USER
#						- WP_ADMIN_PASSWORD
#						- WP_USER
#						- WP_USER_PASSWORD
#					networks:
#						- inception
#					env_file: .env
#					volumes:
#						- wordpress-data:/var/www/html

#			volumes:
#				wordpress-data:
#					name: wordpress-data
#					driver: local
#					driver_opts:
#						o: bind
#						type: none
#						device: /home/lucade-s/data/wordpress/

#				mariadb-data:
#					name: mariadb-data
#					driver: local
#					driver_opts:
#						o: bind
#						type: none
#						device: /home/lucade-s/data/mariadb/"
#	arquivo: Makefile
#		"LOGIN=lucade-s
#		DOCKER_COMPOSE_PATH=./srcs/docker-compose.yml

#		all: up

#		setup:
#			cat /etc/hosts | grep $(LOGIN) || echo "127.0.0.1 $(LOGIN).42.fr" | sudo tee --append /etc/hosts
#			sudo mkdir -p /home/$(LOGIN)/data/mariadb
#			sudo mkdir -p /home/$(LOGIN)/data/wordpress

#		up: setup
#			docker-compose -f $(DOCKER_COMPOSE_PATH) up -d

#		down:
#			docker-compose -f $(DOCKER_COMPOSE_PATH) down

#		delete-volumes:
#			docker volume rm $(shell docker volume ls -q)
#			sudo rm -rf /home/$(LOGIN)/data/mariadb/*
#			sudo rm -rf /home/$(LOGIN)/data/wordpress/*

#		ls:
#			@echo "IMAGES:"
#			@docker image ls -a
#			@echo "\nCONTAINERS:"
#			@docker container ls -a
#			@echo "\nVOLUMES:"
#			@docker volume ls
#			@echo "\nNETWORKS:"
#			@docker network ls -f type=custom

#		clean:
#			docker image prune -af

#		fclean: delete-volumes
#			docker system prune -fa

#		re: fclean all

#		.PHONY: all up down delete-volumes ls clean fclean re"