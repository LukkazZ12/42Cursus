#!/bin/bash

if [ -f /var/www/html/wp-config-sample.php ];
then
	rm /var/www/html/wp-config-sample.php
	wp core install	--allow-root													\
					--path=/var/www/html											\
					--url=lucade-s.42.fr											\
					--title="Inception"												\
					--admin_user="$WP_ADMIN_USER"									\
					--admin_password="$WP_ADMIN_PASSWORD"							\
					--admin_email="$WP_ADMIN_USER@student.42sp.org.br"
	wp user create	--allow-root													\
					--path=/var/www/html "$WP_USER" "$WP_USER@student.42sp.org.br"	\
					--user_pass="$WP_USER_PASSWORD"
fi

exec php-fpm7.4 -F