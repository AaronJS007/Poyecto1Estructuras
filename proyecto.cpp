#include <iostream>
#include <limits>
using namespace std;
#include "listaAlbumes.h"
#include "listaArtistas.h"
#include "listaCanciones.h"
#include "listaGenerosMusicales.h"
#include "listaPlaylist.h"
#include "listaSelloDiscografico.h"

listaCanciones *lista_canciones = new listaCanciones();
listaArtistas *lista_artista = new listaArtistas();
listaAlbumes *lista_albumes = new listaAlbumes();
listaGenerosMusicales *lista_generos = new listaGenerosMusicales();
listaPlaylist *lista_playlist = new listaPlaylist();
listaSelloDiscografico *lista_sellos = new listaSelloDiscografico();

int obtenerEntero(string mensaje)
{
    int numero;
    while (true)
    {
        cout << mensaje;
        cin >> numero;

        if (cin.fail())
        {
            cout << "Error: Ingrese solo numeros enteros.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descarta la entrada incorrecta
        }
        else
        {
            return numero;
        }
    }
}

void imprimirTodasLasListas()
{
    cout << "=====Lista de artistas =====" << endl;
    lista_artista->imprimirSimple();
    cout << "=====Lista de albumes =====" << endl;
    lista_albumes->imprimirSimple();
    cout << "=====Lista de canciones =====" << endl;
    lista_canciones->imprimirSimple();
    cout << "=====Lista de generos =====" << endl;
    lista_generos->imprimirSimple();
    cout << "=====Lista de playlist =====" << endl;
    lista_playlist->imprimirSimple();
    cout << "=====Lista de sellos =====" << endl;
    lista_sellos->imprimirSimple();
}

void reporteDetalleArtistas()
{
    lista_artista->imprimir();
}

void reportePlaylists()
{
   lista_playlist->imprimir();
}

void reporteAlbumesOrdenados()
{
    lista_albumes->imprimir();
}

void reporteSellosConArtistas()
{
    lista_sellos->imprimir();
}

void GeneroConMasCanciones()
{
    lista_generos->generoMasCanciones();
}

void ArtistaConMasAlbumes()
{
    lista_artista->artistaMasAlbumes();
}

void CancionMasLarga()
{
    lista_canciones->cancionMasLarga();
}

void PlaylistMasCanciones()
{
    lista_playlist->playlistMasCanciones();
}

void CantidadAlbumesPorArtista()
{
    lista_artista->CantidadAlbumesPorArtista();
}

void SelloMasArtistas()
{
    lista_sellos->selloConMasArtistas();
}

void CancionesPorAnio()
{
    int anno = obtenerEntero("Ingrese el anio: ");
    lista_canciones->cancionesPublicadas(anno);
}

void AlbumesConMasCanciones()
{
    int numero = obtenerEntero("Ingrese el numero de canciones a superar: ");
    lista_albumes->AlbumesConCancionesMayores(numero);
}

void agregarCancionesPlaylist(){
    int idPlaylist = obtenerEntero("Digite el ID de la playlist: ");
    playlist* pl = lista_playlist->buscar(idPlaylist);

    if (pl == nullptr) {
        cout << "Playlist no encontrada.\n";
        return;
    }

    int idCancion;
    while (true) {
        idCancion = obtenerEntero("Digite el ID de la cancion que desea agregar (0 para salir): ");
        if (idCancion == 0) break;

        cancion * cancion = lista_canciones->buscar(idCancion); // metodo para buscar cancion por ID
        if (cancion == nullptr) {
            cout << "Cancion no encontrada.\n";
        } else {
            if (pl->lstCanciones->incercionInicio(cancion)) {
                cout << "Cancion agregada exitosamente a la playlist.\n";
            } else {
                cout << "La cancion ya esta en la playlist o ocurrio un error.\n";
            }
        }
    }
}

// metodos para crear

