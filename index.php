<?php
require_once "config.php";

$stmt = $pdo->query(
    "SELECT Id, `Motion Detected`, Timestamp, Distance_cm
     FROM Motion_data ORDER BY Id DESC LIMIT 100"
);
$events = $stmt->fetchAll();

$total = $pdo->query(
    "SELECT COUNT(*) FROM Motion_data WHERE `Motion Detected` = 1"
)->fetchColumn();
?>
<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<meta http-equiv="refresh" content="10">
<title>KLIKU Motion Monitoring</title>
<link rel="stylesheet" href="style.css">
</head>
<body>
<main class="container">
<header>
<h1>KLIKU Cement Ltd</h1>
<p>Motion Sensing and Detection System</p>
</header>

<section class="card">
<span>Total detected events</span>
<strong><?php echo htmlspecialchars($total); ?></strong>
</section>

<section class="panel">
<h2>Recent Motion Events</h2>
<table>
<thead>
<tr>
<th>ID</th>
<th>Motion Detected</th>
<th>Distance (cm)</th>
<th>Timestamp</th>
</tr>
</thead>
<tbody>
<?php foreach ($events as $event): ?>
<tr>
<td><?php echo htmlspecialchars($event["Id"]); ?></td>
<td><?php echo (int)$event["Motion Detected"] === 1 ? "Detected" : "Clear"; ?></td>
<td><?php echo htmlspecialchars($event["Distance_cm"]); ?></td>
<td><?php echo htmlspecialchars($event["Timestamp"]); ?></td>
</tr>
<?php endforeach; ?>
</tbody>
</table>
</section>
</main>
</body>
</html>
