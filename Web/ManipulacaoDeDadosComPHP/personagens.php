<?php

$descricao[] = [
    'Guerreiro'=>'O guerreiro é um personagem humano destinado à proteger seu rei não se importando como fará isso, ele tem grandes habilidades com armas de curto alcance, e tem vantagem contra Bruxos e desvantagem contra Caçadores', 
    
    'Mago'=>'O mago é um personagem humano que nasceu com o dom de manipular a magia para seus fins, são pácificos e normalmente preferem não se envolver em conflitos e guerras, mas podem destruir reinos e imperios se assim desejarem. Tem vantagem contra Druidas e desvantagem contra Elfos',

    'Paladino'=> 'O paladino é um personagem humano que tem a habilidade de manipular armas divinas são os únicos que podem realizar tal ato, tem vantagem contra Elfos e desvantagem contra Goblins',

    'Druida'=>'O druida é um personagem humano que tem um imenso conhecimento sobre a vida e a natureza, conhecendo segredos mortos e ocultos, tem grande habilidade para preparar remédios e venenos. Tem vantagem contra Goblins e desvantagem contra Magos e Bruxos',

    'Caçador'=>'O caçador é um personagem humano que tem grande habilidade com armas de longo alcance, técnicas de camuflagem e um exímia determinação, raramente desistem de seus objetivos. Tem vantagem contra Guerreiros e desvantagem contra Assassinos',

    'Bruxo'=>'O bruxo é um personagem humano que consegue canaliza as forças das trevas, através de feitiços, encantamentos, rituais e objetos amaldiçoados. A alma dos bruxos é totalmente corrompida pelas forças das trevas, há quem diga que muitos deles nem conseguem mais controlar seus atos. Tem vantagem contra Assassinos e desvantagem contra Guerreiros e Druidas',

    'Elfos'=>'Os Elfos são seres descendentes das fadas, tem uma enorme ligação com a natureza e ela atende à seus desejos, dedicam suas vidas à proteger a natureza e não se importam em morrer por isso. Odeiam Druidas por eles saberem de segredos que só os elfos deveriam saber. Tem vantagem contra Magos e desvantagem contra Paladinos',

    'Goblins'=>'Os Goblins são seres descendentes dos ogros, optam por viver nas profundezas das florestas de onde quem os imcomoda não costuma retornar. Tem uma força colossal e são muito bons com flechas e lanças. Tem vantagem contra Paladinos e desvantagem contra Druidas',

    'Assassinos'=>'São as criaturas mais temidas, tem grandes conhecimentos em armas de curto e longo alcance, defesa contra magia e técnicas de camuflagem. São muito raros e silenciosos, tem uma aparência pálida, não se importam motivações nem justiça se importam apenas com seu dinheiro, não pagar o valor correto a um assassino é pior do que encomendar à propria morte para ele. Tem vantagem contra Caçadores e Magos e desvantagem contra Bruxos',
];

for ($i=0; $i < 10; $i++) { 
    echo "Nome: " . $array[$i]['nome'] . "<br>";
}


?>