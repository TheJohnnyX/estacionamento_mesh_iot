<?php
try {
	$db = new PDO('mysql:host=localhost;dbname=exercicio_php;charset=utf8mb4', "root", "1234");
}
catch (PDOException $err)
{
	echo 'Erro ao conectar com o MySQL: ' . $err->getMessage();
	exit;
}
