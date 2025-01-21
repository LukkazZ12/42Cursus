FROM nginx:latest

RUN if [ ! -f /etc/ssl/certs/certificate.pem ]; then \
    openssl req \
    -x509 \
    -newkey rsa:4096 \
    -sha256 \
    -days 365 \
    -nodes \
    -keyout /etc/ssl/private/certificate.key.pem \
    -out /etc/ssl/certs/certificate.pem \
    -subj "/C=BR/ST=SP/L=Itaquera/O=42/OU=42/CN=dapaulin@42.fr"; \
    fi

COPY ./nginx/default.conf /etc/nginx/conf.d/default.conf

COPY ./src/ /usr/share/nginx/html/