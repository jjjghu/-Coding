<!-- 表單跳轉 -->
<?php
// 顯示 Request method
echo $_SERVER["REQUEST_METHOD"];
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    header("Location: login.php");
    exit;
}
?>