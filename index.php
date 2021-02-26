<?php

    $bdd = new PDO('mysql:host=localhost;dbname=projet_poo_js', 'root', '');

    if(isset($_POST['inscription']))
    {
        $pseudo = htmlspecialchars($_POST['pseudo']);
        $mail = htmlspecialchars($_POST['mail']);
        $mail2 = htmlspecialchars($_POST['mail2']);
        $mdp = sha1($_POST['mdp']);
        $mdp2 = sha1($_POST['mdp2']);

            if(!empty($_POST['pseudo']) AND !empty($_POST['mail']) AND !empty($_POST['mail2']) AND !empty($_POST['mdp']) AND !empty($_POST['mdp2']))
            {
                $pseudoLenght = strlen($pseudo);
                if($pseudoLenght >= 2)
                {
                    $reqPseudo = $bdd->prepare('SELECT * FROM espace_membre WHERE pseudo = ?');
                    $reqPseudo->execute(array($pseudo));
                    $pseudoExist = $reqPseudo->rowCount();

                    if($pseudoExist == 0)
                    {
                        if($mail == $mail2)
                        {
                            if(filter_var($mail, FILTER_VALIDATE_EMAIL))
                            {
                                $reqMail = $bdd->prepare('SELECT * FROM espace_membre WHERE mail = ?');
                                $reqMail->execute(array($mail));
                                $mailExist = $reqMail->rowCount();
                                
                                if($mailExist == 0)
                                {
                                    if($mdp == $mdp2)
                                    {
                                        $validMember = $bdd->prepare('INSERT INTO espace_membre(pseudo, mail, mdp) VALUES (?, ?, ?)');
                                        $validMember->execute(array($pseudo, $mail, $mdp));
                                        $erreur = "Votre compte à bien été créé.";
                                    } else
                                    {
                                        $erreur = "Vos mot de passe ne correspondent pas.";
                                    }
                                } else
                                {
                                    $erreur = "Votre adresse mail déjà utilisée.";
                                }
                            } else
                            {
                                $erreur = "Veuillez entrer une adresse mail valide.";
                            }
                        } else
                        {
                            $erreur = "Vos adresses mails ne correspondent pas.";
                        }
                    }else
                    {
                        $erreur = "Votre pseudo est déjà utilisé";
                    }
                } else
                {
                    $erreur = "Votre pseudo est trop court.";
                }

            } else 
            {
                $erreur = "Tous les champs doivent être remplis.";
            }
    }
?>

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="style.css">
    <title>Inscription</title>
</head>

<body>
    <div align="center">

        <h2>Inscription</h3>

        <!-- formulaire d'inscription-->

        <form method="POST" action="">

            <table>
                <tr>
                    <td>
                        <label for="pseudo"> Pseudo : </label>
                        <input type="text" placeholder="Votre pseudo" name="pseudo" id="pseudo" value="<?php if(isset($pseudo)) { echo $pseudo; }?>"/>
                    </td>
                </tr>

                <tr>
                    <td>
                        <label for="mail"> Mail : </label>
                        <input type="email" placeholder="Votre mail" name="mail" id="mail"  value="<?php if(isset($mail)) { echo $mail; }?>"/>
                    </td>
                </tr>

                <tr>
                    <td>
                        <label for="mail2"> Confirmation du mail : </label>
                        <input type="email" placeholder="Confirmez votre mail" name="mail2" id="mail2"  value="<?php if(isset($mail2)) { echo $mail2; }?>" />
                    </td>
                </tr>

                <tr>
                    <td>
                        <label for="mdp"> Mot de passe : </label>
                        <input type="password" placeholder="Votre mot de passe" name="mdp" id="mdp"  value="<?php if(isset($mdp)) { echo $mdp; }?>" />
                    </td>
                </tr>

                <tr>
                    <td>
                        <label for="mdp2"> Confirmation du mot de passe : </label>
                        <input type="password" placeholder="Confirmez votre mot de passe" name="mdp2" id="mdp2"  value="<?php if(isset($mdp2)) { echo $mdp2; }?>"/>
                    </td>
                </tr>
                <tr>
                    <td>
                        <input type="submit" name="inscription" value="S'inscrire">
                    </td>
                </tr>
            </table>
        </form>

        <?php
            if(isset($erreur))
            {
                echo '<strong><font color="red">'.$erreur.'</font></strong>';
            }
        ?>

    </div>
</body>

</html>