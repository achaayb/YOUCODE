# test_git

## Liste des commandes git

### Obtenir et créer des projets

|Commande|Info|
|---|---|
|git init|initialiser un dépôt git|
|git clone ssh://git@github.com/[username]/[repository-name].git|Créer une copie locale d'une repo git|

### Snapshotting

|Commande|Info|
|---|---|
|git status|Vérifier l'état du repo|
|git add FICHIER|Ajouter un fichier à la staging area|
|git commit -m "message"|Valider les modifications|

### Branchement et fusion

|Commande|Info|
|---|---|
|git branch|Lister les branches|
|git branch NOM|Créer une branch|
|git branch -d NOM|Supprimer une branche|
|git checkout NOM|basculer vers une branche|
|git merge SOURCE DESTINATION|fusionner deux branches|

### Partage et mise à jour des projets

|Commande|Info|
|---|---|
|git push origin BRANCHE|Poussez une branche vers votre référentiel distant|
|git pull origin BRANCHE|Extraire les modifications du référentiel distant|
|git remote add origin URL|Ajouter un référentiel distant|

### Inspection et comparaison

|Commande|Info|
|---|---|
|git log|Afficher les modifications|
|git diff SOURCE DESTINATION|différence entre deux branches|
