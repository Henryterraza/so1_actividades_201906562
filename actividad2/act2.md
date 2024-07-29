#!/bin/bash

# Leer la variable GITHUB_USER aqui se debe colocar el usuario al cual se desea acceder
GITHUB_USER="_usuario_github"

# Consultar la URL y obtener datos en formato JSON si hubo conexion se optendra la informacion
response=$(curl -s "https://api.github.com/users/$GITHUB_USER")

# Extraer información del JSON usando jq, en response se obtendra los valores
user_id=$(echo "$response" | jq -r '.id')
created_at=$(echo "$response" | jq -r '.created_at')

# Imprimir mensaje
message="Hola $GITHUB_USER. User ID: $user_id. Cuenta fue creada el: $created_at."
echo "$message"

# Crear un archivo de log con la fecha actual
fecha=$(date +'%Y-%m-%d')
log_dir="/tmp/$fecha"
mkdir -p "$log_dir"
log_file="$log_dir/saludos.log"

# Escribir el msj en el archivo de log
echo "$message" >> "$log_file"

# Configuración del cronjob
cronjob="*/5 * * * * /ruta/al/script.sh"
echo "Configuración del cronjob: $cronjob" >> "$log_file"
