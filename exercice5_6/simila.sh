#!/bin/sh

affichesim=false
#on crée une varible pour la fonction v 

if [ $1 = "-v" ]
then 
    affichesim=true
    shift
fi
#on verifie si l'option v est activée, on ajoute un shift pour ne plus avoir à prendre en compte l'option 

if [ $# -ne 2 ]
then
    echo " il faut deux fichiers en arguments sans ou avec l'option -v "
    exit 
fi
# on vérifie que l'on a bien deux arguments qui vont être comparés puis on vérifie que nos arguements sont des fichiers

if [ ! -f $1 ] || [ ! -f $2 ]
then
    echo "les arguments doivent être des fichers"
    exit 2
fi

mkdir tmp
#on crée un fichier tmp pour y crée nos fichiers temporaires

#on crée une fonction pour l'algorithme optimisé: pour cette algorithme on utilise la commande comm (inverse de diff) qui nous renvoie les lignes communes, on utilise sort sinon la commande ne fonctionne pas correctement; enfin, si l'option v est activé on affiche les lignes communes
opti () { 
    sort $1 > tmp/fichier1
    sort $2 > tmp/fichier2
    comm -12 tmp/fichier1 tmp/fichier2 > tmp/comparaison
    if $affichesim
    then
	cat tmp/comparaison
    fi
}

if $affichesim
then
    opti $1 $2 
    exit 1
fi
# si l'option v est activée, on utilise tout de suite l'algorithme optimisé et on arrete le script

#pour obtenir le temps d'exécuttion des algorithmes on va utilise l'option +%s de la commande date
date1=`date +%s`
n=`cat $1 | wc -l `
i=1
# on initilalise les les variables n=nombre de ligne, et i qui va être le numéro de la ligne comparé et on commence notre boucle while
while [ $i -gt $n ]
do
#on crée deux variable a qui contient la ligne avec le numéro voulu dans le fichier puis on le on le cherche dans le second
    a=`sed -n "${i}p" $1`
    b=`grep "$a" $2 `
    i=$(( i + 1 ))
done
date2=`date +%s`

date=$(( date2 - date1))
# on calcule le temps d'éxécution du premier algorithme

time1=`date +%s`
opti $1 $2 
time2=`date +%s`
time=$(( time2 - time1))
#on calcule de temps d'éxécution du second algorithme
taille=`ls -lt $2 | tr -s " " | cut -d  " " -f5`
#on crée un variable pour la taille du second fichier pour le cas ou l'option v n'est pas activée


echo "$taille $date $time" >> info_graph
# on ajoute les variables dans un fichier qu'on utilisera pour faire un graphe

./graphe.sh info_graph

rm -dr tmp/
#on supprime nos fichiers temporaires
