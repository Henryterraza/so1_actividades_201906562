Parte 1: Gestión de Usuarios
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
![](./Img/Captura%20desde%202024-08-04%2021-50-01.png)


Parte 2: Gestión de Grupos
1. Creación de Grupos: Crea dos grupos llamados `grupo1` y `grupo2`.

2. Agregar Usuarios a Grupos: Agrega `usuario1` a `grupo1` y `usuario2` a `grupo2`.

3. Verificar Membresía: Verifica que los usuarios han sido agregados a los grupos utilizando el comando `groups`.

4. Eliminar Grupo: Elimina `grupo2`.

