// Armado con templates para que le cambien "Clase" por lo que sea que quieran usar.
// Si usan esta funcion CON el template, al crearla, deben pasarle al parametro de
// tipo la CLASE, no el **, ya que la template va a armar sola el doble puntero.

/// Ejemplo: AmpliarVector<Padre>(ArrayPadre, maxArray);

// Version 0: no se si anda
template <class Clase>
void AmpliarVector(Clase &arrayViejo, int &max)
{
    // Aumentamos x2 el maximo del array.
    int newMax = max*2;
    // Creamos un nuevo array de punteros, pero con el doble de tamanio.
    Clase newArray = new Clase[newMax]; 
    // Copiamos los datos del array viejo dentro del array nuevo
    for (int i = 0; i < max; i++)
        newArray[i] = arrayViejo[i];
    // Liberamos la memoria del array viejo
    delete[] arrayViejo;
    // Actualizamos el max, y el array viejo
    arrayViejo = newArray;
    max = newMax;
}


// Version 1:
// Recibe por parametro un doble puntero a una clase, y un maximo. 
// Amplia el array x2.
template <class Clase>
void AmpliarVector(Clase ** &arrayViejo, int &max)
{
    // Aumentamos x2 el maximo del array.
    int newMax = max*2;
    // Creamos un nuevo array de punteros, pero con el doble de tamanio.
    Clase ** newArray = new Clase*[newMax]; 
    // Copiamos los datos del array viejo dentro del array nuevo
    for (int i = 0; i < max; i++)
        newArray[i] = arrayViejo[i];
    // Liberamos la memoria del array viejo
    delete[] arrayViejo;
    // Actualizamos el max, y el array viejo
    arrayViejo = newArray;
    max = newMax;
}

// Version 2:
// Pasamos el nuevo maximo que tendra el vector por parametros.
template <class Clase>
void AmpliarVector(Clase ** &arrayViejo, int &max, int nuevoMax)
{
    // Creamos un nuevo array de punteros, pero con el doble de tamanio.
    Clase ** newArray = new Clase*[nuevoMax]; 
    // Copiamos los datos del array viejo dentro del array nuevo
    for (int i = 0; i < max; i++)
        newArray[i] = arrayViejo[i];
    // Liberamos la memoria del array viejo
    delete[] arrayViejo;
    // Actualizamos el max, y el array viejo
    arrayViejo = newArray;
    max = nuevoMax;
}

// Version 3:
// Retorna por parametros el nuevo array.
template <class Clase>
Clase ** AmpliarVector(Clase ** &arrayViejo, int &max)
{
    int nuevoMax = max*2;
    // Creamos un nuevo array de punteros, pero con el doble de tamanio.
    Clase ** newArray = new Clase*[nuevoMax]; 
    // Copiamos los datos del array viejo dentro del array nuevo
    for (int i = 0; i < max; i++)
        newArray[i] = arrayViejo[i];
    // Liberamos la memoria del array viejo
    delete[] arrayViejo;
    // Actualizamos el max.
    max = nuevoMax;

    return newArray;
}

// Version 4:
// Retorna por parametros el nuevo array y controla el nuevo max por parametros.
template <class Clase>
Clase ** AmpliarVector(Clase ** &arrayViejo, int &max, int nuevoMax)
{
    // Creamos un nuevo array de punteros, pero con el doble de tamanio.
    Clase ** newArray = new Clase*[nuevoMax]; 
    // Copiamos los datos del array viejo dentro del array nuevo
    for (int i = 0; i < max; i++)
        newArray[i] = arrayViejo[i];
    // Liberamos la memoria del array viejo
    delete[] arrayViejo;
    // Actualizamos el max.
    max = nuevoMax;

    return newArray;
}
