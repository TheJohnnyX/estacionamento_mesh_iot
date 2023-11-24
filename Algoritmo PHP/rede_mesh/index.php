<?php require_once "includes/db.php";?>
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css" integrity="sha384-BVYiiSIFeK1dGmJRAkycuHAHRg32OmUcww7on3RYdg4Va+PmSTsz/K68vbdEjh4u" crossorigin="anonymous">
  <meta http-equiv="refresh" content="3" > 
  <title>Rede mesh</title>
  <style>
    table, th, td {border:1px solid black;}
    td { padding: 6px; font-size: 40px}
    th { text-align: center; font-size: 20px}
  </style>
</head>
<body>
  <div class="container">
    <main style="padding: 21px;">
      <h1 align="center"><strong>STATUS DAS VAGAS</strong></h1>
      <br><br>
      <?php
      	$query = $db->query("SELECT * FROM mesh_network");
      	$rows = $query->fetchAll(PDO::FETCH_ASSOC);
      ?>
      <table align="center" border="1" cellpadding="0" cellspacing="0" width="40%" height="100px" id="backgroundTable">
        <tr>
          <th align="center">Vaga</th>
          <th align="center">Estado</th>
        </tr>
        <?php foreach ($rows as $node):?>
          <?php 
            if ($node['state'] == 1) {
              $icon = "content/images/red-circle-icon.png";
            } 
            else {
              $icon = "content/images/green-circle-icon.png";
            }
          ?>
          <tr>
            <td align="center"><strong><?php echo $node['node']; ?></strong></td>
            <td align="center"><img src='data:image/png;base64,<?php echo base64_encode(file_get_contents("$icon")); ?>'></td>
          </tr>
        <?php endforeach;?>
        </table>
    </main>
    <br>
    <?php require_once "includes/footer.php";?>
  </div>
</body>
</html>
