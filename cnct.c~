/*
   mtcs - a multithreaded chat serveur
   Philippe Marquet, Apr 2005

   Gestion de la connexion d'un client par un thread
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>

#include "config.h"
#include "tools.h"
#include "cnct.h"

/* Gestion des sockets */
static int sockets[MAX_CONNECTION]; /* tableau initialisé a zero */

static void
add_socket(int fd)
{
    int i;

    pgrs_in();
    for (i=0; i<MAX_CONNECTION; i++) {
        if (sockets[i] == 0) {
            sockets[i] = fd;
            break;
        }
    }
    assert(i!=MAX_CONNECTION);
    pgrs_out();
}

static void
del_socket(int fd)
{
    int i;

    pgrs_in();
    for (i=0; i<MAX_CONNECTION; i++) {
        if (sockets[i] == fd) {
            sockets[i] = 0;
            break;
        }
    }
    assert(i!=MAX_CONNECTION);
    pgrs_out();
}

/* Un client  */
static void
repeater(int sckt)
{
    char buf[MAX_BUFFER];
    int nbc, i;
    const char WELCOME[] = "mtcs : bienvenu\n";

    pgrs_in();
    write(sckt, WELCOME, strlen(WELCOME));

    pgrs("enregistrement d'une socket");
    add_socket(sckt);

    while (1) {
        pgrs("attente read");
        nbc = read(sckt, buf, MAX_BUFFER);
        if (nbc <= 0) {
            pgrs("fin lecture client");
            pgrs("desenregistrement d'une socket");
            del_socket(sckt);
            close(sckt);
            pgrs_out();
            return;
        }
        pgrs("boucle ecriture");
        for(i=0; i<MAX_CONNECTION; i++)
            if (sockets[i])
                write(sockets[i], buf, nbc);
        pgrs("fin boucle ecriture");
    }
}

/* Création d'un client */
/* Version stupide. Pas de creation de thread,
   Le serveur ne peut plus accepter de connexion car il gère
   l'interaction avec le premier client.
*/
int
manage_cnct(int fd)
{
    pgrs_in();

    repeater(fd);

    pgrs_out();
    return 0;
}