void crearArtista()
{
    int id, sello;
    string nombreArt, nombreReal, pais;
    id = obtenerEntero("Ingrese ID: ");
    cin.ignore();
    cout << "Ingrese nombre artistico: ";
    cin >> nombreArt;
    cout << "Ingrese nombre real: ";
    cin >> nombreReal;
    cout << "Ingrese pais: ";
    cin >> pais;
    sello = obtenerEntero("Ingrese ID del sello discografico: ");
    artista *nuevo = new artista(id, nombreArt, nombreReal, pais, sello);
    if (lista_sellos->AgregarArtistaAlSello(nuevo))
    {
        if (lista_artista->insertarArtista(nuevo))
        {
            cout << "Artista agregado exitosamente.\n";
        }
        else
        {
            cout << "Ya existe un artista con ese ID o error al insertar.\n";
            delete nuevo;
        }
    }
    else
    {
        cout << "\nNo hay un sello con el ID: " << nuevo->selloDiscografico;
        delete nuevo;
    }
}
void crearGenero(cancion* nueva)
{
    int IdGeneroMusical;
    string nombre, descripcion;

    cin.ignore();
    cout << "Digite el nombre del Genero: ";
    cin >> nombre;

    if (nueva != nullptr)
    {
        if (lista_generos->AgregarCancionGenero(nueva, nombre))
        {
            cout << "Cancion agregada con exito.\n";
        }
        else
        {
            int opcion;
            while (true)
            {
                cout << "\n--- No existe el genero ---\n";
                cout << "1. Agregar nuevo genero\n";
                cout << "0. Volver al menu principal\n";
                cout << "Seleccione una opcion: ";
                cin >> opcion;

                if (opcion == 1)
                {
                    IdGeneroMusical = obtenerEntero("Digite el ID del nuevo genero: ");
                    cin.ignore(); 
                    cout << "Digite la descripcion del genero: ";
                    cin >> descripcion;

                    if (lista_generos->agregarFinal(IdGeneroMusical,nombre,descripcion))
                    {
                        if (lista_generos->AgregarCancionGenero(nueva, nombre))
                        {
                            cout << "Se agrego correctamente el genero y la cancion.\n";
                        }
                        else
                        {
                            cout << "Error al agregar la cancion al genero.\n";
                        }
                    }
                    else
                    {
                        cout << "No se pudo agregar el genero.\n";
                    }
                    break;
                }
                else if (opcion == 0)
                {
                    return;
                }
                else
                {
                    cout << "Opcion invalida. Intente de nuevo.\n";
                }
            }
        }
    }
    else
    {
        IdGeneroMusical = obtenerEntero("Digite el ID del nuevo genero: ");
        cin.ignore();
        cout << "Digite la descripcion del genero: ";
        cin >> descripcion;

        if (lista_generos->agregarFinal(IdGeneroMusical, nombre, descripcion)){
            cout << "Genero agregado correctamente.\n";
        }
        else
        {
            cout << "No se pudo agregar el genero.\n";
        }
    }
}
void crearCancion()
{
    int id, idAlbum, anno, idArtista;
    float duracion;
    string titulo, compositor, nombreAlbum;

    id = obtenerEntero("Ingrese ID de la cancion: ");
    cin.ignore();
    cout << "Ingrese titulo de la cancion: ";
    cin >> titulo;
    duracion = obtenerEntero("Ingrese duracion (en minutos): ");
    cin.ignore();
    anno = obtenerEntero("Ingrese el anio que se creo: ");
    cout << "Ingrese nombre del compositor: ";
    cin >> compositor;
    idArtista = lista_artista->buscarArtistaPorNombre(compositor);
    cout << "Digite el nombre del album: ";
    cin >> nombreAlbum;
    idAlbum = lista_albumes->buscarArtistaPorNombre(nombreAlbum);
    if (idAlbum == -1 || idArtista == -1)
    {
        cout << "No existe el artista o el album" << endl;
        return;
    }
    cancion *nueva = new cancion(id, titulo, duracion, anno, idAlbum, idArtista);
    if (lista_albumes->incertarCancionAlbum(nueva) && lista_artista->incertarCancionArtista(nueva))
    {
        if (lista_canciones->incercionInicio(nueva))
        {
            cout << "Cancion agregada exitosamente.\n";
            crearGenero(nueva);
        }
        else
        {
            cout << "No se pudo agregar la cancion.\n";
            delete nueva;
        }
    }
    else
    {
        delete nueva;
    }
}
void crearAlbum()
{
    int IDAlbum, anno, numeroCanciones, idArtista;
    string titulo, nombreArtista;
    IDAlbum = obtenerEntero("Ingrese ID del album: ");
    cin.ignore();
    cout << "Ingrese titulo del Album: ";
    cin >> titulo;
    cout << "Ingrese el nombre del artista: ";
    cin >> nombreArtista;
    idArtista = lista_artista->buscarArtistaPorNombre(nombreArtista);
    anno = obtenerEntero("Ingrese el anio que se creo: ");

    album *nuevo = new album(IDAlbum, titulo, anno, 0, idArtista);

    if (lista_artista->incertarAlbumArtista(nuevo))
    {
        if (lista_albumes->incercionFinal(nuevo))
        {
            cout << "Album agregado exitosamente.\n";
        }
        else
        {
            cout << "No se pudo agregar la cancion.\n";
            delete nuevo;
        }
    }
    else
    {
        delete nuevo;
    }
}

