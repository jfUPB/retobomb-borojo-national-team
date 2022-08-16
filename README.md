<p>Hay que iniciar en un estado de configuración con un estado de isBombon == false, el conteo regresivo uint32_t COUNT debe ser de 20000 ms </p>
<p>Los pulsadores UP y DOWN aumentan o disminuyen el COUNT, el LED de bombaContando esta en HIGH </p>
<p> COUNT se puede programar entre 10000 y 60000 ms con cambios de 1000 ms </p>
<p>El tiempo de config debe visualisarse en el serial (serial.write) </p>
<p> el pulsador ARM cambia al estado BOMBISARMED </P>
<p> en el estado BOMBISARMED, comienza la cuenta regresiva de COUNT , el led bombaContando enciende y apaga con frecuencia de 1 hz </p>
<p>una vez COUNT sea 0, la bomba explotará y el led bombaExplosión se activará)
<p> en el estado BOMBISARMED, podrá ser desactivada ingresando una secuencia de pulsadores :UP, DOWN, UP DOWN, UP, UP, ARM </P>
<P>la clave de la bomba se almacena en claveBomba[] </p>
<p>una función con la dirección de memoria de dos arreglos, uno con la clave recibida y otro con la clave correcta, la funcipon devuelve un bool == TRUE si ambas claves coinciden, y FALSE de lo contrario</p>