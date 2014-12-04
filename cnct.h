/*
   mtcs - a multithreaded chat serveur
   Philippe Marquet, Apr 2005

   Gestion de la connexion d'un client par un thread
*/

#ifndef _CNCT_H_
#define _CNCT_H_

/*  Crée un thread qui va
    - enregistrer le descripteur fd comme celui d'un nouveau client
    - puis lire en boucle sur la socket identifiée par fd et répéter
      sur l'ensemble des sockets des autres clients
    Retourne une valeur non nulle si erreur.
*/
extern int manage_cnct(int fd);

#endif