void crearPlaylist()
{
    int Id, Fecha;
    string Nombre,Creador;
    Id=obtenerEntero("Digite el ID de la playlist: ");
    Fecha=obtenerEntero("Digite el anio en que se creo: ");
    cout << "Digite el nombre de la playlist: "; 
    getline(cin,Nombre);
    cout << "Digite el nombre del autor de la playlist: ";
    getline(cin,Creador);
    if(lista_playlist->incercionInicio(Id,Nombre,Creador,Fecha)){
        cout << "Se creo correctamente"<<endl;
    }else{
        cout << "No se pudo crear la playlist.\n";
    }
}
void crearSello() {
    int Id, Anno;
    string Nombre, Pais;

    Id = obtenerEntero("Ingrese el ID del sello discografico: ");
    cin.ignore();

    cout << "Ingrese el nombre del sello: ";
    getline(cin, Nombre);

    cout << "Ingrese el pais del sello: ";
    getline(cin, Pais);

    Anno = obtenerEntero("Ingrese el anio de fundacion del sello: ");

    if (lista_sellos->incercionFinal(Id, Nombre, Pais, Anno)) {
        cout << "Sello discografico agregado exitosamente.\n";
    } else {
        cout << "Ya existe un sello con ese ID o hubo un error al insertar.\n";
    }
}


// metodos para modificar
void modificarArtista()
{
    int id;
    string nombreArtistico, nombreReal, pais;
    id=obtenerEntero("Digite el id del artista: ");
    cout << "Digite el nuevo nombre artistico: ";
    cin >> nombreArtistico;
    cout << "Digite el nuevo nombre artistico: ";
    cin >> nombreReal;
    cout << "Digite el nuevo pais: ";
    cin >> pais;
    if(lista_artista->modificar(id,nombreArtistico,nombreReal,pais)){
        cout << "Se modifico correctamente"<<endl;
    }else{
        cout << "algo salio mal"<<endl;
    }
}
void modificarCancion() {
    int id, duracion, anio;
    string titulo;

    id = obtenerEntero("Digite el ID de la cancion: ");
    cin.ignore();
    cout << "Digite el nuevo titulo: ";
    getline(cin, titulo);
    duracion = obtenerEntero("Digite la nueva duracion en minutos: ");
    anio = obtenerEntero("Digite el nuevo anio de publicacion: ");

    if (lista_canciones->modificar(id, titulo, duracion, anio)) {
        cout << "Cancion modificada correctamente.\n";
    } else {
        cout << "Algo salio mal o la cancion no existe.\n";
    }
}

