#include<iostream>
#include <limits>
using namespace std;
#include"listaAlbumes.h"
#include"listaArtistas.h"
#include"listaCanciones.h"
#include"listaGenerosMusicales.h"
#include"listaPlaylist.h"
#include"listaSelloDiscografico.h"

listaCanciones lista_canciones = new listaCanciones();
listaArtistas lista_artista = new listaArtistas();
listaAlbumes lista_albumes = new listaAlbumes();
listaGenerosMusicales lista_generos = new listaGenerosMusicales();
listaPlaylist lista_playlist = new listaPlaylist();
listaSelloDiscografico lista_sellos = new listaSelloDiscografico();


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
    lista_generos->imprimir();
    lista_playlist->imprimir();
    lista_sellos->imprimir();
}

void reporteDetalleArtistas() {
    listaArtistas->imprimirConDetalle();
}

void reportePlaylists() {
    listaPlaylists->imprimirConCanciones();
}

void reporteAlbumesOrdenados() {
    listaAlbumes->imprimirOrdenadosPorDuracion();
}

void reporteSellosConArtistas() {
    listaSellos->imprimirConArtistas();
}


void GeneroConMasCanciones() {
    lista_generos.generoMasCanciones();
}

void consultaArtistaConMasAlbumes() {
    lista_artista.artistaMasAlbumes();
}

void consultaCancionMasLarga() {
    lista_canciones.cancionMasLarga();
}

void PlaylistMasCanciones() {
    lista_playlist.playlistMasCanciones();
}

void CantidadAlbumesPorArtista() {
    lista_artista.CantidadAlbumesPorArtista();
}

void consultaSelloMasArtistas() {
    lista_sellos.selloConMasArtistas();
}

void consultaCancionesPorAnio() {
    int anno = obtenerEntero("Ingrese el año: ");
    lista_canciones.cancionesPublicadas(anno);
}

void consultaAlbumesConMasCanciones() {
    int numero = obtenerEntero("Ingrese el numero de canciones a superar: ");
    lista_albumes.AlbumesConCancionesMayores(numero);
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
            case 1: consultaGeneroConMasCanciones(); break;
            case 2: consultaArtistaConMasAlbumes(); break;
            case 3: consultaCancionMasLarga(); break;
            case 4: consultaPlaylistMasCanciones(); break;
            case 5: consultaAlbumesPorArtista(); break;
            case 6: consultaSelloMasArtistas(); break;
            case 7: consultaCancionesPorAnio(); break;
            case 8: consultaAlbumesConMasCanciones(); break;
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

