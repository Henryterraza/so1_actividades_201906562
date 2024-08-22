## Instalación

- Crear el script:

    ```bash
    sudo nano /usr/local/bin/act4.sh
    ```

    Contenido del script:

    ```bash
    #!/bin/bash

    while true
    do
        echo "Hola! La fecha y hora actual es: $(date)"
        sleep 1
    done
    ```

- Dar permsisos de ejecucion:

    ```bash
    sudo chmod +x /usr/local/bin/act4.sh
    ```

- Crear el archivo de servicio:

    ```bash
    sudo nano /etc/systemd/system/act4.service
    ```

    Contenido del archivo de servicio:

    ```ini
    [Unit]
    Description=Mostrar saludo con fecha y hora actual

    [Service]
    ExecStart=/usr/local/bin/act4.sh
    Restart=always

    [Install]
    WantedBy=multi-user.target
    ```

- Recargar y habilitar el servicio:

    ```bash
    sudo systemctl daemon-reload  #para recargar los servicios
    sudo systemctl enable act4.service #habilitar el servicio
    sudo systemctl start act4.service #iniciar el servicio
    ```

## Verificación

- Para verificar el estado del servicio:

    ```bash
    sudo systemctl status act4.service
    ```

- Para ver los logs del servicio:

    ```bash
    sudo journalctl -u act4.service
    ```

