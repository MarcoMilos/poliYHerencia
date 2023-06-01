# Polimorfismo y Herencia (serpientes y escaleras)

El código es un script de tipo C++ en el que se nos presenta el reto de diseñar y elaborar un juego sencillo de "Serpientes y escaleras" así como se nos presentó previamente, la diferencia con esta versión es que, ahora, el usuario debe de tener la capacidad de poder establecer de forma manual, los valores de la cantidad de casillas que quiere que contenga su juego, la cantidad de serpientes que quiere ver, la cantidad de escaleras que quiere que hayan, la cantidad de casillas que tendrá que retroceder el jugador tras caer en una casilla de tipo serpiente, la cantidad de casillas que tendrá que avanzar el jugador tras caer en una casilla de tipo escalera, la cantidad de jugadores que quiere ver presentes en su partida, la cantidad de turnos permitidos por partida antes de que se termine la partida, ya sea porque llegaron la límite de turnos o porque algún jugador lograra llegar a la meta y, finalmente, el modo en el que quiere que se presente el juego, ya sea de manera automática, y que el usuario no tenga que presionar ninguna tecla para que la partida comience y finalice, o de manera manual, en la que el usuario se ve forzado a indicarle al código que puede continuar pasando turnos uno a uno hasta finalizar la partida o salirse (en caso de así quererlo). 

Un claro ejemplo de lo explicado anteriormente sería algo parecido a lo siguiente:
-> ¿Cantidad de casillas para su juego?
30
-> ¿Cantidad de serpientes en su juego?
6
-> ¿Cantidad de escaleras en su juego?
4
-> ¿Consecuencia por caer en una casilla de tipo serpiente?
3
-> ¿Recompensa por caer en una casilla de tipo escalera?
3
-> ¿Cantidad de jugadores en la partida?
2
-> ¿Cantidad de turnos permitidos por partida?
15
-> Estableza el modo en el que le gustaría que fuera el juego A (automatico), M (manual)
M/A (depende de lo que seleccione el usuario)

En caso de seleccionar "A", el juego estaría realizando jugadas de manera aleatoria, respetando turnos, los jugadores presentes en la partida, casillas, castigos, recompensas, etc. Una vez llegado, ya sea al límite de turnos permitidos o que un jugador logre llegar a la meta, el juego mostrará un mensaje predeterminado. En caso de llegar al límite de turnos, se mostrará en pantalla un mensaje tipo "Límite de turnos alcanzado" y, seguido a ello, mostrará al jugador más cercano a la meta. En caso de que un jugador logre llegar a la meta antes de que se terminen los turnos permitidos, se mostrará un mensaje de tipo:
             -- Game Over --
            Gracias por jugar
El jugador (número del jugador) es el ganador

Del mismo modo, es importante mencionar en dónde y por qué hicimos uso de "herencia" y de "polimorfismo" en algunas de nuestras clases. Una de las clases en las que utilizamos herencia fue en la de "snake.h" y en la de "ladder.h" puesto que requerimos de heredar las propiedades del padre "tile.h" para poder hacer uso de una casilla, puesto que, como bien sabemos, no se puede tener serpientes y escaleras en espacios vacíos, entonces requeríamos hacer uso de las casillas establecidas de manera "default" para que, de manera aleatoria pudiéramos renombrar algunas a que fueran casillas de estilo "Serpiente" o de estilo "Escalera".

A su vez, hicimos uso de los polimorfismos, al establecer en la clase "board" un vector de tipo Tile encargado de almacenar por igual casillas de tipo "normal", de tipo "serpiente" o de tipo "escalera". Para que esto funcionara, requerimos de hacer uso de la herencia y de los apuntadores. Del mismo modo, para poder hacer uso de los players y recorrer la lista de jugadores en la partida, de uno por uno, requerimos de hacer uso de la herencia y de apuntadores para así, poder hacer uso del polimorfismo.

## Tecnología Utilizada:

* git y github
* 100% C++
* Uso de la librería:
    "cstdlib" -> Para llamar a la funcion rand() del dado

## Importante:

* Será necesario conectar nuestro GitHub con el IDE que estamos utilizando (en caso de estar haciendo uso alguno).
* Es necesario asegurarnos de que todas las clases necesarias para el programa ya estén creadas (para evitarnos erorres innecesarios).
* El ÚNICO archivo de tipo ".cpp" será el de snakes (para ahorrarnos la creación de múltiples archivos ".exe").
* Todos los archivos de jugadores y el "MyGame" tienen que ir como #include dentro del archivo .cpp "snakes".
* Para salir o detener el juego, se tiene que escribir en la terminal/consola "E" o "e" (en referencia a "exit").