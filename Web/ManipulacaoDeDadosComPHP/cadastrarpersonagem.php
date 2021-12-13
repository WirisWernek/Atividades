<?php
$i = 0;
$array[10];

$nome = $_POST['nome'];
$categoria = $_POST['categoria'];
$hp = $_POST['hp'];
$mana = $_POST['mana'];
$forca = $_POST['forca'];
$resistencia = $_POST['resistencia'];

$array[$i] = ['nome' =>$nome, 'categoria' =>$categoria, 'hp' =>$hp, 'mana' =>$mana, 'forca' =>$forca, 'resistencia' =>$resistencia];
$i++;
for ($i=0; $i < 10; $i++) { 
    echo "Nome: " . $array[$i]['nome'] . "<br>";
}

 header('Location: ./index.html');

?>