<?php
    session_start();
    $array;
    $_SESSION['i'];
    
    if($_SESSION['i'] == NULL){
        $_SESSION['i'] = 0;
    }
    
    $nome = $_POST['nome'];
    $categoria = $_POST['categoria'];
    $hp = $_POST['hp'];
    $mana = $_POST['mana'];
    $forca = $_POST['forca'];
    $resistencia = $_POST['resistencia'];
    
    $array = ['nome' =>$nome, 'categoria' =>$categoria, 'hp' =>$hp, 'mana' =>$mana, 'forca' =>$forca, 'resistencia' =>$resistencia];
    
    $_SESSION['array'][$_SESSION['i']] = $array;
    $_SESSION['i']++;
    
    header('Location: ./index.html');

?>