void modificarAlbum() {
    int id;
    string titulo;
    int anio;

    id = obtenerEntero("Digite el ID del album: ");
    cin.ignore();
    cout << "Digite el nuevo titulo del album: ";
    getline(cin, titulo);
    anio = obtenerEntero("Digite el nuevo anio de lanzamiento: ");

    if (lista_albumes->modificar(id, titulo, anio)) {
        cout << "album modificado correctamente.\n";
    } else {
        cout << "Algo salio mal o el album no existe.\n";
    }
}

void modificarGenero() {
    int id;
    string nombre, descripcion;

    id = obtenerEntero("Digite el ID del genero: ");
    cin.ignore();
    cout << "Digite el nuevo nombre del genero: ";
    getline(cin, nombre);
    cout << "Digite la nueva descripcion: ";
    getline(cin, descripcion);

    if (lista_generos->modificar(id, nombre, descripcion)) {
        cout << "Genero modificado correctamente.\n";
    } else {
        cout << "Algo salio mal o el genero no existe.\n";
    }
}

void modificarPlaylist() {
    int id;
    string nombre,creador;

    id = obtenerEntero("Digite el ID de la playlist: ");
    cin.ignore();
    cout << "Digite el nuevo nombre de la playlist: ";
    getline(cin, nombre);
    cout << "Digite el nuevo autor de la playlist: ";
    getline(cin, creador);

    if (lista_playlist->modificar(id, nombre,creador)) {
        cout << "Playlist modificada correctamente.\n";
    } else {
        cout << "Algo salio mal o la playlist no existe.\n";
    }
}

void modificarSello() {
    int id;
    string nombre, pais;

    id = obtenerEntero("Digite el ID del sello discografico: ");
    cin.ignore();
    cout << "Digite el nuevo nombre del sello: ";
    getline(cin, nombre);
    cout << "Digite el nuevo pais del sello: ";
    getline(cin, pais);

    if (lista_sellos->modificar(id, nombre, pais)) {
        cout << "Sello modificado correctamente.\n";
    } else {
        cout << "Algo salio mal o el sello no existe.\n";
    }
}

// metodos para eliminar
void eliminarArtista()
{
    int id;
    id=obtenerEntero("Digite el id: ");
    if(lista_artista->eliminar(id)){
        cout << "Se elimino correctamente"<<endl;
    }else{
        cout << "No se pudo elimnar"<<endl;
    }
}
void eliminarCancion()
{
    int id;
    id=obtenerEntero("Digite el id: ");
    if(lista_canciones->eliminar(id)){
        cout << "Se elimino correctamente"<<endl;
    }else{
        cout << "No se pudo elimnar"<<endl;
    }
}
void eliminarAlbum()
{
    int id;
    id=obtenerEntero("Digite el id: ");
    if(lista_albumes->eliminar(id)){
        cout << "Se elimino correctamente"<<endl;
    }else{
        cout << "No se pudo elimnar"<<endl;
    }
}
void eliminarGenero()
{
    int id;
    id=obtenerEntero("Digite el id: ");
    if(lista_generos->eliminar(id)){
        cout << "Se elimino correctamente"<<endl;
    }else{
        cout << "No se pudo elimnar"<<endl;
    }
}
void eliminarPlaylist()
{
    int id;
    id=obtenerEntero("Digite el id: ");
    if(lista_playlist->eliminar(id)){
        cout << "Se elimino correctamente"<<endl;
    }else{
        cout << "No se pudo elimnar"<<endl;
    }
}
void eliminarSello()
{
    int id;
    id=obtenerEntero("Digite el id: ");
    if(lista_sellos->eliminar(id)){
        cout << "Se elimino correctamente"<<endl;
    }else{
        cout << "No se pudo elimnar"<<endl;
    }
}

void menuCRUD_Artistas()
{
    int opcion;
    do
    {
        cout << "\n--- Menu CRUD Artistas ---\n";
        cout << "1. Agregar artista\n";
        cout << "2. Modificar artista\n";
        cout << "3. Eliminar artista\n";
        cout << "4. Ver todos los artistas\n";
        cout << "0. Volver al menu principal\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
        {
            crearArtista();
            break;
        }
        case 2:
        {
            modificarArtista();
            break;
        }
        case 3:
        {
            eliminarArtista();
            break;
        }
        case 4:
            lista_artista->imprimir();
            break;
        case 0:
            cout << "Saliendo del menu de artistas...\n";
            break;
        default:
            cout << "Opcion invalida. Intente de nuevo.\n";
        }

    } while (opcion != 0);
}

