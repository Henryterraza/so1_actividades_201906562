## Parte 1: Gestión de Usuarios
1. Creación de Usuarios: Crea tres usuarios llamados `usuario1`, `usuario2` y `usuario3`.

```cmd
sudo useradd usuario1
sudo useradd usuario2
sudo useradd usuario3
```

![](./Img/Captura%20desde%202024-08-04%2021-36-40.png)


2. Asignación de Contraseñas: Establece una nueva contraseñas para cada usuario creado.
```
echo 'usuario1:pssusua1' | sudo chpasswd 
echo 'usuario2:pssusua2' | sudo chpasswd 
echo 'usuario3:pssusua3' | sudo chpasswd 
```
![](./Img/Captura%20desde%202024-08-04%2021-46-45.png)

3. Información de Usuarios: Muestra la información de `usuario1` usando el comando `id`.
```
id usuario1
```
![](./Img/Captura%20desde%202024-08-04%2021-50-01.png)

4. Eliminación de Usuarios: Elimina `usuario3`, pero conserva su directorio principal.
```
sudo userdel -f usuario3
```
![](./Img/Captura%20desde%202024-08-04%2021-54-31.png)


## Parte 2: Gestión de Grupos
1. Creación de Grupos: Crea dos grupos llamados `grupo1` y `grupo2`.
```
sudo groupadd grupo1
sudo groupadd grupo2
```
![](./Img/Captura%20desde%202024-08-04%2021-57-20.png)

2. Agregar Usuarios a Grupos: Agrega `usuario1` a `grupo1` y `usuario2` a `grupo2`.
```
sudo usermod -aG grupo1 usuario1
sudo usermod -aG grupo2 usuario2
```
![](./Img/Captura%20desde%202024-08-04%2021-59-24.png)

3. Verificar Membresía: Verifica que los usuarios han sido agregados a los grupos utilizando el comando `groups`.
```
groups usuario1
groups usuario2
```
![](./Img/Captura%20desde%202024-08-04%2022-00-17.png)

4. Eliminar Grupo: Elimina `grupo2`.
```
sudo groupdel grupo2
```
![](./Img/Captura%20desde%202024-08-04%2022-01-30.png)

## Parte 3: Gestión de Permisos
1. Creación de Archivos y Directorios:

    * Como `usuario1`, crea un archivo llamado `archivo1.txt` en su directorio principal y escribe algo en él.
    * Crea un directorio llamado `directorio1` y dentro de ese directorio, un archivo llamado `archivo2.txt`.
```
#al usar el comando useradd no se genera el directorio por lo que se debe crear 

sudo mkdir -p /home/usuario1
sudo chown usuario1:usuario1 /home/usuario1

#seguido realizamos la creacion de los archivos

sudo -u usuario1 bash -c 'echo "Contenido de archivo1" > /home/usuario1/archivo1.txt'
sudo -u usuario1 mkdir /home/usuario1/directorio1
sudo -u usuario1 bash -c 'echo "Contenido de archivo2" > /home/usuario1/directorio1/archivo2.txt'
```
![](./Img/Captura%20desde%202024-08-04%2022-23-56.png)

2. Verificar Permisos: Verifica los permisos del archivo y directorio usando el comando `ls -l` y `ls -ld` respectivamente.
```
ls -l /home/usuario1/archivo1.txt
ls -ld /home/usuario1/directorio1
ls -l /home/usuario1/directorio1/archivo2.txt
```
![](./Img/Captura%20desde%202024-08-04%2022-25-58.png)

3. Modificar Permisos usando `chmod` con Modo Numérico: Cambia los permisos del `archivo1.txt` para que sólo `usuario1` pueda leer y escribir (permisos `rw-`), el grupo pueda leer (permisos `r--`) y nadie más pueda hacer nada.

```
sudo chmod 640 /home/usuario1/archivo1.txt
```
![](./Img/Captura%20desde%202024-08-04%2022-28-11.png)

4. Modificar Permisos usando `chmod` con Modo Simbólico: Agrega permiso de ejecución al propietario del `archivo2.txt`.
```
sudo chmod u+x /home/usuario1/directorio1/archivo2.txt
```
![](./Img/Captura%20desde%202024-08-04%2022-31-13.png)

5. Cambiar el Grupo Propietario: Cambia el grupo propietario de `archivo2.txt` a `grupo1`.
```
sudo chown :grupo1 /home/usuario1/directorio1/archivo2.txt
```
![](./Img/Captura%20desde%202024-08-04%2022-32-51.png)

6. Configurar Permisos de Directorio: Cambia los permisos del `directorio1` para que sólo el propietario pueda entrar (permisos `rwx`), el grupo pueda listar contenidos pero no entrar (permisos `r--`), y otros no puedan hacer nada.
```
sudo chmod 740 /home/usuario1/directorio1
```
![](./Img/Captura%20desde%202024-08-04%2022-34-17.png)

7. Comprobación de Acceso: Intenta acceder al `archivo1.txt` y `directorio1/archivo2.txt` como `usuario2`. Nota cómo el permiso de directorio afecta el acceso a los archivos dentro de él.
```
sudo -u usuario2 cat /home/usuario1/archivo1.txt
sudo -u usuario2 cat /home/usuario1/directorio1/archivo2.txt
```
![](./Img/Captura%20desde%202024-08-04%2022-35-11.png)

8. Verificación Final: Verifica los permisos y propietario de los archivos y directorio nuevamente con `ls -l` y `ls -ld`.
```
ls -l /home/usuario1/archivo1.txt
ls -ld /home/usuario1/directorio1
ls -l /home/usuario1/directorio1/archivo2.txt
```
![](./Img/Captura%20desde%202024-08-04%2022-39-10.png)