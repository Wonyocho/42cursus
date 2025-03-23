#!/bin/sh

# SSL 디렉토리 생성
SSL_DIR="/etc/nginx/ssl"
mkdir -p "$SSL_DIR"

# SSL 키와 인증서 생성
openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
    -keyout "$SSL_DIR/wonyocho.key" \
    -out "$SSL_DIR/wonyocho.crt" \
    -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=GAM/CN=wonyocho.42.fr"

# 키와 인증서 권한 설정
chmod 600 "$SSL_DIR/wonyocho.key" "$SSL_DIR/wonyocho.crt"
chown www-data:www-data "$SSL_DIR/wonyocho.key" "$SSL_DIR/wonyocho.crt"

echo "SSL key and certificate generated successfully."

# Nginx 실행 (포그라운드에서 실행하여 컨테이너 종료 방지)
exec nginx -g "daemon off;"