void menuCRUD_Albumes()
{
    int opcion;
    do
    {
        cout << "\n--- Menu CRUD Albumes ---\n";
        cout << "1. Agregar Album\n";
        cout << "2. Modificar Album\n";
        cout << "3. Eliminar Album\n";
        cout << "4. Ver todos los Album\n";
        cout << "0. Volver al menu principal\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
        {
            crearAlbum();
            break;
        }
        case 2:
        {
            modificarAlbum();
            break;
        }
        case 3:
        {
            eliminarAlbum();
            break;
        }
        case 4:
            lista_albumes->imprimir();
            break;
        case 0:
            cout << "Saliendo del menu de Albumes...\n";
            break;
        default:
            cout << "Opcion invalida. Intente de nuevo.\n";
        }

    } while (opcion != 0);
}

void menuCRUD_Canciones()
{
    int opcion;
    do
    {
        cout << "\n--- Menu CRUD Canciones ---\n";
        cout << "1. Agregar Canciones\n";
        cout << "2. Modificar Canciones\n";
        cout << "3. Eliminar Canciones\n";
        cout << "4. Ver todos los Canciones\n";
        cout << "0. Volver al menu principal\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
        {
            crearCancion();
            break;
        }
        case 2:
        {
            modificarCancion();
            break;
        }
        case 3:
        {
            eliminarCancion();
            break;
        }
        case 4:
            lista_canciones->imprimir();
            break;
        case 0:
            cout << "Saliendo del menu de Canciones...\n";
            break;
        default:
            cout << "Opcion invalida. Intente de nuevo.\n";
        }

    } while (opcion != 0);
}

void menuCRUD_Generos()
{
    int opcion;
    do
    {
        cout << "\n--- Menu CRUD Generos ---\n";
        cout << "1. Agregar Generos\n";
        cout << "2. Modificar Generos\n";
        cout << "3. Eliminar Generos\n";
        cout << "4. Ver todos los Generos\n";
        cout << "0. Volver al menu principal\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
        {
            crearGenero(nullptr);
            break;
        }
        case 2:
        {
            modificarGenero();
            break;
        }
        case 3:
        {
            eliminarGenero();
            break;
        }
        case 4:
            lista_generos->imprimir();
            break;
        case 0:
            cout << "Saliendo del menu de Generos...\n";
            break;
        default:
            cout << "Opcion invalida. Intente de nuevo.\n";
        }

    } while (opcion != 0);
}

void menuCRUD_Playlists()
{
    int opcion;
    do
    {
        cout << "\n--- Menu CRUD Playlists ---\n";
        cout << "1. Agregar Playlists\n";
        cout << "2. Modificar Playlists\n";
        cout << "3. Eliminar Playlists\n";
        cout << "4. Agregar Canciones a Playlist\n";
        cout << "5. Ver todos los Playlists\n";
        cout << "0. Volver al menu principal\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
        {
            crearPlaylist();
            break;
        }
        case 2:
        {
            modificarPlaylist();
            break;
        }
        case 3:
        {
            eliminarPlaylist();
            break;
        }
        case 4:
            agregarCancionesPlaylist();
            break;
        case 5:
            lista_playlist->imprimir();
            break;
        case 0:
            cout << "Saliendo del menu de Playlists...\n";
            break;
        default:
            cout << "Opcion invalida. Intente de nuevo.\n";
        }

    } while (opcion != 0);
}

