<?php
header("Content-Type: application/json");
require_once "config.php";

$distance = filter_input(INPUT_POST, "distance", FILTER_VALIDATE_FLOAT);
$motion = filter_input(INPUT_POST, "motion", FILTER_VALIDATE_INT);

if ($distance === false || $distance === null ||
    $motion === false || $motion === null) {
    http_response_code(400);
    echo json_encode(array("success" => false, "message" => "Invalid data."));
    exit;
}

$stmt = $pdo->prepare(
    "INSERT INTO Motion_data (`Motion Detected`, Distance_cm)
     VALUES (:motion, :distance)"
);

$stmt->execute(array(
    ":motion" => $motion,
    ":distance" => $distance
));

echo json_encode(array("success" => true));
?>
