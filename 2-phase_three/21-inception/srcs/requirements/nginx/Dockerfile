FROM debian:oldstable

RUN apt update -y && apt upgrade -y

RUN apt install -y nginx \
	openssl \
	&& rm -rf /var/lib/apt/lists/*

RUN mkdir /etc/nginx/ssl

COPY ./conf/nginx.conf /etc/nginx/conf.d
RUN openssl req -x509 -nodes -out /etc/nginx/ssl/inception.crt -keyout /etc/nginx/ssl/inception.key -subj "/C=BR/ST=SP/O=42/OU=42SP/CN=lucade-s.42.fr"
RUN chmod 755 /var/www/html
RUN chown -R www-data:www-data /var/www/html

EXPOSE 443

CMD ["nginx", "-g", "daemon off;"]