void menuCRUD_Sellos()
{
    int opcion;
    do
    {
        cout << "\n--- Menu CRUD Sellos ---\n";
        cout << "1. Agregar Sellos\n";
        cout << "2. Modificar Sellos\n";
        cout << "3. Eliminar Sellos\n";
        cout << "4. Ver todos los Sellos\n";
        cout << "0. Volver al menu principal\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
        {
            crearSello();
            break;
        }
        case 2:
        {
            modificarSello();
            break;
        }
        case 3:
        {
            eliminarSello();
            break;
        }
        case 4:
            lista_sellos->imprimir();
            break;
        case 0:
            cout << "Saliendo del menu de Sellos...\n";
            break;
        default:
            cout << "Opcion invalida. Intente de nuevo.\n";
        }

    } while (opcion != 0);
}

void menuReportes()
{
    int opcion;
    do
    {
        cout << "\n--- REPORTES ---\n";
        cout << "1. Imprimir todas las listas\n";
        cout << "2. Detalle de artistas con albumes, canciones y sello\n";
        cout << "3. Listado de playlists y sus canciones\n";
        cout << "4. Albumes con canciones ordenadas por duracion\n";
        cout << "5. Sellos y sus artistas firmados\n";
        cout << "0. Volver\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            imprimirTodasLasListas();
            break;
        case 2:
            reporteDetalleArtistas();
            break;
        case 3:
            reportePlaylists();
            break;
        case 4:
            reporteAlbumesOrdenados();
            break;
        case 5:
            reporteSellosConArtistas();
            break;
        case 0:
            break;
        default:
            cout << "Opcion invalida.\n";
        }
    } while (opcion != 0);
}

void menuConsultas()
{
    int opcion;
    do
    {
        cout << "\n--- CONSULTAS ---\n";
        cout << "1. Genero con mas canciones\n";
        cout << "2. Artista con mas albumes\n";
        cout << "3. Cancion mas larga\n";
        cout << "4. Playlist con mas canciones\n";
        cout << "5. Albumes por artista\n";
        cout << "6. Sello con mas artistas\n";
        cout << "7. Canciones por anio\n";
        cout << "8. Albumes con mas de X canciones\n";
        cout << "0. Volver\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            GeneroConMasCanciones();
            break;
        case 2:
            ArtistaConMasAlbumes();
            break;
        case 3:
            CancionMasLarga();
            break;
        case 4:
            PlaylistMasCanciones();
            break;
        case 5:
            CantidadAlbumesPorArtista();
            break;
        case 6:
            SelloMasArtistas();
            break;
        case 7:
            CancionesPorAnio();
            break;
        case 8:
            AlbumesConMasCanciones();
            break;
        case 0:
            break;
        default:
            cout << "Opcion invalida.\n";
        }
    } while (opcion != 0);
}

void menuMantenimiento()
{
    int opcion;
    do
    {
        cout << "\n--- MANTENIMIENTO ---\n";
        cout << "1. Artistas\n";
        cout << "2. Albumes\n";
        cout << "3. Canciones\n";
        cout << "4. Generos Musicales\n";
        cout << "5. Playlists\n";
        cout << "6. Sellos Discograficos\n";
        cout << "0. Volver\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            menuCRUD_Artistas();
            break;
        case 2:
            menuCRUD_Albumes();
            break;
        case 3:
            menuCRUD_Canciones();
            break;
        case 4:
            menuCRUD_Generos();
            break;
        case 5:
            menuCRUD_Playlists();
            break;
        case 6:
            menuCRUD_Sellos();
            break;
        case 0:
            break;
        default:
            cout << "Opcion invalida.\n";
        }
    } while (opcion != 0);
}

void menuPrincipal()
{
    int opcion;
    do
    {
        cout << "\n====== MENU PRINCIPAL ======\n";
        cout << "1. Mantenimiento\n";
        cout << "2. Consultas\n";
        cout << "3. Reportes\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            menuMantenimiento();
            break;
        case 2:
            menuConsultas();
            break;
        case 3:
            menuReportes();
            break;
        case 0:
            cout << "Saliendo del sistema...\n";
            break;
        default:
            cout << "Opcion invalida.\n";
        }
    } while (opcion != 0);
}

int main()
{
    menuPrincipal();
    return 0;
}
