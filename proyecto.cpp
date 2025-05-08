#include<iostream>
#include <limits>
using namespace std;
#include"listaAlbumes.h"
#include"listaArtistas.h"
#include"listaCanciones.h"
#include"listaGenerosMusicales.h"
#include"listaPlaylist.h"
#include"listaSelloDiscografico.h"

listaCanciones* lista_canciones = new listaCanciones();
listaArtistas* lista_artista = new listaArtistas();
listaAlbumes* lista_albumes = new listaAlbumes();
listaGenerosMusicales* lista_generos = new listaGenerosMusicales();
listaPlaylist* lista_playlist = new listaPlaylist();
listaSelloDiscografico* lista_sellos = new listaSelloDiscografico();


int obtenerEntero(string mensaje) {
    int numero;
    while (true) {
        cout << mensaje;
        cin >> numero;

        if (cin.fail()) {
            cout << "Error: Ingrese solo números enteros.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descarta la entrada incorrecta
        } else {
            return numero;
        }
    }
}

void imprimirTodasLasListas() {
    lista_artista->imprimir();
    lista_albumes->imprimir();
    lista_canciones->imprimir();
    //lista_generos imprimir();
    //lista_playlist imprimir();
    //lista_sellos imprimir();
}

void reporteDetalleArtistas() {
    //listaArtistas->imprimirConDetalle();
}

void reportePlaylists() {
    //listaPlaylists->imprimirConCanciones();
}

void reporteAlbumesOrdenados() {
    //listaAlbumes->imprimirOrdenadosPorDuracion();
}

void reporteSellosConArtistas() {
    //listaSellos->imprimirConArtistas();
}


void GeneroConMasCanciones() {
    lista_generos->generoMasCanciones();
}

void ArtistaConMasAlbumes() {
    lista_artista->artistaMasAlbumes();
}

void CancionMasLarga() {
    lista_canciones->cancionMasLarga();
}

void PlaylistMasCanciones() {
    lista_playlist->playlistMasCanciones();
}

void CantidadAlbumesPorArtista() {
    lista_artista->CantidadAlbumesPorArtista();
}

void SelloMasArtistas() {
    lista_sellos->selloConMasArtistas();
}

void CancionesPorAnio() {
    int anno = obtenerEntero("Ingrese el año: ");
    lista_canciones->cancionesPublicadas(anno);
}

void AlbumesConMasCanciones() {
    int numero = obtenerEntero("Ingrese el numero de canciones a superar: ");
    lista_albumes->AlbumesConCancionesMayores(numero);
}

void menuCRUD_Artistas() {
    // Similar a tu `menuGEntrenador`
}

void menuCRUD_Albumes() {
    // Similar pero enfocado en agregar, modificar y eliminar álbumes
}

void menuCRUD_Canciones() {
    // CRUD para canciones
}

void menuCRUD_Generos() {
    // CRUD para géneros musicales
}

void menuCRUD_Playlists() {
    // CRUD para playlists y su contenido
}

void menuCRUD_Sellos() {
    // CRUD para sellos discográficos
}



void menuReportes() {
    int opcion;
    do {
        cout << "\n--- REPORTES ---\n";
        cout << "1. Imprimir todas las listas\n";
        cout << "2. Detalle de artistas con álbumes, canciones y sello\n";
        cout << "3. Listado de playlists y sus canciones\n";
        cout << "4. Álbumes con canciones ordenadas por duración\n";
        cout << "5. Sellos y sus artistas firmados\n";
        cout << "0. Volver\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: imprimirTodasLasListas(); break;
            case 2: reporteDetalleArtistas(); break;
            case 3: reportePlaylists(); break;
            case 4: reporteAlbumesOrdenados(); break;
            case 5: reporteSellosConArtistas(); break;
            case 0: break;
            default: cout << "Opción inválida.\n";
        }
    } while (opcion != 0);
}


void menuConsultas() {
    int opcion;
    do {
        cout << "\n--- CONSULTAS ---\n";
        cout << "1. Género con más canciones\n";
        cout << "2. Artista con más álbumes\n";
        cout << "3. Canción más larga\n";
        cout << "4. Playlist con más canciones\n";
        cout << "5. Álbumes por artista\n";
        cout << "6. Sello con más artistas\n";
        cout << "7. Canciones por año\n";
        cout << "8. Álbumes con más de X canciones\n";
        cout << "0. Volver\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: GeneroConMasCanciones(); break;
            case 2: ArtistaConMasAlbumes(); break;
            case 3: CancionMasLarga(); break;
            case 4: PlaylistMasCanciones(); break;
            case 5: CantidadAlbumesPorArtista(); break;
            case 6: SelloMasArtistas(); break;
            case 7: CancionesPorAnio(); break;
            case 8: AlbumesConMasCanciones(); break;
            case 0: break;
            default: cout << "Opción inválida.\n";
        }
    } while (opcion != 0);
}


void menuMantenimiento() {
    int opcion;
    do {
        cout << "\n--- MANTENIMIENTO ---\n";
        cout << "1. Artistas\n";
        cout << "2. Álbumes\n";
        cout << "3. Canciones\n";
        cout << "4. Géneros Musicales\n";
        cout << "5. Playlists\n";
        cout << "6. Sellos Discográficos\n";
        cout << "0. Volver\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: menuCRUD_Artistas(); break;
            case 2: menuCRUD_Albumes(); break;
            case 3: menuCRUD_Canciones(); break;
            case 4: menuCRUD_Generos(); break;
            case 5: menuCRUD_Playlists(); break;
            case 6: menuCRUD_Sellos(); break;
            case 0: break;
            default: cout << "Opción inválida.\n";
        }
    } while (opcion != 0);
}


void menuPrincipal() {
    int opcion;
    do {
        cout << "\n====== MENÚ PRINCIPAL ======\n";
        cout << "1. Mantenimiento\n";
        cout << "2. Consultas\n";
        cout << "3. Reportes\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: menuMantenimiento(); break;
            case 2: menuConsultas(); break;
            case 3: menuReportes(); break;
            case 0: cout << "Saliendo del sistema...\n"; break;
            default: cout << "Opción inválida.\n";
        }
    } while (opcion != 0);
}

